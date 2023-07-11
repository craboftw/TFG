#include <iostream>
#include <fstream>
#include "Dominio/Generic.h"
#include "Visitor/Jsoneitor.h"
#include "Dominio/Trackeable/Stakeholder.h"
#include "nlohmann/json.hpp"
#include "Dominio/Trackeable/Organization.h"
#include "Dominio/InformationRequirement.h"
#include "Visitor/DiagramManager.h"
#include "Servicio/ServicioUserCase.h"
#include "Visitor/HtmlManager.h"
#include "Dominio/Trackeable/MatrixTraces.h"
#include "Servicio/ServicioMatrixTraces.h"
#include "Servicio/ServicioHTML.h"

std::string generateHTML(InformationRequirement& requirement) {
    std::string html;

    // Estilos CSS para la tabla
    html += "<style>";
    html += "table { width: 100%; border-collapse: collapse; }";
    html += "th, td { padding: 10px; text-align: left; }";
    html += "th { background-color: #333; color: #fff; }";
    html += "td { background-color: #f1f1f1; }";
    html += "</style>";

    // Abrir la tabla
    html += "<table>";

    // Agregar el ID del requerimiento en una fila de encabezado
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>ID</th>";
    html += "<td colspan='3' style='font-family: Arial, sans-serif;'>" + static_cast<std::string>(requirement.getId()) + "</td>";
    html += "</tr>";

    // Agregar el nombre del requerimiento en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Nombre</th>";
    html += "<td colspan='3' style='font-family: Arial, sans-serif;'>" + requirement.getName() + "</td>";
    html += "</tr>";

    // Agregar la descripción del requerimiento en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Descripción</th>";
    html += "<td colspan='3' style='font-family: Arial, sans-serif;'>" + requirement.getDescription() + "</td>";
    html += "</tr>";
    // Agregar Max Simultaneous Occurrence y Avg Simultaneous Occurrence en la misma fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Max Simultaneous Occurrence</th>";
    html += "<td colspan='3' style='font-family: Arial, sans-serif;'>" + std::to_string(requirement.getMaxSimultaneousOccurrence()) + "</td>";
    html += "</tr>";

    // Agregar Tiempo estimado máximo de vida y Tiempo estimado promedio de vida en la misma fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Tiempo estimado máximo de vida</th>";
    html += "<td colspan='3' style='font-family: Arial, sans-serif;'>" + requirement.strLifeMaxEstimate() + "</td>";
    html += "</tr>";

    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Tiempo estimado promedio de vida</th>";
    html += "<td colspan='3' style='font-family: Arial, sans-serif;'>" + requirement.strLifeAvgEstimate() + "</td>";
    html += "</tr>";

    // Agregar la importancia y urgencia del requerimiento en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Importancia</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + requirement.strImportanceLevel() + "</td>";
    html += "<th style='font-family: Arial, sans-serif;'>Urgencia</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + requirement.strUrgencyLevel() + "</td>";
    html += "</tr>";

    // Agregar la fase de desarrollo y estabilidad del requerimiento en una fila
    html += "<tr>";
    html += "<th style='font-family: Arial, sans-serif;'>Fase de desarrollo</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + requirement.strPhase() + "</td>";
    html += "<th style='font-family: Arial, sans-serif;'>Estabilidad</th>";
    html += "<td style='font-family: Arial, sans-serif;'>" + requirement.strEstability() + "</td>";
    html += "</tr>";

    // Cerrar la tabla
    html += "</table>";

    return html;
}






// for convenience
using json = nlohmann::json;

void crearstakeholder(){


    Stakeholder stakeholder(1);
    stakeholder.setName("Fran");
    stakeholder.setDescription("Soy Fran");
    stakeholder.setVersionMajor("1");
    stakeholder.setVersionMinor("0");
    stakeholder.setComments("Comentario");
    stakeholder.setEmail("fran.lo@pe.z");
    stakeholder.setPhone("123456789");
    stakeholder.setAddress("Calle falsa 123");
    stakeholder.setStakeholderRole("Jefazo");


    Jsoneitor jsoneitor;
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
    std::cout << "Stakeholder Role: " << a.getStakeholderRole() << std::endl;
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

InformationRequirement crearInformationRequirement()
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
    return informationRequirement;
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

    HtmlManager htmlManager;
    //std::cout<<htmlManager.generateTable(restrictionRequirement.getId())<<std::endl;

}

void pruebaServicioUserCase()
{
        ServicioUserCase servicio;

        // Crear un UserCase y obtener su ID
        OID id = servicio.createUserCase();
        std::cout << "ID del UserCase creado: " << id.operator std::string() << std::endl;

        // Establecer propiedades del UserCase
        servicio.setAbstract(id, true);
        servicio.setPrecondition(id, "Precondición del UserCase");
        servicio.setPostcondition(id, "Postcondición del UserCase");

        servicio.setFrequency(id, TimeQuantity(5, TimeQuantity::DAY));
        std::vector<Step> steps = {Step(true, "Descripción del paso 1"), Step(false, "Descripción del paso 2")};
        servicio.setSteps(id, steps);
        Step newStep(false, "Nuevo paso");
        servicio.addStep(id, newStep);

        // Obtener propiedades del UserCase
        bool isAbstract = servicio.getAbstract(id);
        std::cout << "Abstracto: " << std::boolalpha << isAbstract << std::endl;
        std::string precondition = servicio.getPrecondition(id);
        std::cout << "Precondición: " << precondition << std::endl;
        std::string postcondition = servicio.getPostcondition(id);
        std::cout << "Postcondición: " << postcondition << std::endl;
        std::list<OID> retrievedObjectives = servicio.getObjectives(id);
        std::cout << "Objetivos:";
        for (const auto& objective : retrievedObjectives) {
            std::cout << " " << objective.operator std::string();
        }
        std::cout << std::endl;
        TimeQuantity frequency = servicio.getFrequency(id);
        std::cout << "Frecuencia: " << frequency.getQuantity() << " " << frequency.getUnit() << std::endl;
        std::vector<Step> retrievedSteps = servicio.getSteps(id);
        std::cout << "Pasos:";
        for (const auto& step : retrievedSteps) {
            std::cout << " " << step.getDescription();
        }
        std::cout << std::endl;
        std::list<OID> retrievedActors = servicio.getActors(id);
        std::cout << "Actores:";
        for (const auto& actor : retrievedActors) {
            std::cout << " " << actor.operator std::string();
        }
        OID id4 = {"UC",id.getId()-3};
        servicio.setGeneralization(id, id4);

    std::cout << std::endl;
        std::string package = servicio.getPackage(id);
        std::cout << "Paquete: " << package << std::endl;
        OID generalization = servicio.getGeneralization(id);
        std::cout << "Generalización: " << generalization.operator std::string() << std::endl;

        // Modificar propiedades de un paso específico
        servicio.setAbstractStep(id, 1, true);
        servicio.setConditionStep(id, 0, "Condición modificada");
        servicio.setCommentsStep(id, 1, "Comentarios modificados");
        servicio.setDescriptionStep(id, 1, "Descripción modificada");

        // Establecer propiedades de un paso específico
        servicio.setTypeStep(id, 0, INCLUDE);
        OID id2 = {"UC",id.getId()-1};
        servicio.setReferenceStep(id, 0, OID(id2));

    OID id3 = {"UC",id.getId()-2};
        servicio.setTypeStep(id, 1, EXTEND);
        servicio.setReferenceStep(id, 1, OID(id3));


        // Obtener propiedades de un paso específico
        bool isAbstractStep = servicio.getAbstractStep(id, 1);
        std::cout << "Abstracto: " << std::boolalpha << isAbstractStep << std::endl;
        std::string condition = servicio.getConditionStep(id, 0);
        std::cout << "Condición: " << condition << std::endl;
        std::string comments = servicio.getCommentsStep(id, 1);
        std::cout << "Comentarios: " << comments << std::endl;
        std::string description = servicio.getDescriptionStep(id, 1);
        std::cout << "Descripción: " << description << std::endl;
        type type = servicio.getTypeStep(id, 0);
        std::cout << "Tipo: " << type << std::endl;
        OID reference = servicio.getReferenceStep(id, 0);
        std::cout << "Referencia: " << reference.operator std::string() << std::endl;

        // Eliminar propiedades de un paso específico
        DiagramManager diagramManager;
        FileJsonManager fileJsonManager;
        std::list<UserCase> userCases = fileJsonManager.loadAllUserCase();
        auto actores = fileJsonManager.loadAllActorUC();
        //diagramManager.visit(userCases,actores);

    }

    void pruebaInformationRequirement()
    {
        InformationRequirement requirement(1);
        requirement.setName("Requerimiento de prueba");
        requirement.setDescription("Este es un requerimiento de prueba")    ;
        std::set<OID> authors = {OID{"SH", 1}};
        requirement.setAuthors(authors);
        requirement.setDescription("Poesia sobre la primavera\n"
                                  "La primavera la sangre altera\n"
                                  "y yo me altero cuando te veo\n"
                                  "y tu te alteras cuando me ves\n"
                                  "y nos alteramos porque nos queremos");
        requirement.setImportanceLevel(Priority::HIGH);
        requirement.setUrgencyLevel(Priority::MEDIUM);
        requirement.setPhase(Priority::IMPLEMENTATION);
        requirement.setEstability(Priority::STABLE);
        requirement.setMaxSimultaneousOccurrence(5);
        requirement.setAvgSimultaneousOccurrence(3);
        requirement.setLifeMaxEstimate(TimeQuantity(10, TimeQuantity::DAY));
        requirement.setLifeAvgEstimate(TimeQuantity(5, TimeQuantity::DAY));
        requirement.addChange(Change(1,"Cambiado numero máximo de ocurrencias",Fecha(),"Se establece a 5 el número máximo de ocurrencias simultáneas"));
        requirement.addSpecificInformation("Información específica de prueba", "Esta es la información específica de prueba");
        requirement.addSpecificInformation("Información específica de prueba 2", "Esta es la información específica de prueba 2");
        requirement.addSpecificInformation("Información específica de prueba 3", "Esta es la información específica de prueba 3");
        HtmlManager htmlManager;
        //crea un fichero prueba html
        std::ofstream file;
        file.open("prueba.html");
        file<<htmlManager.generateTableInformationRequirement(requirement.getId());
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
    stp1.setType(ACTOR);
    stp1.setReference(OID({"AC",1}));

    Step stp2;
    stp2.setDescription("Poner la cacerola con agua");
    stp2.setCondition("La cacerola esta vacia");
    stp2.setComments("No se puede poner la cacerola si ya hay una");
    stp2.setType(SYSTEM);

    Step stp3;
    stp3.setDescription("Esperar a que hierva");
    stp3.setCondition("");
    stp3.setComments("");
    stp3.setType(SYSTEM);

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
    userCase.setFrequency({4,TimeQuantity::WEEK});

    Step step1;
    step1.setAbstract(false);
    step1.setDescription("Poner a hervir agua");
    step1.setCondition("Tener agua");
    step1.setComments("No se puede hervir agua sin agua");
    step1.setType(INCLUDE);
    step1.setReference({"UC",1});

    Step step2;
    step2.setAbstract(false);
    step2.setDescription("Agregar sal");
    step2.setCondition("Tener sal");
    step2.setComments("No se puede agregar sal sin sal");
    step2.setType(SYSTEM);

    Step step3;
    step3.setAbstract(false);
    step3.setDescription("Agregar spaghetti");
    step3.setCondition("Tener spaghetti");
    step3.setComments("No se puede agregar spaghetti sin spaghetti");
    step3.setType(SYSTEM);

    Step step4;
    step4.setAbstract(false);
    step4.setDescription("Esperar 10 minutos");
    step4.setCondition("Tener tiempo");
    step4.setComments("No se puede esperar sin tiempo");
    step4.setType(SYSTEM);

    Step step5;
    step5.setAbstract(false);
    step5.setDescription("Colar spaghetti");
    step5.setCondition("Tener colador");
    step5.setComments("No se puede colar sin colador");
    step5.setType(SYSTEM);

    Step step6;
    step6.setAbstract(false);
    step6.setDescription("Agregar salsa de tomate");
    step6.setCondition("Tener salsa de tomate");
    step6.setComments("No se puede agregar salsa de tomate sin salsa de tomate");
            step6.setType(ACTOR);
    step6.setReference(OID({"AC",1}));

    /*Add one exception of type Exception
    struct Exception{
        unsigned id;
        unsigned step;
        type stepType;
        std::string description;
        std::string condition;
        std::string comments;
        OID reference;
    };*/

    userCase.addException({1,INCLUDE,"No hay agua","No hay agua","No hay agua",{"UC",1}});
    userCase.addException({2,EXTEND,"No hay sal","No hay sal","No hay sal",{"UC",1}});
    userCase.addException({3,ACTOR,"No hay spaghetti","No hay spaghetti","No hay spaghetti",{"AC",1}});
    userCase.addException({4,SYSTEM,"No hay tiempo","No hay tiempo","No hay tiempo",{"UC",1}});


    Step step7;
    step7.setAbstract(false);
    step7.setDescription("Servir");
    step7.setCondition("Tener plato");
    step7.setComments("No se puede servir sin plato");
    step7.setType(ACTOR);
    step7.setReference(OID({"AC",1}));

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

    HtmlManager htmlManager;
    //in file userCase.html htmlManager.generateTable(userCase)

}

