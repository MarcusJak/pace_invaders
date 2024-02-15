#include "game.h"


Game::Game()
{
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    setScene(scene);
    setBackgroundBrush(QBrush(QImage("/home/marcus/game1/bilder/rymd.jpg")));
}

void Game::gameSet(){
    view->setFixedSize(1800,900);
    scene->setSceneRect(0,0,1800,900);
    setFixedSize(1800,900);
    timerEnemySpawn =new QTimer();
    obj=new storeObjects();

    stats =new Stats;
    start =new menyObj();
    exit =new menyObj();
    start->setPixmap(QPixmap("/home/marcus/build-Projekt_Game_Marcus-Desktop_Qt_6_2_2_GCC_64bit-Debug/bilder/play.png"));
    exit->setPixmap(QPixmap("/home/marcus/build-Projekt_Game_Marcus-Desktop_Qt_6_2_2_GCC_64bit-Debug/bilder/end_not.png"));
    start->setPos(500,250);
    exit->setPos(500,500);

}


void Game::gameNew()
{

  scene->removeItem(start);
  scene->removeItem(exit);
  obj->player = new Player();
  scene->addItem(obj->player);
  obj->player->setFlag(QGraphicsItem::ItemIsFocusable);
  obj->player->setFocus();
  timerEnemySpawn->start(rand()%1000 + 3000);
  stats->deault();
  setBackgroundBrush(QBrush(QImage("/home/marcus/game1/bilder/rymd.jpg")));

}

void Game::gameRemove(){
    timerEnemySpawn->stop();
    obj->removeAllBullets();
    delete obj->player;
    stats->meny();
}


void Game::gameMeny()
{
    scene->addItem(start);
    scene->addItem(exit);
    start->setFlag(QGraphicsItem::ItemIsFocusable);
    exit->setFlag(QGraphicsItem::ItemIsFocusable);
    start->setFocus();

}
