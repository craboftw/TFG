//
// Created by Fran- on 30/06/2023.
//

#include "ServicioUserCase.h"

OID ServicioUserCase::createUserCase(std::string nombre) {
    UserCase userCase(JsonRepository::lastUserCase()+1);
    if (nombre == "") nombre = userCase.getId().operator std::string();
    userCase.setName(nombre);
    JsonRepository::save(userCase);
    return userCase.getId();
}

void ServicioUserCase::setAbstract(OID id, bool _abstract) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setAbstract");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setAbstract");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.setAbstract(_abstract);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setPrecondition(OID id, std::string _precondition) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setPrecondition");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setPrecondition");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.setPrecondition(_precondition);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setPostcondition(OID id, std::string _postcondition) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setPostcondition");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setPostcondition");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.setPostcondition(_postcondition);
    JsonRepository::save(userCase);

}

void ServicioUserCase::setObjectives(OID id, std::list<OID> _objectives) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setObjectives");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setObjectives");
UserCase userCase = JsonRepository::loadUserCase(id);
    std::list<OID> objectives;
    for (OID objective : _objectives) {
        if (objective.getPrefix() != SystemObjective::getPrefixID()) throw std::invalid_argument("El id de un objetivo no corresponde a un Objetivo, setObjectives");
        if (!JsonRepository::exist(objective)) throw std::invalid_argument("El id de un objetivo no existe, setObjectives");
        objectives.push_back(objective);
    }
    userCase.setObjectives(objectives);
    JsonRepository::save(userCase);

}

void ServicioUserCase::addObjective(OID id, OID objective) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, addObjective");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addObjective");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.addObjective(objective);
    JsonRepository::save(userCase);

}

void ServicioUserCase::removeObjective(OID id, OID objective) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, removeObjective");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeObjective");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.removeObjective(objective);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setFrequency(OID id, TimeQuantity _frequency) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setFrequency");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setFrequency");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.setFrequency(_frequency);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setSteps(OID id, std::vector<Step> _steps) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setSteps");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setSteps");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.setSteps(_steps);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setActors(OID id, std::list<OID> _actors) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setActors");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setActors");
    UserCase userCase = JsonRepository::loadUserCase(id);
    std::list<OID> actors;
    for (OID actor : _actors) {
        if (actor.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id de un actor no corresponde a un Actor, setActors");
        if (!JsonRepository::exist(actor)) throw std::invalid_argument("El id de un actor no existe, setActors");
        actors.push_back(actor);
    }
    userCase.setActors(actors);

}

void ServicioUserCase::setPackage(OID id, std::string _package) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setPackage");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setPackage");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.setPackage(_package);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setGeneralization(OID id, OID _generalization) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCrCase, setGeneralization");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setGeneralization");
    if (_generalization.getPrefix() != UserCase::getPrefixID()) throw std::invalid_argument("El id de la generalizacion no corresponde a un UserCase, setGeneralization");
    if (!JsonRepository::exist(_generalization)) throw std::invalid_argument("El id de la generalizacion no existe, setGeneralization");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.setGeneralization(_generalization);
    JsonRepository::save(userCase);
}

void ServicioUserCase::addStep(OID id, Step step) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, addStep");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addStep");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.addStep(step);
    JsonRepository::save(userCase);
}

void ServicioUserCase::addStep(OID id, Step step, int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, addStep");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addStep");
    UserCase userCase = JsonRepository::loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no es valida, addStep");
    userCase.addStep(step, pos);
    JsonRepository::save(userCase);
}

void ServicioUserCase::addActor(OID id, OID actor) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, addActor");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addActor");
    if (actor.getPrefix() != UserCase::getPrefixID()) throw std::invalid_argument("El id a agregar no corresponde a un Actor, addActor");
    if (!JsonRepository::exist(actor)) throw std::invalid_argument("El id a agregar no existe, addActor");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.addActor(actor);
    JsonRepository::save(userCase);
}

bool ServicioUserCase::getAbstract(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getAbstract");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getAbstract");
    UserCase userCase = JsonRepository::loadUserCase(id);
    return userCase.getAbstract();
}

std::string ServicioUserCase::getPrecondition(OID id) {
       if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getPrecondition");
        if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getPrecondition");
        UserCase userCase = JsonRepository::loadUserCase(id);
        return userCase.getPrecondition();
}

std::string ServicioUserCase::getPostcondition(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getPostcondition");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getPostcondition");
    UserCase userCase = JsonRepository::loadUserCase(id);
    return userCase.getPostcondition();

}

std::list<OID> ServicioUserCase::getObjectives(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getObjectives");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getObjectives");
    UserCase userCase = JsonRepository::loadUserCase(id);
    auto objetivos = userCase.getActors();
    std::list<OID> objetivosOID;
    //test if actors exist
    for (auto obj : objetivos) {
        if (JsonRepository::exist(obj)) objetivosOID.push_back(obj);
    }
    return objetivosOID;
}

