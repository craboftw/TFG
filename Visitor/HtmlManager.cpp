//
// Created by Fran- on 03/07/2023.
//

#include "HtmlManager.h"


// Color constants or variables as std::string
const std::string COLOR_HEADER_BG = "#6241F8" ;
const std::string COLOR_HEADER_TEXT = "#FFFFFF";
const std::string COLOR_CELL_BG = "#D3DBF3";
const std::string COLOR_STEP_SEPARATOR = "#ccc";
const std::string COLOR_EXCEPTION_SEPARATOR = "#000000";
const std::string COLOR_BORDER = "#08088A";
const std::string COLOR_NAME = "#191970";



std::string HtmlManager::generateHead(OID id){
    std::string html;
    html += "<html>";
    html += "<meta charset=\"UTF-8\">";
    html += "<style>";
    html += "table { width: 100%; border-collapse: collapse; border: 3px solid " + COLOR_BORDER + "; }";
    html += "th, td { padding: 10px; text-align: left; border-bottom: 1px solid " + COLOR_STEP_SEPARATOR + "; }";
    html += "th { background-color: "+COLOR_HEADER_BG+"; color: " + COLOR_HEADER_TEXT + "; }";
    html += "td { background-color: " + COLOR_CELL_BG + "; }";
    html += ".step-separator {border-bottom: 1px dashed " + COLOR_STEP_SEPARATOR + ";margin-bottom: 10px;padding-bottom: 10px;}";
    html += "</style>";


    // Abrir la tabla
    html += "<table>";


    html += generateTableTrackeable(id);
    return html;
}
std::string HtmlManager::generateTablePriority(OID id) {
    std::string html;
    // Agregar la importancia y urgencia del requerimiento en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Importancia</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + servicioPriority.strImportanceLevel(id) + "</td>";
    html += "<th style='font-family: Arial, sans-serif;'>Urgencia</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + servicioPriority.strUrgencyLevel(id) + "</td>";
    html += "</tr>";

    // Agregar la fase de desarrollo y estabilidad del requerimiento en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Fase de desarrollo</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + servicioPriority.strPhase(id) + "</td>";
    html += "<th style='font-family: Arial, sans-serif;'>Estabilidad</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + servicioPriority.strEstability(id) + "</td>";
    html += "</tr>";

    return html;
}

std::string obtenerTipoTrackeable(OID id)
{
    std::map<std::string ,std::string > mapa;
    mapa[ActorUC::getPrefixID()] = "Actor de caso de uso";
    mapa[UserCase::getPrefixID()] = "Caso de uso";
    mapa[InformationRequirement::getPrefixID()] = "Requerimiento de información";
    mapa[NonFunctionalRequirement::getPrefixID()] = "Requerimiento no funcional";
    mapa[FunctionalRequirement::getPrefixID()] = "Requerimiento funcional";
    mapa[Stakeholder::getPrefixID()] = "Stakeholder";
    mapa[Organization::getPrefixID()] = "Organización";
    mapa[RestrictionRequirement::getPrefixID()] = "Requisito de restricción";
    mapa[SystemObjective::getPrefixID()] = "Objetivo del sistema";
    mapa[MatrixTraces::getPrefixID()] = "Matriz de trazabilidad";
    mapa[UserStories::getPrefixID()] = "Historia de usuario";

    return mapa[id.getPrefix()];
}

std::string HtmlManager::generateTableTrackeable(OID id) {
    std::string html;
    std::string tipoTrackeable = obtenerTipoTrackeable(id);

    // make the next line in a color COLOR_NAME

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif; background-color: " + COLOR_NAME + "; color: " + COLOR_HEADER_TEXT + ";' colspan='1'>"+tipoTrackeable+"</th>";
    html += "<td style='font-family: Arial, sans-serif;color: "+COLOR_HEADER_TEXT+"; background-color: " + COLOR_NAME + ";' colspan='5'> <strong>" +id.operator std::string()+"  "+ servicioTrackeable.getName(id) + "</strong></td>";
    html += "</tr>";



    // Agregar la descripción del trackeable en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' colspan='1'>Descripción</th>";
    html += "<td style='font-family: Arial, sans-serif;' colspan='5'>" + servicioTrackeable.getDescription(id) + "</td>";
    html += "</tr>";






    return html;
}


