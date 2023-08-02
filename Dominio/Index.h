//
// Created by Fran- on 15/07/2023.
//

#ifndef TFG_INDEX_H
#define TFG_INDEX_H

#include <string>
#include <vector>
#include "Visitor/LinkedGeneralTree.cpp"
#include "Dominio/Trackeable/Trackeable.h"


typedef struct {
    unsigned id;
    std::string titulo;
    std::string indice;
    std::vector<OID> elementos;
}ElementosIndex;

class Index : public Trackeable{
public:
    Index(unsigned id):Trackeable(prefix,id){ index.insertarRaiz({lastID++,"INDICE","",std::vector<OID>()});}
    Index(Agen<ElementosIndex> index,unsigned id) :Trackeable(prefix,id), index(index) {}
    Index() = default;
    unsigned createIndex(std::string titulo,unsigned id);
    void deleteIndex(unsigned id);
    void moveIndex(unsigned id,unsigned pos);
    std::string printIndex(unsigned id);
    std::vector<ElementosIndex> getIndex();
    std::vector<OID> getElements(unsigned id);
    void addElement(unsigned id, OID oid);
    void deleteElement(unsigned index,OID id);
    void moveElementInIndex(unsigned index,OID id,unsigned pos);
    void setTitulo(unsigned id,std::string titulo);
    void setElementos(unsigned id,std::vector<OID> elementos);
    std::string getTitulo(unsigned id);
    std::string getIndice(unsigned id);
    unsigned getLastID();
    Agen<ElementosIndex> getIndexTree();

    
    inline static std::string getPrefixID() { return prefix; }

    void setLastID(unsigned last);

private:
    Agen<ElementosIndex> index;
    unsigned lastID = 0;


    inline static std::string prefix = "IX";

    Agen<ElementosIndex>::nodo buscarNodo(Agen<ElementosIndex>::nodo n, unsigned int id);
    std::string printRecursive(std::string print, Agen<ElementosIndex>::nodo n);
    Agen<ElementosIndex>::nodo buscarNodo(Agen<ElementosIndex>::nodo n, OID id);


};



#endif //TFG_INDEX_H
