//
// Created by Fran- on 15/07/2023.
//
#include "Index.h"
#include "Trackeable/Trackeable.h"

unsigned int getNumberOfElements(Agen<ElementosIndex>::nodo n) {
    //recorrer index y buscar el id. Una vez encontrado devolver el vector de oid.
    Agen<ElementosIndex> A;
    if (n == Agen<ElementosIndex>::NODO_NULO) {
        return 0;
    } else {
        auto nodo = A.hijoIzqdo(n);
        if (nodo == Agen<ElementosIndex>::NODO_NULO) {
            return 1;
        } else {
            unsigned int i = 1;
            while (nodo != Agen<ElementosIndex>::NODO_NULO) {
                i += getNumberOfElements(nodo);
                nodo = A.hermDrcho(nodo);
            }
            return i;
        }
    }
}



unsigned Index::createIndex(std::string titulo,unsigned id) {
    //recorrer index y buscar el id
    auto nodo = buscarNodo(index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede crear el index, createIndex");
    } else {
        if (index.hijoIzqdo(nodo) == Agen<ElementosIndex>::NODO_NULO) {
            index.insertarHijoIzqdo(nodo,{lastID++,titulo,"",std::vector<OID>()});
            return lastID-1;
        }
        else
        {
            auto nodo2 = index.hijoIzqdo(nodo);
            while (index.hermDrcho(nodo2) != Agen<ElementosIndex>::NODO_NULO) {
                nodo2 = index.hermDrcho(nodo2);
            }
            index.insertarHermDrcho(nodo2,{lastID++,titulo,"",std::vector<OID>()});
            return lastID-1;
        }

    }
}

void Index::deleteIndex(unsigned id) {
    //recorrer index y buscar el id
    //flotar el hijo izquierdo
//borrar el nodo

    auto nodo = buscarNodo(index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede borrar el index, deleteEntry");
    } else {
        index.eliminarHijoIzqdo(nodo);
    }
}

Agen<ElementosIndex>::nodo Index::buscarNodo(Agen<ElementosIndex>::nodo n,unsigned int id) {
    //Recursive search of the node with the id
    if (n == Agen<ElementosIndex>::NODO_NULO) {
        return Agen<ElementosIndex>::NODO_NULO;
    } else if (index.elemento(n).id == id) {
        return n;
    } else {
        auto hijo = index.hijoIzqdo(n);
        while (hijo != Agen<ElementosIndex>::NODO_NULO) {
            auto nodo = buscarNodo(hijo, id);
            if (nodo != Agen<ElementosIndex>::NODO_NULO) {
                return nodo;
            }
            hijo = index.hermDrcho(hijo) ;
        }
        return Agen<ElementosIndex>::NODO_NULO;
    }
}

void Index::moveIndex(unsigned int id, unsigned int pos) {
    //recorrer index y buscar el id, luego mover el id entero a un hijoizquierdo de pos
    auto nodo = buscarNodo(index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede mover el index, moveEntry");
    } else {
        auto nodopos = buscarNodo(index.raiz(),pos);
        if (nodopos == Agen<ElementosIndex>::NODO_NULO) {
            throw std::domain_error("El id no existe, no se puede mover el index, moveEntry");
        } else {
            index.insertarHijoIzqdo(nodopos,index.elemento(nodo));
            index.hijoIzqdo(nodopos)->hizq= nodo;
        }
    }
}

std::string Index::printIndex(unsigned int id) {
    //recorrer index y buscar el id. Una vez encontrado localizar su posicion respecto a sus hermanos y guardarlo en un string.
    //subir un nivel y hacer lo mismo con el padre, hasta llegar a la raiz.
    //una vez llegado a la raiz, imprimir el string.
    //ejemplo de resultado = 2.3.5
    auto nodo = buscarNodo(index.raiz(),id);
    return printRecursive(std::string(),nodo);

}

std::string Index::printRecursive(std::string print, Agen<ElementosIndex>::nodo n) {
    auto padre = index.padre(n);
    if (n == index.raiz())
        return print;

    auto hijo = index.hijoIzqdo(padre);
    unsigned int i = 1;
    while (hijo != n) {
        hijo = index.hermDrcho(hijo);
        i++;
    }
    std::string aux = std::to_string(i) + "." + print;
    return printRecursive(aux,padre);
}

std::vector<ElementosIndex> Index::getIndex()
{
    std::vector<ElementosIndex> v;
    auto nodo = index.raiz();
    unsigned int i = 1;
    unsigned int encontrados = 1;
    unsigned cantidadElementos = getNumberOfElements(nodo);
    while (encontrados <= cantidadElementos)
    {
        if (nodo != Agen<ElementosIndex>::NODO_NULO) {
            auto elemento = index.elemento(nodo);
            elemento.indice = printRecursive(std::string(),nodo);
            v.push_back(elemento);
            encontrados++;
        }
        nodo = buscarNodo(index.raiz(),i);
        i++;
    }
    //ordenamos el vector de cabeceras y con el mismo orden ordenamos el vector de elementos
    for (unsigned int i = 0; i < v.size(); i++) {
        for (unsigned int j = 0; j < v.size(); j++) {
            if (v[i].indice < v[j].indice) {
                std::swap(v[i],v[j]);
            }
        }
    }
    return v;
}

