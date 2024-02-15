#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H

#include "bullets.h"



//! Denna klass är enemys skott som är en barn till ett skott
class Enemy_Bullet:public bullets{
Q_OBJECT
public:
    Enemy_Bullet()=delete;
    //! denna konstruktor sätter vilken som har skjutit samt pixel bilden
    //! @param enemyPlace vem som har skjutit skottet
    Enemy_Bullet(int enemyPlace);

    //! denna funktion minskar värdet på who då en enemy har raderats ur vectorn
    void decreaseEnemyPosV();
//! för att se vems skottet är
    int getEnemyPosV();
public slots:
    //! denna funktion gör så att enemy skottet rör sig.
    //! och håller koll på om skottet träffar en spelare eller en spelares skott, samt om skottet har åkt ur bild
     void move() override;
private:
     int enemyBulletPosV;

};

#endif // ENEMY_BULLET_H