std::string HtmlManager::generateTableChanges(OID id) {

    std::string html;

    // Agregar la versión y la fecha del trackeable en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Rango de versiones</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + servicioTrackeable.getVersionMinor(id) + " - " + servicioTrackeable.getVersionMajor(id) + "</td>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Fecha</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + servicioTrackeable.getDate(id).toString() + "</td>";
    html += "</tr>";

    // Agregar los autores del trackeable en una fila
    std::set<OID> authors = servicioTrackeable.getAuthors(id);
    std::string palabro;
    if (authors.empty() or authors.size() == 1)
        palabro = "Autor";
    else
        palabro = "Autores";


    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' colspan='1'>"+palabro+"</th>";
    html += "<td style='font-family: Arial, sans-serif;' colspan='3'>";
    //get every name of the authors
    for (auto author : authors) {
        html +=  servicioStakeholder.getName(author);
        //if it is not the last author, add a comma
        if (author != *authors.rbegin()) {
            html += ", ";
        }
        else {
            html += ".</td>";
        }
    }
    html += "</tr>";

    //now the tracesTo
    std::set<OID> tracesTo = servicioTrackeable.getTracesTo(id);
    if (!tracesTo.empty()) {
        html += "<tr>";
        html += "<th style='font-family: Arial, sans-serif;' colspan='1'>Dependencias con:</th>";
        html += "<td style='font-family: Arial, sans-serif;' colspan='3'>";
        //get every name of the authors
        for (auto trace : tracesTo) {
            html += "<strong>"+ trace.operator std::string() +"</strong>  "+ servicioTrackeable.getName(trace);
            //if it is not the last author, add a comma
            if (trace != *tracesTo.rbegin()) {
                html += ", ";
            }
            else {
                html += ".</td>";
            }
        }
        html += "</tr>";
    }



    // Agregar los cambios del trackeable en una fila
    std::list<Change> changes = servicioTrackeable.getChanges(id);
    if (!changes.empty()) {

        html += "<tr>";
        html += "<th style='font-family: Arial, sans-serif;' colspan='5'>Cambios</th>";
        html += "</tr>";
        html += "<tr>";
        html += "<td style='font-family: Arial, sans-serif;' colspan='3'>";
        for (const auto &change: changes) {
            html += "<strong>Cambio:</strong> " + change.getVersion() + "<br>";
            html += "<strong>Fecha:</strong> " + change.getDate().toString() + "<br>";
            html += "<strong>Comentarios:</strong> " + change.getComments() + "<br>";
            html += "<br>";
        }
        html += "</td>";
        html += "</tr>";
    }


    return html;

}

std::string HtmlManager::generateTable(std::list<SpecificInformation> lista)
{
    std::string html;
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' colspan='1'>Información específica</th>";
    html += "<td style='font-family: Arial, sans-serif;' colspan='5'>";
    for (const auto& info : lista) { //Añade una pelota gorda negra a la siguiente linea añadiendo lo siguiente: <span style='font-size: 20px;'>&#9679;</span>
        html += "<span style='font-size: 20px;'>&#9679; </span>" ;
        html += "<strong>"+info.name +":</strong> <br>"; //añade una sangria a la siguiente linea añadiendo lo siguiente: <span style='margin-left: 30px;'>" + info.description + "</span><br>";
        html += " <span style='margin-left: 30px;'>\"" + info.description + "\"<br></span>";
    }
    html += "</td>";
    html += "</tr>";

    return html;
}

std::string HtmlManager::generateTableInformationRequirement (OID requirement) {
    std::string html;
    html += generateHead(requirement);

    html += generateTable(servicioInformationRequirement.getSpecificInformation(requirement));
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Maxima ocurrencia simultanea</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + servicioInformationRequirement.strMaxSimultaneousOccurrence(requirement) + "</td>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Promedio de ocurrencia simultanea</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + servicioInformationRequirement.strAvgSimultaneousOccurrence(requirement) + "</td>";
    html += "</tr>";
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Estimacion de vida maxima</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + servicioInformationRequirement.strLifeMaxEstimate(requirement) + "</td>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Estimacion de vida promedio</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + servicioInformationRequirement.strLifeAvgEstimate(requirement) + "</td>";
    html += "</tr>";


    html += generateTableChanges(requirement);
    html += "</table>";
    html += "</html>";

    return html;


}


