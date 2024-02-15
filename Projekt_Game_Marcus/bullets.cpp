#include "bullets.h"
#include <QTimer>


bullets::~bullets()
{
    timer->stop();
    disconnect(timer, &QTimer::timeout,this,&bullets::move);

}

void bullets::timerStart(int time)
{
    timer->start(time);
    connect(timer, &QTimer::timeout,this,&bullets::move);
}


