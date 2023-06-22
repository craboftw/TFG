//
// Created by Fran- on 21/06/2023.
//

#ifndef TFG_GENERIC_H
#define TFG_GENERIC_H


#include "./Priority/Priority.h"
#include "./Trackeable/Trackeable.h"


class SystemObjective : public Trackeable, public Priority, virtual public ListaCambios {
public:
    explicit SystemObjective(OID id) : Trackeable(std::move(id)), Priority(), ListaCambios() {}
    void accept(Visitor visitor) override;
};

class RestrictionRequirement : public Trackeable, public Priority, virtual public ListaCambios {
public:
    explicit RestrictionRequirement(OID id) : Trackeable(std::move(id)), Priority(), ListaCambios() {}
    void accept(Visitor visitor) override;
};

class FunctionalRequirement : public Trackeable, public Priority, virtual public ListaCambios {
public:
    explicit FunctionalRequirement(OID id) : Trackeable(std::move(id)), Priority(), ListaCambios() {}
};

class NonFunctionalRequirement : public Trackeable, public Priority, virtual public ListaCambios {
public:
    explicit NonFunctionalRequirement(OID id) : Trackeable(std::move(id)), Priority(), ListaCambios() {}
};

class ActorUC : public Trackeable, virtual public ListaCambios {
public:
    // Agrega el cierre de llave que falta
};

#endif //TFG_GENERIC_H
