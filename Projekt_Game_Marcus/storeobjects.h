#ifndef STOREOBJECTS_H
#define STOREOBJECTS_H

#include "enemy.h"
#include "player.h"
#include <QGraphicsView>


//! denna klass håller spelaren samt alla enemys
class storeObjects:public QGraphicsView
{
public:
    //! denna default konstruktor sätter ihop timern ifrån game med spawn funktionen
    storeObjects();
    // player objectet
    Player * player;
    //! enemy objectet
    Enemy * enemy;
    //! denna vector håller alla enemys
    std::vector<Enemy*> vEnemy;
    //! Tar bort alla bullets både spelaren och enemys
    void removeAllBullets();
    //! tar bort alla enemys
    void enemyRemove();
public slots:
    //! spawnar enemys
    void spawn();
};

#endif // STOREOBJECTS_H
