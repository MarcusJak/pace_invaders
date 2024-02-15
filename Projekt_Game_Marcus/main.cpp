#include "game.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

Game* game;
int main(int argc, char *argv[])
{
  srand(time(0));
  QApplication application(argc, argv);

  game =new Game();
  game->gameSet();

  game->show();
  game->gameMeny();
  return application.exec();
}