std::string HtmlManager::generateTableUserCase(OID id) {
    std::string html;
    html += generateHead(id);

    //th es el color de la celda de la cabecera



    // Agregar el campo abstracto en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Abstracto</th>";
    std::string abstract = servicioUserCase.getAbstract(id) ? "Sí" : "No";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + abstract + "</td>";
    html += "</tr>";

    // Agregar la precondición en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Precondición</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioUserCase.getPrecondition(id) + "</td>";
    html += "</tr>";

    // Agregar la postcondición en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Postcondición</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioUserCase.getPostcondition(id) + "</td>";
    html += "</tr>";

    // Agregar los pasos en una fila
    /*
     *   <tr>
    <th style='font-family: Arial, sans-serif;' colspan=6>Pasos</th>
  </tr>
  <tr>
    <td style='font-family: Arial, sans-serif;' colspan=6>
     * */

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' colspan=6>Pasos</th> </tr> <tr>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=6>";

    std::vector<Step> steps = servicioUserCase.getSteps(id);
    unsigned int i = 0;
    for (const auto& step : steps) {
        html += "<strong>Paso "+ std::to_string(i++) +":</strong> " + step.getDescription() + "<br>";
        html += "<strong>Condición:</strong> " + step.getCondition() + "<br>";
        html += "<strong>Comentarios:</strong> " + step.getComments() + "<br>";
        switch (step.getType()) {
            case SYSTEM:
                html += "<strong>Tipo:</strong> El sistema es quien realiza este paso. <br>";
                break;
            case ACTOR:
                html += "<strong>Tipo:</strong> El actor "+servicioActorUC.getName(step.getReference())+" es quien realiza este paso. <br>";
                break;
            case INCLUDE:
                html += "<strong>Tipo:</strong> Include: &#09<strong>Caso de uso:</strong> " +step.getReference().operator std::string()+": "+ servicioUserCase.getName(step.getReference()) + "<br>";
                break;
            case EXTEND:
                html += "<strong>Tipo:</strong> Extend: &#09<strong>Caso de uso:</strong> " +step.getReference().operator std::string()+": "+ servicioUserCase.getName(step.getReference()) + "<br>";
                break;
        }

        //print the next line only if the step is not the last one
        if (i < steps.size())
        html += "<hr style=\"border-top: 1px dashed " + COLOR_EXCEPTION_SEPARATOR + ";\">";


    }
    html += "</td>";    html += "</tr>";


    std::vector<Exception> exceptions = servicioUserCase.getExceptions(id);
    if (!exceptions.empty()) {
        html += "<tr>";
        html += "<th style='font-family: Arial, sans-serif;' colspan=6>Excepciones</th> </tr> <tr>";
        html += "<td style='font-family: Arial, sans-serif;'colspan=6>";
        unsigned int i = 0;
        for (const auto& exception : exceptions) {
            html += "<strong>Paso:</strong> " + std::to_string(exception.step) + "<br>";
            html += "<strong>Condición:</strong> " + exception.condition + "<br>";
            html += "<strong>Acción:</strong> " + exception.description + "<br>";
            html += "<strong>Comentarios:</strong> " + exception.comments + "<br>";
            switch (exception.stepType) {
                case SYSTEM:
                    html += "<strong>Tipo:</strong> El sistema es quien realiza este paso. <br>";
                    break;
                case ACTOR:
                    html += "<strong>Tipo:</strong> El actor "+servicioActorUC.getName(exception.reference)+" es quien realiza este paso. <br>";
                    break;
                case INCLUDE:
                    html += "<strong>Tipo:</strong> Include: &#09<strong>Caso de uso:</strong> " +exception.reference.operator std::string()+": "+ servicioUserCase.getName(exception.reference) + "<br>";
                    break;
                case EXTEND: //tabulador en html es &#09;
                    html += "<strong>Tipo:</strong> Extend: &#09<strong>Caso de uso:</strong> " +exception.reference.operator std::string()+": "+ servicioUserCase.getName(exception.reference) + "<br>";
                    break;

            }
            i++;
            if (i < exceptions.size())
            html += "<hr style=\"border-top: 1px dotted " + COLOR_EXCEPTION_SEPARATOR + ";\">";

        }
    }

    html += "</td>";    html += "</tr>";


    // Agregar los actores en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Actores</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>";

    std::list<OID> actors = servicioUserCase.getActors(id);
    for (const auto& actor : actors) {
        html += "<strong>ID:</strong> " + actor.operator std::string() + "<br>";
    }

    html += "</td>";
    html += "</tr>";

    // Agregar los objetivos en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Objetivos</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>";

    std::list<OID> objectives = servicioUserCase.getObjectives(id);
    for (const auto& objective : objectives) {
        html += "<strong>ID:</strong> " + objective.operator std::string() + "<br>";
    }

    html += "</td>";
    html += "</tr>";

    // Agregar el paquete en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Paquete</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioUserCase.getPackage(id) + "</td>";
    html += "</tr>";

    // Agregar la frecuencia en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Frecuencia</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioUserCase.strFrequency(id)+"</td>";
    html += "</tr>";

    // Agregar la generalización en una fila
    if (servicioUserCase.getGeneralization(id) != OID()) {
        html += "<tr>";
        html += "<th style='font-family: Arial, sans-serif;'>Generalización</th>";
        html += "<td style='font-family: Arial, sans-serif;'colspan=3>" +
                servicioUserCase.getGeneralization(id).operator std::string() + "</td>";
        html += "</tr>";
    }

    html += generateTablePriority(id);
    html += generateTableChanges(id);
    html += "</table>";
    html += "</html>";


    //add TFG/Diagrams/UseCaseDiagram.png


    return html;
}

