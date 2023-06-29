#include <iostream>
#include <fstream>
#include "Dominio/Generic.h"
#include "Visitor/Jsoneitor.h"
#include "Dominio/Trackeable/Stakeholder.h"
#include "nlohmann/json.hpp"
#include "Dominio/Trackeable/Organization.h"
#include "Dominio/InformationRequirement.h"
#include "Visitor/DiagramManager.h"

// for convenience
using json = nlohmann::json;

void crearstakeholder(){

    Rol_Stakeholder rol_stakeholder(1);
    rol_stakeholder.setName("Programador");
    rol_stakeholder.setDescription("Encargado de picar código");


    Stakeholder stakeholder(1);
    stakeholder.setName("Fran");
    stakeholder.setDescription("Soy Fran");
    stakeholder.setVersionMajor("1");
    stakeholder.setVersionMinor("0");
    stakeholder.setComments("Comentario");
    stakeholder.setEmail("fran.lo@pe.z");
    stakeholder.setPhone("123456789");
    stakeholder.setAddress("Calle falsa 123");

    rol_stakeholder.addAuthor(stakeholder.getId());

    Jsoneitor jsoneitor;
    jsoneitor.visit(rol_stakeholder);
    jsoneitor.visit(stakeholder);

}

void print(Stakeholder a)
{
    //Quiero imprimir las tildes y las ñ
    std::cout << "ID: " << a.getId().operator std::string() << std::endl;
    std::cout << "Name: " << a.getName() << std::endl;
    std::cout << "Description: " << a.getDescription() << std::endl;
    std::cout << "Version: " << a.getVersionMajor() << "." << a.getVersionMinor() << std::endl;
    std::cout << "Comments: " << a.getComments() << std::endl;
    std::cout << "Email: " << a.getEmail() << std::endl;
    std::cout << "Phone: " << a.getPhone() << std::endl;
    std::cout << "Address: " << a.getAddress() << std::endl;
    std::cout << "Stakeholder Role: " << a.getStakeholderRole().operator std::string() << std::endl;
    std::cout << "Works for Organization: " << a.getWorksForOrganization().operator std::string() << std::endl;
    //prueba de los set y list
auto set1 = a.getTracesFrom();
auto set2 = a.getTracesTo();
auto list = a.getChanges();
auto set3 = a.getAuthors();
std::cout << "Traces From: " << std::endl;
for(auto i : set1)
{
    std::cout << i.operator std::string() << std::endl;
}
std::cout << "Traces To: " << std::endl;
for(auto i : set2)
{
    std::cout << i.operator std::string() << std::endl;
}
std::cout << "Changes: " << std::endl;
for(auto i : list)
{
    std::cout << i.getVersion() << std::endl;
    std::cout << i.getDate().toString() << std::endl;
    std::cout << i.getComments() << std::endl;
}
std::cout << "Authors: " << std::endl;
for(auto i : set3)
{
    std::cout << i.operator std::string() << std::endl;
}

}

void crearOrganization(){
    Organization organization(1);
    organization.setName("Megacorp");
    organization.setDescription("Fabricante de Protomascotas");
    organization.setVersionMajor("1");
    organization.setVersionMinor("0");
    organization.setComments("Comunicacion por correo electronico");
    //la informacion de contacto tiene que ser un string muy largo y explayado.
    organization.setContactInfo("Nombre de la empresa: Megacorp\nTipo de empresa: Megacorp es una empresa ficticia especializada en tecnología y servicios innovadores.\nDirección: Avenida Tecnológica 1234, Ciudad Futura, País Imaginario.\nTeléfono: +1 (555) 123-4567\nCorreo electrónico: info@megacorp.com\nSitio web: www.megacorp.com\nRedes sociales:\nFacebook: www.facebook.com/megacorp\nTwitter: www.twitter.com/megacorp\nInstagram: www.instagram.com/megacorp\nHorario de atención al cliente: \nLunes a viernes: 9:00 a.m. - 6:00 p.m.\nSábados: 9:00 a.m. - 1:00 p.m.\n\nNota: Esta información es completamente ficticia y no corresponde a ninguna empresa real.");
    //prueba de traces, changes y authors
    organization.addAuthor({"SH",1});
    Jsoneitor jsoneitor;
    jsoneitor.visit(organization);

}

