#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsItem>

//! denna klassen håller poängen för spelaren
class Score: public QGraphicsTextItem
{
public:
//! denna default konstruktor sätter score till 0 och skriver texten
    Score();
    //! hämtar score
    int getScore();
    //! sätter score
    //! @param value vad score ska sättas till
    void setScore(int value);
    //! öka score och printa
    void increase();
private:
    int score;
};

#endif // SCORE_H