std::string HtmlManager::generateTableStakeholder(OID stakeholder) {
    std::string html = generateHead(stakeholder) ;
    /*    std::string getEmail(OID id);
    std::string getPhone(OID id);
    std::string getAddress(OID id);
    std::string getStakeholderRole(OID id);
    OID getWorksForOrganization(OID id);*/
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Email</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioStakeholder.getEmail(stakeholder) + "</td>";
    html += "</tr>";

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Teléfono</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioStakeholder.getPhone(stakeholder) + "</td>";
    html += "</tr>";

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Dirección</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioStakeholder.getAddress(stakeholder) + "</td>";
    html += "</tr>";

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Rol</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioStakeholder.getStakeholderRole(stakeholder) + "</td>";
    html += "</tr>";

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Organización</th>";
    OID organization = servicioStakeholder.getWorksForOrganization(stakeholder);
    auto frase = organization.operator std::string()+": "+servicioOrganization.getName(organization);
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" +frase+"</td>";
    html += "</tr>";
    html += generateTableChanges(stakeholder);

    html += "</table>";
    html += "</html>";

    return html;
}

std::string HtmlManager::generateTableActorUC(OID actorUC) {
    //    std::string getPackage();
    //    OID getGeneralization() const;

    std::string html = generateHead(actorUC) ;
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Paquete</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioActorUC.getPackage(actorUC) + "</td>";
    html += "</tr>";

    if (servicioActorUC.getGeneralization(actorUC) != OID()) {
        html += "<tr>";
        html += "<th style='font-family: Arial, sans-serif;'>Generalización</th>";
        html += "<td style='font-family: Arial, sans-serif;'colspan=3>" +
                servicioActorUC.getGeneralization(actorUC).operator std::string() + "</td>";
        html += "</tr>";
    }

    html += generateTableChanges(actorUC);
    html += "</table>";
    html += "</html>";

    return html;
}

std::string HtmlManager::generateTableText(OID requirement) {
    std::string html;
    std::string description = servicioText.getDescription(requirement);

    // Reemplazar saltos de línea individuales por etiquetas <br>
    size_t pos = 0;
    while ((pos = description.find('\n', pos)) != std::string::npos) {
        description.replace(pos, 1, "<br>");
        pos += 4;  // Longitud de "<br>"
    }

    // Dividir en párrafos si hay dos saltos de línea consecutivos
    std::vector<std::string> paragraphs;
    std::string paragraph;
    std::istringstream iss(description);
    for (std::string line; std::getline(iss, line);) {
        if (line.empty()) {
            if (!paragraph.empty()) {
                paragraphs.push_back(paragraph);
                paragraph.clear();
            }
        } else {
            if (!paragraph.empty()) {
                paragraph += "<br>";
            }
            paragraph += line;
        }
    }
    if (!paragraph.empty()) {
        paragraphs.push_back(paragraph);
    }

    // Construir el HTML final
    html += "<html>";
    html += "<p style='font-family: Arial, sans-serif; padding: 10px;'>";
    for (const std::string& para : paragraphs) {
        html += "<span style='font-size: 18px; color: #333333;'>";
        html += para;
        html += "</span></p>";
    }
    html += "</html>";

    return html;
}

std::string HtmlManager::generateTableNonFunctionalRequirement(OID requirement) {
    std::string html = generateHead(requirement) ;

    html += generateTablePriority(requirement);
    html += generateTableChanges(requirement);

    html += "</table>";    html += "</html>";

    return html;
}