TimeQuantity ServicioUserCase::getFrequency(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getFrequency");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getFrequency");
    UserCase userCase = JsonRepository::loadUserCase(id);
    return userCase.getFrequency();
}

std::vector<Step> ServicioUserCase::getSteps(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a leer no corresponde a un UserCase, getSteps");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getSteps");
    UserCase userCase = JsonRepository::loadUserCase(id);
    return userCase.getSteps();

}

std::list<OID> ServicioUserCase::getActors(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getActors");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getActors");
    UserCase userCase = JsonRepository::loadUserCase(id);
    auto actors = userCase.getActors();
    std::list<OID> actorsOID;
    //test if actors exist
    for (auto actor : actors) {
        if (JsonRepository::exist(actor)) actorsOID.push_back(actor);
    }
    return actorsOID;
}

std::string ServicioUserCase::getPackage(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getPackage");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getPackage");
    UserCase userCase = JsonRepository::loadUserCase(id);
    auto package = userCase.getPackage();
    return package;
}


OID ServicioUserCase::getGeneralization(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID())
        throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getAbstract");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getAbstract");
    UserCase userCase = JsonRepository::loadUserCase(id);
    auto generalization = userCase.getGeneralization();
    if (generalization == OID())
        return generalization;
    if (JsonRepository::exist(generalization))
        return generalization;
    else {
        userCase.setGeneralization(OID());
        JsonRepository::save(userCase);
        return OID();
    }
}

void ServicioUserCase::removeStep(OID id, int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, removeStep");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeStep");
    UserCase userCase = JsonRepository::loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, removeStep");
    userCase.removeStep(pos);
    JsonRepository::save(userCase);
}

bool ServicioUserCase::getAbstractStep(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getAbstract");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getAbstract");
    UserCase userCase = JsonRepository::loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getAbstract");
    return userCase.getSteps()[pos].getAbstract();
}

std::string ServicioUserCase::getDescriptionStep(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getDescription");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getDescription");
    UserCase userCase = JsonRepository::loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getDescription");
    return userCase.getSteps()[pos].getDescription();

}

std::string ServicioUserCase::getConditionStep(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getCondition");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getCondition");
    UserCase userCase = JsonRepository::loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size())throw std::invalid_argument("La posicion no corresponde a un Step, getCondition");
    return userCase.getSteps()[pos].getCondition();
}

std::string ServicioUserCase::getCommentsStep(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getComments");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getComments");
    UserCase userCase = JsonRepository::loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getComments");
    return userCase.getSteps()[pos].getComments();

}

type ServicioUserCase::getTypeStep(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getType");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getType");
    //pos must be betwenn 0 and steps.size() + 1
    UserCase userCase = JsonRepository::loadUserCase(id);
        if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");
    return userCase.getSteps()[pos].getType();

}

OID ServicioUserCase::getReferenceStep(OID id, unsigned int pos) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getReference");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a leer no existe, getReference");

    UserCase userCase = JsonRepository::loadUserCase(id);
    auto reference = userCase.getSteps()[pos].getReference();

    if (!JsonRepository::exist(reference)) return OID();
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    return reference;
}

void ServicioUserCase::setAbstractStep(OID id, unsigned int pos, bool _abstract) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setAbstract");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setAbstract");
    UserCase userCase = JsonRepository::loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setAbstract(_abstract);
    userCase.setSteps(pasos);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setConditionStep(OID id, unsigned int pos, std::string _condition) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setCondition");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setCondition");
    UserCase userCase = JsonRepository::loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setCondition(_condition);
    userCase.setSteps(pasos);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setCommentsStep(OID id, unsigned int pos, std::string _comments) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setComments");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setComments");
        UserCase userCase = JsonRepository::loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setComments(_comments);
    userCase.setSteps(pasos);
        JsonRepository::save(userCase);
}

void ServicioUserCase::setDescriptionStep(OID id, unsigned int pos, std::string _description) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setDescription");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setDescription");
        UserCase userCase = JsonRepository::loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setDescription(_description);
    userCase.setSteps(pasos);
        JsonRepository::save(userCase);
}

void ServicioUserCase::setTypeStep(OID id, unsigned int pos, type _type) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setType");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setType");

        UserCase userCase = JsonRepository::loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setType(_type);
    userCase.setSteps(pasos);

        JsonRepository::save(userCase);

}

