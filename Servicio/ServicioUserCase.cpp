//
// Created by Fran- on 30/06/2023.
//

#include "ServicioUserCase.h"
#include "Dominio/UserCase.h"

OID ServicioUserCase::createUserCase(std::string nombre) {
    UserCase userCase(fileJsonManager.lastUserCase()+1);
    if (nombre == "") nombre = userCase.getId().operator std::string();
    userCase.setName(nombre);
    fileJsonManager.save(userCase);
    return userCase.getId();
}

void ServicioUserCase::setAbstract(OID id, bool _abstract) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setAbstract");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setAbstract");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.setAbstract(_abstract);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::setPrecondition(OID id, std::string _precondition) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setPrecondition");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setPrecondition");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.setPrecondition(_precondition);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::setPostcondition(OID id, std::string _postcondition) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setPostcondition");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setPostcondition");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.setPostcondition(_postcondition);
    fileJsonManager.save(userCase);

}

void ServicioUserCase::setObjectives(OID id, std::list<OID> _objectives) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setObjectives");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setObjectives");
UserCase userCase = fileJsonManager.loadUserCase(id);
    std::list<OID> objectives;
    for (OID objective : _objectives) {
        if (objective.getPrefix() != SystemObjective::getPrefixID()) throw std::invalid_argument("El id de un objetivo no corresponde a un Objetivo, setObjectives");
        if (!fileJsonManager.exist(objective)) throw std::invalid_argument("El id de un objetivo no existe, setObjectives");
        objectives.push_back(objective);
    }
    userCase.setObjectives(objectives);
    fileJsonManager.save(userCase);

}

void ServicioUserCase::addObjective(OID id, OID objective) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, addObjective");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addObjective");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.addObjective(objective);
    fileJsonManager.save(userCase);

}

void ServicioUserCase::removeObjective(OID id, OID objective) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, removeObjective");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, removeObjective");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.removeObjective(objective);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::setFrequency(OID id, TimeQuantity _frequency) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setFrequency");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setFrequency");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.setFrequency(_frequency);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::setSteps(OID id, std::vector<Step> _steps) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setSteps");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setSteps");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.setSteps(_steps);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::setActors(OID id, std::list<OID> _actors) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setActors");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setActors");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    std::list<OID> actors;
    for (OID actor : _actors) {
        if (actor.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id de un actor no corresponde a un Actor, setActors");
        if (!fileJsonManager.exist(actor)) throw std::invalid_argument("El id de un actor no existe, setActors");
        actors.push_back(actor);
    }
    userCase.setActors(actors);

}

void ServicioUserCase::setPackage(OID id, std::string _package) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setPackage");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setPackage");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.setPackage(_package);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::setGeneralization(OID id, OID _generalization) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCrCase, setGeneralization");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setGeneralization");
    if (_generalization.getPrefix() != UserCase::getPrefixID()) throw std::invalid_argument("El id de la generalizacion no corresponde a un UserCase, setGeneralization");
    if (!fileJsonManager.exist(_generalization)) throw std::invalid_argument("El id de la generalizacion no existe, setGeneralization");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.setGeneralization(_generalization);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::addStep(OID id, Step step) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, addStep");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addStep");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.addStep(step);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::addStep(OID id, Step step, int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, addStep");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addStep");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no es valida, addStep");
    userCase.addStep(step, pos);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::addActor(OID id, OID actor) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, addActor");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addActor");
    if (actor.getPrefix() != UserCase::getPrefixID()) throw std::invalid_argument("El id a agregar no corresponde a un Actor, addActor");
    if (!fileJsonManager.exist(actor)) throw std::invalid_argument("El id a agregar no existe, addActor");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    userCase.addActor(actor);
    fileJsonManager.save(userCase);
}

bool ServicioUserCase::getAbstract(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getAbstract");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getAbstract");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    return userCase.getAbstract();
}

std::string ServicioUserCase::getPrecondition(OID id) {
       if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getPrecondition");
        if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getPrecondition");
        UserCase userCase = fileJsonManager.loadUserCase(id);
        return userCase.getPrecondition();
}

std::string ServicioUserCase::getPostcondition(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getPostcondition");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getPostcondition");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    return userCase.getPostcondition();

}

std::list<OID> ServicioUserCase::getObjectives(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getObjectives");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getObjectives");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    auto objetivos = userCase.getActors();
    std::list<OID> objetivosOID;
    //test if actors exist
    for (auto obj : objetivos) {
        if (fileJsonManager.exist(obj)) objetivosOID.push_back(obj);
    }
    return objetivosOID;
}

TimeQuantity ServicioUserCase::getFrequency(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getFrequency");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getFrequency");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    return userCase.getFrequency();
}

std::vector<Step> ServicioUserCase::getSteps(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getSteps");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getSteps");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    return userCase.getSteps();

}