void print(Organization a){
    setlocale(LC_ALL, "spanish");
    std::cout << "ID: " << a.getId().operator std::string() << std::endl;
    std::cout << "Name: " << a.getName() << std::endl;
    std::cout << "Description: " << a.getDescription() << std::endl;
    std::cout << "Version: " << a.getVersionMajor() << "." << a.getVersionMinor() << std::endl;
    std::cout << "Comments: " << a.getComments() << std::endl;
    std::cout << "Contact Info: " << a.getContactInfo() << std::endl;
    //prueba de los set y list
}

void crearUserCase(){
    UserCase userCase2(1);
    userCase2.setName("Hervir agua");
    userCase2.setDescription("Hervir agua en una cacerola");
    userCase2.setVersionMajor("1");
    userCase2.setVersionMinor("0");
    userCase2.setComments("Que util");
    userCase2.setPrecondition("Precondiciones");
    userCase2.setPostcondition("Postcondiciones");
    userCase2.setEstability(Priority::STABLE);
    userCase2.setUrgencyLevel(Priority::HIGH);
    userCase2.setImportanceLevel(Priority::MEDIUM);
    userCase2.setEstability(Priority::STABLE);

    //UserCasePart
    userCase2.setAbstract(false);
    userCase2.setPrecondition("Precondiciones");
    userCase2.setPostcondition("Postcondiciones");
    userCase2.addObjective({"OS",1});
    userCase2.addAuthor({"SH",1});

    userCase2.setPackage("Cocina");
    userCase2.setFrequency({1,TimeQuantity::HOUR});

    Step stp1;
    stp1.setDescription("Encender la cocina");
    stp1.setCondition("La cocina esta apagada");
    stp1.setComments("No se puede encender la cocina si esta encendida");
    stp1.setType(Step::ACTOR);

    Step stp2;
    stp2.setDescription("Poner la cacerola con agua");
    stp2.setCondition("La cacerola esta vacia");
    stp2.setComments("No se puede poner la cacerola si ya hay una");
    stp2.setType(Step::ACTOR);

    Step stp3;
    stp3.setDescription("Esperar a que hierva");
    stp3.setCondition("");
    stp3.setComments("");
    stp3.setType(Step::SYSTEM);

    userCase2.addStep(stp1);
    userCase2.addStep(stp2);
    userCase2.addStep(stp3);





    UserCase userCase(2);
    userCase.setName("Cocinar espaguetis con tomate");
    userCase.setDescription("Realizacion culinaria de un plato de pasta con la salsa de tomate");
    userCase.setVersionMajor("1");
    userCase.setVersionMinor("0");
    userCase.setComments("Que rico");
    userCase.setPrecondition("Precondiciones");
    userCase.setPostcondition("Postcondiciones");
    userCase.setEstability(Priority::STABLE);
    userCase.setUrgencyLevel(Priority::HIGH);
    userCase.setImportanceLevel(Priority::MEDIUM);
    userCase.setEstability(Priority::STABLE);

    //UserCasePart
    userCase.setAbstract(false);
    userCase.setPrecondition("Precondiciones");
    userCase.setPostcondition("Postcondiciones");
    userCase.addObjective({"OS",1});
    userCase.addAuthor({"SH",1});
    userCase.addActor({"AC",1});
    userCase.setPackage("Menu");
    userCase.setFrequency({1,TimeQuantity::WEEK});

    Step step1;
    step1.setAbstract(false);
    step1.setDescription("Poner a hervir agua");
    step1.setCondition("Tener agua");
    step1.setComments("No se puede hervir agua sin agua");
    step1.setType(Step::INCLUDE);
    step1.setReference({"UC",1});

    Step step2;
    step2.setAbstract(false);
    step2.setDescription("Agregar sal");
    step2.setCondition("Tener sal");
    step2.setComments("No se puede agregar sal sin sal");
    step2.setType(Step::ACTOR);

    Step step3;
    step3.setAbstract(false);
    step3.setDescription("Agregar spaghetti");
    step3.setCondition("Tener spaghetti");
    step3.setComments("No se puede agregar spaghetti sin spaghetti");
    step3.setType(Step::ACTOR);

    Step step4;
    step4.setAbstract(false);
    step4.setDescription("Esperar 10 minutos");
    step4.setCondition("Tener tiempo");
    step4.setComments("No se puede esperar sin tiempo");
    step4.setType(Step::ACTOR);

    Step step5;
    step5.setAbstract(false);
    step5.setDescription("Colar spaghetti");
    step5.setCondition("Tener colador");
    step5.setComments("No se puede colar sin colador");
    step5.setType(Step::ACTOR);

    Step step6;
    step6.setAbstract(false);
    step6.setDescription("Agregar salsa de tomate");
    step6.setCondition("Tener salsa de tomate");
    step6.setComments("No se puede agregar salsa de tomate sin salsa de tomate");
    step6.setType(Step::ACTOR);

    Step step7;
    step7.setAbstract(false);
    step7.setDescription("Servir");
    step7.setCondition("Tener plato");
    step7.setComments("No se puede servir sin plato");
    step7.setType(Step::ACTOR);

    userCase.addStep(step1);
    userCase.addStep(step2);
    userCase.addStep(step3);
    userCase.addStep(step4);
    userCase.addStep(step5);
    userCase.addStep(step6);
    userCase.addStep(step7);

    ActorUC actorUC(1);
    actorUC.setName("Cocinero");
    actorUC.setDescription("Persona que cocina");
    actorUC.setVersionMajor("1");
    actorUC.setVersionMinor("0");
    actorUC.setComments("Que rico");
    actorUC.setPackage("Cocina");


    Jsoneitor jsoneitor;
    jsoneitor.visit(actorUC);
    jsoneitor.visit(userCase2) ;
    jsoneitor.visit(userCase);

    std::list<UserCase> userCases;
    userCases.push_back(userCase);
    userCases.push_back(userCase2);

    DiagramManager diagramManager;
    diagramManager.visit(userCases);

};

