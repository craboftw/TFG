//
// Created by Fran- on 02/07/2023.
//

#include "ServicioInformationRequirement.h"

OID ServicioInformationRequirement::createInformationRequirement(std::string nombre)
{
    InformationRequirement obj(fileJsonManager.lastInformationRequirement());
    if (nombre == "") nombre = obj.getId().operator std::string();
    obj.setName(nombre);
    fileJsonManager.save(obj);
    return obj.getId();
}

void ServicioInformationRequirement::setMaxSimultaneousOccurrence(OID id, unsigned int maxSimultaneousOccurrence) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setMaxSimultaneousOccurrence(maxSimultaneousOccurrence);
    fileJsonManager.save(obj);
}

void ServicioInformationRequirement::setAvgSimultaneousOccurrence(OID id, unsigned int avgSimultaneousOccurrence) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setAvgSimultaneousOccurrence(avgSimultaneousOccurrence);
    fileJsonManager.save(obj);
}

void ServicioInformationRequirement::setLifeMaxEstimate(OID id, const TimeQuantity &lifeMaxEstimate) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setLifeMaxEstimate(lifeMaxEstimate);
    fileJsonManager.save(obj);
}

void ServicioInformationRequirement::setLifeAvgEstimate(OID id, const TimeQuantity &lifeAvgEstimate) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setLifeAvgEstimate(lifeAvgEstimate);
    fileJsonManager.save(obj);
}

unsigned int ServicioInformationRequirement::getMaxSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.getMaxSimultaneousOccurrence();
}

unsigned int ServicioInformationRequirement::getAvgSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.getAvgSimultaneousOccurrence();
}

TimeQuantity ServicioInformationRequirement::getLifeMaxEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.getLifeMaxEstimate();
}

TimeQuantity ServicioInformationRequirement::getLifeAvgEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.getLifeAvgEstimate();
}

std::string ServicioInformationRequirement::strMaxSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.strMaxSimultaneousOccurrence();
}

std::string ServicioInformationRequirement::strAvgSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.strAvgSimultaneousOccurrence();

}

std::string ServicioInformationRequirement::strLifeMaxEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.strLifeMaxEstimate();

}

std::string ServicioInformationRequirement::strLifeAvgEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strPhase");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strPhase");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.strLifeAvgEstimate();

}


