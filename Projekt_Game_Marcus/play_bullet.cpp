#include "play_bullet.h"
#include "enemy.h"
#include "game.h"
#include "player.h"

extern Game *game;

play_Bullet::play_Bullet()
{
    setPixmap(QPixmap("/home/marcus/game1/874fa0e5bf7b854.png"));
    bullets::timerStart(2);

}

void play_Bullet::move()
{
    setPos(x()+1,y());

    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem *i , list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item)
        {

                item->timerShoot->stop();
                game->stats->score->increase();

                scene()->removeItem(item);
                item->notVisible();

                game->obj->player->bulletRemove(this);
                return;
        }
    }

     if(pos().x()>scene()->width()){
         game->obj->player->bulletRemove(this);
        return;
     }

}

