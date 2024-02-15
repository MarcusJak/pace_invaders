#include "game.h"


extern Game *game;

Enemy::Enemy(int enemyPlace)
{
    this->enemyPosV=enemyPlace;
    setPos(game->scene->width(),(rand()%700)-100);

    setPixmap(QPixmap("/home/marcus/game1/bilder/astriod.png"));
    timerMove =new QTimer();
    connect(timerMove, &QTimer::timeout,this,&Enemy::move);
    timerMove->start(40);

    timerShoot =new QTimer();

    connect(timerShoot, &QTimer::timeout,this,&Enemy::shoot);
    timerShoot->start(rand()%600+1000);
    visible=true;
}

Enemy::~Enemy()
{
    removeBullets();
    timerMove->stop();
    timerShoot->stop();
    disconnect(timerShoot, &QTimer::timeout,this,&Enemy::shoot);
    disconnect(timerMove, &QTimer::timeout,this,&Enemy::move);
}
void Enemy::move()
{
    setPos(x()-10,y());

    QList<QGraphicsItem *> list = collidingItems();
    foreach(QGraphicsItem * i , list)
    {
        if (i==game->obj->player)
        {
            game->stats->hp->sethp(0);
            return;
        }

    }
    if(pos().x()<0)
    {
        if(this->visible)
        {
            game->stats->hp->decrease();
        }
        game->obj->enemyRemove();
        delete this;

    }
}
void Enemy::shoot()
{
    Enemy_Bullet * shoot= new Enemy_Bullet(enemyPosV);
    shoot->setPos(x()-70,y()+125);
    vEnemyBullet.push_back(shoot);
    scene()->addItem(shoot);
}

void Enemy::bulletHit(Enemy_Bullet* hit)
{
    auto iter = std::find(vEnemyBullet.begin(), vEnemyBullet.end(), hit);
    if (iter != vEnemyBullet.end())
    {
        vEnemyBullet.erase(iter);
    }
    delete hit;
}

void Enemy::decreaseEnemyPosV()
{
    enemyPosV--;
    std::for_each(vEnemyBullet.begin(),vEnemyBullet.end(),[&]( Enemy_Bullet* enemy)
    {
        enemy->decreaseEnemyPosV();
    });
}

int Enemy::getEnemyPosV()
{
    return enemyPosV;
}

void Enemy::removeBullets(){
    std::for_each(vEnemyBullet.begin(),vEnemyBullet.end(),[&]( bullets* enemy)
    {delete enemy;});
    vEnemyBullet.clear();
}


void Enemy::notVisible()
{
    this->visible = !visible;
}