OID pruebaServicioStakeholder()
{
    ServicioStakeholder servicioStakeholder;
    auto id = servicioStakeholder.createStakeholder("Pakito");
    servicioStakeholder.setName(id,"Pakito");
    servicioStakeholder.setDescription(id,"El mejor");
    servicioStakeholder.setVersionMajor(id,"2");
    servicioStakeholder.setVersionMinor(id,"0");
    servicioStakeholder.setComments(id,"Que rico");
    servicioStakeholder.setEmail(id,"pa@ki.to");
    servicioStakeholder.setPhone(id,"123456789");
    servicioStakeholder.setAddress(id,"Calle de la piruleta");
    servicioStakeholder.setWorksForOrganization(id,{"OR",1});
    servicioStakeholder.setStakeholderRole(id,"Autor de la aplicacion");
    return id;
}

OID pruebaServicioOrganitacion()
{
    //make megacorp company, the most important company in the world
    ServicioOrganization servicioOrganizacion;
    auto id = servicioOrganizacion.createOrganization("Megacorp");
    servicioOrganizacion.setName(id,"Megacorp");
    servicioOrganizacion.setDescription(id,"La mejor empresa del mundo");
    servicioOrganizacion.setVersionMajor(id,"1");
    servicioOrganizacion.setVersionMinor(id,"0");
    servicioOrganizacion.setComments(id,"Son ricos");
    servicioOrganizacion.setContactInfo(id,"www.megacorp.com");


    return id;
}

void pruebaServicioMatrix()
{
    /*   MatrixTraces matrixTraces(1);
    matrixTraces.addPrefixFrom("UC");
    matrixTraces.addPrefixFrom("OR");
    matrixTraces.addPrefixFrom("IR");
    matrixTraces.addPrefixTo("UC");
    matrixTraces.addPrefixTo("FR");
    matrixTraces.addPrefixTo("SO");
    matrixTraces.addPrefixTo("NF");
    matrixTraces.addPrefixTo("TX");
    matrixTraces.addPrefixTo("IR");
    matrixTraces.addPrefixTo("AC");
    matrixTraces.addPrefixTo("SH");
    matrixTraces.addPrefixTo("OR");
    matrixTraces.addPrefixTo("IN");
    matrixTraces.addPrefixTo("TE");
    matrixTraces.addPrefixTo("PR");

    matrixTraces.addTrackeable(uc);
    matrixTraces.addTrackeable(fr);
    matrixTraces.addTrackeable(so);
    matrixTraces.addTrackeable(nf);
    matrixTraces.addTrackeable(tx);
    matrixTraces.addTrackeable(ir);
    matrixTraces.addTrackeable(ac);
    matrixTraces.addTrackeable(sh);
    matrixTraces.addTrackeable({"OR",1});
    matrixTraces.addTrackeable({"UC",2});*/

    ServicioMatrixTraces servicioMatrixTraces;
    auto id = servicioMatrixTraces.createMatrixTraces("la matriz");
    servicioMatrixTraces.addPrefixFrom(id,"UC");
    servicioMatrixTraces.addPrefixFrom(id,"OR");
    servicioMatrixTraces.addPrefixFrom(id,"IR");
    servicioMatrixTraces.addPrefixTo(id,"UC");
    servicioMatrixTraces.addPrefixTo(id,"FR");
    servicioMatrixTraces.addPrefixTo(id,"SO");
    servicioMatrixTraces.addPrefixTo(id,"NF");
    servicioMatrixTraces.addPrefixTo(id,"TX");
    servicioMatrixTraces.addPrefixTo(id,"IR");
    servicioMatrixTraces.addPrefixTo(id,"AC");
    servicioMatrixTraces.addPrefixTo(id,"SH");
    servicioMatrixTraces.addPrefixTo(id,"OR");
    servicioMatrixTraces.addPrefixTo(id,"IN");
    servicioMatrixTraces.addPrefixTo(id,"TE");
    servicioMatrixTraces.addPrefixTo(id,"PR");
    OID fr = {"FR",1};
    OID so = {"SO",1};
    OID nf = {"NF",1};
    OID tx = {"TX",1} ;
    OID ir = {"IR",1} ;
    OID uc = {"UC",1} ;
    OID uc2 = {"UC",2} ;
    OID ac = {"AC",1} ;
    OID sh = {"SH",1} ;

    servicioMatrixTraces.addTrackeable(id,uc);
    servicioMatrixTraces.addTrackeable(id,fr);
    servicioMatrixTraces.addTrackeable(id,so);
    servicioMatrixTraces.addTrackeable(id,nf);
    servicioMatrixTraces.addTrackeable(id,tx);
    servicioMatrixTraces.addTrackeable(id,ir);
    servicioMatrixTraces.addTrackeable(id,ac);
    servicioMatrixTraces.addTrackeable(id,sh);
    servicioMatrixTraces.addTrackeable(id,{"OR",1});
    servicioMatrixTraces.addTrackeable(id,{"UC",2});
    servicioMatrixTraces.addTrackeable(id,{"IR",1});
    servicioMatrixTraces.addTrackeable(id,{"IN",1});



}

void pruebashtml()
{
    ServicioStakeholder servicioStakeholder;
    ServicioOrganization servicioOrganization;
    ServicioUserCase servicioUserCase;
    ServicioFunctionalRequirement servicioFunctionalRequirement;
    ServicioSystemObjective servicioSystemObjective;
    ServicioInformationRequirement servicioInformationRequirement;
    ServicioActorUC servicioActorUC;
    ServicioUserStories servicioUserStories;





    OID fr = {"FR",1};
    OID so = {"SO",1};
    OID nf = {"NF",1};
    OID tx = {"TX",1} ;
    OID ir = {"IR",1} ;
    OID uc = {"UC",1} ;
    OID uc2 = {"UC",2} ;
    OID ac = {"AC",1} ;
    OID sh = {"SH",1} ;
    auto setVacio = std::set<OID>();

    HtmlManager htmlManager;
    std::list <OID> userCases;
    //insert iduc in the list usercases
    userCases = {{"UC",1},{"UC",2}};
    auto htmlir = htmlManager.generateTableInformationRequirement(ir);
    std::ofstream file;
    file.open("usercase.html");
    std::list<ActorUC> listaActores;
    DiagramManager diagramGenerator;
    diagramGenerator.visit(userCases, {{"AC", 1}});
    //diagramGenerator.visit(userCases);
    for (auto &uc : userCases) {
        file << htmlManager.generateTableUserCase(uc);
        //make a separator between the tables
        file << "<br>";
    }
    //auto adjust the size of the image to the size of the window make the width 100%
    file<< "<html><body><img src=\"TFG\\Diagrams\\UseCaseDiagram.png\" alt=\"diagram\"  width=\"100%\" height=\"auto\"></body></html>";
    file<<"<br>";
    file<<htmlir ;
    file<<"<br>";
    file<<htmlManager.generateTableStakeholder({"SH",1});
    file<<"<br>";
    file<<htmlManager.generateTableActorUC({"AC",1});
    file<<"<br>";
    file<<htmlManager.generateTableText(tx) ;
    file<<"<br>";
    file<<htmlManager.generateTableNonFunctionalRequirement(nf) ;
    file<<"<br>";
    file<<htmlManager.generateTableFunctionalRequirement(fr) ;
    file<<"<br>";
    file<<htmlManager.generateTableSystemObjetive(so) ;
    pruebaServicioMatrix();

    auto matrix = OID {"MT",1};

    file<<"<br>";
    file<<htmlManager.generateMatrixTraces(matrix);
    file<<"<br>";
    std::list<OID> listaus; //hasta el 11
    listaus = {{"US",1},{"US",2}, {"US",4}, {"US",5}, {"US",6}};
    for (auto &us : listaus) {
        file << htmlManager.generateTableUserStory(us);
        //make a separator between the tables
        file << "<br>";
    }
    file<<htmlManager.generateUserStory(listaus);


}