void print(UserCase userCase)
{
    setlocale(LC_ALL, "spanish");
    std::cout << "ID: " << userCase.getId().operator std::string() << std::endl;
    std::cout << "Name: " << userCase.getName() << std::endl;
    std::cout << "Description: " << userCase.getDescription() << std::endl;
    std::cout << "Version: " << userCase.getVersionMajor() << "." << userCase.getVersionMinor() << std::endl;
    std::cout << "Comments: " << userCase.getComments() << std::endl;
    std::cout << "Precondition: " << userCase.getPrecondition() << std::endl;
    std::cout << "Postcondition: " << userCase.getPostcondition() << std::endl;

    std::cout << "Urgency Level: " << userCase.getUrgencyLevel() << std::endl;
    std::cout << "Importance Level: " << userCase.getImportanceLevel() << std::endl;
    std::cout << "Urgency Level: " << userCase.getImportanceLevel() << std::endl;
    std::cout << "Phase level: " << userCase.getPhase() << std::endl;

    std::cout << "Abstract: " << userCase.isAbstract() << std::endl;
    std::cout << "Precondition: " << userCase.getPrecondition() << std::endl;
    std::cout << "Postcondition: " << userCase.getPostcondition() << std::endl;
    for (auto objective : userCase.getObjectives())
    {
        std::cout << "Objective: " << objective.operator std::string() << std::endl;
    }
    for (auto author : userCase.getAuthors())
    {
        std::cout << "Author: " << author.operator std::string() << std::endl;
    }
    for (auto actor : userCase.getActors())
    {
        std::cout << "Actor: " << actor.operator std::string() << std::endl;
    }
    int i = 0;

    for (auto steps : userCase.getSteps())
    {
        std::cout << "\n";
        std::cout << "Step " << ++i << std::endl;
        std::cout << "Step: " << steps.getDescription() << std::endl;
        std::cout << "Abstract: " << steps.getAbstract() << std::endl;
        std::cout << "Condition: " << steps.getCondition() << std::endl;
        std::cout << "Comments: " << steps.getComments() << std::endl;
        std::cout << "Type: " << steps.getType() << std::endl;
        std::cout << "Reference: " << steps.getReference().operator std::string() << std::endl;
    }
}

