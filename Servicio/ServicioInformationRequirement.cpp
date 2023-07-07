//
// Created by Fran- on 02/07/2023.
//

#include "ServicioInformationRequirement.h"

OID ServicioInformationRequirement::createInformationRequirement(std::string nombre)
{
    InformationRequirement obj(fileJsonManager.lastInformationRequirement() +1);
    if (nombre == "") nombre = obj.getId().operator std::string();
    obj.setName(nombre);
    fileJsonManager.save(obj);
    return obj.getId();
}

void ServicioInformationRequirement::setMaxSimultaneousOccurrence(OID id, unsigned int maxSimultaneousOccurrence) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setMaxSimultaneousOccurrence");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setMaxSimultaneousOccurrence");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setMaxSimultaneousOccurrence(maxSimultaneousOccurrence);
    fileJsonManager.save(obj);
}

void ServicioInformationRequirement::setAvgSimultaneousOccurrence(OID id, unsigned int avgSimultaneousOccurrence) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setAvgSimultaneousOccurrence");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setAvgSimultaneousOccurrence");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setAvgSimultaneousOccurrence(avgSimultaneousOccurrence);
    fileJsonManager.save(obj);
}

void ServicioInformationRequirement::setLifeMaxEstimate(OID id, const TimeQuantity &lifeMaxEstimate) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setLifeMaxEstimate");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setLifeMaxEstimate");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setLifeMaxEstimate(lifeMaxEstimate);
    fileJsonManager.save(obj);
}

void ServicioInformationRequirement::setLifeAvgEstimate(OID id, const TimeQuantity &lifeAvgEstimate) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setLifeAvgEstimate");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setLifeAvgEstimate");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setLifeAvgEstimate(lifeAvgEstimate);
    fileJsonManager.save(obj);
}

unsigned int ServicioInformationRequirement::getMaxSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getMaxSimultaneousOccurrence");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getMaxSimultaneousOccurrence");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.getMaxSimultaneousOccurrence();
}

unsigned int ServicioInformationRequirement::getAvgSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getAvgSimultaneousOccurrence");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getAvgSimultaneousOccurrence");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.getAvgSimultaneousOccurrence();
}

TimeQuantity ServicioInformationRequirement::getLifeMaxEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getLifeMaxEstimate");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getLifeMaxEstimate");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.getLifeMaxEstimate();
}

TimeQuantity ServicioInformationRequirement::getLifeAvgEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getLifeAvgEstimate");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getLifeAvgEstimate");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    return obj.getLifeAvgEstimate();
}

std::string ServicioInformationRequirement::strMaxSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strMaxSimultaneousOccurrence");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strMaxSimultaneousOccurrence");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    auto maxSimultaneousOccurrence = obj.getMaxSimultaneousOccurrence();
    if (maxSimultaneousOccurrence == 0) return "Ninguna";
    if (maxSimultaneousOccurrence == 1 ) return "1 vez.";
    else return std::to_string(maxSimultaneousOccurrence) + " veces.";
}

std::string ServicioInformationRequirement::strAvgSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strAvgSimultaneousOccurrence");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strAvgSimultaneousOccurrence");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    auto maxSimultaneousOccurrence = obj.getMaxSimultaneousOccurrence();
    if (maxSimultaneousOccurrence == 0) return "Ninguna";
    if (maxSimultaneousOccurrence == 1 ) return "1 vez.";
    else return std::to_string(maxSimultaneousOccurrence) + " veces.";
}

