#include "enemy_bullet.h"
#include "game.h"
#include "player.h"
extern Game *game;

Enemy_Bullet::Enemy_Bullet(int enemyPlace)
{
    this->enemyBulletPosV=enemyPlace;
    setPixmap(QPixmap("/home/marcus/game1/874fa0e5bf7b854.png"));
    bullets::timerStart(20);
}


void Enemy_Bullet::decreaseEnemyPosV()
{
enemyBulletPosV--;
}

int Enemy_Bullet::getEnemyPosV(){
    return enemyBulletPosV;
}


void Enemy_Bullet::move()
{
    setPos(x()-20,y());
    QList<QGraphicsItem *> list = collidingItems();
    foreach(QGraphicsItem * i , list)
    {
        if (i==game->obj->player)
        {
            game->obj->vEnemy[enemyBulletPosV]->bulletHit(this);
            game->stats->hp->decrease();
            return;
        }
        play_Bullet * item= dynamic_cast<play_Bullet *>(i);
        if(item)
        {
            game->obj->vEnemy[enemyBulletPosV]->bulletHit(this);
            game->obj->player->bulletRemove(item);
            return;
        }
    }

     if(pos().x()<0)
     {
         game->obj->vEnemy[enemyBulletPosV]->bulletHit(this);
     }

}