void ServicioUserCase::setReferenceStep(OID id, unsigned int pos, OID _reference) {
    if (_reference.getPrefix() !=  UserCase::getPrefixID() and _reference.getPrefix() != ActorUC::getPrefixID()) throw std::invalid_argument("El id referencia no corresponde a un UserCase o un Actor, setReference" );
    if (!JsonRepository::exist(_reference)) throw std::invalid_argument("El id referencia no existe, setReference");
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setReference");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setReference");

    UserCase userCase = JsonRepository::loadUserCase(id);
    if (pos < 0 || pos > userCase.getSteps().size()) throw std::invalid_argument("La posicion no corresponde a un Step, getType");

    auto pasos = userCase.getSteps();
    pasos[pos].setReference(_reference);
    userCase.setSteps(pasos);
    JsonRepository::save(userCase);

}

std::list<std::pair<OID, std::string>> ServicioUserCase::getUseCases() {
    auto lista = JsonRepository::loadAllUserCase();
    std::list<std::pair<OID,std::string>> listaOID;
    for (auto &userCase : lista) {
        listaOID.push_back(std::make_pair(userCase.getId(),userCase.getName()));
    }
    return listaOID;

}

std::vector<Exception> ServicioUserCase::getExceptions(OID oid) {
    if (oid.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getExceptions");
    if (!JsonRepository::exist(oid)) throw std::invalid_argument("El id a modificar no existe, getExceptions");
    UserCase userCase = JsonRepository::loadUserCase(oid);
    return userCase.getExceptions();
}

void ServicioUserCase::removeActor(OID id, OID actor) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, removeActor");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeActor");
    if (actor.getPrefix() !=  ActorUC::getPrefixID()) throw std::invalid_argument("El id actor debe ser un Actor, removeActor");
    if (!JsonRepository::exist(actor)) throw std::invalid_argument("El id actor no existe, removeActor");

    UserCase userCase = JsonRepository::loadUserCase(id);
    auto actores = userCase.getActors();
    actores.remove(actor);
    userCase.setActors(actores);
    JsonRepository::save(userCase);
}




void ServicioUserCase::addException(OID id, Exception exception) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, addException");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addException");
    UserCase userCase = JsonRepository::loadUserCase(id);
    auto exceptions = userCase.getExceptions();
    exceptions.push_back(exception);
    userCase.setExceptions(exceptions);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setException(OID id, unsigned int pos, Exception exception) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setException");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setException");
    UserCase userCase = JsonRepository::loadUserCase(id);
    auto exceptions = userCase.getExceptions();
    if (pos < 0 || pos > exceptions.size()) throw std::invalid_argument("La posicion no corresponde a una excepcion, setException");
    exceptions[pos] = exception;
    userCase.setExceptions(exceptions);
    JsonRepository::save(userCase);
}

void ServicioUserCase::setExceptions(OID id, std::vector<Exception> exceptions) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setExceptions");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setExceptions");
    UserCase userCase = JsonRepository::loadUserCase(id);
    userCase.setExceptions(exceptions);
    JsonRepository::save(userCase);

}

std::string ServicioUserCase::strFrequency(OID id) {
    if (id.getPrefix() !=  UserCase::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strFrequency");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, strFrequency");
    UserCase userCase = JsonRepository::loadUserCase(id);
    std::string str;
    auto frequency =  userCase.getFrequency();
    switch (frequency.getUnit()) {
        case TimeQuantity::MILLISECOND:
            if (frequency.getQuantity() > 1)
                str = "Cada " + std::to_string(frequency.getQuantity()) + " milisegundos";
            else
                str = "Cada milisegundo";
            break;
        case TimeQuantity::SECOND:
            if (frequency.getQuantity() > 1)
                str = "Cada " + std::to_string(frequency.getQuantity()) + " segundos";
            else
                str = "Cada segundo";
            break;
        case TimeQuantity::MINUTE:
            if (frequency.getQuantity() > 1)
                str = "Cada " + std::to_string(frequency.getQuantity()) + " minutos";
            else
                str = "Cada minuto";
            break;
        case TimeQuantity::HOUR:
            if (frequency.getQuantity() > 1)
                str = "Cada " + std::to_string(frequency.getQuantity()) + " horas";
            else
                str = "Cada hora";
            break;
        case TimeQuantity::DAY:
            if (frequency.getQuantity() > 1)
                str = "Cada " + std::to_string(frequency.getQuantity()) + " dias";
            else
                str = "Cada dia";
            break;
        case TimeQuantity::WEEK:
            if (frequency.getQuantity() > 1)
                str = "Cada " + std::to_string(frequency.getQuantity()) + " semanas";
            else
                str = "Cada semana";
            break;
        case TimeQuantity::MONTH:
            if (frequency.getQuantity() > 1)
                str = "Cada " + std::to_string(frequency.getQuantity()) + " meses";
            else
                str = "Cada mes";
            break;
        case TimeQuantity::YEAR:
            if (frequency.getQuantity() > 1)
                str = "Cada " + std::to_string(frequency.getQuantity()) + " años";
            else
                str = "Cada año";
            break;
    }
    return str;
}




