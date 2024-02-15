#ifndef STATS_H
#define STATS_H

#include "health.h"
#include "score.h"
//! denna klass håller i statsen som hp och score
class Stats:public QGraphicsTextItem
{
public:
    //! default konstruktorn skapar endast score samt hp
    Stats();
    //! denna funktion sätter upp hur statsen skall visas när menyn väljs
    void meny();
    //! denna funktion sätter upp hur statsen skall visas när spelet är igång
    void deault();
    //! score objektet
    Score *score;
    //! hp objektet
    health *hp;

private:
    int tempscore;


};

#endif // STATS_H