std::string HtmlManager::generateTableFunctionalRequirement(OID requirement) {
    std::string html = generateHead(requirement) ;

    html += generateTablePriority(requirement);
    html += generateTableChanges(requirement);

    html += "</table>";    html += "</html>";

    return html;
}

std::string HtmlManager::generateTableSystemObjetive(OID requirement) {
    std::string html = generateHead(requirement) ;

    html += generateTablePriority(requirement);
    html += generateTableChanges(requirement);

    html += "</table>";    html += "</html>";

    return html;
}

std::string HtmlManager::generateTableRestrictionRequirement(OID requirement) {
    std::string html = generateHead(requirement) ;

    html += generateTablePriority(requirement);
    html += generateTableChanges(requirement);
    html += "</table>";    html += "</html>";

    return html;
}

std::string HtmlManager::generateTableOrganization(OID organization) {
    std::string html = generateHead(organization) ;

    html += generateTableChanges(organization);
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Informacion de Contacto</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + servicioOrganization.getContactInfo(organization) + "</td>";
    html += "</tr>";

    html += "</table>";    html += "</html>";

    return html;

}

std::string HtmlManager::generateMatrixTraces(OID id)
{
    std::string html;
    html += "<html>";
    html += "<head>";
    html += "<meta charset=\"UTF-8\">";
    html += "<style>";
    html += "table { width: 100%; border-collapse: collapse; border: 3px solid " + COLOR_BORDER + "; }";
    html += "th, td { padding: 10px; text-align: left; border-bottom: 1px solid " + COLOR_STEP_SEPARATOR + "; }";
    html += "th { background-color: "+COLOR_HEADER_BG+"; color: " + COLOR_HEADER_TEXT + "; }";
    html += "td { background-color: " + COLOR_CELL_BG + "; }";
    html += ".step-separator {border-bottom: 1px dashed " + COLOR_STEP_SEPARATOR + ";margin-bottom: 10px;padding-bottom: 10px;}";
    html += "</style>";


    // Abrir la tabla
    html += "<table>";

    //Cada elemento de trackeableto ocupara una columna
    auto trackeableTo = servicioMatrixTraces.getTrackeablesTo(id);
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Requerimientos</th>";
    for (auto trackeable : trackeableTo)
    {
        html += "<th style='font-family: Arial, sans-serif; text-align: center;'>"    + trackeable.operator std::string() + "</th>";
    }
html += "</tr>";

        //Cada elemento de trackeableFrom ocupara una fila
        auto trackeableFrom = servicioMatrixTraces.getTrackeablesFrom(id);
        auto matrixbool = servicioMatrixTraces.getMatrix(id);
        unsigned int i = 0;
        for (auto trackeable : trackeableFrom)
        {
            html += "<tr>";
            html += "<th style='font-family: Arial, sans-serif;'>" + trackeable.operator std::string() + "</th>";
            //add a vertical separator
            unsigned int j = 0;
            for (auto trackeable2 : trackeableTo)
            {
                if (matrixbool[i][j])
                {
                    // Write an arrow pointing up emoji
                    html += "<td style='font-family: Arial, sans-serif; border-right: 1px solid " + COLOR_STEP_SEPARATOR + "; text-align: center;'>⬆\uFE0F </td>";
                }
                else
                {
                    html += "<td style='font-family: Arial, sans-serif; border-right: 1px solid " + COLOR_STEP_SEPARATOR + "; text-align: center;'></td>";
                }
                j++;
            }
            html += "</tr>";
            i++;

        }

        // Cerrar la tabla
        html += "</table>";
        html += "</html>";

        return html;

}
std::string HtmlManager::generateTableUserStory(OID id)
{
    std::string role = servicioUserStories.getRole(id);
    std::string goal = servicioUserStories.getGoal(id);
    std::string benefit = servicioUserStories.getBenefit(id);
    unsigned priorityPoints = servicioUserStories.getPriorityPoints(id);
    unsigned devTimePoints = servicioUserStories.getDevTimePoints(id);

    std::string html = generateHead(id) ;



    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Rol</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + role + "</td>";
    html += "</tr>";
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Meta</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + goal + "</td>";
    html += "</tr>";
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Beneficio</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + benefit + "</td>";
    html += "</tr>";
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Time Points</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + std::to_string(devTimePoints) + "</td>";
    html += "<th style='font-family: Arial, sans-serif;'>Priority Points</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + std::to_string(priorityPoints) + "</td>";
    html += "</tr>";
    html += generateTablePriority(id);
    html += generateTableChanges(id);

    html += "</table>";
    html += "</html>";

    return html;
}

