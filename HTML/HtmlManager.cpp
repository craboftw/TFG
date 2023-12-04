//
// Created by Fran- on 03/07/2023.
//

#include "HtmlManager.h"
#include "ServicioHTML.h"
#include "Servicio/ServicioPersona.h"
#include "Servicio/ServicioInterview.h"
#include "OID.h"


// Color constants or variables as std::string
const std::string COLOR_HEADER_BG = "#6241F8" ;
const std::string COLOR_HEADER_TEXT = "#FFFFFF";
const std::string COLOR_CELL_BG = "#D3DBF3";
const std::string COLOR_STEP_SEPARATOR = "#ccc";
const std::string COLOR_EXCEPTION_SEPARATOR = "#000000";
const std::string COLOR_BORDER = "#08088A";
const std::string COLOR_NAME = "#191970";
const std::string headHtml = R"(
<html>
<head>
  <meta charset="UTF-8">
  <style>
    table {
      width: 100%;
      border-collapse: collapse;
      margin: 8px;
      border: 3px solid )" + COLOR_BORDER + R"(;
    }
    th, td {
      padding: 10px;
      text-align: left;
      border-bottom: 1px solid )" + COLOR_STEP_SEPARATOR + R"(;
      font-family: Arial;
    }
    th {
      background-color: )" + COLOR_HEADER_BG + R"(;
      color: )" + COLOR_HEADER_TEXT + R"(;
    }
    td {
      background-color: )" + COLOR_CELL_BG + R"(;
    }
    .step-separator {
      border-bottom: 1px dashed )" + COLOR_STEP_SEPARATOR + R"(;
      margin-bottom: 10px;
      padding-bottom: 10px;

    }
  </style>
</head>
<body>
  <table>
)";


std::string HtmlManager::generateHead(OID id){
    std::string html = headHtml;
    html += generateTableTrackeable(id);
    return html;
}
std::string HtmlManager::generateTablePriority(OID id) {
    std::string html;
    // Agregar la importancia y urgencia del requerimiento en una fila
    html += "<tr><th >Importancia</th><td >" + servicioPriority.strImportanceLevel(id) + "</td><th >Urgencia</th><td >" + servicioPriority.strUrgencyLevel(id) + "</td></tr>";

    // Agregar la fase de desarrollo y estabilidad del requerimiento en una fila
    html += "<tr><th >Fase de desarrollo</th><td >" + servicioPriority.strPhase(id) + "</td><th >Estabilidad</th><td >" + servicioPriority.strEstability(id) + "</td></tr>";

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
    mapa[Interview::getPrefixID()] = "Entrevista";
    mapa[Persona::getPrefixID()] = "Persona";
    if (mapa.find(id) != mapa.end())
        return "Tipo por determinar";
    return mapa[id.getPrefix()];
}

std::string HtmlManager::generateTableTrackeable(OID id) {
    std::string html;
    std::string tipoTrackeable = obtenerTipoTrackeable(id);

    // make the next line in a color COLOR_NAME

    html += "<tr><th style='font-family: Arial, sans-serif; background-color: " + COLOR_NAME + "; color: " + COLOR_HEADER_TEXT + ";' colspan='1'>"+tipoTrackeable+"</th><td style='font-family: Arial, sans-serif;color: "+COLOR_HEADER_TEXT+"; background-color: " + COLOR_NAME + ";' colspan='5'> <strong>" +id.operator std::string()+"  "+ servicioTrackeable.getName(id) + "</strong></td></tr>";



    // Agregar la descripción del trackeable en una fila
    std::string descripcion = servicioTrackeable.getDescription(id);
    if (!descripcion.empty()) {
        html += "<tr><th  colspan='1'>Descripción</th><td  colspan='5'>" + descripcion + "</td></tr>";
    }






    return html;
}


