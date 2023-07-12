//
// Created by Fran- on 29/06/2023.
//

#ifndef TFG_USERCASEDIAGRAM_H
#define TFG_USERCASEDIAGRAM_H
#include "Servicio/ServicioUserCase.h"
#include "Servicio/ServicioActorUC.h"




class UserCaseDiagram : public Trackeable {

public:

    UserCaseDiagram(unsigned id): Trackeable(prefix,id){}
    UserCaseDiagram(): Trackeable(){}
    void setElements(std::set<OID> userCaseList, std::set<OID> actorUCList);
    std::set<OID> getUserCaseList();
    std::set<OID> getActorUCList();
    void addUserCase(OID userCase);
    void removeUserCase(OID userCase);
    void visit(Visitor *visitor);
    void update();


    static std::string getPrefixID() {return prefix;}

private:

    std::map<std::string,std::set<OID>> packagesUC;
    std::map<std::string,std::set<OID>> packagesActor;
    std::set<std::string > packages;
    std::set<OID> userCaseList;
    std::set<OID> actorUCList;
    std::map<OID,std::string> nombres;
    inline static std::string prefix = "UD";
};



#endif //TFG_USERCASEDIAGRAM_H
