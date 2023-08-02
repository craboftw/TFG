//
// Created by Fran- on 08/07/2023.
//

#include "UserStories.h"

void UserStories::accept(Visitor *visitor) {
    Trackeable::accept(visitor);
}

void UserStories::setRole(std::string role) {
    this->role = role;
}

void UserStories::setGoal(std::string goal) {
    this->goal = goal;
}

void UserStories::setBenefit(std::string benefit) {
    this->benefit = benefit;
}

std::string UserStories::getRole() {
    return role;
}

std::string UserStories::getGoal() {
    return goal;
}

std::string UserStories::getBenefit() {
    return benefit;
}

unsigned UserStories::getPriorityPoints() {
    return priorityPoints;
}

unsigned UserStories::getDevTimePoints() {
    return DevTimePoints;
}

void UserStories::setPriorityPoints(unsigned int priorityPoints) {
    UserStories::priorityPoints = priorityPoints;
}

void UserStories::setDevTimePoints(unsigned int DevTimePoints) {
    UserStories::DevTimePoints = DevTimePoints;
}
