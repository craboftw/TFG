//
// Created by Fran- on 02/07/2023.
//

#include "ServicioInformationRequirement.h"

OID ServicioInformationRequirement::createInformationRequirement(std::string nombre)
{
    InformationRequirement obj(JsonRepository::lastInformationRequirement() +1);
    if (nombre == "") nombre = obj.getId().operator std::string();
    obj.setName(nombre);
    JsonRepository::save(obj);
    return obj.getId();
}

void ServicioInformationRequirement::setMaxSimultaneousOccurrence(OID id, unsigned int maxSimultaneousOccurrence) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setMaxSimultaneousOccurrence");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setMaxSimultaneousOccurrence");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    obj.setMaxSimultaneousOccurrence(maxSimultaneousOccurrence);
    JsonRepository::save(obj);
}

void ServicioInformationRequirement::setAvgSimultaneousOccurrence(OID id, unsigned int avgSimultaneousOccurrence) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setAvgSimultaneousOccurrence");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setAvgSimultaneousOccurrence");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    obj.setAvgSimultaneousOccurrence(avgSimultaneousOccurrence);
    JsonRepository::save(obj);
}

void ServicioInformationRequirement::setLifeMaxEstimate(OID id, const TimeQuantity &lifeMaxEstimate) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setLifeMaxEstimate");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setLifeMaxEstimate");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    obj.setLifeMaxEstimate(lifeMaxEstimate);
    JsonRepository::save(obj);
}

void ServicioInformationRequirement::setLifeAvgEstimate(OID id, const TimeQuantity &lifeAvgEstimate) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, setLifeAvgEstimate");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setLifeAvgEstimate");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    obj.setLifeAvgEstimate(lifeAvgEstimate);
    JsonRepository::save(obj);
}

unsigned int ServicioInformationRequirement::getMaxSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getMaxSimultaneousOccurrence");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getMaxSimultaneousOccurrence");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    return obj.getMaxSimultaneousOccurrence();
}

unsigned int ServicioInformationRequirement::getAvgSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getAvgSimultaneousOccurrence");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getAvgSimultaneousOccurrence");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    return obj.getAvgSimultaneousOccurrence();
}

TimeQuantity ServicioInformationRequirement::getLifeMaxEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getLifeMaxEstimate");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getLifeMaxEstimate");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    return obj.getLifeMaxEstimate();
}

TimeQuantity ServicioInformationRequirement::getLifeAvgEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, getLifeAvgEstimate");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getLifeAvgEstimate");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    return obj.getLifeAvgEstimate();
}

std::string ServicioInformationRequirement::strMaxSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strMaxSimultaneousOccurrence");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, strMaxSimultaneousOccurrence");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    auto maxSimultaneousOccurrence = obj.getMaxSimultaneousOccurrence();
    if (maxSimultaneousOccurrence == 0) return "Ninguna";
    if (maxSimultaneousOccurrence == 1 ) return "1 vez.";
    else return std::to_string(maxSimultaneousOccurrence) + " veces.";
}

std::string ServicioInformationRequirement::strAvgSimultaneousOccurrence(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strAvgSimultaneousOccurrence");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, strAvgSimultaneousOccurrence");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
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
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, strLifeMaxEstimate");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    auto lifeMaxEstimate = obj.getLifeMaxEstimate();
    return strTimequantity(lifeMaxEstimate);
}

std::string ServicioInformationRequirement::strLifeAvgEstimate(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un UserCase, strLifeAvgEstimate");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, strLifeAvgEstimate");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    auto lifeAvgEstimate = obj.getLifeAvgEstimate();
    return strTimequantity(lifeAvgEstimate);

}

std::list<std::pair<OID, std::string>> ServicioInformationRequirement::getInformationRequirements() {
    std::list<std::pair<OID, std::string>> list;
    auto lista = JsonRepository::loadAllInformationRequirement();
    for (auto ir : lista) {
            list.push_back(std::make_pair(ir.getId(), ir.getName()));
        }
    return list;
}

void ServicioInformationRequirement::setSpecificInformation(OID id,
                                                            const std::list<SpecificInformation> &specificInformation) {

if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, setSpecificInformation");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setSpecificInformation");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);

    obj.setSpecificInformation(specificInformation);
    JsonRepository::save(obj);
}
void ServicioInformationRequirement::addSpecificInformation(OID id, const std::string name, const std::string description) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, addSpecificInformation");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, addSpecificInformation");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);

    obj.addSpecificInformation(name, description);
    JsonRepository::save(obj);
}

void ServicioInformationRequirement::removeSpecificInformation(OID id, unsigned idSpecificInformation) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, removeSpecificInformation");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, removeSpecificInformation");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    obj.removeSpecificInformation(idSpecificInformation);
    JsonRepository::save(obj);
}

std::list<SpecificInformation> ServicioInformationRequirement::getSpecificInformation(OID id) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, getSpecificInformation");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, getSpecificInformation");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);

    return obj.getSpecificInformation();
}

void ServicioInformationRequirement::setSpecificInformationName(OID id, const unsigned int idSpecificInformation,
                                                                const std::string &name) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, setSpecificInformationName");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setSpecificInformationName");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    obj.setSpecificInformationName(idSpecificInformation, name);
    JsonRepository::save(obj);
}

void ServicioInformationRequirement::setSpecificInformationDescription(OID id, const unsigned int idSpecificInformation,
                                                                       const std::string &description) {
    if (id.getPrefix() !=  InformationRequirement::getPrefixID()) throw std::invalid_argument("El id a modificar no corresponde a un InformationRequirement, setSpecificInformationDescription");
    if (!JsonRepository::exist(id)) throw std::invalid_argument("El id a modificar no existe, setSpecificInformationDescription");
    InformationRequirement obj = JsonRepository::loadInformationRequirement(id);
    obj.setSpecificInformationDescription(idSpecificInformation, description);
    JsonRepository::save(obj);
}




