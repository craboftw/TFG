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
        servicio.setAbstract(id, 1, true);
        servicio.setCondition(id, 0, "Condición modificada");
        servicio.setComments(id, 1, "Comentarios modificados");
        servicio.setDescription(id, 1, "Descripción modificada");

        // Establecer propiedades de un paso específico
        servicio.setType(id, 0, INCLUDE);
        OID id2 = {"UC",id.getId()-1};
        servicio.setReference(id, 0, OID(id2));

    OID id3 = {"UC",id.getId()-2};
        servicio.setType(id, 1, EXTEND);
        servicio.setReference(id, 1, OID(id3));


        // Obtener propiedades de un paso específico
        bool isAbstractStep = servicio.getAbstract(id, 1);
        std::cout << "Abstracto: " << std::boolalpha << isAbstractStep << std::endl;
        std::string condition = servicio.getCondition(id, 0);
        std::cout << "Condición: " << condition << std::endl;
        std::string comments = servicio.getComments(id, 1);
        std::cout << "Comentarios: " << comments << std::endl;
        std::string description = servicio.getDescription(id, 1);
        std::cout << "Descripción: " << description << std::endl;
        type type = servicio.getType(id, 0);
        std::cout << "Tipo: " << type << std::endl;
        OID reference = servicio.getReference(id, 0);
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


int main() {
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



    return 0 ;
}







