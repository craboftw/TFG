//
// Created by Fran- on 21/07/2023.
//

#include "ServicioInterview.h"

/* Organization organization(fileJsonManager.lastOrganization()+1);
    if (name.empty()) name = organization.getId().operator std::string();
    organization.setName(name);
    fileJsonManager.save(organization);
    return organization.getId();
}

void ServicioOrganization::setContactInfo(OID id, std::string _contactInfo) {
    if (id.getPrefix() != Organization::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Organization, setContactInfo");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a modificar no existe, setContactInfo");
    Organization organization = fileJsonManager.loadOrganization(id);
    organization.setContactInfo(_contactInfo);
    fileJsonManager.save(organization);
}

std::string ServicioOrganization::getContactInfo(OID id) {
    if (id.getPrefix() != Organization::getPrefixID()) throw std::invalid_argument("El id a leer no es de un Organization, getContactInfo");
    if (!fileJsonManager.exist(id)) throw std::invalid_argument("El id a leer no existe, getContactInfo");
    Organization organization = fileJsonManager.loadOrganization(id);
    return organization.getContactInfo();*/

OID ServicioInterview::createInterview(std::string name = "") {
    if (name.empty()) name = std::to_string(JsonRepository::lastInterview()+1);
    Interview interview(JsonRepository::lastInterview()+1);
    interview.setName(name);
    JsonRepository::save(interview);
    return interview.getId();

}

void ServicioInterview::addQuestion(OID interview, std::string question, std::string answer) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, addQuestion");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, addQuestion");
    if (question.empty()) throw std::invalid_argument("La pregunta no puede estar vacia, addQuestion");
    if (answer.empty()) throw std::invalid_argument("La respuesta no puede estar vacia, addQuestion");
    Interview obj = JsonRepository::loadInterview(interview);
    obj.addQuestion(question, answer);
    JsonRepository::save(obj);
}

void ServicioInterview::addQuestion(OID interview, std::string question, std::string answer, unsigned int position) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, addQuestion");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, addQuestion");
    if (question.empty()) throw std::invalid_argument("La pregunta no puede estar vacia, addQuestion");
    if (answer.empty()) throw std::invalid_argument("La respuesta no puede estar vacia, addQuestion");
    Interview obj = JsonRepository::loadInterview(interview);
    if (position > obj.getQuestions().size())
    obj.addQuestion(question, answer, position);
    JsonRepository::save(obj);
}

void ServicioInterview::removeQuestion(OID interview, unsigned int position) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, removeQuestion");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, removeQuestion");
    Interview obj = JsonRepository::loadInterview(interview);
    if (position > obj.getQuestions().size()) throw std::invalid_argument("La posicion no puede ser mayor que el numero de preguntas, removeQuestion");
    obj.removeQuestion(position);
    JsonRepository::save(obj);
}

Question ServicioInterview::getQuestion(OID interview, unsigned int position) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, getQuestion");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, getQuestion");
    Interview obj = JsonRepository::loadInterview(interview);
    if (position > obj.getQuestions().size()) throw std::invalid_argument("La posicion no puede ser mayor que el numero de preguntas, getQuestion");
    return obj.getQuestion(position);
}

void ServicioInterview::addStakeholderAsking(OID interview, OID stakeholder) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, addStakeholderAsking");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, addStakeholderAsking");
    if (stakeholder.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Stakeholder, addStakeholderAsking");
    if (!JsonRepository::exist(stakeholder)) throw std::invalid_argument("El id a modificar no existe, addStakeholderAsking");
    Interview obj = JsonRepository::loadInterview(interview);
    obj.addStakeholderAsking(stakeholder);
    JsonRepository::save(obj);
}

void ServicioInterview::addStakeholderInterviewed(OID interview, OID stakeholder) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, addStakeholderInterviewed");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, addStakeholderInterviewed");
    if (stakeholder.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Stakeholder, addStakeholderInterviewed");
    if (!JsonRepository::exist(stakeholder)) throw std::invalid_argument("El id a modificar no existe, addStakeholderInterviewed");
    Interview obj = JsonRepository::loadInterview(interview);
    obj.addStakeholderInterviewed(stakeholder);
    JsonRepository::save(obj);
}

void ServicioInterview::removeStakeholderAsking(OID interview, OID stakeholder) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, addStakeholderInterviewed");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, addStakeholderInterviewed");
    if (stakeholder.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Stakeholder, addStakeholderInterviewed");
    if (!JsonRepository::exist(stakeholder)) throw std::invalid_argument("El id a modificar no existe, addStakeholderInterviewed");
    Interview obj = JsonRepository::loadInterview(interview);
    obj.removeStakeholderAsking(stakeholder);
    JsonRepository::save(obj);
}

void ServicioInterview::removeStakeholderInterviewed(OID interview, OID stakeholder) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, addStakeholderInterviewed");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, addStakeholderInterviewed");
    if (stakeholder.getPrefix() != Stakeholder::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Stakeholder, addStakeholderInterviewed");
    if (!JsonRepository::exist(stakeholder)) throw std::invalid_argument("El id a modificar no existe, addStakeholderInterviewed");
    Interview obj = JsonRepository::loadInterview(interview);
    obj.removeStakeholderInterviewed(stakeholder);
    JsonRepository::save(obj);
}

std::set<OID> ServicioInterview::getStakeholdersAsking(OID interview) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, getStakeholdersAsking");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, getStakeholdersAsking");
    Interview obj = JsonRepository::loadInterview(interview);
    return obj.getStakeholdersAsking();
}

std::set<OID> ServicioInterview::getStakeholdersInterviewed(OID interview) {
    if (interview.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, getStakeholdersInterviewed");
    if (!JsonRepository::exist(interview)) throw std::invalid_argument("El id a modificar no existe, getStakeholdersInterviewed");
    Interview obj = JsonRepository::loadInterview(interview);
    return obj.getStakeholdersInterviewed();
}

std::vector<Question> ServicioInterview::getQuestions(OID oid) {
    if (oid.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, getQuestions");
    if (!JsonRepository::exist(oid)) throw std::invalid_argument("El id a modificar no existe, getQuestions");
    Interview obj = JsonRepository::loadInterview(oid);
    return obj.getQuestions();
}

std::string ServicioInterview::getPlace(OID oid) {
    if (oid.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, getPlace");
    if (!JsonRepository::exist(oid)) throw std::invalid_argument("El id a modificar no existe, getPlace");
    Interview obj = JsonRepository::loadInterview(oid);
    return obj.getPlace();
}

void ServicioInterview::setPlace(OID oid, std::string place) {
    if (oid.getPrefix() != Interview::getPrefixID()) throw std::invalid_argument("El id a modificar no es de un Interview, setPlace");
    if (!JsonRepository::exist(oid)) throw std::invalid_argument("El id a modificar no existe, setPlace");
    Interview obj = JsonRepository::loadInterview(oid);
    obj.setPlace(place);
    JsonRepository::save(obj);
}