std::string HtmlManager::generateTableChanges(OID id) {

    std::string html;

    std::string versionMayor = servicioTrackeable.getVersionMajor(id);
    std::string versionMenor = servicioTrackeable.getVersionMinor(id);
    if (!versionMayor.empty() and !versionMenor.empty())
    {  html += "<tr><th  width='25%'>Rango de versiones</th><td  width='25%'>" + versionMayor + " - " + versionMenor + "</td>";
    }
    if (versionMenor.empty())
    {
        html += "<tr><th  width='25%'>Versión</th><td  width='25%'>" + versionMayor + "</td>";

    }
    if (versionMayor.empty())
    {
        html += "<tr><th  width='25%'>Versión</th><td  width='25%'>" + versionMenor + "</td>";
    }
    html += "<th  width='25%'>Fecha</th><td  width='25%'>" + servicioTrackeable.getDate(id).toString() + "</td></tr>";

    // Agregar los autores del trackeable en una fila
    std::set<OID> authors = servicioTrackeable.getAuthors(id);
    std::string palabro;
    unsigned int autorsize = authors.size();
    if (autorsize == 1)
        palabro = "Autor";
    else
        palabro = "Autores";

    if (autorsize != 0) {
        html += "<tr><th  colspan='1'>" + palabro + "</th><td  colspan='3'>";
        //get every name of the authors
        for (auto author: authors) {
            html += servicioStakeholder.getName(author);
            //if it is not the last author, add a comma
            if (author != *authors.rbegin()) {
                html += ", ";
            } else {
                html += ".</td>";
            }
        }
        html += "</tr>";
    }

    //now the tracesTo
    std::set<OID> tracesTo = servicioTrackeable.getTracesTo(id);
    if (!tracesTo.empty()) {
        html += "<tr><th  colspan='1'>Dependencias con:</th><td  colspan='3'>";
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

        html += "<tr><th  colspan='5'>Cambios</th></tr><tr><td  colspan='3'>";
        for (const auto &change: changes) {
            html += "<strong>Cambio:</strong> " + change.getVersion() + "<br><strong>Fecha:</strong> " + change.getDate().toString() + "<br><strong>Comentarios:</strong> " + change.getComments() + "<br><br>";
        }
        html += "</td></tr>";
    }

    // ImprimirLosComentarios
    auto comments = servicioTrackeable.getComments(id);
    if (!comments.empty()) {
        html += "<tr><th >Comentarios</th><td colspan=3>" + comments + "</td></tr>";
    }


    return html;

}

std::string HtmlManager::generateTable(std::list<SpecificInformation> lista)
{
    std::string html;
    html += "<tr><th  colspan='1'>Información específica</th><td  colspan='5'>";
    for (const auto& info : lista) { //Añade una pelota gorda negra a la siguiente linea añadiendo lo siguiente: <span style='font-size: 20px;'>&#9679;</span>
        html += "<span style='font-size: 20px;'>&#9679; </span> <strong>"+info.name +":</strong>"; //añade una sangria a la siguiente linea añadiendo lo siguiente: <span style='margin-left: 30px;'>" + info.description + "</span><br>";
        if (!info.description.empty())
        html += "<br> <span style='margin-left: 30px;'>\"" + info.description + "\"<br></span>";
    }
    html += "</td></tr>";

    return html;
}

std::string HtmlManager::generateTableInformationRequirement (OID requirement) {
    std::string html;
    html += generateHead(requirement);

    html += generateTable(servicioInformationRequirement.getSpecificInformation(requirement));
    html += "<tr><th  width='25%'>Maxima ocurrencia simultanea</th><td  width='25%'>" + servicioInformationRequirement.strMaxSimultaneousOccurrence(requirement) + "</td><th  width='25%'>Promedio de ocurrencia simultanea</th><td  width='25%'>" + servicioInformationRequirement.strAvgSimultaneousOccurrence(requirement) + "</td></tr><tr><th  width='25%'>Estimacion de vida maxima</th><td  width='25%'>" + servicioInformationRequirement.strLifeMaxEstimate(requirement) + "</td><th  width='25%'>Estimacion de vida promedio</th><td  width='25%'>" + servicioInformationRequirement.strLifeAvgEstimate(requirement) + "</td></tr>";


    html += generateTableChanges(requirement);
    html += "</table></html>";

    return html;


}


