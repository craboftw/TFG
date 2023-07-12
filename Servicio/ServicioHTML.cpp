//
// Created by Fran- on 08/07/2023.
//

#include <stack>
#include "ServicioHTML.h"



void ServicioHTML::printHTML() {
    std::string html;
    HtmlManager htmlManager;
    std::ofstream file;
    file.open("index.html");
    html += "<!DOCTYPE html>\n";
    html += "<html>\n";
    html += "<head>\n";
    html += "<title>Documento de especificaicon de requisitos</title>\n";
    html += "<meta charset=\"UTF-8\">\n";

    html += "<style>\n";
    html += ".content {\n";
    html += "margin-bottom: 20px;\n";
    html += "border: 1px solid #ccc;\n";
    html += "padding: 10px;\n";
    html += "}\n";
    html += "</style>\n";
    html += "</head>\n";
    html += "<body>\n";
    auto vec = index.getIndex();
    std::list<std::string> list;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        unsigned headertype = std::count(it->indice.begin(), it->indice.end(), '.');
        html += "<h" + std::to_string(headertype) + ">" + it->indice + " " + it->titulo + "</h" + std::to_string(headertype) + ">\n";
        //html += "<body> <h1>" + it->indice + it->titulo + "</h1> </body>\n";
        for (auto elemento : it->elementos) {
            std::string str;
            str = "<div id=\"" + elemento.operator std::string()+"\"></div>\n";
            html += str;
            html += "<br>\n";
            list.push_back("'"+elemento.operator std::string()+".html'");
        }
    }
    html += "<script>\n";
    html += "var files = [";
for (auto it = list.begin(); it != list.end(); ++it) {
        html += *it;
        if (std::next(it) != list.end()) {
            html += ",";
        }
    }
    html += "];\n";
    html += "files.forEach(function(file) {\n"
            "        var xhr = new XMLHttpRequest();\n"
            "        xhr.open('GET', file, true);\n"
            "        xhr.onreadystatechange = function() {\n"
            "            if (xhr.readyState === 4 && xhr.status === 200) {\n"
            "                var contentDiv = document.createElement('div');\n"
            "                contentDiv.className = 'content';\n"
            "                contentDiv.innerHTML = xhr.responseText;\n"
            "                var targetDiv = document.getElementById(file.split(\".\")[0]);\n"
            "                if (targetDiv) {\n"
            "                    targetDiv.appendChild(contentDiv);\n"
            "                }\n"
            "            }\n"
            "        };\n"
            "        xhr.send();\n"
            "    });"
            "</script>\n";
    html += "</body>\n";
    html += "</html>\n";
    file << html;
    file.close();
}


void ServicioHTML::printElement(OID it){
    HtmlManager htmlManager;
    std::string html;
    std::ofstream file;
    file.open(it.operator std::string()+".html");
    switch (prefixes[it.getPrefix()]) {
        case STAKEHOLDER:
            file<<htmlManager.generateTableStakeholder(it);
            break;
        case RESTRICTION_REQUIREMENT:
            file<<htmlManager.generateTableRestrictionRequirement(it);
            break;
        case FUNCTIONAL_REQUIREMENT:
            file<<htmlManager.generateTableFunctionalRequirement(it);
            break;
        case NON_FUNCTIONAL_REQUIREMENT:
            file<<htmlManager.generateTableNonFunctionalRequirement(it);
            break;
        case ACTOR_UC:
            file<<htmlManager.generateTableActorUC(it);
            break;
        case INFORMATION_REQUIREMENT:
            file<<htmlManager.generateTableInformationRequirement(it);
            break;
        case ORGANIZATION:
            file<<htmlManager.generateTableOrganization(it);
            break;
        case SYSTEM_OBJECTIVE:
            file<<htmlManager.generateTableSystemObjetive(it);
            break;
        case USER_CASE:
            file<<htmlManager.generateTableUserCase(it);
            break;
        case TEXT:
            file<<htmlManager.generateTableText(it);
            break;
        case MATRIX_TRACES:
            file<<htmlManager.generateMatrixTraces(it);
            break;
        case NULLTYPE:
            file<<"";
        default:
            throw std::invalid_argument("Invalid prefix");
    }
}

unsigned ServicioHTML::createIndex(std::string titulo, unsigned int id) {
    return index.createIndex(titulo,id);
}

void ServicioHTML::deleteIndex(unsigned int id) {
    index.deleteIndex(id);
    printHTML();
}

void ServicioHTML::moveIndex(unsigned int id, unsigned int pos) {
    index.moveIndex(id,pos);
    printHTML();
}

std::string ServicioHTML::printIndex(unsigned int id) {
    return index.printIndex(id);
}

std::vector<ElementosIndex> ServicioHTML::getIndex() {
    return index.getIndex();
}

std::vector<OID> ServicioHTML::getElements(unsigned int id) {
    return index.getElements(id);
}

void ServicioHTML::addElement(unsigned int id, OID oid) {
    index.addElement(id,oid);
    printHTML();
}

void ServicioHTML::deleteElement(unsigned int index, OID id) {
    this->index.deleteElement(index,id);
    printHTML();
}

void ServicioHTML::moveElementInIndex(unsigned int index, OID id, unsigned int pos) {
    this->index.moveElementInIndex(index,id,pos);
    printHTML();
}