void prueba()
{
 ServicioHTML servicioHTML;
 ServicioText servicioText;
 auto idTexto1 = servicioText.createText("Introduccion");
 servicioText.setDescription(idTexto1,"\n"
                                      "El objetivo principal del sistema de Venta de Espartos a desarrollar es crear una plataforma digital en forma de página web para la comercialización y venta de los variados productos de espartos que fabrica el artesano Antonio López. Se trata de una solución moderna y efectiva que permitirá a los clientes personalizar sus pedidos a su gusto, ya sea en el tamaño de las persianas, las dimensiones de las cabezas de toro o la apariencia de los bolsos, entre otros. De esta manera, se podrán satisfacer las necesidades específicas de cada cliente, incrementando así la satisfacción del cliente y aumentando su fidelidad a la empresa. Este sistema será un impulso para el negocio de Antonio López, ya que simplificará la forma en que se gestionan los pedidos y se adaptarán a las necesidades de cada cliente. Asimismo, permitirá la exposición de sus productos a un público mucho más amplio, permitiendo que más personas se familiaricen con su trabajo, aumentando así la visibilidad y la reputación de su empresa en el mercado. \n"
                                      "\n"
                                      "La presencia en internet es crucial en el mundo de los negocios moderno, y lamentablemente, nuestro cliente ha estado fuera del radar durante demasiado tiempo. Sin una página web o un medio de contacto efectivo, su alcance se ha limitado a aquellos que ya lo conocen. Pero esto no tiene por qué seguir siendo así, y es por eso que hemos asumido la tarea de desarrollar una página web para nuestro cliente, con el objetivo de darle a su negocio la visibilidad que merece. \n"
                                      "\n"
                                      "Después de la realización de este proyecto se podrán ofrecer servicios a un público mucho más amplio y diverso, y establecer su presencia en internet para llegar a nuevas audiencias y clientes potenciales. A través de la personalización de los pedidos, su negocio podrá destacar en un mercado cada vez más competitivo y responder a las necesidades específicas de cada cliente. Además, la página web le permitirá establecer una relación más cercana con sus clientes y recibir feedback, lo que puede ser una gran ayuda para mejorar y crecer en el futuro. \n"
                                      "\n"
                                      "En el resto del documento describiremos en profundidad los requisitos necesarios para llevar a cabo el prototipo, los objetivos del sistema y todo lo necesario para llevar a cabo este proyecto. \n""\n"
                                      "");
 auto indiceIntroduccion = servicioHTML.index.createIndex("Introduccion",0);
 servicioHTML.index.addElement(indiceIntroduccion,idTexto1);

 ServicioStakeholder servicioStakeholder;
 ServicioOrganization servicioOrganization;
 auto idOrg1 = servicioOrganization.createOrganization("Esparto Antonio Lopez");
 servicioOrganization.setContactInfo(idOrg1,"Camino de la Avellana nº 21, Chiclana, Cádiz. 679 87 54 91.");
 auto idOrg2 = servicioOrganization.createOrganization("KrenkoTeam");
servicioOrganization.setContactInfo(idOrg2,"Escuela Superior de Ingeniería, Universidad de Cádiz. 956 01 50 00.");
auto idStakeholder1 = servicioStakeholder.createStakeholder("Antonio López");
servicioStakeholder.setWorksForOrganization(idStakeholder1,idOrg1);
servicioStakeholder.setStakeholderRole(idStakeholder1,"Cliente");
auto idStakeholder2 = servicioStakeholder.createStakeholder("Francisco López Guerrero");
servicioStakeholder.setWorksForOrganization(idStakeholder2,idOrg2);
servicioStakeholder.setStakeholderRole(idStakeholder2,"Ingeniero de Software");
auto idStakeholder3 = servicioStakeholder.createStakeholder("Miriam Armario Cantos");
servicioStakeholder.setWorksForOrganization(idStakeholder3,idOrg2);
servicioStakeholder.setStakeholderRole(idStakeholder3,"Ingeniera de Software");
auto indiceParticipantes = servicioHTML.index.createIndex("Participantes",0);
servicioHTML.index.addElement(indiceParticipantes,idStakeholder1);
servicioHTML.index.addElement(indiceParticipantes,idStakeholder2);
servicioHTML.index.addElement(indiceParticipantes,idStakeholder3);
servicioHTML.index.addElement(indiceParticipantes,idOrg1);
servicioHTML.index.addElement(indiceParticipantes,idOrg2);

auto idDescripcion = servicioText.createText("Descripcion");

        servicioText.setDescription(idDescripcion,"El negocio del esparto al que nos referimos está solo llevado por Antonio López, un hombre que trabaja solo y no está del todo acostumbrado a las nuevas tecnologías. Esto hace que su sistema de venta de productos de espartos se limite solo a la comunicación por WhatsApp o llamada, haciendo que sea más lenta la venta. Es decir, el cliente contacta con Antonio López, éste hace un boceto del pedido, lo manda, espera confirmación, y si todo está bien se procede a la venta. Si son necesarios cambios este proceso se retrasa más de lo necesario. \n"
                            "\n"
                            "Nos encontramos también con el problema de que todos los datos se guardan a papel, o en los contactos de Antonio López, lo que acaba siendo muy confuso también para él. Hay que buscar manualmente a todos los contactos en caso de haber algún problema. Si pasase cualquier cosa con el móvil de Antonio López todos los clientes estarían perdidos. " );
auto indiceDescripcion = servicioHTML.index.createIndex("Descripcion del sistema actual",0);
servicioHTML.index.addElement(indiceDescripcion,idDescripcion);

    ServicioSystemObjective servicioSystemObjective;
auto idObjetivo1 = servicioSystemObjective.createSystemObjective("Generador de hojas de pedido.");
//servicioSystemObjective.setVersionMajor(idObjetivo1,"1.0");
servicioSystemObjective.setVersionMinor(idObjetivo1,"0.0");
servicioSystemObjective.addAuthor(idObjetivo1,idStakeholder2);
servicioSystemObjective.addAuthor(idObjetivo1,idStakeholder3);
servicioSystemObjective.setDescription(idObjetivo1, "El sistema deberá generar imágenes que resuman el pedido customizado por el cliente, de forma que éste pueda entenderse con el artesano y ambos comprendan rápidamente el pedido. ");
servicioSystemObjective.setImportanceLevel(idObjetivo1, Priority::HIGH);
servicioSystemObjective.setUrgencyLevel(idObjetivo1, Priority::HIGH);
servicioSystemObjective.setPhase(idObjetivo1, Priority::VALIDATION);
servicioSystemObjective.setEstability(idObjetivo1, Priority::STABLE);

auto idObjetivo2 = servicioSystemObjective.createSystemObjective("Informar al artesano de los pedidos.");
servicioSystemObjective.setVersionMajor(idObjetivo2,"1.0");
servicioSystemObjective.setVersionMinor(idObjetivo2,"0.0");
servicioSystemObjective.addAuthor(idObjetivo2,idStakeholder2);
servicioSystemObjective.addAuthor(idObjetivo2,idStakeholder3);
servicioSystemObjective.setDescription(idObjetivo2, "El sistema deberá ser capaz rápidamente de ponerse en contacto con el artesano, mandándole la hoja de pedido al WhatsApp. ");
servicioSystemObjective.setImportanceLevel(idObjetivo2, Priority::HIGH);
servicioSystemObjective.setUrgencyLevel(idObjetivo2, Priority::MEDIUM);
servicioSystemObjective.setPhase(idObjetivo2, Priority::DEVELOPMENT);
servicioSystemObjective.setEstability(idObjetivo2, Priority::STABLE);

auto idObjetivo3 = servicioSystemObjective.createSystemObjective("Gestionar los productos.");
servicioSystemObjective.setVersionMajor(idObjetivo3,"1.0");
servicioSystemObjective.setVersionMinor(idObjetivo3,"0.0");
servicioSystemObjective.addAuthor(idObjetivo3,idStakeholder2);
servicioSystemObjective.addAuthor(idObjetivo3,idStakeholder3);
servicioSystemObjective.setDescription(idObjetivo3, "El sistema deberá proporcionar diversas formas para la especializacion de las hojas de pedido. ");
servicioSystemObjective.setImportanceLevel(idObjetivo3, Priority::HIGH);
servicioSystemObjective.setUrgencyLevel(idObjetivo3, Priority::MEDIUM);
servicioSystemObjective.setPhase(idObjetivo3, Priority::DEVELOPMENT);
servicioSystemObjective.setEstability(idObjetivo3, Priority::STABLE);
servicioSystemObjective.setComments(idObjetivo3, "Cuando se implemente el sistema, habrá un Asistente, que no es un usuario, solo gestiona productos de la página web. ");

auto idObjetivo4 = servicioSystemObjective.createSystemObjective("Gestionar el acceso.");
servicioSystemObjective.setVersionMajor(idObjetivo4,"1.0");
servicioSystemObjective.setVersionMinor(idObjetivo4,"0.0");
servicioSystemObjective.addAuthor(idObjetivo4,idStakeholder2);
servicioSystemObjective.addAuthor(idObjetivo4,idStakeholder3);
servicioSystemObjective.setDescription(idObjetivo4, "El sistema deberá proporcionar un sistema de acceso para los usuarios. ");
servicioSystemObjective.setImportanceLevel(idObjetivo4, Priority::HIGH);
servicioSystemObjective.setUrgencyLevel(idObjetivo4, Priority::HIGH);
servicioSystemObjective.setPhase(idObjetivo4, Priority::DEVELOPMENT);
servicioSystemObjective.setEstability(idObjetivo4, Priority::STABLE);

auto idObjetivo5 = servicioSystemObjective.createSystemObjective("Generar factura o presupuesto.");
servicioSystemObjective.setVersionMajor(idObjetivo5,"1.0");
servicioSystemObjective.setVersionMinor(idObjetivo5,"0.0");
servicioSystemObjective.addAuthor(idObjetivo5,idStakeholder2);
servicioSystemObjective.addAuthor(idObjetivo5,idStakeholder3);
servicioSystemObjective.setDescription(idObjetivo5, "Cuando se implemente el sistema, habrá un Asistente, que no es un usuario, solo gestiona productos de la página web. ");
servicioSystemObjective.setImportanceLevel(idObjetivo5, Priority::HIGH);
servicioSystemObjective.setUrgencyLevel(idObjetivo5, Priority::HIGH);
servicioSystemObjective.setPhase(idObjetivo5, Priority::DEVELOPMENT);
servicioSystemObjective.setEstability(idObjetivo5, Priority::STABLE);

auto idObjetivo6 = servicioSystemObjective.createSystemObjective("Mostrar la informacion de los productos.");
servicioSystemObjective.setVersionMajor(idObjetivo6,"1.0");
servicioSystemObjective.setVersionMinor(idObjetivo6,"0.0");
servicioSystemObjective.addAuthor(idObjetivo6,idStakeholder2);
servicioSystemObjective.addAuthor(idObjetivo6,idStakeholder3);
servicioSystemObjective.setDescription(idObjetivo6, "El sistema deberá mostrar la información de los productos de forma que el usuario pueda verlos. Se informara tambien de los productos mas vendidos.");
servicioSystemObjective.setImportanceLevel(idObjetivo6, Priority::HIGH);
servicioSystemObjective.setUrgencyLevel(idObjetivo6, Priority::HIGH);
servicioSystemObjective.setPhase(idObjetivo6, Priority::DEVELOPMENT);
servicioSystemObjective.setEstability(idObjetivo6, Priority::STABLE);

auto indiceObjetivos = servicioHTML.index.createIndex("Objetivos del sistema",0);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo1);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo2);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo3);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo4);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo5);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo6);

