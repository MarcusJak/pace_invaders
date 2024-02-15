#include "game.h"
#include "menyObj.h"
#include <QKeyEvent>

extern Game *game;
menyObj::menyObj()
{
    game->meny=true;

}
void menyObj::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Up)
    {
        game->meny=true;
        game->start->setPixmap(QPixmap("/home/marcus/build-Projekt_Game_Marcus-Desktop_Qt_6_2_2_GCC_64bit-Debug/bilder/play.png"));
        game->exit->setPixmap(QPixmap("/home/marcus/build-Projekt_Game_Marcus-Desktop_Qt_6_2_2_GCC_64bit-Debug/bilder/end_not.png"));
    }
    if(event->key()==Qt::Key_Down)
    {
        game->meny=false;
        game->start->setPixmap(QPixmap("/home/marcus/build-Projekt_Game_Marcus-Desktop_Qt_6_2_2_GCC_64bit-Debug/bilder/play_Not.png"));
        game->exit->setPixmap(QPixmap("/home/marcus/build-Projekt_Game_Marcus-Desktop_Qt_6_2_2_GCC_64bit-Debug/bilder/end.png"));

    }
    if(event->key()==Qt::Key_Space)
    {
        if(game->meny)
        {
            game->gameNew();
        }
        else if(!game->meny)
        {
            exit(3);
        }

    }
}
