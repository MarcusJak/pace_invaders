#ifndef BULLETS_H
#define BULLETS_H
#include <QGraphicsItem>
#include <QTimer>

//! det här är en klass för bullets både för player och enemy.
class bullets:public QObject, public QGraphicsPixmapItem
{
public:
    bullets()=default;
//! denna destructor disconnectar move funktionen och timer, samt stoppar timern
   ~bullets();
    //! startar timern som gör så att bullets rör sig
    //!@param time är tiden som bullet ska uppdateras med
    void timerStart(int time);

    public slots:
    //! move funktionen som rör sig utifrån om det är ett enemy eller player skott
    virtual void move() =0;

    private:
    QTimer *timer =new QTimer();
};

#endif // BULLETS_H
