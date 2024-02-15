#ifndef ENEMY_H
#define ENEMY_H

#include "enemy_bullet.h"


//! Själva enemy skapelsen samt där skottet skapas
class Enemy:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //! @param enemyPlace vart enemyn ligger i vektorn
    Enemy(int enemyPlace);
    ~Enemy();

    //! denna funktion är då ett enemy skott har träffat spelaren
    //! @param hit vilket enemy skott som har blivit träffat
    void bulletHit(Enemy_Bullet* hit);
    //! sänker vart denna enemy ligger i vektorn
    void decreaseEnemyPosV();
    //! hämtar vart denna enemy ligger i enemy vektorn
    int getEnemyPosV();
    //! tar bort all enemys skott
    void removeBullets();
    QTimer *timerShoot;
    //! Denna funktion togglar visible
    void notVisible();

public slots:
    //! denna funktion gör så att enemy rör sig.
    //! Samt kollar om enemy har krockat eller om den har åkt ur bild
    void move();
    //! denna funktion skapar ett skott
    void shoot();

private:
    int enemyPosV;
    QTimer *timerMove;
    bool visible;
    std::vector<Enemy_Bullet*> vEnemyBullet;


};
#endif // ENEMY_H
