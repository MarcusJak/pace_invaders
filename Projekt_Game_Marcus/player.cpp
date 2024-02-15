#include "play_bullet.h"
#include "enemy.h"
#include "enemy_bullet.h"
#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
Player::Player()
{
    setPixmap(QPixmap("/home/marcus/build-Projekt_Game_Marcus-Desktop_Qt_6_2_2_GCC_64bit-Debug/bilder/player.png"));
    timerGlide =new QTimer();
    connect(timerGlide, SIGNAL(timeout()),this,SLOT(glide()));
    timerGlide->start(20);


    timerReload =new QTimer();
    connect(timerReload, SIGNAL(timeout()),this,SLOT(ammoReload()));
    timerReload->start(1000);
}

Player::~Player()
{
timerGlide->stop();
timerReload->stop();
disconnect(timerReload, SIGNAL(timeout()),this,SLOT(ammoReload()));
disconnect(timerGlide, SIGNAL(timeout()),this,SLOT(glide()));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left&&5<pos().x())
    {
        setPos(x()-5,y());
        speedX=-5;

    }
     if(event->key()==Qt::Key_Right&&pos().x()<(scene()->width()-250))
    {
        setPos(x()+5,y());
        speedX=5;

    }
     if(event->key()==Qt::Key_Up&&5<pos().y())
    {
        setPos(x(),y()-5);
        speedY=-5;

    }
     if(event->key()==Qt::Key_Down&&pos().y()<(scene()->height()-238))
    {
         setPos(x(),y()+5);

         speedY=5;
    }

     if(event->key()==Qt::Key_Space&&amountB<1)
     {
        play_Bullet *bullet = new play_Bullet;
        bullet->setPos(x()+128,y()+45);
        scene()->addItem(bullet);
        vPlayerBullet.push_back(bullet);
        amountB++;
    }
}


void Player::glide()
{

    if((5>pos().x()||pos().x()>(scene()->width()-250)))
    {
        speedX=0;
    }
    if((5>pos().y()||pos().y()>(scene()->height()-238)))
    {
        speedY=0;
    }
    setPos(x()+speedX,y()+speedY);
}

void Player::ammoReload()
{
   if(amountB>0)
   {
       amountB--;
   }
}

void Player::removeBullets(){
    std::for_each(vPlayerBullet.begin(),vPlayerBullet.end(),[&]( bullets* player)
    {
        delete player;
        }
    );
    vPlayerBullet.clear();

}



void Player::bulletRemove(play_Bullet* hit){
    auto iter = std::find(vPlayerBullet.begin(), vPlayerBullet.end(), hit);
    if (iter != vPlayerBullet.end())
    {
        vPlayerBullet.erase(iter);
    }
    delete hit;
}
