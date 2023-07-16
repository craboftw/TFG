//
// Created by Fran- on 08/07/2023.
//

#include <stack>
#include <thread>
#include "ServicioHTML.h"



void ServicioHTML::printHTML(OID id) {
    std::string html;
    HtmlManager htmlManager;
    ServicioTrackeable servicioTrackeable;
    std::ofstream file;
    file.open("index.html");
    std::string authors;
    auto authorsid = servicioTrackeable.getAuthors(id);
    for (auto it : authorsid) {
        authors += servicioTrackeable.getName(it) + ", ";
    }
    authors = authors.substr(0, authors.size() - 2) + ".";
    html += "<!DOCTYPE html>\n"
            "<html>\n"
            "<head>\n"
            "<title>"+servicioTrackeable.getName(id)+"</title>\n"
            "<meta charset=\"UTF-8\">\n"
            "<style>\n"
            ".header {\n"
            "  background-color: #f2f2f2;\n"
            "  padding: 20px;\n"
            "}\n"
            "\n"
            ".title {\n"
            "  font-size: 24px;\n"
            "  font-weight: bold;\n"
            "  margin-bottom: 10px;\n"
            "}\n"
            "\n"
            ".authors {\n"
            "  font-size: 18px;\n"
            "  font-style: italic;\n"
            "  margin-bottom: 10px;\n"
            "}\n"
            "\n"
            ".date {\n"
            "  font-size: 18px;\n"
            "  margin-bottom: 10px;\n"
            "}\n"
            "\n"
            ".description {\n"
            "  font-size: 18px;\n"
            "}\n"
            "\n"
            ".content {\n"
            "  margin-bottom: 20px;\n"
            "  border: 1px solid #ccc;\n"
            "  padding: 10px;\n"
            "}\n"
            "\n"
            "ul {\n"
            "  font-family: Arial, sans-serif;\n"
            "}\n"
            "</style>\n"
            "</head>\n"
            "<body>\n"
            "<div class=\"header\">\n"
            "  <div class=\"title\">"+servicioTrackeable.getName(id)+"</div>\n"
            "  <div class=\"authors\">"+authors+"</div>\n"
            "</div>\n"
            "  <div class=\"date\">"+servicioTrackeable.getDate(id).toString()+"</div>\n"
            "  <div class=\"description\">"+servicioTrackeable.getDescription(id)+".</div>\n"
            "</div>";
    auto vec = getIndex(id);
for (auto it = vec.begin(); it != vec.end(); ++it) {
        html += "<li><a href=\"#" + it->indice + "\">" + it->indice + " " + it->titulo + "</a></li>\n";
    }
    
    std::list<std::string> list;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        unsigned headertype = std::count(it->indice.begin(), it->indice.end(), '.');
        html += "<h" + std::to_string(headertype) + " id=\"" + it->indice + "\">" + it->indice + " " + it->titulo + "</h" + std::to_string(headertype) + ">\n";
        for (auto id : it->elementos) {
            std::string str;
            str = "<div id=\"" + id.operator std::string()+"\"></div>\n";
            html += str;
            html += "<br>\n";
            list.push_back("'"+id.operator std::string()+".html'");
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
            "    });\n"
            "</script>\n"
            "</body>\n"
            "</html>\n" ;
    file << html;
    file.close();
}


void ServicioHTML::printElement(OID it){
    std::map<std::string, unsigned> prefijos = {{Stakeholder::getPrefixID(),STAKEHOLDER},
                                                {RestrictionRequirement::getPrefixID(),RESTRICTION_REQUIREMENT},
                                                {FunctionalRequirement::getPrefixID(),FUNCTIONAL_REQUIREMENT},
                                                {NonFunctionalRequirement::getPrefixID(),NON_FUNCTIONAL_REQUIREMENT},
                                                {ActorUC::getPrefixID(),ACTOR_UC},
                                                {InformationRequirement::getPrefixID(),INFORMATION_REQUIREMENT},
                                                {Organization::getPrefixID(),ORGANIZATION},
                                                {SystemObjective::getPrefixID(),SYSTEM_OBJECTIVE},
                                                {UserCase::getPrefixID(),USER_CASE},
                                                {Text::getPrefixID(),TEXT},
                                                {MatrixTraces::getPrefixID(),MATRIX_TRACES},
                                                {UserCaseDiagram::getPrefixID(),USER_CASE_DIAGRAM},
                                                {UserStories::getPrefixID(),USER_STORIES},
                                                {OID().getPrefix(),NULL}};
    HtmlManager htmlManager;
    std::string html;
    std::ofstream file;
    file.open(it.operator std::string()+".html");
    switch (prefijos[it.getPrefix()]) {
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
        case USER_CASE_DIAGRAM:
            file<<htmlManager.generateUserCaseDiagram(it);
            break;
        case NULLTYPE:
            file<<"";
        default:
            throw std::invalid_argument("Invalid prefix");
    }
}

OID ServicioHTML::createIndex(std::string titulo) {
    Index index(JsonRepository::lastIndex() +1);
    if (titulo.empty()) titulo = index.getId().operator std::string();
    index.setName(titulo);
    JsonRepository::save(index);
    return index.getId();
}


/*    void deleteEntry(OID id,unsigned idnode);
    void moveEntry(OID id, unsigned idnode,unsigned newIdnode);
    std::string printEntry(OID id,unsigned idnode);
    std::vector<ElementosIndex> getIndex(OID id);
    std::vector<OID> getElements(OID id,unsigned idnode);
    void addElement(OID id,unsigned idnode, OID element);
    void deleteElement(OID id,unsigned idnode,OID element);
    void moveElementInIndex(OID id,unsigned idnode,OID element,unsigned newIdnode);*/

void ServicioHTML::deleteEntry(OID id, unsigned idnode) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,deleteEntry");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,deleteEntry");
    Index index = JsonRepository::loadIndex(id);
    index.deleteIndex(idnode);
    JsonRepository::save(index);
} 

