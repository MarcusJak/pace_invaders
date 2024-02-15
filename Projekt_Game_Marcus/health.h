#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsItem>




//! denna klassen håller hp av spelaren
class health: public QGraphicsTextItem
{
public:
    //! sätter antalet liv samt texten
    health();
    //! för att få score
    int gethp();
    //! för att sätta hp
    //! @param hp hur mycket hp som skall sättas
    void sethp(int hp);

    //! denna funktion ökar hp
    void increase();
    //! denna funktion sänker hp samt kollar om spelet ska börja om
    void decrease();

private:
    int hp;
};


#endif // HEALTH_H
