#ifndef PLAY_BULLET_H
#define PLAY_BULLET_H

#include "bullets.h"

//! Denna klass är spelarens skott som är en barn till ett skott
class play_Bullet:public bullets{
Q_OBJECT
public:
    //! default konstruktor sätter bild samt startar move klockan
    play_Bullet();
public slots:
    //! denna funktion gör så att objektet rör sig. Samt kollas det om ett skott träffar en enemy´
    void move() override;
};

#endif // PLAY_BULLET_H
