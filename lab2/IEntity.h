//
// Created by red on 05.12.2021.
//

#ifndef REWORKED_IENTITY_H
#define REWORKED_IENTITY_H
//#include "../lab3/Observalbe.h"

class IEntity{
public:
    virtual void interact(IEntity *){};
    virtual int getType() = 0;
};


#endif //REWORKED_IENTITY_H
