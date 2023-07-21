//
// Created by Fran- on 21/07/2023.
//

#include "Interview.h"

void Interview::addQuestion(std::string question, std::string answer) {
    questions.push_back({question, answer});
}

void Interview::addQuestion(std::string question, std::string answer, unsigned int position) {
    questions.insert(questions.begin()+position, {question, answer});
}

void Interview::removeQuestion(unsigned int position) {
    questions.erase(questions.begin()+position);
}

Question Interview::getQuestion(unsigned int position) {
    return questions[position];
}

std::string Interview::getPrefixID() {
    return prefix;
}

void Interview::addStakeholderAsking(OID stakeholder) {
    stakeholdersAsking.insert(stakeholder);
}

void Interview::addStakeholderInterviewed(OID stakeholder) {
    stakeholdersInterviewed.insert(stakeholder);
}

void Interview::removeStakeholderAsking(OID stakeholder) {
    stakeholdersAsking.erase(stakeholder);
}

void Interview::removeStakeholderInterviewed(OID stakeholder) {
    stakeholdersInterviewed.erase(stakeholder);
}

std::set<OID> Interview::getStakeholdersAsking() {
    return stakeholdersAsking;
}

std::set<OID> Interview::getStakeholdersInterviewed() {
    return stakeholdersInterviewed;
}

void Interview::setQuestions(std::vector<Question> questions) {
    this->questions = questions;
}

void Interview::setStakeholdersAsking(std::set<OID> stakeholders) {
    this->stakeholdersAsking = stakeholders;
}

void Interview::setStakeholdersInterviewed(std::set<OID> stakeholders) {
    this->stakeholdersInterviewed = stakeholders;
}

void Interview::setPlace(std::string place) {
    this->place = place;
}

std::string Interview::getPlace() {
    return place;
}

std::vector<Question> Interview::getQuestions() {
    return questions;
}