std::list<OID> ServicioUserCase::getActors(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getActors");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getActors");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    auto actors = userCase.getActors();
    std::list<OID> actorsOID;
    //test if actors exist
    for (auto actor : actors) {
        if (fileJsonManager.exist(actor)) actorsOID.push_back(actor);
    }
    return actorsOID;
}

std::string ServicioUserCase::getPackage(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getPackage");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getPackage");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    auto package = userCase.getPackage();
    return package;
}


OID ServicioUserCase::getGeneralization(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID())
        throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getAbstract");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getAbstract");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    std::cout<<"\n"<<userCase.getGeneralization().getPrefix()<<std::endl;
    auto generalization = userCase.getGeneralization();

    if (id != OID() and fileJsonManager.exist(generalization))
    return generalization;
    else {
        userCase.setGeneralization(OID());
        fileJsonManager.save(userCase);
        return OID();
    }
}

void ServicioUserCase::removeStep(OID id, int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, removeStep");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, removeStep");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, removeStep");
    userCase.removeStep(pos);
    fileJsonManager.save(userCase);
}

bool ServicioUserCase::getAbstract(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getAbstract");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getAbstract");
    UserCase userCase = fileJsonManager.loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getAbstract");
    return userCase.getSteps()[pos].getAbstract();
}

std::string ServicioUserCase::getDescription(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getDescription");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getDescription");
    UserCase userCase = fileJsonManager.loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getDescription");
    return userCase.getSteps()[pos].getDescription();

}

std::string ServicioUserCase::getCondition(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getCondition");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getCondition");
    UserCase userCase = fileJsonManager.loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size())throw std::invalid_argument("La posicion no corresponde a un Step, getCondition");
    return userCase.getSteps()[pos].getCondition();
}

std::string ServicioUserCase::getComments(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getComments");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getComments");
    UserCase userCase = fileJsonManager.loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getComments");
    return userCase.getSteps()[pos].getComments();

}

type ServicioUserCase::getType(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getType");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getType");
    //pos must be betwenn 0 and steps.size() + 1
    UserCase userCase = fileJsonManager.loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");
    return userCase.getSteps()[pos].getType();

}

OID ServicioUserCase::getReference(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getReference");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getReference");

    UserCase userCase = fileJsonManager.loadUserCase(id);
    auto reference = userCase.getSteps()[pos].getReference();

    if (!fileJsonManager.exist(reference)) return OID();
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    return reference;
}

void ServicioUserCase::setAbstract(OID id, unsigned int pos, bool _abstract) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setAbstract");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setAbstract");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setAbstract(_abstract);
    userCase.setSteps(pasos);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::setCondition(OID id, unsigned int pos, std::string _condition) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setCondition");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setCondition");
    UserCase userCase = fileJsonManager.loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setCondition(_condition);
    userCase.setSteps(pasos);
    fileJsonManager.save(userCase);
}

void ServicioUserCase::setComments(OID id, unsigned int pos, std::string _comments) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setComments");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setComments");
        UserCase userCase = fileJsonManager.loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setComments(_comments);
    userCase.setSteps(pasos);
        fileJsonManager.save(userCase);
}

void ServicioUserCase::setDescription(OID id, unsigned int pos, std::string _description) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setDescription");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setDescription");
        UserCase userCase = fileJsonManager.loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setDescription(_description);
    userCase.setSteps(pasos);
        fileJsonManager.save(userCase);
}

void ServicioUserCase::setType(OID id, unsigned int pos, type _type) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setType");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setType");

        UserCase userCase = fileJsonManager.loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setType(_type);
    userCase.setSteps(pasos);

        fileJsonManager.save(userCase);

}

void ServicioUserCase::setReference(OID id, unsigned int pos, OID _reference) {
    if (_reference.getPrefix() != UserCase::getPrefixID()) throw std::invalid_argument("El id referencia debe ser un UserCase, setReference");
    if (!fileJsonManager.exist(_reference)) throw std::invalid_argument("El id referencia no existe, setReference");
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setReference");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setReference");

    UserCase userCase = fileJsonManager.loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setReference(_reference);
    userCase.setSteps(pasos);
    fileJsonManager.save(userCase);

}

std::list<std::pair<OID, std::string>> ServicioUserCase::getUseCases() {
    auto lista = fileJsonManager.loadAllUserCase();
    std::list<std::pair<OID,std::string>> listaOID;
    for (auto &userCase : lista) {
        listaOID.push_back(std::make_pair(userCase.getId(),userCase.getName()));
    }
    return listaOID;

}

std::list<Exception> ServicioUserCase::getExceptions(OID oid) {
    if (oid.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getExceptions");
    if (!fileJsonManager.exist(oid)) throw std::invalid_argument("El id a modificar no existe, getExceptions");
    UserCase userCase = fileJsonManager.loadUserCase(oid);
    return userCase.getExceptions();
}




