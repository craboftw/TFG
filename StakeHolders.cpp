#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "Fecha.h"

class Stakeholder;

class Organization {
private:
    std::string name;
    std::string contactInfo;
    std::string comments;
    std::string description;
    std::set<Stakeholder*> stakeholders;
public:

    Organization(const std::string& company, const std::string& contactInfo,
                 const std::string& description, const std::string& comments= "")
            : name(company),
              contactInfo(contactInfo),
              comments(comments),
              description(description)
    {}
    void print(){
        std::cout << "Name: " << name << std::endl;
        std::cout << "Contact info: " << contactInfo << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "Comments: " << comments << std::endl;
    }
};


class Rol_Stakeholder {
public:
    std::string name;
    std::string description;
    static Rol_Stakeholder nulo;

    Rol_Stakeholder(const std::string& name, const std::string description = ""):
            name(name), description(description) {}
};

class Stakeholder {
private:

    std::string id;
    std::string name;
    //Informacion de contacto
    std::string email;
    std::string phone;
    std::string address;


    std::string versionMajor;
    std::string versionMinor;
    Fecha date_init;
    std::string comments;
    Rol_Stakeholder* stakeholderRole;
    bool isDeveloper;
    bool isCustomer;
    Organization worksForOrganization;
    static Stakeholder nulo;
public:

    Stakeholder(const std::string& oid, const std::string& name,
                const std::string& email, const std::string& phone,
                std::string versionMajor, std::string versionMinor,
                const Fecha date, const std::string& comments,
                const Rol_Stakeholder* stakeholderRole, bool isDeveloper, bool isCustomer,
                const Organization& worksForOrganization)
            : id(oid),
              name(name),
              versionMajor(versionMajor),
              versionMinor(versionMinor),
              date_init(date),
              comments(comments),
              stakeholderRole(stakeholderRole),
              worksForOrganization(worksForOrganization) {}

              void print()
              {
                std::cout << "OID: " << id << std::endl;
                std::cout << "Name: " << name << std::endl;
                std::cout << "Email: " << email << std::endl;
                std::cout << "Phone: " << phone << std::endl;
                std::cout << "Version major: " << versionMajor << std::endl;
                std::cout << "Version minor: " << versionMinor << std::endl;
                std::cout << "Date init: ";
                date_init.print();
                std::cout << std::endl;
                std::cout << "Comments: " << comments << std::endl;
                std::cout << "Stakeholder role: " << stakeholderRole << std::endl;
                std::cout << "Works for organization: ";
                worksForOrganization.print();
                std::cout << std::endl;
              }
};


int main() {
    //PRUEBA DE ORGANIZACION Y STAKEHOLDER
    std::cout << "PRUEBA DE ORGANIZACION " << std::endl;
    Organization org("Org", "Contact info", "Description", "Comments");
    org.print();
    std::cout << "\nPRUEBA DE STAKEHOLDER " << std::endl;
    Stakeholder stakeholder("001", "Name", "Email", "Phone", "Version major", "Version minor",
                            Fecha(2021, 6, 18), "Comments", "Stakeholder role", true, true, org);
    stakeholder.print();
    return 0;

}