std::string strTimequantity(TimeQuantity lifeMaxEstimate) {
    std::string str = "";
    switch (lifeMaxEstimate.getUnit()) {
        case TimeQuantity::MILLISECOND:
            if (lifeMaxEstimate.getQuantity() > 1)
                return std::to_string(lifeMaxEstimate.getQuantity()) + " milisegundos";
            else
                return "1 milisegundo";
            break;
        case TimeQuantity::SECOND:
            if (lifeMaxEstimate.getQuantity() > 1)
                return std::to_string(lifeMaxEstimate.getQuantity()) + " segundos";
            else
                return "1 segundo";
            break;
        case TimeQuantity::MINUTE:
            if (lifeMaxEstimate.getQuantity() > 1)
                return std::to_string(lifeMaxEstimate.getQuantity()) + " minutos";
            else
                return "1 minuto";
            break;
        case TimeQuantity::HOUR:
            if (lifeMaxEstimate.getQuantity() > 1)
                return std::to_string(lifeMaxEstimate.getQuantity()) + " horas";
            else
                return "1 hora";
            break;
        case TimeQuantity::DAY:
            if (lifeMaxEstimate.getQuantity() > 1)
                return std::to_string(lifeMaxEstimate.getQuantity()) + " dias";
            else
                return "1 dia";
            break;
        case TimeQuantity::WEEK:
            if (lifeMaxEstimate.getQuantity() > 1)
                return std::to_string(lifeMaxEstimate.getQuantity()) + " semanas";
            else
                return "1 semana";
            break;
        case TimeQuantity::MONTH:
            if (lifeMaxEstimate.getQuantity() > 1)
                return std::to_string(lifeMaxEstimate.getQuantity()) + " meses";
            else
                return "1 mes";
            break;
        case TimeQuantity::YEAR:
            if (lifeMaxEstimate.getQuantity() > 1)
                return std::to_string(lifeMaxEstimate.getQuantity()) + " años";
            else
                return "1 año";
            break;
        default:
            return "Error";
            break;

    }
}

std::string ServicioInformationRequirement::strLifeMaxEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strLifeMaxEstimate");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strLifeMaxEstimate");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    auto lifeMaxEstimate = obj.getLifeMaxEstimate();
    return strTimequantity(lifeMaxEstimate);
}

std::string ServicioInformationRequirement::strLifeAvgEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strLifeAvgEstimate");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, strLifeAvgEstimate");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    auto lifeAvgEstimate = obj.getLifeAvgEstimate();
    return strTimequantity(lifeAvgEstimate);

}

std::list<std::pair<OID, std::string>> ServicioInformationRequirement::getInformationRequirements() {
    std::list<std::pair<OID, std::string>> list;
    auto lista = fileJsonManager.loadAllInformationRequirement();
    for (auto ir : lista) {
            list.push_back(std::make_pair(ir.getId(), ir.getName()));
        }
    return list;
}

void ServicioInformationRequirement::setSpecificInformation(OID id,
                                                            const std::list<SpecificInformation> &specificInformation) {

if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, setSpecificInformation");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setSpecificInformation");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);

    obj.setSpecificInformation(specificInformation);
    fileJsonManager.save(obj);
}
void ServicioInformationRequirement::addSpecificInformation(OID id, const std::string name, const std::string description) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, addSpecificInformation");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, addSpecificInformation");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);

    obj.addSpecificInformation(name, description);
    fileJsonManager.save(obj);
}

void ServicioInformationRequirement::removeSpecificInformation(OID id, unsigned idSpecificInformation) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, removeSpecificInformation");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, removeSpecificInformation");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.removeSpecificInformation(idSpecificInformation);
    fileJsonManager.save(obj);
}

std::list<SpecificInformation> ServicioInformationRequirement::getSpecificInformation(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, getSpecificInformation");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, getSpecificInformation");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);

    return obj.getSpecificInformation();
}

void ServicioInformationRequirement::setSpecificInformationName(OID id, const unsigned int idSpecificInformation,
                                                                const std::string &name) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, setSpecificInformationName");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setSpecificInformationName");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setSpecificInformationName(idSpecificInformation, name);
    fileJsonManager.save(obj);
}

void ServicioInformationRequirement::setSpecificInformationDescription(OID id, const unsigned int idSpecificInformation,
                                                                       const std::string &description) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, setSpecificInformationDescription");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setSpecificInformationDescription");
    InformationRequirement obj = fileJsonManager.loadInformationRequirement(id);
    obj.setSpecificInformationDescription(idSpecificInformation, description);
    fileJsonManager.save(obj);
}




