//
// Created by Fran- on 03/07/2023.
//

#include "HtmlManager.h"

std::string HtmlManager::generateTable(Priority *priority) {
    std::string html;
    // Agregar la importancia y urgencia del requerimiento en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Importancia</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + priority->strImportanceLevel() + "</td>";
    html += "<th style='font-family: Arial, sans-serif;'>Urgencia</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + priority->strUrgencyLevel() + "</td>";
    html += "</tr>";

    // Agregar la fase de desarrollo y estabilidad del requerimiento en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Fase de desarrollo</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + priority->strPhase() + "</td>";
    html += "<th style='font-family: Arial, sans-serif;'>Estabilidad</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + priority->strEstability() + "</td>";
    html += "</tr>";

    return html;
}

std::string HtmlManager::generateTable(Trackeable *trackeable) {
    std::string html;

    // Agregar el ID del trackeable en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>ID</th>";
    html += "<td style='font-family: Arial, sans-serif;' colspan='5'>" + static_cast<std::string>(trackeable->getId()) + "</td>";
    html += "</tr>";

    // Agregar el nombre del trackeable en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' colspan='1'>Nombre</th>";
    html += "<td style='font-family: Arial, sans-serif;' colspan='5'>" + trackeable->getName() + "</td>";
    html += "</tr>";

    // Agregar la descripción del trackeable en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' colspan='1'>Descripción</th>";
    html += "<td style='font-family: Arial, sans-serif;' colspan='5'>" + trackeable->getDescription() + "</td>";
    html += "</tr>";






    return html;
}


std::string HtmlManager::generateTableChanges(Trackeable *trackeable) {

    std::string html;

    // Agregar la versión y la fecha del trackeable en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Rango de versiones</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + trackeable ->getVersionMinor()+" - "+ trackeable->getVersionMajor() + "</td>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Fecha</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + trackeable->getDate().toString() + "</td>";
    html += "</tr>";

    // Agregar los autores del trackeable en una fila

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' colspan='1'>Autores</th>";
    html += "<td style='font-family: Arial, sans-serif;' colspan='3'>";
    //get every name of the authors
    std::set<OID> authors = trackeable->getAuthors();
    for (auto author : authors) {
        html +=  servicioStakeholder.getName(author);
        //if it is not the last author, add a comma
        if (author != *authors.rbegin()) {
            html += ", ";
        }
    }
    html += ".</td>";
    html += "</tr>";



    // Agregar los cambios del trackeable en una fila

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' colspan='5'>Cambios</th>";
    html += "</tr>";
    html += "<tr>";
    html += "<td style='font-family: Arial, sans-serif;' colspan='5'>";
    std::list<Change> changes = trackeable->getChanges();
    for (const auto& change : changes) {
        html += "<strong>Cambio:</strong> " + change.getVersion() + "<br>";
        html += "<strong>Fecha:</strong> " + change.getDate().toString() + "<br>";
        html += "<strong>Comentarios:</strong> " + change.getComments() + "<br>";
        html += "<br>";
    }
    html += "</td>";
    html += "</tr>";

    return html;

}

std::string HtmlManager::generateTable(std::list<SpecificInformation> lista)
{
    std::string html;
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' colspan='1'>Información específica</th>";
    html += "<td style='font-family: Arial, sans-serif;' colspan='5'>";
    for (const auto& info : lista) {
        html += "<strong>"+info.name +":</strong> <br>";
        html += info.description + "<br>";
    }
    html += "</td>";
    html += "</tr>";

    return html;
}

std::string HtmlManager::generateTable(InformationRequirement requirement) {
    std::string html;


    html += "<style>";
    html += "table { width: 100%; border-collapse: collapse; }";
    html += "th, td { padding: 10px; text-align: left; }";
    html += "th { background-color: #333; color: #fff; }";
    html += "td { background-color: #f1f1f1; }";
    html += "</style>";

    // Abrir la tabla
    html += "<table>";

    Trackeable* trackeable = &requirement;
    html += generateTable(trackeable);
    html += generateTable(requirement.getSpecificInformation()) ;

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Maxima ocurrencia simultanea</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + requirement.strMaxSimultaneousOccurrence() + "</td>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Promedio de ocurrencia simultanea</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + requirement.strAvgSimultaneousOccurrence() + "</td>";
    html += "</tr>";
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Estimacion de vida maxima</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + requirement.strLifeMaxEstimate() + "</td>";
    html += "<th style='font-family: Arial, sans-serif;' width='25%'>Estimacion de vida promedio</th>";
    html += "<td style='font-family: Arial, sans-serif;' width='25%'>" + requirement.strLifeAvgEstimate() + "</td>";
    html += "</tr>";

    Priority* priority = &requirement;
    html += generateTable(priority);
    html += generateTableChanges(trackeable);
    html += "</table>";

    return html;


}