std::string HtmlManager::generateUserStory(OID id) {
    std::string html;

    std::string role = servicioUserStories.getRole(id);
    std::string goal = servicioUserStories.getGoal(id);
    std::string benefit = servicioUserStories.getBenefit(id);
    unsigned priorityPoints = servicioUserStories.getPriorityPoints(id);
    unsigned devTimePoints = servicioUserStories.getDevTimePoints(id);

    html += "<table style='width: 100%; border-collapse: collapse;'>";
    html += "<tr style='line-height: 60%;'>";
    html += "<th style='font-family: Arial, sans-serif; background-color: " + COLOR_NAME + "; color: " + COLOR_HEADER_TEXT + "; width: 50%; font-size: 60%; padding: 0;'>Time Points: " + std::to_string(devTimePoints) + "</th>";
    html += "<td style='font-family: Arial, sans-serif; color: " + COLOR_HEADER_TEXT + "; background-color: " + COLOR_NAME + "; width: 50%; font-size: 60%; padding: 0;'> <strong> Importance Points: " + std::to_string(priorityPoints) + "</strong></td>";
    html += "</tr>";
    html += "</table>";



    html += "<table style='width: 100%; border-top: 0px solid " + COLOR_BORDER + ";'>";
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif; width: 20%;'>Como</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + role + "</td>";
    html += "</tr>";
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif; width: 20%; border-top: 0px;'>Quiero</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + goal + "</td>";
    html += "</tr>";
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif; width: 20%; border-top: 0px;'>Para</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + benefit + "</td>";
    html += "</tr>";
    html += "</table>";

    return html;
}


std::string HtmlManager::generateUserStory(const std::list<OID>& listID) {
    std::string html;
    // El mismo código que generateUserStory(OID id), pero para una lista de OID. En este caso, la tabla ocupará todo el ancho de la página o el ancho del contenedor,
    // siendo cada tabla un cuarto del ancho de la página.
    html += "<table style='width: 100%;'>";
    unsigned int i = 0;
    html += "<tr>";
    for (auto id : listID) {
        if (i != 4) {
            html += "<td style='width: 25%;'>";
            html += generateUserStory(id);
            html += "</td>";
            i++;
        } else {
            html += "</tr><tr>";
            html += "<td style='width: 25%;'>";
            html += generateUserStory(id);
            html += "</td>";
            i = 1;
        }
    }
    html += "</tr>";
    html += "</table>";
    html += "</html>";

    return html;
}


unsigned IndexHTMLelement::getPos() const {
    return pos ;
}

void IndexHTMLelement::setPos(unsigned int pos) {
    this->pos = pos;
}

OID IndexHTMLelement::getId() const {
    return id;
}

std::set<OID> IndexHTMLelement::getElementsToPrint() const {
    return elementsToPrint;
}

void IndexHTMLelement::setElementsToPrint(const std::set<OID> &elementsToPrint) {
    this->elementsToPrint = elementsToPrint;
}

void IndexHTMLelement::addElementToPrint(OID id) {
    elementsToPrint.insert(id);
}

void IndexHTMLelement::addElementToPrint(std::set<OID> ids) {
    elementsToPrint.insert(ids.begin(), ids.end());
}

void IndexHTMLelement::removeElementToPrint(OID id) {
    elementsToPrint.erase(id);
}

void IndexHTMLelement::removeElementToPrint(std::set<OID> ids) {
    for (auto id : ids) {
        elementsToPrint.erase(id);
    }
}

void IndexHTMLelement::addsubLevel(IndexHTMLelement hijo) {
    sublevels.push_back(hijo);
}

void IndexHTMLelement::removeSubLevel(unsigned int pos) {
    sublevels.erase(sublevels.begin() + pos);
}

std::vector<IndexHTMLelement> IndexHTMLelement::getSublevels() const {
    return sublevels;
}

IndexHTMLelement IndexHTMLelement::getSubLevel(unsigned int pos) const {
    return sublevels[pos];
}

void IndexHTMLelement::setsubLevel(IndexHTMLelement hijo, unsigned int pos) {
    sublevels[pos] = hijo;
}

void IndexHTMLelement::setId(OID id) {
    this->id = id;
}

std::string IndexHTMLelement::getName() const {
    return name;
}

void IndexHTMLelement::setName(std::string name) {
    this->name = name;
}