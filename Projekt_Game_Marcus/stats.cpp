#include "game.h"
#include "stats.h"

#include <QFont>
extern Game *game;

Stats::Stats()
{
    hp= new health;
    score=new Score;

}
void Stats::meny(){
    score->setFont(QFont("times",100));
    score->setPos(550,50);
    if(hp->gethp()==0)
    {
        game->scene->removeItem(hp);
    }
}


void Stats::deault(){
    game->scene->addItem(hp);

    if(hp->gethp()!=0)
    {
        game->scene->addItem(score);
    }

    hp->setFont(QFont("times",16));
    score->setFont(QFont("times",16));
    hp->sethp(3);
    hp->setPos(0,40);

  score->setPos(0,20);
  score->setScore(0);
}

