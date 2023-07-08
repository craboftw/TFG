//
// Created by Fran- on 08/07/2023.
//

#include <stack>
#include "ServicioHTML.h"

void ServicioHTML::addElement(OID id, OID elemento) {
    auto it = &mainPage;
    std::stack<IndexHTMLelement*> pila;
    pila.push(it);
    while(!pila.empty()){
        IndexHTMLelement* aux = pila.top();
        pila.pop();
        if(aux->getId() == id){
            aux->addElementToPrint(elemento);
            return;
        }
        for(auto it: aux->getSublevels()){
            pila.push(&it);
        }
    }
}

void ServicioHTML::eraseElement(OID id, OID elemento) {
    auto it = &mainPage;
    std::stack<IndexHTMLelement*> pila;
    pila.push(it);
    while(!pila.empty()){
        IndexHTMLelement* aux = pila.top();
        pila.pop();
        if(aux->getId() == id){
            aux->removeElementToPrint(elemento);
            return;
        }
        for(auto it: aux->getSublevels()){
            pila.push(&it);
        }
    }
}

OID ServicioHTML::createIndex(OID posicion, std::string name) {
    auto it = &mainPage;
    std::stack<IndexHTMLelement*> pila;
    pila.push(it);
    while(!pila.empty()){
        //buscar el padre del elemento a buscar, contar la posicion dentro de los sublevels
        IndexHTMLelement* aux = pila.top();
        pila.pop();
        unsigned pos = 0;
        for(auto it: aux->getSublevels()){
            if(it.getId() == posicion){
                indexCounter++;
                IndexHTMLelement nuevo(indexCounter);
                nuevo.setName(name);
                nuevo.setPos(pos)   ;
                aux->addsubLevel(nuevo);
                return nuevo.getId();
            }
            pila.push(&it);
            pos++;
        }
        for(auto it: aux->getSublevels()){
            pila.push(&it);
        }
    }
    return OID(IndexHTMLelement::getPrefixID(),-1) ;
}

void ServicioHTML::deleteIndex(OID id) {
    auto it = &mainPage;
    std::stack<IndexHTMLelement*> pila;
    pila.push(it);
    while(!pila.empty()){
        IndexHTMLelement* aux = pila.top();
        pila.pop();
        //recorrer todos los sublevels y eliminar el que tenga el id
        for(auto it: aux->getSublevels()){
            if(it.getId() == id){
                aux->removeSubLevel(it.getPos());
                return;
            }
            pila.push(&it);
        }
        for(auto it: aux->getSublevels()){
            pila.push(&it);
        }
    }

}

void ServicioHTML::setIndexName(OID id, IndexHTMLelement sublevel) {
    auto it = &mainPage;
    std::stack<IndexHTMLelement*> pila;
    pila.push(it);
    while(!pila.empty()){
        IndexHTMLelement* aux = pila.top();
        pila.pop();
        if(aux->getId() == id){
            aux->setName(sublevel.getName());
            return;
        }
    }
}

void ServicioHTML::printHTML() {
    HtmlManager htmlManager;
    for (auto it: mainPage.getElementsToPrint()){

            //build a file with the name of the OID.operator std::string()
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

            default:
                throw std::invalid_argument("Invalid prefix");
        }
    }
}

void printElement(OID)
{

}