ServicioInformationRequirement servicioInformationRequirement;
auto idrequisito1 = servicioInformationRequirement.createInformationRequirement("Tipos de productos");
servicioInformationRequirement.setVersionMajor(idrequisito1,"1.0");
servicioInformationRequirement.setVersionMinor(idrequisito1,"0.0");
servicioInformationRequirement.addAuthor(idrequisito1,idStakeholder2);
servicioInformationRequirement.addAuthor(idrequisito1,idStakeholder3);
servicioInformationRequirement.setDescription(idrequisito1, "El sistema deberá proporcionar diversos tipos de productos para que el usuario pueda elegir.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Cabezas de toro","Decoraciones de esparto con la forma de una cabeza de toro.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Bolsos","Bolsos de esparto.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Persianas","Persianas de esparto personalizables con los tamañanos que el cliente desee.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Alfombras","Alfombras de esparto personalizables con los tamañanos que el cliente desee.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Fundas de botella", "Fundas de botella de esparto.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Fundas de maceta", "Fundas de maceta de esparto.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Revisteros","Revisteros de esparto.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Cestos","Cestos de esparto.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Burros","Burros de esparto.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Reores","Alfombras redondas de esparto del diametro que el cliente desee.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Canastos","Canastos de esparto.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Leñeros","Leñeros de esparto.");
servicioInformationRequirement.addSpecificInformation(idrequisito1,"Productos Personalizados","Productos de esparto personalizados con las formas y tamaños que el cliente desee.");
servicioInformationRequirement.setLifeAvgEstimate(idrequisito1, {2,TimeQuantity::YEAR});
servicioInformationRequirement.setLifeMaxEstimate(idrequisito1, {5,TimeQuantity::YEAR});
servicioInformationRequirement.setImportanceLevel(idrequisito1, Priority::HIGH);
servicioInformationRequirement.setUrgencyLevel(idrequisito1, Priority::HIGH);
servicioInformationRequirement.setPhase(idrequisito1, Priority::DEVELOPMENT);
servicioInformationRequirement.setEstability(idrequisito1, Priority::STABLE);
auto idrequisito2 = servicioInformationRequirement.createInformationRequirement("Contacto con el Artesano");
servicioInformationRequirement.setVersionMajor(idrequisito2,"1.0");
servicioInformationRequirement.setVersionMinor(idrequisito2,"0.0");
servicioInformationRequirement.addAuthor(idrequisito2,idStakeholder1);
servicioInformationRequirement.addAuthor(idrequisito2,idStakeholder2);
servicioInformationRequirement.addAuthor(idrequisito2,idStakeholder3);
servicioInformationRequirement.setDescription(idrequisito2, "El sistema deberá almacenar la información correspondiente a las formas preferidas del artesano de contacto. Whatsapp por preferencia. En concreto: Whatsapp, Facebook, Instagram y Llamada.");
servicioInformationRequirement.addSpecificInformation(idrequisito2,"Whatsapp","");
servicioInformationRequirement.addSpecificInformation(idrequisito2,"Facebook","");
servicioInformationRequirement.addSpecificInformation(idrequisito2,"Instagram","");
servicioInformationRequirement.addSpecificInformation(idrequisito2,"Llamada","");
servicioInformationRequirement.setLifeAvgEstimate(idrequisito2, {2,TimeQuantity::YEAR});
servicioInformationRequirement.setLifeMaxEstimate(idrequisito2, {5,TimeQuantity::YEAR});
servicioInformationRequirement.setImportanceLevel(idrequisito2, Priority::HIGH);
servicioInformationRequirement.setUrgencyLevel(idrequisito2, Priority::HIGH);
servicioInformationRequirement.setPhase(idrequisito2, Priority::DEVELOPMENT);
servicioInformationRequirement.setEstability(idrequisito2, Priority::STABLE);
auto idrequisito3 = servicioInformationRequirement.createInformationRequirement("Informacion del taller");
servicioInformationRequirement.setVersionMajor(idrequisito3,"1.0");
servicioInformationRequirement.setVersionMinor(idrequisito3,"0.0");
servicioInformationRequirement.addAuthor(idrequisito3,idStakeholder2);
servicioInformationRequirement.addAuthor(idrequisito3,idStakeholder3);
servicioInformationRequirement.setDescription(idrequisito3, "El sistema deberá almacenar la información correspondiente a dónde se encuentra actualmente el taller. En concreto: Localización y Horario de apertura.");
servicioInformationRequirement.addSpecificInformation(idrequisito3,"Localización","");
servicioInformationRequirement.addSpecificInformation(idrequisito3,"Horario de apertura","");
servicioInformationRequirement.setLifeAvgEstimate(idrequisito3, {2,TimeQuantity::YEAR});
servicioInformationRequirement.setLifeMaxEstimate(idrequisito3, {5,TimeQuantity::YEAR});
servicioInformationRequirement.setImportanceLevel(idrequisito3, Priority::HIGH);
servicioInformationRequirement.setUrgencyLevel(idrequisito3, Priority::HIGH);
servicioInformationRequirement.setPhase(idrequisito3, Priority::DEVELOPMENT);
servicioInformationRequirement.setEstability(idrequisito3, Priority::STABLE);
auto idrequisito4 = servicioInformationRequirement.createInformationRequirement("Información sobre el cliente");
servicioInformationRequirement.setVersionMajor(idrequisito4,"1.0");
servicioInformationRequirement.setVersionMinor(idrequisito4,"0.0");
servicioInformationRequirement.addAuthor(idrequisito4,idStakeholder1);
servicioInformationRequirement.addAuthor(idrequisito4,idStakeholder2);
servicioInformationRequirement.addAuthor(idrequisito4,idStakeholder3);
servicioInformationRequirement.setDescription(idrequisito4, "El sistema deberá almacenar la información correspondiente a los usuarios del sistema. En concreto: Nombre, Clave, NIF, Email, Dirección y Teléfono.");
servicioInformationRequirement.addSpecificInformation(idrequisito4,"Nombre","");
servicioInformationRequirement.addSpecificInformation(idrequisito4,"Clave","");
servicioInformationRequirement.addSpecificInformation(idrequisito4,"NIF","");
servicioInformationRequirement.addSpecificInformation(idrequisito4,"Email","");
servicioInformationRequirement.addSpecificInformation(idrequisito4,"Dirección","");
servicioInformationRequirement.addSpecificInformation(idrequisito4,"Teléfono","");
servicioInformationRequirement.setLifeAvgEstimate(idrequisito4, {2,TimeQuantity::YEAR});
servicioInformationRequirement.setLifeMaxEstimate(idrequisito4, {5,TimeQuantity::YEAR});
servicioInformationRequirement.setImportanceLevel(idrequisito4, Priority::HIGH);
servicioInformationRequirement.setUrgencyLevel(idrequisito4, Priority::HIGH);
servicioInformationRequirement.setPhase(idrequisito4, Priority::DEVELOPMENT);
auto idrequisito5 = servicioInformationRequirement.createInformationRequirement("Información sobre las facturas");
servicioInformationRequirement.setVersionMajor(idrequisito5,"1.0");
servicioInformationRequirement.setVersionMinor(idrequisito5,"0.0");
servicioInformationRequirement.addAuthor(idrequisito5,idStakeholder2);
servicioInformationRequirement.addAuthor(idrequisito5,idStakeholder3);
servicioInformationRequirement.setDescription(idrequisito5, "El sistema deberá almacenar la información correspondiente a las facturas generadas de los pedidos.");
servicioInformationRequirement.setLifeAvgEstimate(idrequisito5, {2,TimeQuantity::YEAR});
servicioInformationRequirement.setLifeMaxEstimate(idrequisito5, {5,TimeQuantity::YEAR});
servicioInformationRequirement.setImportanceLevel(idrequisito5, Priority::HIGH);
servicioInformationRequirement.setUrgencyLevel(idrequisito5, Priority::HIGH);
servicioInformationRequirement.setPhase(idrequisito5, Priority::DEVELOPMENT);
//PENDIENTES LAS RESTRICCIONES

auto indiceRequisitos = servicioHTML.index.createIndex("Catalogo de Requisitos del Sistema",0);
auto indiceRequisitosInformacion = servicioHTML.index.createIndex("Requisitos de Informacion",indiceRequisitos);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito1);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito2);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito3);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito4);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito5);

ServicioFunctionalRequirement servicioFunctionalRequirement;
auto idfrequsito1 = servicioFunctionalRequirement.createFunctionalRequirement("Boton de acceso directo a redes sociales");
servicioFunctionalRequirement.setVersionMajor(idfrequsito1,"1.0");
servicioFunctionalRequirement.setVersionMinor(idfrequsito1,"0.0");
servicioFunctionalRequirement.addAuthor(idfrequsito1,idStakeholder1);
servicioFunctionalRequirement.addAuthor(idfrequsito1,idStakeholder2);
servicioFunctionalRequirement.addAuthor(idfrequsito1,idStakeholder3);
servicioFunctionalRequirement.setDescription(idfrequsito1, "El sistema deberá contar con botones para acceder rápidamente a los métodos de contacto del artesano.");
servicioFunctionalRequirement.setImportanceLevel(idfrequsito1, Priority::HIGH);
servicioFunctionalRequirement.setUrgencyLevel(idfrequsito1, Priority::HIGH);
servicioFunctionalRequirement.setPhase(idfrequsito1, Priority::DEVELOPMENT);
auto idfrequsito2 = servicioFunctionalRequirement.createFunctionalRequirement("Generador de hojas de pedido");
servicioFunctionalRequirement.setVersionMajor(idfrequsito2,"1.0");
servicioFunctionalRequirement.setVersionMinor(idfrequsito2,"0.0");
servicioFunctionalRequirement.addAuthor(idfrequsito2,idStakeholder1);
servicioFunctionalRequirement.addAuthor(idfrequsito2,idStakeholder2);
servicioFunctionalRequirement.addAuthor(idfrequsito2,idStakeholder3);

ServicioRestrictionRequirement servicioRestrictionRequirement;
auto idrestriccion1 = servicioRestrictionRequirement.createRestrictionRequirement("Unicidad del email");
servicioRestrictionRequirement.setVersionMajor(idrestriccion1,"1.0");
servicioRestrictionRequirement.setVersionMinor(idrestriccion1,"0.0");
servicioRestrictionRequirement.addAuthor(idrestriccion1,idStakeholder1);
servicioRestrictionRequirement.addAuthor(idrestriccion1,idStakeholder2);
servicioRestrictionRequirement.addAuthor(idrestriccion1,idStakeholder3);
servicioRestrictionRequirement.setDescription(idrestriccion1, "La información almacenada por el sistema deberá satisfacer la siguiente restricción: los emails deberán ser únicos para cada cliente, es decir, no puede haber dos clientes distintos con el mismo email.");
servicioRestrictionRequirement.setImportanceLevel(idrestriccion1, Priority::HIGH);
servicioRestrictionRequirement.setUrgencyLevel(idrestriccion1, Priority::HIGH);
servicioRestrictionRequirement.setPhase(idrestriccion1, Priority::DEVELOPMENT);
auto idrestriccion2 = servicioRestrictionRequirement.createRestrictionRequirement("Unicidad NIF");
servicioRestrictionRequirement.setVersionMajor(idrestriccion2,"1.0");
servicioRestrictionRequirement.setVersionMinor(idrestriccion2,"0.0");
servicioRestrictionRequirement.addAuthor(idrestriccion2,idStakeholder1);
servicioRestrictionRequirement.addAuthor(idrestriccion2,idStakeholder2);
servicioRestrictionRequirement.addAuthor(idrestriccion2,idStakeholder3);
servicioRestrictionRequirement.setDescription(idrestriccion2, "La información almacenada por el sistema deberá satisfacer la siguiente restricción: los NIF deberán ser únicos para cada cliente, es decir, no puede haber dos clientes distintos con el mismo NIF.");
servicioRestrictionRequirement.setImportanceLevel(idrestriccion2, Priority::HIGH);
servicioRestrictionRequirement.setUrgencyLevel(idrestriccion2, Priority::HIGH);
servicioRestrictionRequirement.setPhase(idrestriccion2, Priority::DEVELOPMENT);