void crearInformationRequirement()
{
    InformationRequirement informationRequirement(1) ;
    informationRequirement.setName("Nombre");
    informationRequirement.setDescription("Descripcion");
    informationRequirement.setVersionMajor("1");
    informationRequirement.setVersionMinor("1");
    informationRequirement.setComments("Comentarios");

    informationRequirement.setUrgencyLevel(static_cast<Priority::Importance>(1));
    informationRequirement.setImportanceLevel(static_cast<Priority::Importance>(1));
    informationRequirement.setPhase(static_cast<Priority::Development_phase>(1));
    informationRequirement.setEstability(static_cast<Priority::Estability>(1));

    informationRequirement.setMaxSimultaneousOccurrence(1);
    informationRequirement.setAvgSimultaneousOccurrence(1);
    informationRequirement.setLifeAvgEstimate(TimeQuantity(1,TimeQuantity::DAY));
    informationRequirement.setLifeMaxEstimate(TimeQuantity(1,TimeQuantity::WEEK));


    Jsoneitor jsoneitor;
    jsoneitor.visit(informationRequirement);
}

void print(InformationRequirement i)
{
    setlocale(LC_ALL, "spanish");
    std::cout << "ID: " << i.getId().operator std::string() << std::endl;
    std::cout << "Name: " << i.getName() << std::endl;
    std::cout << "Description: " << i.getDescription() << std::endl;
    std::cout << "Version: " << i.getVersionMajor() << "." << i.getVersionMinor() << std::endl;
    std::cout << "Comments: " << i.getComments() << std::endl;

    std::cout << "Urgency Level: " << i.getUrgencyLevel() << std::endl;
    std::cout << "Importance Level: " << i.getImportanceLevel() << std::endl;
    std::cout << "Urgency Level: " << i.getImportanceLevel() << std::endl;
    std::cout << "Phase level: " << i.getPhase() << std::endl;

    std::cout << "MaxSimultaneousOccurrence: " << i.getMaxSimultaneousOccurrence() << std::endl;
    std::cout << "AvgSimultaneousOccurrence: " << i.getAvgSimultaneousOccurrence() << std::endl;
    std::cout << "LifeAvgEstimate: " << i.getLifeAvgEstimate().getQuantity() << std::endl;
    std::cout << "LifeMaxEstimate: " << i.getLifeMaxEstimate().getQuantity() << std::endl;
}

void crearRestrictionRequirement()
{
    RestrictionRequirement restrictionRequirement(1) ;
    restrictionRequirement.setName("Nombre");
    restrictionRequirement.setDescription("Descripcion");
    restrictionRequirement.setVersionMajor("1");
    restrictionRequirement.setVersionMinor("1");
    restrictionRequirement.setComments("Comentarios");

    restrictionRequirement.setUrgencyLevel(static_cast<Priority::Importance>(1));
    restrictionRequirement.setImportanceLevel(static_cast<Priority::Importance>(1));
    restrictionRequirement.setPhase(static_cast<Priority::Development_phase>(1));
    restrictionRequirement.setEstability(static_cast<Priority::Estability>(1));

    Jsoneitor jsoneitor;
    jsoneitor.visit(restrictionRequirement);


}




int main() {
    setlocale(LC_ALL, "spanish");

std::string prefix = "IR";
unsigned id = 1;
//crearInformationRequirement();
FileJsonManager fileJsonManager;
Jsoneitor jsoneitor;
//crearUserCase();
auto lista = fileJsonManager.loadAllStakeholder();
//print
for (auto s : lista) {
    print(s);
    std::cout<<std::endl;
}}
