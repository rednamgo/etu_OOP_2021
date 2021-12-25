//
// Created by red on 14.12.2021.
//

#ifndef REWORKED_PLAYERSEARCHOVERLAY_H
#define REWORKED_PLAYERSEARCHOVERLAY_H
#include "Overlay.h"

class PlayerSearchOverlay: public Overlay {
public:
    PlayerSearchOverlay() = default;
    explicit PlayerSearchOverlay(Room *room);
    void createOverlay(Room *room);
    ~PlayerSearchOverlay() = default;
    //[[nodiscard]] Overlay* clone() const { return new PlayerSearchOverlay(*this);}
    void flipIntoFleeOverlay(); //to create flee overlay
};


#endif //REWORKED_PLAYERSEARCHOVERLAY_H