auto indicerequisitosfun = servicioHTML.index.createIndex("Requisitos Funcionales",indiceRequisitos);
servicioHTML.index.addElement(indiceRequisitos,idfrequsito1);
servicioHTML.index.addElement(indiceRequisitos,idfrequsito2);
servicioHTML.index.addElement(indiceRequisitos,idrestriccion1);
servicioHTML.index.addElement(indiceRequisitos,idrestriccion2);

ServicioActorUC servicioActor;
auto idActor1 = servicioActor.createActorUC("Cliente");
servicioActor.setVersionMajor(idActor1,"1.0");
servicioActor.setVersionMinor(idActor1,"0.0");
servicioActor.addAuthor(idActor1,idStakeholder2);
servicioActor.addAuthor(idActor1,idStakeholder3);
servicioActor.setDescription(idActor1, "El cliente es el usuario que accede a la aplicación para realizar pedidos.");

auto idActor2 = servicioActor.createActorUC("Asistente de artesano");
servicioActor.setVersionMajor(idActor2,"1.0");
servicioActor.setVersionMinor(idActor2,"0.0");
servicioActor.addAuthor(idActor2,idStakeholder2);
servicioActor.addAuthor(idActor2,idStakeholder3);
servicioActor.setDescription(idActor2, "El asistente de artesano es el usuario que accede a la aplicación para gestionar los pedidos. Debido a que el artesano no tiene conocimientos informáticos, el asistente de artesano es el encargado de gestionar los pedidos.");

auto indiceDigramasCU = servicioHTML.index.createIndex("Diagramas de Casos de Uso",indicerequisitosfun);
auto indiceActorUC = servicioHTML.index.createIndex("Definicion de actores",indicerequisitosfun);
servicioHTML.index.addElement(indiceActorUC,idActor1);
servicioHTML.index.addElement(indiceActorUC,idActor2);

ServicioUserCase servicioUseCase;

