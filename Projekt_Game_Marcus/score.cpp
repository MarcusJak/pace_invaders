#include "score.h"
#include <QGraphicsTextItem>

Score::Score()
{

    score=0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
}

int Score::getScore()
{
    return score;
}

void Score::setScore(int value)
{
    score=value;
    setPlainText(QString("Score: ") + QString::number(score));

}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}
