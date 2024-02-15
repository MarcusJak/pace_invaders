#include "game.h"
#include "health.h"

#include <QFont>
extern Game *game;

health::health()
{
    hp=3;

    setPlainText(QString("hp: ") + QString::number(hp));
        setDefaultTextColor(Qt::white);
}

int health::gethp()
{
    return hp;
}

void health::sethp(int hp)
{
    this->hp=hp;
    setPlainText(QString("hp: ") + QString::number(hp));
    if(hp==0)
    {
        game->gameRemove();
        game->gameMeny();
        return;
    }
}

void health::increase()
{
    hp++;
    setPlainText(QString("hp: ") + QString::number(hp));


}

void health::decrease()
{
    hp--;
    setPlainText(QString("hp: ") + QString::number(hp));
    if(game->stats->hp->gethp()==0)
    {
        game->gameRemove();
        game->gameMeny();
        return;
    }

}