auto idUC1 = servicioUseCase.createUserCase("Alta Cliente");
servicioUseCase.setPrecondition(idUC1,"El cliente no está registrado en el sistema");
servicioUseCase.addAuthor(idUC1,idStakeholder2);
servicioUseCase.addAuthor(idUC1,idStakeholder3);
servicioUseCase.setDescription(idUC1,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando el Cliente pulse el botón de registrarse en la página web.");
servicioUseCase.setPostcondition(idUC1,"El cliente ya está registrado en el sistema y puede iniciar sesión");
servicioUseCase.setFrequency(idUC1,{20,TimeQuantity::MONTH});
servicioUseCase.setImportanceLevel(idUC1,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC1,Priority::HIGH);
servicioUseCase.setEstability(idUC1,Priority::STABLE);

servicioUseCase.addStep(idUC1, {false,"Accede a la página web",""});
servicioUseCase.setTypeStep(idUC1,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC1,0,idActor1);
servicioUseCase.addStep(idUC1, {false,"Introduce sus datos personales (nombre, apellidos, DNI, dirección, teléfono, correo electrónico, contraseña)",""});
servicioUseCase.setTypeStep(idUC1,1,type::ACTOR);
servicioUseCase.setReferenceStep(idUC1,1,idActor1);
servicioUseCase.addStep(idUC1, {false,"Crea una contraseña",""});
servicioUseCase.setTypeStep(idUC1,2,type::SYSTEM);
servicioUseCase.addStep(idUC1, {false,"El sistema comprueba que los datos introducidos son correctos y que el correo electrónico y el NIF no está registrado en el sistema",""});
servicioUseCase.setTypeStep(idUC1,3,type::ACTOR);
servicioUseCase.setReferenceStep(idUC1,3,idActor1);
servicioUseCase.addStep(idUC1, {false,"El sistema envía un correo electrónico de confirmación al cliente",""});
servicioUseCase.setTypeStep(idUC1,4,type::SYSTEM);
servicioUseCase.addStep(idUC1, {false,"El sistema guarda los datos del cliente",""});
Exception excep1 {4,SYSTEM,"El sistema muestra un mensaje de error y el caso de uso queda sin efecto","Si el nombre no tiene el formato correcto (se han añadido caracteres especiales)",""};
Exception excep2 {4,SYSTEM,"El sistema muestra un mensaje de error y el caso de uso queda sin efecto","Si el apellido no tiene el formato correcto (se han añadido caracteres especiales)",""};
Exception excep3 {4,SYSTEM,"El sistema muestra un mensaje de error y el caso de uso queda sin efecto","Si el correo electrónico no tiene el formato correcto (texto + @ + host + . + com) ",""};
Exception excep4 {4,SYSTEM,"El sistema muestra un mensaje de error y el caso de uso queda sin efecto","Si el correo electrónico ya está registrado en el sistema",""};
Exception excep5 {4,SYSTEM,"El sistema muestra un mensaje de error y el caso de uso queda sin efecto","Si el NIF está registrado en el sistema",""};
Exception excep6 {4,SYSTEM,"El sistema muestra un mensaje de error y el caso de uso queda sin efecto","Si el cliente no acepta las condiciones de uso",""};

servicioUseCase.addException(idUC1,excep1);
servicioUseCase.addException(idUC1,excep2);
servicioUseCase.addException(idUC1,excep3);
servicioUseCase.addException(idUC1,excep4);
servicioUseCase.addException(idUC1,excep5);
servicioUseCase.addException(idUC1,excep6);

auto idUC2 = servicioUseCase.createUserCase("Iniciar sesión");
servicioUseCase.setPrecondition(idUC2,"El cliente ya está registrado en el sistema");
servicioUseCase.addAuthor(idUC2,idStakeholder2);
servicioUseCase.addAuthor(idUC2,idStakeholder3);
servicioUseCase.setDescription(idUC2,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando el Cliente pulse el botón de iniciar sesión en la página web.");
servicioUseCase.setPostcondition(idUC2,"El cliente ya está registrado en el sistema y puede iniciar sesión");
servicioUseCase.setFrequency(idUC2,{20,TimeQuantity::MONTH});
servicioUseCase.setImportanceLevel(idUC2,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC2,Priority::HIGH);
servicioUseCase.setEstability(idUC2,Priority::STABLE);

servicioUseCase.addStep(idUC2, {false,"Accede a su perfil en la página web",""});
servicioUseCase.setTypeStep(idUC2,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC2,0,idActor1);
servicioUseCase.addStep(idUC2, {false,"Selecciona la opción \"Eliminar cuenta\"",""});
servicioUseCase.setTypeStep(idUC2,1,type::ACTOR);
servicioUseCase.setReferenceStep(idUC2,1,idActor1);
servicioUseCase.addStep(idUC2, {false,"Muestra mensaje de confirmación",""});
servicioUseCase.setTypeStep(idUC2,2,type::SYSTEM);
servicioUseCase.addStep(idUC2, {false,"Confirma que quiere darse de baja",""});
servicioUseCase.setTypeStep(idUC2,3,type::ACTOR);
servicioUseCase.setReferenceStep(idUC2,3,idActor1);

Exception exception2uc {4,SYSTEM,"El sistema muestra un mensaje de que su cuenta sigue siendo útil, a continuación este caso de uso queda sin efecto","Si no confirma que quiere darse de baja",""};
servicioUseCase.addException(idUC2,exception2uc);
auto idUC3 = servicioUseCase.createUserCase("Modificar datos de cliente");
servicioUseCase.setPrecondition(idUC3,"El Cliente debe estar dado de alta en la página y haber iniciado sesión.");
servicioUseCase.addAuthor(idUC3,idStakeholder2);
servicioUseCase.addAuthor(idUC3,idStakeholder3);
servicioUseCase.setDescription(idUC3,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando El Cliente pulsa el botón \"Modificar datos\"");
servicioUseCase.setPostcondition(idUC3,"El sistema guarda los datos del cliente modificados.");
servicioUseCase.setFrequency(idUC3,{10,TimeQuantity::MONTH});
servicioUseCase.setImportanceLevel(idUC3,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC3,Priority::HIGH);
servicioUseCase.setEstability(idUC3,Priority::STABLE);

servicioUseCase.addStep(idUC3, {false,"Entra en su perfil",""});
servicioUseCase.setTypeStep(idUC3,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC3,0,idActor1);
servicioUseCase.addStep(idUC3, {false,"Pulsa en la opción \"Modificar datos\"",""});
servicioUseCase.setTypeStep(idUC3,1,type::ACTOR);
servicioUseCase.setReferenceStep(idUC3,1,idActor1);
servicioUseCase.addStep(idUC3, {false,"Muestra los datos actuales del Cliente y da la opción de modificarlos",""});
servicioUseCase.setTypeStep(idUC3,2,type::SYSTEM);
servicioUseCase.addStep(idUC3, {false,"Valida los datos introducidos y los actualiza",""});
servicioUseCase.setTypeStep(idUC3,3,type::SYSTEM);

Exception exception3uc {4,SYSTEM,"El sistema muestra mensaje de error, a continuación este caso de uso queda sin efecto","Si los datos introducidos no siguen el formato correcto",""};
servicioUseCase.addException(idUC3,exception3uc);

auto idUC4 = servicioUseCase.createUserCase("Identificación de Cliente");
servicioUseCase.setPrecondition(idUC4,"El Cliente se ha dado de alta en el sistema.");
servicioUseCase.addAuthor(idUC4,idStakeholder2);
servicioUseCase.addAuthor(idUC4,idStakeholder3);
servicioUseCase.setDescription(idUC4,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando el Cliente quiere iniciar sesión.");
servicioUseCase.setPostcondition(idUC4,"El sistema identifica al cliente y le permite acceder a las funcionalidades de la página.");
servicioUseCase.setFrequency(idUC4,{40,TimeQuantity::MONTH});
servicioUseCase.setImportanceLevel(idUC4,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC4,Priority::HIGH);
servicioUseCase.setEstability(idUC4,Priority::STABLE);

servicioUseCase.addStep(idUC4, {false,"Inicia sesión con su correo electrónico y contraseña",""});
servicioUseCase.setTypeStep(idUC4,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC4,0,idActor1);
servicioUseCase.addStep(idUC4, {false,"Verifica las credenciales del Cliente y lo identifica en el sistema",""});
servicioUseCase.setTypeStep(idUC4,1,type::SYSTEM);
servicioUseCase.addStep(idUC4, {false,"Muestra las funcionalidades de la página para clientes con cuenta",""});
servicioUseCase.setTypeStep(idUC4,2,type::SYSTEM);

Exception exception4uc {1,SYSTEM,"El sistema muestra mensaje de error, a continuación este caso de uso queda sin efecto","Si el cliente introduce correo o contraseña incorrectas",""};
servicioUseCase.addException(idUC4,exception4uc);

Exception exception4uc1 {2,SYSTEM,"El sistema muestra mensaje de error, a continuación este caso de uso queda sin efecto","Si el cliente no está dado de alta",""};
servicioUseCase.addException(idUC4,exception4uc1);

auto idUC5 = servicioUseCase.createUserCase("Identificación de Cliente");
servicioUseCase.setPrecondition(idUC5,"El Cliente se ha dado de alta en el sistema.");
servicioUseCase.addAuthor(idUC5,idStakeholder2);
servicioUseCase.addAuthor(idUC5,idStakeholder3);
servicioUseCase.setDescription(idUC5,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando el Cliente quiere iniciar sesión.");
servicioUseCase.setPostcondition(idUC5,"El sistema identifica al cliente y le permite acceder a las funcionalidades de la página.");
servicioUseCase.setFrequency(idUC5,{40,TimeQuantity::MONTH});
servicioUseCase.setImportanceLevel(idUC5,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC5,Priority::HIGH);
servicioUseCase.setEstability(idUC5,Priority::STABLE);

servicioUseCase.addStep(idUC5, {false,"Inicia sesión con su correo electrónico y contraseña",""});
servicioUseCase.setTypeStep(idUC5,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC5,0,idActor1);
servicioUseCase.addStep(idUC5, {false,"Verifica las credenciales del Cliente y lo identifica en el sistema",""});
servicioUseCase.setTypeStep(idUC5,1,type::SYSTEM);
servicioUseCase.addStep(idUC5, {false,"Muestra las funcionalidades de la página para clientes con cuenta",""});
servicioUseCase.setTypeStep(idUC5,2,type::SYSTEM);

Exception exception5uc {1,SYSTEM,"El sistema muestra mensaje de error, a continuación este caso de uso queda sin efecto","Si el cliente introduce correo o contraseña incorrectas",""};
servicioUseCase.addException(idUC5,exception5uc);

Exception exception5uc1 {2,SYSTEM,"El sistema muestra mensaje de error, a continuación este caso de uso queda sin efecto","Si el cliente no está dado de alta",""};
servicioUseCase.addException(idUC5,exception5uc1);

servicioUseCase.addTraceTo(idUC1, idObjetivo5);
servicioUseCase.addTraceTo(idUC1, idObjetivo6);
servicioUseCase.addTraceTo(idUC2, idObjetivo5);
servicioUseCase.addTraceTo(idUC2, idObjetivo6);
servicioUseCase.addTraceTo(idUC4, idObjetivo5);
servicioUseCase.addTraceTo(idUC4, idObjetivo6);
servicioUseCase.addTraceTo(idUC5, idrequisito4);
servicioUseCase.setPackage(idUC1,"Gestion de clientes");
servicioUseCase.setPackage(idUC2,"Gestion de clientes");
servicioUseCase.setPackage(idUC3,"Gestion de clientes");
servicioUseCase.setPackage(idUC4,"Gestion de clientes");
servicioUseCase.setPackage(idUC5,"Gestion de clientes");


auto idUC6 = servicioUseCase.createUserCase();
servicioUseCase.setPrecondition(idUC6,"El producto no está registrado en el sistema.");
servicioUseCase.setPrecondition(idUC6,"El Asistente ha iniciado sesión en el sistema y es reconocido como tal.");
servicioUseCase.addAuthor(idUC6,idStakeholder2);
servicioUseCase.addAuthor(idUC6,idStakeholder3);
servicioUseCase.setDescription(idUC6,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando el Asistente quiere publicar un nuevo producto de esparto. Selecciona la opción de añadir nuevo producto.");
servicioUseCase.setPostcondition(idUC6,"El producto es creado y almacenado en el sistema.");
servicioUseCase.setFrequency(idUC6,{10,TimeQuantity::YEAR});
servicioUseCase.setImportanceLevel(idUC6,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC6,Priority::HIGH);
servicioUseCase.setEstability(idUC6,Priority::STABLE);

servicioUseCase.addStep(idUC6, {false,"El actor Pulsa en la sección Productos.",""});
servicioUseCase.setTypeStep(idUC6,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC6,0,idActor2);
servicioUseCase.addStep(idUC6, {false,"El actor selecciona la acción Añadir nuevo producto.",""});
servicioUseCase.setTypeStep(idUC6,1,type::ACTOR);
servicioUseCase.setReferenceStep(idUC6,1,idActor2);
servicioUseCase.addStep(idUC6, {false,"El sistema muestra la plantilla a rellenar para la publicación de ese producto.",""});
servicioUseCase.setTypeStep(idUC6,2,type::SYSTEM);
servicioUseCase.addStep(idUC6, {false,"El actor rellena la plantilla con nombre, precio, descripción y foto.",""});
servicioUseCase.setTypeStep(idUC6,3,type::ACTOR);
servicioUseCase.setReferenceStep(idUC6,3,idActor2);
servicioUseCase.addStep(idUC6, {false,"El sistema comprueba que la información introducida sigue el formato correcto, y crea el nuevo producto.",""});
servicioUseCase.setTypeStep(idUC6,4,type::SYSTEM);

Exception exception6uc {1,SYSTEM,"El sistema muestra mensaje de error, a continuación este caso de uso queda sin efecto","Si los datos introducidos tienen errores en el formato",""};
servicioUseCase.addException(idUC6,exception6uc);
servicioUseCase.addTraceTo(idUC6, idObjetivo4);
servicioUseCase.setPackage(idUC6,"Gestion de productos");


auto idUC7 = servicioUseCase.createUserCase();
servicioUseCase.setPrecondition(idUC7,"El producto a eliminar existe en el sistema.");
servicioUseCase.setPrecondition(idUC7,"El Asistente ha iniciado sesión en el sistema y es reconocido como tal.");
servicioUseCase.addAuthor(idUC7,idStakeholder3);
servicioUseCase.addAuthor(idUC7,idStakeholder2);
servicioUseCase.setDescription(idUC7,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando el asistente selecciona la opción de eliminar un producto de esparto.");
servicioUseCase.setPostcondition(idUC7,"El producto deja de estar registrado en el sistema.");
servicioUseCase.setFrequency(idUC7,{5,TimeQuantity::YEAR});
servicioUseCase.setImportanceLevel(idUC7,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC7,Priority::HIGH);
servicioUseCase.setEstability(idUC7,Priority::STABLE);

servicioUseCase.addStep(idUC7, {false,"El actor Asistente (ACT-0003) accede a la sección de Productos.",""});
servicioUseCase.setTypeStep(idUC7,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC7,0,idActor2);
servicioUseCase.addStep(idUC7, {false,"El actor Asistente busca el producto (con el idP) que quiere eliminar y lo selecciona.",""});
servicioUseCase.setTypeStep(idUC7,1,type::ACTOR);
servicioUseCase.setReferenceStep(idUC7,1,idActor2);
servicioUseCase.addStep(idUC7, {false,"El actor Asistente pulsa la opción Eliminar Producto.",""});
servicioUseCase.setTypeStep(idUC7,2,type::ACTOR);
servicioUseCase.setReferenceStep(idUC7,2,idActor2);
servicioUseCase.addStep(idUC7, {false,"El sistema muestra un mensaje de confirmación para eliminar el producto.",""});
servicioUseCase.setTypeStep(idUC7,3,type::SYSTEM);
servicioUseCase.addStep(idUC7, {false,"El actor Asistente confirma que quiere eliminar el producto.",""});
servicioUseCase.setTypeStep(idUC7,4,type::ACTOR);
servicioUseCase.setReferenceStep(idUC7,4,idActor2);
servicioUseCase.addStep(idUC7, {false,"El sistema elimina el producto de la página web.",""});
servicioUseCase.setTypeStep(idUC7,5,type::SYSTEM);

Exception exception7uc {1,SYSTEM,"El sistema no elimina el producto, a continuación este caso de uso queda sin efecto","Si El Asistente no confirma la eliminación del producto",""};
servicioUseCase.addException(idUC7,exception7uc);
servicioUseCase.addTraceTo(idUC7, idObjetivo4);
servicioUseCase.setPackage(idUC7,"Gestion de productos");

auto idUC8 = servicioUseCase.createUserCase();
servicioUseCase.setPrecondition(idUC8,"El Asistente tiene que estar registrado e identificado como tal. El producto debe estar registrado en el sistema.");
servicioUseCase.addAuthor(idUC8,idStakeholder3);
servicioUseCase.addAuthor(idUC8,idStakeholder2);
servicioUseCase.setDescription(idUC8,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando el asistente quiere consultar un producto en específico y entra en la sección Productos.");
servicioUseCase.setPostcondition(idUC8,"El Asistente visualiza los detalles de un producto.");
servicioUseCase.setFrequency(idUC8,{10,TimeQuantity::MONTH});
servicioUseCase.setImportanceLevel(idUC8,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC8,Priority::HIGH);
servicioUseCase.setEstability(idUC8,Priority::STABLE);

servicioUseCase.addStep(idUC8, {false,"El actor Asistente accede a la sección de Productos.",""});
servicioUseCase.setTypeStep(idUC8,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC8,0,idActor2);
servicioUseCase.addStep(idUC8, {false,"El actor Asistente busca el producto que quiere consultar y lo selecciona.",""});
servicioUseCase.setTypeStep(idUC8,1,type::ACTOR);
servicioUseCase.setReferenceStep(idUC8,1,idActor2);
servicioUseCase.addStep(idUC8, {false,"El sistema muestra los detalles del producto seleccionado: precio, descripción, tamaño...",""});
servicioUseCase.setTypeStep(idUC8,2,type::SYSTEM);

servicioUseCase.addTraceTo(idUC8, idObjetivo1);
servicioUseCase.addTraceTo(idUC8, idObjetivo4);
servicioUseCase.setPackage(idUC8,"Gestion de productos");


auto idUC9 = servicioUseCase.createUserCase();
servicioUseCase.setPrecondition(idUC9,"El Cliente tiene que estar registrado en la página web y haber iniciado sesión.");
servicioUseCase.addAuthor(idUC9,idStakeholder1);
servicioUseCase.addAuthor(idUC9,idStakeholder2);
servicioUseCase.setDescription(idUC9,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando el Cliente quiere realizar un pedido customizado.");
servicioUseCase.setPostcondition(idUC9,"Se registra un boceto personalizado.");
servicioUseCase.setFrequency(idUC9,{5,TimeQuantity::DAY});
servicioUseCase.setImportanceLevel(idUC9,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC9,Priority::HIGH);
servicioUseCase.setEstability(idUC9,Priority::STABLE);

servicioUseCase.addStep(idUC9, {false,"El actor Cliente entra en la sección de peronalizar pedido.",""});
servicioUseCase.setTypeStep(idUC9,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC9,0,idActor1);
servicioUseCase.addStep(idUC9, {false,"El sistema muestra las opciones de personalización.",""});
servicioUseCase.setTypeStep(idUC9,1,type::SYSTEM);
servicioUseCase.addStep(idUC9, {false,"El actor Cliente elije las medidas y productos disponibles, y crea una hoja de un pedido que quiere.",""});
servicioUseCase.setTypeStep(idUC9,2,type::ACTOR);
servicioUseCase.setReferenceStep(idUC9,2,idActor1);
servicioUseCase.addStep(idUC9, {false,"El sistema guarda el boceto y lo deja para posibles consultas o para enviarlo. Da la opción de descarga también.",""});
servicioUseCase.setTypeStep(idUC9,3,type::SYSTEM);

servicioUseCase.addTraceTo(idUC9, idObjetivo2);

servicioUseCase.setPackage(idUC9,"Gestion de pedidos");

auto idUC10 = servicioUseCase.createUserCase();
servicioUseCase.setPrecondition(idUC10,"El Cliente tiene que estar registrado en la página web y haber iniciado sesión.");
servicioUseCase.addAuthor(idUC10,idStakeholder1);
servicioUseCase.addAuthor(idUC10,idStakeholder2);
servicioUseCase.setDescription(idUC10,"El sistema deberá comportarse tal como se describe en el siguiente caso de uso cuando el Cliente quiere realizar un pedido.");
servicioUseCase.setPostcondition(idUC10,"Se redirecciona a WhatsApp el pedido realizado y la factura o presupuesto dependiendo del tipo de pedido.");
servicioUseCase.setFrequency(idUC10,{5,TimeQuantity::DAY});
servicioUseCase.setImportanceLevel(idUC10,Priority::HIGH);
servicioUseCase.setUrgencyLevel(idUC10,Priority::HIGH);
servicioUseCase.setEstability(idUC10,Priority::STABLE);

servicioUseCase.addStep(idUC10, {false,"El actor Cliente selecciona los productos ( de la página o personalizados) que quiere comprar.",""});
servicioUseCase.setTypeStep(idUC10,0,type::ACTOR);
servicioUseCase.setReferenceStep(idUC10,0,idActor1);
servicioUseCase.addStep(idUC10, {false,"El actor Cliente selecciona la opción de hacer un envío.",""});
servicioUseCase.setTypeStep(idUC10,1,type::ACTOR);
servicioUseCase.setReferenceStep(idUC10,1,idActor1);
servicioUseCase.addStep(idUC10, {false,"El sistema muestra los detalles del envío, y pide la confirmación del Cliente.",""});
servicioUseCase.setTypeStep(idUC10,2,type::SYSTEM);
servicioUseCase.addStep(idUC10, {false,"El actor Cliente confirma el pedido.",""});
servicioUseCase.setTypeStep(idUC10,3,type::ACTOR);
servicioUseCase.setReferenceStep(idUC10,3,idActor1);
servicioUseCase.addStep(idUC10, {false,"El sistema manda al WhastApp del espartero la información de todo el pedido.",""});
servicioUseCase.setTypeStep(idUC10,4,type::SYSTEM);
servicioUseCase.addStep(idUC10, {false,"El actor Cliente ya puede ponerse en contacto con el espartero y concretar los detalles de entrega.",""});
servicioUseCase.setTypeStep(idUC10,5,type::ACTOR);
servicioUseCase.setReferenceStep(idUC10,5,idActor1);

servicioUseCase.addTraceTo(idUC10, idObjetivo3);
servicioUseCase.addTraceTo(idUC10, idObjetivo6);
servicioUseCase.addTraceTo(idUC10, idObjetivo2);

servicioUseCase.setPackage(idUC10,"Gestion de pedidos");

auto indiceCU = servicioHTML.index.createIndex("Casos de uso",indicerequisitosfun);
auto indiceCU1 = servicioHTML.index.createIndex("Casos de uso del subsistema de gestion de clientes",indiceCU);
auto indiceCU2 = servicioHTML.index.createIndex("Casos de uso del subsistema de gestion de productos",indiceCU);
auto indiceCU3 = servicioHTML.index.createIndex("Casos de uso del subsistema de gestion de pedidos",indiceCU);
servicioHTML.index.addElement(indiceCU1,idUC1);
servicioHTML.index.addElement(indiceCU1,idUC2);
servicioHTML.index.addElement(indiceCU1,idUC3);
servicioHTML.index.addElement(indiceCU1,idUC4);
servicioHTML.index.addElement(indiceCU1,idUC5);

servicioHTML.index.addElement(indiceCU2,idUC6);
servicioHTML.index.addElement(indiceCU2,idUC7);
servicioHTML.index.addElement(indiceCU2,idUC8);

servicioHTML.index.addElement(indiceCU3,idUC9);
servicioHTML.index.addElement(indiceCU3,idUC10);

ServicioNonFunctionalRequirement servicioNFR;

auto idnf1 = servicioNFR.createNonFunctionalRequirement("Portabilidad");
servicioNFR.addAuthor(idnf1,idStakeholder3);
servicioNFR.addAuthor(idnf1,idStakeholder2);
servicioNFR.setDescription(idnf1,"El sistema debe ser capaz de funcionar en cualquier dispositivo.");
servicioNFR.setImportanceLevel(idnf1,Priority::HIGH);
servicioNFR.setUrgencyLevel(idnf1,Priority::HIGH);
servicioNFR.setEstability(idnf1,Priority::STABLE);
servicioNFR.setPhase(idnf1,Priority::DEVELOPMENT);

auto idnf2 = servicioNFR.createNonFunctionalRequirement("Control de Clientes");
servicioNFR.addAuthor(idnf2,idStakeholder1);
servicioNFR.addAuthor(idnf2,idStakeholder2);
servicioNFR.setDescription(idnf2,"El sistema debe ser capaz de controlar los clientes. Solo el asistente puede acceder a los datos de los clientes.");
servicioNFR.setImportanceLevel(idnf2,Priority::HIGH);
servicioNFR.setUrgencyLevel(idnf2,Priority::HIGH);
servicioNFR.setEstability(idnf2,Priority::STABLE);
servicioNFR.setPhase(idnf2,Priority::DEVELOPMENT);

auto indiceRequisitosNoFuncionales = servicioHTML.index.createIndex("Requisitos no funcionales",indiceRequisitos);
servicioHTML.index.addElement(indiceRequisitosNoFuncionales,idnf1);
servicioHTML.index.addElement(indiceRequisitosNoFuncionales,idnf2);

ServicioMatrixTraces servicioMatrixTraces;
auto idm = servicioMatrixTraces.createMatrixTraces("Matriz de rastreabilidad Objetivos/Requisitos");
servicioMatrixTraces.addPrefixTo(idm, SystemObjective::getPrefixID());
servicioMatrixTraces.addPrefixFrom(idm, NonFunctionalRequirement::getPrefixID());
servicioMatrixTraces.addPrefixFrom(idm, FunctionalRequirement::getPrefixID());
servicioMatrixTraces.addPrefixFrom(idm, InformationRequirement::getPrefixID());
servicioMatrixTraces.addPrefixFrom(idm, RestrictionRequirement::getPrefixID());

servicioMatrixTraces.addTrackeable(idm, idObjetivo1);
servicioMatrixTraces.addTrackeable(idm, idObjetivo2);
servicioMatrixTraces.addTrackeable(idm, idObjetivo3);
servicioMatrixTraces.addTrackeable(idm, idObjetivo4);
servicioMatrixTraces.addTrackeable(idm, idObjetivo5);
servicioMatrixTraces.addTrackeable(idm, idObjetivo6);
servicioMatrixTraces.addTrackeable(idm, idnf1);
servicioMatrixTraces.addTrackeable(idm, idnf2);
servicioMatrixTraces.addTrackeable(idm, idrequisito1);
servicioMatrixTraces.addTrackeable(idm, idrequisito2);
servicioMatrixTraces.addTrackeable(idm, idrequisito3);
servicioMatrixTraces.addTrackeable(idm, idrequisito4);
servicioMatrixTraces.addTrackeable(idm, idrequisito5);
servicioMatrixTraces.addTrackeable(idm, idrestriccion1);
servicioMatrixTraces.addTrackeable(idm, idrestriccion2);
servicioMatrixTraces.addTrackeable(idm, idfrequsito1);
servicioMatrixTraces.addTrackeable(idm, idfrequsito2);

servicioInformationRequirement.addTraceTo(idrequisito1, idObjetivo4);
servicioInformationRequirement.addTraceTo(idrequisito2, idObjetivo3);
servicioInformationRequirement.addTraceTo(idrequisito4, idObjetivo2);
servicioInformationRequirement.addTraceTo(idrequisito4, idObjetivo5);
servicioInformationRequirement.addTraceTo(idrequisito4, idObjetivo6);
servicioRestrictionRequirement.addTraceTo(idrestriccion1, idObjetivo5);
servicioRestrictionRequirement.addTraceTo(idrestriccion1, idObjetivo6);
servicioRestrictionRequirement.addTraceTo(idrestriccion2, idObjetivo5);
servicioRestrictionRequirement.addTraceTo(idrestriccion2, idObjetivo6);
servicioFunctionalRequirement.addTraceTo(idfrequsito1, idObjetivo3);
servicioFunctionalRequirement.addTraceTo(idfrequsito2, idObjetivo2);


auto indiceMatrix = servicioHTML.index.createIndex("Matriz de rastreabilidad Objetivos/Requisitos",0);
servicioHTML.index.addElement(indiceMatrix,idm);

auto idGlosario = servicioText.createText("Glosario");
servicioText.setDescription(idGlosario,"Esparto: Hoja de esta planta, radical, larga, dura, resistente y tan arrollada sobre sí que parece tener forma de hilo.\n"
                                       "\n"
                                       "Pleita: Faja o tira de esparto, palma, pita u otros ramales entretejidos que, cosida con otras, se utiliza para hacer sombreros, esteras, etc.\n"
                                       "");
auto indiceGlo = servicioHTML.index.createIndex("Glosario de terminos",0);
servicioHTML.index.addElement(indiceGlo,idGlosario);
    auto idEntrevista = servicioText.createText("Entrevista");

servicioText.setDescription(idEntrevista,"Esta es la entrevista para Ingeniería de Requisitos, él es Antonio López, el espartero de Chiclana, y vamos a realizarle algunas preguntas para analizar el posible software a desarrollar. Empezamos por la primera. \n"
                                         "\n"
                                         "-¿Cuál es el problema o necesidad específica que está buscando solucionar con una aplicación? \n"
                                         "\n"
                                         "Pues lo que es el tema de cómo arreglaría tantas preguntas, como todo el mundo me pregunta, ¿qué artículo tiene usted? Pues poderlo llevar a redes sociales que no me hagan la pregunta, que simplemente lo veáis, y sigan, evidentemente, a lo que es el artículo que le interese. \n"
                                         "\n"
                                         "-¿Hay algún otro intento previo de solucionar este problema o de una aplicación? Si es así, ¿por qué falló? \n"
                                         "\n"
                                         "Se hizo, pero se hizo de cuatro artículos, nada más, o cinco artículos, después se hizo mal. No se detallaron los precios, no, en fin, falló el completo. Estaba mal hecho, cuando una cosa está mal hecha, está mal hecha. Y entonces, ya luego hemos ido rebotando a todo el mundo por WhatsApp, y es donde no hemos defendido, pero que por WhatsApp tampoco es. \n"
                                         "\n"
                                         "-Es decir, ¿que la comunicación de pasarle los productos va por WhatsApp? \n"
                                         "\n"
                                         "Sí, ahora mismo sí, es la solución que hay. A no ser que hubiera lo que es una buena página web, una buena fórmula de que el cliente directamente lo hubiera, pero claro, siempre tendría que contactar conmigo, puesto que somos una persona no más fabricando, no tenemos capacidad de vender por encima de la web, si no nos saturan. \n"
                                         "\n"
                                         "-¿Cómo describiría el proceso del trabajo del artesano? \n"
                                         "\n"
                                         "Eso es manual, eso no tiene más historia, aguja y cuerda y vámonos. \n"
                                         "\n"
                                         "-Quiero decir, pero desde que el cliente te contacta a ti hasta que llega, ¿cómo el cliente te llega a contactar a ti? ¿Cómo haces tú que el producto le llega al cliente? ¿Cuál es todo el proceso ahí? \n"
                                         "\n"
                                         "\n"
                                         "Simplemente, mensajería, empaqueto, preparo, mensajería, envío, dirección de envío, lo que es con los códigos postales y demás hoy en día no se pierde ningún producto, además, todos, todos, todos quedan grabados y si hay una incidencia, lo recuperas en 30 segundos. \n"
                                         "\n"
                                         "\n"
                                         "\n"
                                         "-¿Hay algún otro usuario, otra persona que debe interactuar con la página, además de tú? \n"
                                         "\n"
                                         "Ahora mismo, cuando me hace falta lo que es el tema de facturación o algo, yo tengo la agencia, o sea, la agencia, la gestoría que ellos mismos me gestionan la parte de documento o si me hiciera falta de que por ejemplo cualquier proyecto que me pidieran de ingenería por algo, me hicieran falta de que me la aclararan, tengo mi gestoría que me hace lo que me hiciera falta. Es la parte técnica. \n"
                                         "\n"
                                         "-Pero entonces la gestoría que es la que lleva los papeles legales, ¿es la que tú querrías que te rellenara los tipos de productos en la página web? \n"
                                         "\n"
                                         "Es que hoy en día, para ser el proveedor de muchas empresas, te piden cosas que a mí me suenan los nombres a chino. Entonces lo mejor que hago cuando me entro en una empresa, por ejemplo, como ha pasado últimamente con televisión. Televisión Española me pedía hasta mi fecha de nacimiento pero de todo. ¿Qué hice? Mire usted, tome usted el número de teléfono de mi gestoría y las chavalas en las gestorías se encargaron de todo y no hubo problema ninguno. Cuando nos ha tocado el extranjero que lleva números de clave de exportación distinto, pues me ha pasado igual y hemos podido lamentar que me han pedido al mundo entero, le hemos podido enviar lo que pasa que hay ciertos puntos del mundo que son más caros o menos caros pero por enviarlo puedes enviar donde quieras. \n"
                                         "\n"
                                         "-¿Cómo querría que fuese el acceso a la web desde tu parte? ¿Es decir como administrador y dueño de ello o simplemente como usuario más? \n"
                                         "\n"
                                         "No, por la parte de lo que es de administrador te vuelvo a decir lo mismo en la web, simplemente me haría falta a mí, informativa con idea de que automáticamente hiciera igual que hace todo lo poquito que tengo de redes sociales. Hable usted con Antonio por WhatsApp. A mi me gusta que me llegue a mí y me explique porque si no no hay forma de llevar, porque esto es totalmente construido a mano todos son diferentes pero todos son parecidos. \n"
                                         "\n"
                                         "-Claro, pero ponte que en un año no aparece en la página web, por ejemplo, un producto nuevo y tienes que añadirlo tú. \n"
                                         "\n"
                                         "Sí. Socorro. Socorro. Buscaría la gestoría o buscaría alguien. \n"
                                         "\n"
                                         "-Ok. Cuando me atasco hay que pedir socorro, eso es muy lógico en la vida. \n"
                                         "\n"
                                         "-¿Hay algo en concreto, alguna característica que quieres que la aplicación o la página web pueda hacer por ti más que lo comentado hasta ahora de que informe al cliente hay algo más aparte de eso? \n"
                                         "\n"
                                         "La verdad es que lo desconozco por el tema que yo no sé si la página web se podría enviar lo que eran vídeos constructivos, o sea, vídeos de como enlazar que como lo desconozco el tema de las redes sociales, esa parte sería a la par que vas haciendo, fraccionar este tramo. Y después, unirlo todo para mandárselo al cliente. De conocimiento ahí no llego, pero sería muy bonito poder hacer cuadros enteros de la elaboración. La elaboración completa de su trabajo. O sea, que el cliente tenga un seguimiento de producto exacto. \n"
                                         "\n"
                                         "\n"
                                         "-¿Hay alguna restricción en cuanto al costo o tiempo necesario para desarrollar la aplicación o la página web? \n"
                                         "\n"
                                         "No. Simplemente no. Ni por requisitos ni por poder o no poder no tengo problema. \n"
                                         "\n"
                                         "-¿Te interesa que en la aplicación haya un perfil de comunicaciones para este tipo de cosas como una revista, un certamen, un concurso? \n"
                                         "\n"
                                         "Ah, si me gusta pero al final no hago caso nunca. Me gusta que me inviten a todos lados a todos los certamenes, de España entera de todos lados y no voy a ningún lado. \n"
                                         "\n"
                                         "-¿Y cuándo es que tú vas? \n"
                                         "\n"
                                         "No voy. Cuando es que voy es porque tengo a veces necesidad de salir del agobio del taller, simplemente programo cualquier cliente en la entrega y hago la entrega en cualquier punto de España o en cualquier punto de... Cuidado, que capaz de hacerla hasta afuera por decir, me voy un poquito. \n"
                                         "\n"
                                         "-Te hace falta una aplicación que cosa esparto. \n"
                                         "\n"
                                         "No, hombre. \n"
                                         "\n"
                                         "-Este es el final de la entrevista a Antonio López. Muchas gracias por colaborar. \n"
                                         "\n"
                                         "Para mi no ha sido problema ninguno al revés. Para lo que queráis. \n"
                                         "\n"
                                         "-Pues nada, muchas gracias. \n"
                                         "\n"
                                         "A ustedes.");
    auto indiceEntrevista = servicioHTML.index.createIndex("Entrevista",0);
    servicioHTML.index.addElement(indiceEntrevista,idEntrevista);

servicioHTML.printHTML();



}
int main() {
        std::vector<std::string> filenames = {
                "TX1.html","SH1.html","SH2.html","SH3.html","OR1.html","OR2.html",
                "TX2.html","SO1.html","SO2.html","SO3.html","SO4.html","SO5.html",
                "SO6.html","FR1.html","FR2.html","RR1.html","RR2.html","IR1.html",
                "IR2.html","IR3.html","IR4.html","IR5.html","AC1.html","AC2.html",
                "UC1.html","UC2.html","UC3.html","UC4.html","UC5.html","UC6.html",
                "UC7.html","UC8.html","UC9.html","UC10.html","NF1.html","NF2.html",
                "MT1.html","TX3.html","TX4.html"
        };

        std::vector<OID> objects;

        for (const std::string& filename : filenames) {
            std::string name = filename.substr(0, filename.find(".html"));
            objects.emplace_back(name, 0);  // You can replace 0 with the desired unsigned int ID
        }
        ServicioHTML servicioHTML;
        servicioHTML.index.createIndex("Entrevista",0);

}
       /* std::vector<std::string> filenames = {
        "TX1.html","SH1.html","SH2.html","SH3.html","OR1.html","OR2.html",
        "TX2.html","SO1.html","SO2.html","SO3.html","SO4.html","SO5.html",
        "SO6.html","FR1.html","FR2.html","RR1.html","RR2.html","IR1.html",
        "IR2.html","IR3.html","IR4.html","IR5.html","AC1.html","AC2.html",
        "UC1.html","UC2.html","UC3.html","UC4.html","UC5.html","UC6.html",
        "UC7.html","UC8.html","UC9.html","UC10.html","NF1.html","NF2.html",
        "MT1.html","TX3.html","TX4.html"
    };*/
       std::vector<OID> objects;


ServicioHTML servicioHTML;
auto indiceIntroduccion = servicioHTML.index.createIndex("Introduccion",0);
servicioHTML.index.addElement(indiceIntroduccion,idTexto1);
auto indiceParticipantes = servicioHTML.index.createIndex("Participantes",0);
servicioHTML.index.addElement(indiceParticipantes,idStakeholder1);
servicioHTML.index.addElement(indiceParticipantes,idStakeholder2);
servicioHTML.index.addElement(indiceParticipantes,idStakeholder3);
servicioHTML.index.addElement(indiceParticipantes,idOrg1);
servicioHTML.index.addElement(indiceParticipantes,idOrg2);
auto indiceDescripcion = servicioHTML.index.createIndex("Descripcion del sistema actual",0);
servicioHTML.index.addElement(indiceDescripcion,idDescripcion);
auto indiceObjetivos = servicioHTML.index.createIndex("Objetivos del sistema",0);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo1);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo2);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo3);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo4);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo5);
servicioHTML.index.addElement(indiceObjetivos,idObjetivo6);
auto indiceRequisitos = servicioHTML.index.createIndex("Catalogo de Requisitos del Sistema",0);
auto indiceRequisitosInformacion = servicioHTML.index.createIndex("Requisitos de Informacion",indiceRequisitos);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito1);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito2);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito3);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito4);
servicioHTML.index.addElement(indiceRequisitosInformacion,idrequisito5);
auto indicerequisitosfun = servicioHTML.index.createIndex("Requisitos Funcionales",indiceRequisitos);
servicioHTML.index.addElement(indiceRequisitos,idfrequsito1);
servicioHTML.index.addElement(indiceRequisitos,idfrequsito2);
servicioHTML.index.addElement(indiceRequisitos,idrestriccion1);
servicioHTML.index.addElement(indiceRequisitos,idrestriccion2);
auto indiceDigramasCU = servicioHTML.index.createIndex("Diagramas de Casos de Uso",indicerequisitosfun);
auto indiceActorUC = servicioHTML.index.createIndex("Definicion de actores",indicerequisitosfun);
servicioHTML.index.addElement(indiceActorUC,idActor1);
servicioHTML.index.addElement(indiceActorUC,idActor2);
auto indiceCU = servicioHTML.index.createIndex("Casos de uso",indicerequisitosfun);
auto indiceCU1 = servicioHTML.index.createIndex("Casos de uso del subsistema de gestion de clientes",indiceCU);
auto indiceCU2 = servicioHTML.index.createIndex("Casos de uso del subsistema de gestion de productos",indiceCU);
auto indiceCU3 = servicioHTML.index.createIndex("Casos de uso del subsistema de gestion de pedidos",indiceCU);
servicioHTML.index.addElement(indiceCU1,idUC1);
servicioHTML.index.addElement(indiceCU1,idUC2);
servicioHTML.index.addElement(indiceCU1,idUC3);
servicioHTML.index.addElement(indiceCU1,idUC4);
servicioHTML.index.addElement(indiceCU1,idUC5);
servicioHTML.index.addElement(indiceCU2,idUC6);
servicioHTML.index.addElement(indiceCU2,idUC7);
servicioHTML.index.addElement(indiceCU2,idUC8);
servicioHTML.index.addElement(indiceCU3,idUC9);
servicioHTML.index.addElement(indiceCU3,idUC10);
auto indiceRequisitosNoFuncionales = servicioHTML.index.createIndex("Requisitos no funcionales",indiceRequisitos);
servicioHTML.index.addElement(indiceRequisitosNoFuncionales,idnf1);
servicioHTML.index.addElement(indiceRequisitosNoFuncionales,idnf2);
auto indiceMatrix = servicioHTML.index.createIndex("Matriz de rastreabilidad Objetivos/Requisitos",0);
servicioHTML.index.addElement(indiceMatrix,idm);
auto indiceGlo = servicioHTML.index.createIndex("Glosario de terminos",0);
servicioHTML.index.addElement(indiceGlo,idGlosario);
auto indiceEntrevista = servicioHTML.index.createIndex("Entrevista",0);
servicioHTML.index.addElement(indiceEntrevista,idEntrevista);
servicioHTML.printHTML();
ServicioHTML servicioHTML;
servicioHTML.index.createIndex("Entrevista",0);




