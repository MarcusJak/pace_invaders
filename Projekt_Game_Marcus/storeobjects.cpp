#include "game.h"
#include "storeobjects.h"
extern Game *game;

storeObjects::storeObjects()
{
    connect(game->timerEnemySpawn, &QTimer::timeout,this,&storeObjects::spawn);

}

void storeObjects::spawn()
{
            Enemy * enemy= new Enemy(vEnemy.size());
            vEnemy.push_back(enemy);
            game->scene->addItem(enemy);
}

void storeObjects::removeAllBullets()
{
    player->removeBullets();

    std::for_each(vEnemy.begin(),vEnemy.end(),[&]( Enemy* enemy)
    {
        enemy->removeBullets();
        delete enemy;
        }
    );
    vEnemy.clear();
}


void storeObjects::enemyRemove()
{
  vEnemy[0]->removeBullets();
  vEnemy.erase(vEnemy.begin());
  std::for_each(vEnemy.begin(),vEnemy.end(),[&]( Enemy* enemy)
  {
      enemy->decreaseEnemyPosV();
      }
  );

}