std::string HtmlManager::generateTableUserCase(OID id) {
    std::string html;
    html += generateHead(id);

    //th es el color de la celda de la cabecera



    // Agregar el campo abstracto en una fila
    html += "<tr><th >Abstracto</th>";
    bool abstracto = servicioUserCase.getAbstract(id);
    if (abstracto)
        html += "<td colspan=3>Si</td></tr>";
    else
        html += "<td colspan=3>No</td></tr>";
    // Agregar la precondición en una fila
    html += "<tr><th >Precondición</th><td colspan=3>" + servicioUserCase.getPrecondition(id) + "</td></tr>";

    // Agregar la postcondición en una fila
    html += "<tr><th >Postcondición</th><td colspan=3>" + servicioUserCase.getPostcondition(id) + "</td></tr>";

    // Agregar los pasos en una fila
    /*
     *   <tr>
    <th  colspan=6>Pasos</th>
  </tr>
  <tr>
    <td  colspan=6>
     * */

    html += "<tr><th  colspan=6>Pasos</th> </tr> <tr><td colspan=6>";

    std::vector<Step> steps = servicioUserCase.getSteps(id);
    unsigned int i = 0;
    for (const auto& step : steps) {
        html += "<strong>Paso "+ std::to_string(i++) +":</strong> " + step.getDescription() + "<br><strong>Condición:</strong> " + step.getCondition() + "<br><strong>Comentarios:</strong> " + step.getComments() + "<br>";
        switch (step.getType()) {
            case SYSTEM:
                html += "<strong>Tipo:</strong> El sistema es quien realiza este paso. <br>";
                break;
            case ACTOR:
                if(step.getReference() != OID())
                html += "<strong>Tipo:</strong> El actor "+servicioActorUC.getName(step.getReference())+" es quien realiza este paso. <br>";
                break;
            case INCLUDE:
                if(step.getReference() != OID())
                    html += "<strong>Tipo:</strong> Include: &#09<strong>Caso de uso:</strong> " +step.getReference().operator std::string()+": "+ servicioUserCase.getName(step.getReference()) + "<br>";
                break;
            case EXTEND:
                if(step.getReference() != OID())
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
        html += "<tr><th  colspan=6>Excepciones</th> </tr> <tr><td colspan=6>";
        unsigned int i = 0;
        for (const auto& exception : exceptions) {
            html += "<strong>Paso:</strong> " + std::to_string(exception.step) + "<br><strong>Condición:</strong> " + exception.condition + "<br><strong>Acción:</strong> " + exception.description + "<br><strong>Comentarios:</strong> " + exception.comments + "<br>";
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
    html += "<tr><th >Actores</th><td colspan=3>";
    //getActors from every step and exception
    auto pasos = servicioUserCase.getSteps(id);
    std::set<OID> actors;
    for (const auto& paso : pasos) {
            if (paso.getType() == ACTOR && paso.getReference() != OID())
                actors.insert(paso.getReference());
    }
    auto excepciones = servicioUserCase.getExceptions(id);
    for (const auto& excepcion : excepciones) {
        if (excepcion.stepType == ACTOR && excepcion.reference != OID()) {
            actors.insert(excepcion.reference);
        }
    }
    for (const auto& actor : actors) {
        html += "<strong>" + actor.operator std::string() + "</strong> "+ servicioTrackeable.getName(actor)+"<br>";
    }

    html += "</td></tr>";

    // Agregar los objetivos en una fila
    html += "<tr><th >Objetivos</th><td colspan=3>";

    std::list<OID> objectives = servicioUserCase.getObjectives(id);
    for (const auto& objective : objectives) {
        html += "<strong>" + objective.operator std::string() + "</strong> "+ servicioTrackeable.getName(objective)+"<br>";
    }

    html += "</td></tr>";
    std::string paquete = servicioUserCase.getPackage(id);
    if (paquete != "") {
        // Agregar el paquete en una fila
        html += "<tr><th >Paquete</th><td colspan=3>" + paquete + "</td></tr>";
    }

    // Agregar la frecuencia en una fila
    html += "<tr><th >Frecuencia</th><td colspan=3>" + servicioUserCase.strFrequency(id)+"</td></tr>";

    // Agregar la generalización en una fila
    if (servicioUserCase.getGeneralization(id) != OID()) {
        html += "<tr><th >Generalización</th><td colspan=3>" +
                servicioUserCase.getGeneralization(id).operator std::string() + "</td></tr>";
    }

    html += generateTablePriority(id);
    html += generateTableChanges(id);
    html += "</table></html>";


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
    std::string email = servicioStakeholder.getEmail(stakeholder);
    std::string phone = servicioStakeholder.getPhone(stakeholder);
    std::string address = servicioStakeholder.getAddress(stakeholder);
    std::string role = servicioStakeholder.getStakeholderRole(stakeholder);

    if (!email.empty())
    {
        html += "<tr><th >Email</th><td colspan=3>" + servicioStakeholder.getEmail(stakeholder) + "</td></tr>";
    }

    if (!phone.empty())
    {
        html += "<tr><th >Teléfono</th><td colspan=3>" + servicioStakeholder.getPhone(stakeholder) + "</td></tr>";
    }

    if (!address.empty())
    {
        html += "<tr><th >Dirección</th><td colspan=3>" + servicioStakeholder.getAddress(stakeholder) + "</td></tr>";
    }

    if (!role.empty())
    {
        html += "<tr><th >Rol</th><td colspan=3>" + servicioStakeholder.getStakeholderRole(stakeholder) + "</td></tr>";
    }
    OID organization = servicioStakeholder.getWorksForOrganization(stakeholder);
    if (organization != OID())
    {
        html += "<tr><th >Organización</th>";
        auto frase = organization.operator std::string() + ": " + servicioOrganization.getName(organization);
        html += "<td colspan=3>" + frase + "</td></tr>";
    }
    html += generateTableChanges(stakeholder);

    html += "</table></html>";

    return html;
}

std::string HtmlManager::generateTableActorUC(OID actorUC) {
    //    std::string getPackage();
    //    OID getGeneralization() const;

    std::string html = generateHead(actorUC) ;
    html += "<tr><th >Paquete</th><td colspan=3>" + servicioActorUC.getPackage(actorUC) + "</td></tr>";

    if (servicioActorUC.getGeneralization(actorUC) != OID()) {
        html += "<tr><th >Generalización</th><td colspan=3>" +
                servicioActorUC.getGeneralization(actorUC).operator std::string() + "</td></tr>";
    }

    html += generateTableChanges(actorUC);
    html += "</table></html>";

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
    html += "<html><p style='font-family: Arial, sans-serif; padding: 10px;'>";
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

    html += "<tr><th >Informacion de Contacto</th><td colspan=3>" + servicioOrganization.getContactInfo(organization) + "</td></tr>";
    html += generateTableChanges(organization);

    html += "</table>";    html += "</html>";

    return html;

}

std::string HtmlManager::generateMatrixTraces(OID id)
{
    std::string html;
    html += "<html><head><meta charset=\"UTF-8\"><style>table { width: 100%; border-collapse: collapse; border: 3px solid " + COLOR_BORDER + "; }th, td { padding: 10px; text-align: left; border-bottom: 1px solid " + COLOR_STEP_SEPARATOR + "; }th { background-color: "+COLOR_HEADER_BG+"; color: " + COLOR_HEADER_TEXT + "; }td { background-color: " + COLOR_CELL_BG + "; }.step-separator {border-bottom: 1px dashed " + COLOR_STEP_SEPARATOR + ";margin-bottom: 10px;padding-bottom: 10px;}</style>";


    // Abrir la tabla
    html += "<table>";

    //Cada elemento de trackeableto ocupara una columna
    auto trackeableTo = servicioMatrixTraces.getTrackeablesTo(id);
    html += "<tr><th >Requerimientos</th>";
    for (auto trackeable : trackeableTo)
    {
        html += "<th style='font-family: Arial, sans-serif; text-align: center;'>"    + trackeable.operator std::string() + "</th>";
    }
html += "</tr>";

        //Cada elemento de trackeableFrom ocupara una fila
        auto trackeableFrom = servicioMatrixTraces.getTrackeablesFrom(id);
        auto matrixbool = servicioMatrixTraces.getMatrix(id);
        unsigned int i = 0;
        for (const auto& trackeable : trackeableFrom)
        {
            html += "<tr><th >" + trackeable.operator std::string() + "</th>";
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
        html += "</table></html>";

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



    html += "<tr><th >Rol</th><td colspan=3>" + role + "</td></tr><tr><th >Meta</th><td colspan=3>" + goal + "</td></tr><tr><th >Beneficio</th><td colspan=3>" + benefit + "</td></tr><tr><th >Time Points</th><td >" + std::to_string(devTimePoints) + "</td><th >Priority Points</th><td >" + std::to_string(priorityPoints) + "</td></tr>";
    html += generateTablePriority(id);
    html += generateTableChanges(id);

    html += "</table></html>";

    return html;
}

std::string HtmlManager::generateUserStory(OID id) {
    std::string html;

    std::string role = servicioUserStories.getRole(id);
    std::string goal = servicioUserStories.getGoal(id);
    std::string benefit = servicioUserStories.getBenefit(id);
    unsigned priorityPoints = servicioUserStories.getPriorityPoints(id);
    unsigned devTimePoints = servicioUserStories.getDevTimePoints(id);

    html += "<table style='width: 100%; border-collapse: collapse;'><tr style='line-height: 60%;'><th style='font-family: Arial, sans-serif; background-color: " + COLOR_NAME + "; color: " + COLOR_HEADER_TEXT + "; width: 50%; font-size: 60%; padding: 0;'>Time Points: " + std::to_string(devTimePoints) + "</th><td style='font-family: Arial, sans-serif; color: " + COLOR_HEADER_TEXT + "; background-color: " + COLOR_NAME + "; width: 50%; font-size: 60%; padding: 0;'> <strong> Importance Points: " + std::to_string(priorityPoints) + "</strong></td></tr></table>";



    html += "<table style='width: 100%; border-top: 0px solid " + COLOR_BORDER + ";'><tr><th style='font-family: Arial, sans-serif; width: 20%;'>Como</th><td >" + role + "</td></tr><tr><th style='font-family: Arial, sans-serif; width: 20%; border-top: 0px;'>Quiero</th><td >" + goal + "</td></tr><tr><th style='font-family: Arial, sans-serif; width: 20%; border-top: 0px;'>Para</th><td >" + benefit + "</td></tr></table>";

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
            html += "</tr><tr><td style='width: 25%;'>";
            html += generateUserStory(id);
            html += "</td>";
            i = 1;
        }
    }
    html += "</tr></table></html>";

    return html;
}

std::string HtmlManager::generateUserCaseDiagram(OID id)
{
    std::string html;
    std::string name = servicioTrackeable.getName(id);
    html += "<html><head></head><body><img src='" + id.operator std::string() + ".png' alt='" + name + "' ></body></html>";
    return html;
}

std::string HtmlManager::generateTablePersona(OID id) {
    std::string html = generateHead(id);
    ServicioPersona servicioPersona;
    std::string gender = servicioPersona.getGender(id);
    unsigned age = servicioPersona.getAge(id);
    std::string ageString = std::to_string(age);
    // if both are not empty then we put them in the same row
    std::string photo = servicioPersona.getPhoto(id);
    if (!photo.empty()) {
        // photo is the path to the photo with the size of 400 max in any dimension
        html += "<tr><th>Foto</th><td colspan=3><img src='" + photo + "' alt='Foto de " + servicioPersona.getName(id) + "' style='max-width: 400px; max-height: 400px;'></td></tr>";

        if (!gender.empty() && age != 0) {
            html += "<tr><th>Edad</th><td>" + ageString + "</td><th>Género</th><td>" + gender + "</td></tr>";
        } else {
            if (gender.empty() && age != 0) {
                html += "<tr><th>Edad</th><td colspan=3>" + ageString + "</td></tr>";
            } else if (!gender.empty() && age == 0) {
                html += "<tr><th>Género</th><td colspan=3>" + gender + "</td></tr>";
            }
        }
    }

    std::string location = servicioPersona.getLocation(id);
    if (!location.empty()) {
        html += "<tr><th>Ubicación</th><td colspan=3>" + location + "</td></tr>";
    }

    std::string occupation = servicioPersona.getOccupation(id);
    if (!occupation.empty()) {
        html += "<tr><th>Ocupación</th><td colspan=3>" + occupation + "</td></tr>";
    }
    std::string background = servicioPersona.getBackground(id);
    if (!background.empty()) {
        html += "<tr><th>Antecedentes</th><td colspan=3>" + background + "</td></tr>";
    }
    std::string goals = servicioPersona.getGoals(id);
    if (!goals.empty()) {
        html += "<tr><th>Metas</th><td colspan=3>" + goals + "</td></tr>";
    }
    std::string challenges = servicioPersona.getChallenges(id);
    if (!challenges.empty()) {
        html += "<tr><th>Desafíos</th><td colspan=3>" + challenges + "</td></tr>";
    }
    std::string behavior = servicioPersona.getBehavior(id);
    if (!behavior.empty()) {
        html += "<tr><th>Comportamiento</th><td colspan=3>" + behavior + "</td></tr>";
    }
    std::string communicationStyle = servicioPersona.getCommunicationStyle(id);
    if (!communicationStyle.empty()) {
        html += "<tr><th>Estilo de comunicación</th><td colspan=3>" + communicationStyle + "</td></tr>";
    }
    std::string technologyAdoption = servicioPersona.getTechnologyAdoption(id);
    if (!technologyAdoption.empty()) {
        html += "<tr><th>Adopción de tecnología</th><td colspan=3>" + technologyAdoption + "</td></tr>";
    }
    std::string influences = servicioPersona.getInfluences(id);
    if (!influences.empty()) {
        html += "<tr><th>Influencias</th><td colspan=3>" + influences + "</td></tr>";
    }
    std::string informationSources = servicioPersona.getInformationSources(id);
    if (!informationSources.empty()) {
        html += "<tr><th>Fuentes de información</th><td colspan=3>" + informationSources + "</td></tr>";
    }
    std::string userJourney = servicioPersona.getUserJourney(id);
    if (!userJourney.empty()) {
        html += "<tr><th>Viaje del usuario</th><td colspan=3>" + userJourney + "</td></tr>";
    }
    std::string brandRelationship = servicioPersona.getBrandRelationship(id);
    if (!brandRelationship.empty()) {
        html += "<tr><th>Relación con la marca</th><td colspan=3>" + brandRelationship + "</td></tr>";
    }
    html += generateTableChanges(id);
    html += "</table></html>";

    return html;
}


std::string HtmlManager::generateTableInterview( OID id) {
    std::string html = generateHead(id);
    ServicioInterview servicioInterview;
    std::vector<Question> questions = servicioInterview.getQuestions(id);
    std::set<OID> stakeholdersAsking = servicioInterview.getStakeholdersAsking(id);
    std::set<OID> stakeholdersInterviewed = servicioInterview.getStakeholdersInterviewed(id);
    std::string place = servicioInterview.getPlace(id);
if (!place.empty())
    {
        html += "<tr><th >Lugar</th><td colspan=3>" + place + "</td></tr>";
    }
    if (!stakeholdersAsking.empty())
    {
        html += "<tr><th >Stakeholders preguntando</th><td colspan=3>";
        for (auto stakeholder : stakeholdersAsking)
        {
            html += servicioTrackeable.getName(stakeholder) + ", ";
        }
        //delete last space and comma and add .
        html.pop_back();
        html.pop_back();
        html += ".";
        html += "</td></tr>";
    }
    if (!stakeholdersInterviewed.empty())
    {
        html += "<tr><th >Stakeholders entrevistados</th><td colspan=9>";
        for (auto stakeholder : stakeholdersInterviewed)
        {
            html += servicioTrackeable.getName(stakeholder) + ", ";
        }
        //delete last space and comma and add .
        html.pop_back();
        html.pop_back();
        html += ".";
        html += "</td></tr>";
    }
    if (!questions.empty())
    {
        //question.question and question.answer
        for (auto question : questions)
        {
         //caracter circle solid blue : &#9898;
            html += "<tr><td colspan=9>";
            html += "<span style=\"color:blue\">" + question.question + "</span><br>";
            html += question.answer + "<br>";
        }
        html += "</td></tr>";
    }
    
    return html; 

}
