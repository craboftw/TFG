#include "Servicio/ServicioActorUC.h"
#include "Servicio/ServicioGeneric.h"
#include "Servicio/ServicioInformationRequirement.h"
#include "dialog.h"

#include <QApplication>
#include "Servicio/ServicioOrganization.h"
#include "HTML/ServicioHTML.h"
#include "Dominio/Generic.h"
#include "Dominio/InformationRequirement.h"
#include "Servicio/ServicioUserCase.h"
#include "Servicio/ServicioMatrixTraces.h"
#include "HTML/ServicioHTML.h"
#include "Servicio/ServicioDiagramUC.h"
#include "Servicio/ServicioInterview.h"
#include "Servicio/ServicioPersona.h"
#include "Servicio/ServicioStakeholder.h"
#include "OID.h"

void prueba()
{

 ServicioHTML servicioHTML;
 ServicioText servicioText;
 auto idIndice = servicioHTML.createIndex("DERS Esparto web");
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
 auto indiceIntroduccion = servicioHTML.createEntry(idIndice,"Introduccion",     0);
 servicioHTML.addElement(idIndice,indiceIntroduccion,idTexto1);

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
auto indiceParticipantes = servicioHTML.createEntry(idIndice,"Participantes",     0);
servicioHTML.addElement(idIndice,indiceParticipantes,idStakeholder1);
servicioHTML.addElement(idIndice,indiceParticipantes,idStakeholder2);
servicioHTML.addElement(idIndice,indiceParticipantes,idStakeholder3);
servicioHTML.addElement(idIndice,indiceParticipantes,idOrg1);
servicioHTML.addElement(idIndice,indiceParticipantes,idOrg2);

    servicioHTML.addAuthor(idIndice, idStakeholder2);
    servicioHTML.addAuthor(idIndice, idStakeholder3);


auto idDescripcion = servicioText.createText("Descripcion");

        servicioText.setDescription(idDescripcion,"El negocio del esparto al que nos referimos está solo llevado por Antonio López, un hombre que trabaja solo y no está del todo acostumbrado a las nuevas tecnologías. Esto hace que su sistema de venta de productos de espartos se limite solo a la comunicación por WhatsApp o llamada, haciendo que sea más lenta la venta. Es decir, el cliente contacta con Antonio López, éste hace un boceto del pedido, lo manda, espera confirmación, y si todo está bien se procede a la venta. Si son necesarios cambios este proceso se retrasa más de lo necesario. \n"
                            "\n"
                            "Nos encontramos también con el problema de que todos los datos se guardan a papel, o en los contactos de Antonio López, lo que acaba siendo muy confuso también para él. Hay que buscar manualmente a todos los contactos en caso de haber algún problema. Si pasase cualquier cosa con el móvil de Antonio López todos los clientes estarían perdidos. " );
auto indiceDescripcion = servicioHTML.createEntry(idIndice,"Descripcion del sistema actual",     0);
servicioHTML.addElement(idIndice,indiceDescripcion,idDescripcion);

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

auto indiceObjetivos = servicioHTML.createEntry(idIndice,"Objetivos del sistema",     0);
servicioHTML.addElement(idIndice,indiceObjetivos,idObjetivo1);
servicioHTML.addElement(idIndice,indiceObjetivos,idObjetivo2);
servicioHTML.addElement(idIndice,indiceObjetivos,idObjetivo3);
servicioHTML.addElement(idIndice,indiceObjetivos,idObjetivo4);
servicioHTML.addElement(idIndice,indiceObjetivos,idObjetivo5);
servicioHTML.addElement(idIndice,indiceObjetivos,idObjetivo6);

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

auto indiceRequisitos = servicioHTML.createEntry(idIndice,"Catalogo de Requisitos del Sistema",     0);
auto indiceRequisitosInformacion = servicioHTML.createEntry(idIndice,"Requisitos de Informacion",indiceRequisitos);
servicioHTML.addElement(idIndice,indiceRequisitosInformacion,idrequisito1);
servicioHTML.addElement(idIndice,indiceRequisitosInformacion,idrequisito2);
servicioHTML.addElement(idIndice,indiceRequisitosInformacion,idrequisito3);
servicioHTML.addElement(idIndice,indiceRequisitosInformacion,idrequisito4);
servicioHTML.addElement(idIndice,indiceRequisitosInformacion,idrequisito5);

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

ServicioPersona servicioPersona;
    OID antonioId = servicioPersona.createPersona("Antonio López");

    // Configuramos los atributos de Antonio López
    servicioPersona.setAge(antonioId, 60);
   // servicioPersona.setPhoto(antonioId, "fotonMano.jpg")      ;
    servicioPersona.setGender(antonioId, "Masculino"); // Género asumido masculino
    servicioPersona.setLocation(antonioId, "Chiclana");
    servicioPersona.setOccupation(antonioId, "Espartero");
    servicioPersona.setBackground(antonioId, "Artesano");
    servicioPersona.setGoals(antonioId, "Poder llevar sus productos a redes sociales para que los clientes puedan verlos y seguirlos.");
    servicioPersona.setChallenges(antonioId, "Encontrar una solución que permita mostrar sus productos en redes sociales sin que lo saturen de preguntas.");
    servicioPersona.setBehavior(antonioId, "Realiza trabajos manuales de espartería.");
    servicioPersona.setCommunicationStyle(antonioId, "Prefiere que los clientes le contacten por WhatsApp.");
    servicioPersona.setTechnologyAdoption(antonioId, "No tiene mucha experiencia en tecnología.");
    servicioPersona.setInfluences(antonioId, "Su gestoría le ayuda en temas legales y de facturación.");
    servicioPersona.setInformationSources(antonioId, "Desconoce cómo funcionan las redes sociales.");
    servicioPersona.setUserJourney(antonioId, "Los clientes le contactan por WhatsApp, él prepara y envía los productos por mensajería.");
    servicioPersona.setBrandRelationship(antonioId, "Le gustaría tener una web informativa y una página de redes sociales para mostrar sus productos.");

    auto idPersona = servicioHTML.createEntry(idIndice,"Antonio López",0);
    servicioHTML.addElement(idIndice,idPersona,antonioId);

auto indicerequisitosfun = servicioHTML.createEntry(idIndice,"Requisitos Funcionales",indiceRequisitos);
servicioHTML.addElement(idIndice,indiceRequisitos,idfrequsito1);
servicioHTML.addElement(idIndice,indiceRequisitos,idfrequsito2);
servicioHTML.addElement(idIndice,indiceRequisitos,idrestriccion1);
servicioHTML.addElement(idIndice,indiceRequisitos,idrestriccion2);

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

auto indiceDigramasCU = servicioHTML.createEntry(idIndice,"Diagramas de Casos de Uso",indicerequisitosfun);
auto indiceActorUC = servicioHTML.createEntry(idIndice,"Definicion de actores",indicerequisitosfun);
servicioHTML.addElement(idIndice,indiceActorUC,idActor1);
servicioHTML.addElement(idIndice,indiceActorUC,idActor2);

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
servicioUseCase.addObjective(idUC1,idObjetivo5);
servicioUseCase.addObjective(idUC1,idObjetivo6);
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
servicioUseCase.addObjective(idUC2,idObjetivo6);
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
servicioUseCase.addObjective(idUC3,idObjetivo6);
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
servicioUseCase.addObjective(idUC3,idObjetivo6);
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
servicioUseCase.addObjective(idUC4,idObjetivo6);
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


auto idUC6 = servicioUseCase.createUserCase("Añadir nuevo producto");
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


auto idUC7 = servicioUseCase.createUserCase("Eliminar producto");
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

auto idUC8 = servicioUseCase.createUserCase("Consultar producto");
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


auto idUC9 = servicioUseCase.createUserCase("Crear hoja de pedido customizado");
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

auto idUC10 = servicioUseCase.createUserCase("Realizar pedido");
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

auto indiceCU = servicioHTML.createEntry(idIndice,"Casos de uso",indicerequisitosfun);
auto indiceCU1 = servicioHTML.createEntry(idIndice,"Casos de uso del subsistema de gestion de clientes",indiceCU);
auto indiceCU2 = servicioHTML.createEntry(idIndice,"Casos de uso del subsistema de gestion de productos",indiceCU);
auto indiceCU3 = servicioHTML.createEntry(idIndice,"Casos de uso del subsistema de gestion de pedidos",indiceCU);
    ServicioDiagramUC servicioDiagramUC;
auto diagrama1 =  servicioDiagramUC.createDiagramUC("Diagrama de casos de uso de la gestion de clientes");
servicioDiagramUC.addUserCase(diagrama1,idUC1);
servicioDiagramUC.addUserCase(diagrama1,idUC2);
servicioDiagramUC.addUserCase(diagrama1,idUC3);
servicioDiagramUC.addUserCase(diagrama1,idUC4);
servicioDiagramUC.addUserCase(diagrama1,idUC5);


servicioHTML.addElement(idIndice,indiceCU1,idUC1);
servicioHTML.addElement(idIndice,indiceCU1,idUC2);
servicioHTML.addElement(idIndice,indiceCU1,idUC3);
servicioHTML.addElement(idIndice,indiceCU1,idUC4);
servicioHTML.addElement(idIndice,indiceCU1,idUC5);
servicioHTML.addElement(idIndice,indiceCU1,diagrama1);

auto diagrama2 =  servicioDiagramUC.createDiagramUC("Diagrama de casos de uso de la gestion de productos");
servicioDiagramUC.addUserCase(diagrama2,idUC6);
servicioDiagramUC.addUserCase(diagrama2,idUC7);
servicioDiagramUC.addUserCase(diagrama2,idUC8);
servicioHTML.addElement(idIndice,indiceCU2,idUC6);
servicioHTML.addElement(idIndice,indiceCU2,idUC7);
servicioHTML.addElement(idIndice,indiceCU2,idUC8);
servicioHTML.addElement(idIndice,indiceCU2,diagrama2);

auto diagrama3 =  servicioDiagramUC.createDiagramUC("Diagrama de casos de uso de la gestion de pedidos");
servicioDiagramUC.addUserCase(diagrama3,idUC9);
servicioDiagramUC.addUserCase(diagrama3,idUC10);
servicioHTML.addElement(idIndice,indiceCU3,idUC9);
servicioHTML.addElement(idIndice,indiceCU3,idUC10);
servicioHTML.addElement(idIndice,indiceCU3,diagrama3);

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

auto indiceRequisitosNoFuncionales = servicioHTML.createEntry(idIndice,"Requisitos no funcionales",indiceRequisitos);
servicioHTML.addElement(idIndice,indiceRequisitosNoFuncionales,idnf1);
servicioHTML.addElement(idIndice,indiceRequisitosNoFuncionales,idnf2);

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

auto indiceMatrix = servicioHTML.createEntry(idIndice,"Matriz de rastreabilidad Objetivos/Requisitos",     0);
servicioHTML.addElement(idIndice,indiceMatrix,idm);
    ServicioInterview servicioInterview;

    auto idInterview = servicioInterview.createInterview("Entrevista a Antonio López, espartero de Chiclana");
    servicioInterview.addQuestion(idInterview,"¿Cuál es el problema o necesidad específica que está buscando solucionar con una aplicación?", "Pues lo que es el tema de cómo arreglaría tantas preguntas, como todo el mundo me pregunta, ¿qué artículo tiene usted? Pues poderlo llevar a redes sociales que no me hagan la pregunta, que simplemente lo veáis, y sigan, evidentemente, a lo que es el artículo que le interese.");
    servicioInterview.addQuestion(idInterview,"¿Hay algún otro intento previo de solucionar este problema o de una aplicación? Si es así, ¿por qué falló?","Se hizo, pero se hizo de cuatro artículos, nada más, o cinco artículos, después se hizo mal. No se detallaron los precios, no, en fin, falló el completo. Estaba mal hecho, cuando una cosa está mal hecha, está mal hecha. Y entonces, ya luego hemos ido rebotando a todo el mundo por WhatsApp, y es donde no hemos defendido, pero que por WhatsApp tampoco es. \n" );
    servicioInterview.addQuestion(idInterview,"Es decir, ¿que la comunicación de pasarle los productos va por WhatsApp?", "Sí, ahora mismo sí, es la solución que hay. A no ser que hubiera lo que es una buena página web, una buena fórmula de que el cliente directamente lo hubiera, pero claro, siempre tendría que contactar conmigo, puesto que somos una persona no más fabricando, no tenemos capacidad de vender por encima de la web, si no nos saturan. \n" );
    servicioInterview.addQuestion(idInterview,"¿Cómo describiría el proceso del trabajo del artesano?","Eso es manual, eso no tiene más historia, aguja y cuerda y vámonos." );
    servicioInterview.addQuestion(idInterview,"Quiero decir, pero desde que el cliente te contacta a ti hasta que llega, ¿cómo el cliente te llega a contactar a ti? ¿Cómo haces tú que el producto le llega al cliente? ¿Cuál es todo el proceso ahí?", "Simplemente, mensajería, empaqueto, preparo, mensajería, envío, dirección de envío, lo que es con los códigos postales y demás hoy en día no se pierde ningún producto, además, todos, todos, todos quedan grabados y si hay una incidencia, lo recuperas en 30 segundos." );
    servicioInterview.addQuestion(idInterview,"¿Hay algún otro usuario, otra persona que debe interactuar con la página, además de tú?","Ahora mismo, cuando me hace falta lo que es el tema de facturación o algo, yo tengo la agencia, o sea, la agencia, la gestoría que ellos mismos me gestionan la parte de documento o si me hiciera falta de que por ejemplo cualquier proyecto que me pidieran de ingenería por algo, me hicieran falta de que me la aclararan, tengo mi gestoría que me hace lo que me hiciera falta. Es la parte técnica. \n" );
    servicioInterview.addQuestion(idInterview,"Pero entonces la gestoría que es la que lleva los papeles legales, ¿es la que tú querrías que te rellenara los tipos de productos en la página web?", "Es que hoy en día, para ser el proveedor de muchas empresas, te piden cosas que a mí me suenan los nombres a chino. Entonces lo mejor que hago cuando me entro en una empresa, por ejemplo, como ha pasado últimamente con televisión. Televisión Española me pedía hasta mi fecha de nacimiento pero de todo. ¿Qué hice? Mire usted, tome usted el número de teléfono de mi gestoría y las chavalas en las gestorías se encargaron de todo y no hubo problema ninguno. Cuando nos ha tocado el extranjero que lleva números de clave de exportación distinto, pues me ha pasado igual y hemos podido lamentar que me han pedido al mundo entero, le hemos podido enviar lo que pasa que hay ciertos puntos del mundo que son mas caros pero enviar donde quieres." );
    servicioInterview.addQuestion(idInterview,"¿Cómo querría que fuese el acceso a la web desde tu parte? ¿Es decir como administrador y dueño de ello o simplemente como usuario más?","No, por la parte de lo que es de administrador te vuelvo a decir lo mismo en la web, simplemente me haría falta a mí, informativa con idea de que automáticamente hiciera igual que hace todo lo poquito que tengo de redes sociales. Hable usted con Antonio por WhatsApp. A mi me gusta que me llegue a mí y me explique porque si no no hay forma de llevar, porque esto es totalmente construido a mano todos son diferentes pero todos son parecidos. \n" );
    servicioInterview.addQuestion(idInterview,"¿Hay algo en concreto, alguna característica que quieres que la aplicación o la página web pueda hacer por ti más que lo comentado hasta ahora de que informe al cliente hay algo más aparte de eso?","La verdad es que lo desconozco por el tema que yo no sé si la página web se podría enviar lo que eran vídeos constructivos, o sea, vídeos de como enlazar que como lo desconozco el tema de las redes sociales, esa parte sería a la par que vas haciendo, fraccionar este tramo. Y después, unirlo todo para mandárselo al cliente. De conocimiento ahí no llego." );
    servicioInterview.addQuestion(idInterview, "Claro, pero ponte que en un año no aparece en la página web, por ejemplo, un producto nuevo y tienes que añadirlo tú.", "Sí. Socorro. Socorro. Buscaría la gestoría o buscaría alguien. cuando me atasco hay que pedir socorro, eso es muy lógico en la vida. \n" );
    servicioInterview.addQuestion(idInterview,"Hay alguna restricción en cuanto al costo o tiempo necesario para desarrollar la aplicación o la página web?","No. Simplemente no. Ni por requisitos ni por poder o no poder no tengo problema. \n" );
    servicioInterview.addQuestion(idInterview,"¿Te interesa que en la aplicación haya un perfil de comunicaciones para este tipo de cosas como una revista, un certamen, un concurso?","Ah, si me gusta pero al final no hago caso nunca. Me gusta que me inviten a todos lados a todos los certamenes, de España entera de todos lados y no voy a ningún lado. \n" );
    servicioInterview.addQuestion(idInterview,"¿Y cuándo es que tú vas?","No voy. Cuando es que voy es porque tengo a veces necesidad de salir del agobio del taller, simplemente programo cualquier cliente en la entrega y hago la entrega en cualquier punto de España o en cualquier punto de... Cuidado, que capaz de hacerla hasta afuera por decir, me voy un poquito. \n" );
    servicioInterview.addQuestion(idInterview,"Te hace falta una aplicación que cosa esparto.","No, hombre. \n" );
    servicioInterview.addQuestion(idInterview,"Este es el final de la entrevista a Antonio López. Muchas gracias por colaborar.", "Para mi no ha sido problema ninguno al revés. Para lo que queráis. \n" );
    servicioInterview.addQuestion(idInterview,"Pues nada, muchas gracias.", "A ustedes." );
    servicioInterview.addStakeholderAsking(idInterview,idStakeholder2);
    servicioInterview.addStakeholderAsking(idInterview,idStakeholder3);
    servicioInterview.addStakeholderInterviewed(idInterview,idStakeholder1);
    auto indiceEntrevista = servicioHTML.createEntry(idIndice,"Entrevista",     0);
    servicioHTML.addElement(idIndice,indiceEntrevista,idInterview);
auto idGlosario = servicioText.createText("Glosario");
servicioText.setDescription(idGlosario,"Esparto: Hoja de esta planta, radical, larga, dura, resistente y tan arrollada sobre sí que parece tener forma de hilo.\n"
                                       "\n"
                                       "Pleita: Faja o tira de esparto, palma, pita u otros ramales entretejidos que, cosida con otras, se utiliza para hacer sombreros, esteras, etc.\n"
                                       "");
auto indiceGlo = servicioHTML.createEntry(idIndice,"Glosario de terminos",     0);
    servicioHTML.addElement(idIndice,indiceGlo,idGlosario);


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

ServicioHTML::printHTML(idIndice);


}

int main(int argc, char *argv[])
{
prueba();
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