void ServicioHTML::moveEntry(OID id, unsigned idnode, unsigned newIdnode) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,moveEntry");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,moveEntry");
    Index index = JsonRepository::loadIndex(id);
    index.moveIndex(idnode,newIdnode);
    JsonRepository::save(index);
}

std::string ServicioHTML::printEntry(OID id, unsigned idnode) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,printEntry");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,printEntry");
    Index index = JsonRepository::loadIndex(id);
    return index.printIndex(idnode);
}

std::vector<ElementosIndex> ServicioHTML::getIndex(OID id) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,getIndex");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,getIndex");
    Index index = JsonRepository::loadIndex(id);
    return index.getIndex();
}

std::vector<OID> ServicioHTML::getElements(OID id, unsigned idnode) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,getElements");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,getElements");
    Index index = JsonRepository::loadIndex(id);
    return index.getElements(idnode);
}

void ServicioHTML::addElement(OID id, unsigned idnode, OID element) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,addElement");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,addElement");
    if (!JsonRepository::exist(element)) throw std::invalid_argument("El elemento no existe,addElement");
    Index index = JsonRepository::loadIndex(id);
    index.addElement(idnode,element);
    JsonRepository::save(index);
}

void ServicioHTML::deleteElement(OID id, unsigned idnode, OID element) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,deleteElement");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,deleteElement");
    if (!JsonRepository::exist(element)) throw std::invalid_argument("El elemento no existe,deleteElement");
    Index index = JsonRepository::loadIndex(id);
    index.deleteElement(idnode,element);
    JsonRepository::save(index);
}

unsigned ServicioHTML::createEntry(OID id, unsigned int idnode) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,createEntry");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,createEntry");
    Index index = JsonRepository::loadIndex(id);
    auto entry = index.createIndex("",idnode);
    JsonRepository::save(index);
    return entry;
}

unsigned     ServicioHTML::createEntry(OID id, unsigned int idnode, std::string title) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,createEntry");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,createEntry");
    Index index = JsonRepository::loadIndex(id);
    auto entry = index.createIndex(title,idnode);
    JsonRepository::save(index);
    return entry;
}

unsigned int ServicioHTML::createEntry(OID id, std::string title, unsigned int idnode) {
    if (id.getPrefix() != Index::getPrefixID()) throw std::invalid_argument("El id no es un indice,createEntry");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id no existe,createEntry");
    Index index = JsonRepository::loadIndex(id);
    auto entry = index.createIndex(title,idnode);
    JsonRepository::save(index);
    return entry;
}





