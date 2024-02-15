#ifndef PLAYER_H
#define PLAYER_H
#include <play_bullet.h>


//! själva spelarens klass, även finns spelarens rörelse samt skapas spelarens skott i denna klass
class Player:public QObject, public QGraphicsPixmapItem{
 Q_OBJECT

public:
//! denna default konstruktor sätter igång glide samt om laddningen
    Player();
    //! stoppar alla timers samt disconnectar
    ~Player();
    //! Tar in knapptryck och agerar utefter de
    //! @param event vilken knapp som har tryckts
    void keyPressEvent(QKeyEvent * event);

    //! när en av spelaren skott träffar så tas den bort eller om den åker utaför skärmen
    //! @param vilket spelar skott som har blivit träffat
    void bulletRemove(play_Bullet *hit);

    //! tar bort alla skott som spelaren har skjutit
    void removeBullets();
public slots:
        //! denna funktion gör så att spelaren glider då den ej kan stå still
    void glide();
    //! reloadar så att spelaren kan skjuta igen
    void ammoReload();

private:
    std::vector<play_Bullet*> vPlayerBullet;
    int amountB=0;
    int speedX;
    int speedY;
    QTimer *timerGlide;
    QTimer *timerReload;

};

#endif // PLAYER_H