std::vector<OID> Index::getElements(unsigned int id) {
    //recorrer index y buscar el id. Una vez encontrado devolver el vector de oid.
    auto nodo = buscarNodo(index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede obtener el vector de oid, getElements");
    } else {
        return index.elemento(nodo).elementos;
    }
}

void Index::addElement(unsigned id, OID oid) {
    //recorrer index y buscar el id. Una vez encontrado añadir el oid al vector de oid.
    auto nodo = buscarNodo(index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede añadir el oid, addElement");
    } else {
        index.elemento(nodo).elementos.push_back(oid);
    }
}

Agen<ElementosIndex>::nodo Index::buscarNodo(Agen<ElementosIndex>::nodo n, OID id) {
    //Recursive search of the node with the element id
    if (n == Agen<ElementosIndex>::NODO_NULO) {
        return Agen<ElementosIndex>::NODO_NULO;
    }
    std::vector<OID> vec = index.elemento(n).elementos;
    auto vbegin = vec.begin();
    auto vend = vec.end();
    for (auto it = vbegin; it != vend; ++it) {
        if (*it == id) {
            return n;
        }
    }
    auto hijo = index.hijoIzqdo(n);
    while (hijo != Agen<ElementosIndex>::NODO_NULO) {
        auto nodo = buscarNodo(hijo, id);
        if (nodo != Agen<ElementosIndex>::NODO_NULO) {
            return nodo;
        }
        hijo = index.hermDrcho(hijo) ;
    }
    return Agen<ElementosIndex>::NODO_NULO;

}

void Index::deleteElement(unsigned id, OID oid) {
    //recorrer index y buscar el id. Una vez encontrado borrar el oid del vector de oid.
    auto nodo = buscarNodo(this->index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede borrar el oid, deleteElement");
    } else {
        auto vecElementos = index.elemento(nodo).elementos;
        auto vbegin = vecElementos.begin();
        auto vend = vecElementos.end();
        for (auto it = vbegin; it != vend; ++it) {
            if (*it == oid) {
                vecElementos.erase(it);
            }
        }
        nodo->elto.elementos = vecElementos;
    }
}

void Index::moveElementInIndex(unsigned inodo, OID oid, unsigned int pos) {
    //recorrer index y buscar el id. Una vez encontrado mover el oid del vector de oid a la posicion pos.auto nodo = buscarNodo(this->index.raiz(),id);
    auto nodo = buscarNodo(this->index.raiz(),oid);
    auto nodoPos = buscarNodo(this->index.raiz(),inodo);

    if (nodo == Agen<ElementosIndex>::NODO_NULO || nodoPos == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede mover el oid, moveElement");
        if (index.elemento(nodoPos).elementos.size() < pos)
            throw std::domain_error("La posicion no existe, no se puede mover el oid, moveElement");
    } else {
        auto vecElementos = index.elemento(nodo).elementos;
        auto vbegin = vecElementos.begin();
        auto vend = vecElementos.end();
        for (auto it = vbegin; it != vend; ++it) {
            if (*it == id) {
                vecElementos.erase(it);
            }
        }
        auto vecElementosPos = index.elemento(nodoPos).elementos;
        vecElementosPos.insert(vecElementosPos.begin()+pos,oid);
        nodo->elto.elementos = vecElementos;
        nodoPos->elto.elementos = vecElementosPos;
    }

}

Agen<ElementosIndex> Index::getIndexTree() {
    return index;
}

   /*void setTitulo(unsigned id,std::string titulo);
    void setElementos(unsigned id,std::vector<OID> elementos);
    std::string getTitulo(unsigned id);
    unsigned getIndice(unsigned id);
    Agen<ElementosIndex> getIndexTree();*/

void Index::setTitulo(unsigned id, std::string titulo) {
    auto nodo = buscarNodo(this->index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede cambiar el titulo, setTitulo");
    } else {
        nodo->elto.titulo = titulo;
    }
}

void Index::setElementos(unsigned id, std::vector<OID> elementos) {
    auto nodo = buscarNodo(this->index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede cambiar el vector de oid, setElementos");
    } else {
        nodo->elto.elementos = elementos;
    }
}

std::string Index::getTitulo(unsigned id) {
    auto nodo = buscarNodo(this->index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede obtener el titulo, getTitulo");
    } else {
        return nodo->elto.titulo;
    }
}

std::string Index::getIndice(unsigned id) {
    auto nodo = buscarNodo(this->index.raiz(),id);
    if (nodo == Agen<ElementosIndex>::NODO_NULO) {
        throw std::domain_error("El id no existe, no se puede obtener el indice, getIndice");
    } else {
        return nodo->elto.indice;
    }
}

unsigned Index::getLastID() {
    return lastID;
}

void Index::setLastID(unsigned int last) {
    lastID = last;
}

#include "Index.h"
