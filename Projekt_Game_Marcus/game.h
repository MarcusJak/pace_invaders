#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include "menyObj.h"
#include "stats.h"
#include "storeobjects.h"

//! själva spel klassen där de olika spelalägen finns
class Game:  public QGraphicsView
{
public:
    Game();
    //! scene där allt händer
    QGraphicsScene * scene;


    //! denna håller player and enemys
    storeObjects * obj;
    //! denna håller statsen hp och score
    Stats *stats;
   //! enemy spawn timer
    QTimer * timerEnemySpawn;
    //! start meny knappen
    menyObj *start;
    //! exit meny knappen
    menyObj *exit;
    //! meny funktionen som tar spelet till menyn när nån har dött eller när spelet startas
    void gameMeny();
    //! vilken meny som är vald
    bool meny;
    //! nytt spel
    void gameNew();
    //! startar spelet
    void gameSet();

    void gameRemove();
private:
    QGraphicsView * view;
};

#endif // GAME_H