std::string HtmlManager::generateTable(UserCase userCase) {
    std::string html;

    html += "<style>";
    html += "table { width: 100%; border-collapse: collapse; }";
    html += "th, td { padding: 10px; text-align: left; }";
    html += "th { background-color: #333; color: #fff; }";
    html += "td { background-color: #f1f1f1; }";
    html += "</style>";

    // Abrir la tabla
    html += "<table>";

    Trackeable* trackeable = &userCase;
    html += generateTable(trackeable);
    html += generateTable(&userCase);

    // Agregar el campo abstracto en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Abstracto</th>";
    std::string abstract = userCase.isAbstract() ? "Sí" : "No";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + abstract + "</td>";
    html += "</tr>";

    // Agregar la precondición en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Precondición</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + userCase.getPrecondition() + "</td>";
    html += "</tr>";

    // Agregar la postcondición en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Postcondición</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + userCase.getPostcondition() + "</td>";
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

    std::vector<Step> steps = userCase.getSteps();
    unsigned int i = 0;
    for (const auto& step : steps) {
        html += "<strong>Paso "+ std::to_string(i++) +":</strong> " + step.getDescription() + "<br>";
        html += "<strong>Condición:</strong> " + step.getCondition() + "<br>";
        html += "<strong>Comentarios:</strong> " + step.getComments() + "<br>";
        html += "<strong>Tipo:</strong> " + std::to_string(static_cast<int>(step.getType())) + "<br>";

        //print the next line only if the step is not the last one
        if (i < steps.size())
        html += "<hr style=\"border-top: 1px dashed #999;\">";

        std::list<Exception> exceptions = step.getExceptions();
        if (!exceptions.empty()) {
            html += "<strong>Excepciones:</strong><br>";
            for (const auto& exception : exceptions) {
                html += "<hr style=\"border-top: 1px dotted #999;\">";
                html += "<strong>ID:</strong> " + std::to_string(exception.id) + "<br>";
                html += "<strong>Paso:</strong> " + std::to_string(exception.step) + "<br>";
                html += "<strong>Tipo de paso:</strong> " + std::to_string(static_cast<int>(exception.stepType)) + "<br>";
                html += "<strong>Descripción:</strong> " + exception.description + "<br>";
                html += "<strong>Condición:</strong> " + exception.condition + "<br>";
                html += "<strong>Comentarios:</strong> " + exception.comments + "<br>";
                if (exception.reference != OID())
                    html += "<strong>Referencia:</strong> " + exception.reference.operator std::string() + "<br>";
                html += "<br>";
            }
        }
    }

    html += "</td>";    html += "</tr>";


    // Agregar los actores en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Actores</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>";

    std::list<OID> actors = userCase.getActors();
    for (const auto& actor : actors) {
        html += "<strong>ID:</strong> " + actor.operator std::string() + "<br>";
    }

    html += "</td>";
    html += "</tr>";

    // Agregar los objetivos en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Objetivos</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>";

    std::list<OID> objectives = userCase.getObjectives();
    for (const auto& objective : objectives) {
        html += "<strong>ID:</strong> " + objective.operator std::string() + "<br>";
    }

    html += "</td>";
    html += "</tr>";

    // Agregar el paquete en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Paquete</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + userCase.getPackage() + "</td>";
    html += "</tr>";

    // Agregar la frecuencia en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Frecuencia</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>  WIP" /*+ userCase.getFrequency() +*/ "</td>";
    html += "</tr>";

    // Agregar la generalización en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Generalización</th>";
    html += "<td style='font-family: Arial, sans-serif;'colspan=3>" + userCase.getGeneralization().operator std::string() + "</td>";
    html += "</tr>";

    Priority* priority = &userCase;
    html += generateTable(priority);
    html += generateTableChanges(trackeable);
    html += "</table>";

    return html;
}








