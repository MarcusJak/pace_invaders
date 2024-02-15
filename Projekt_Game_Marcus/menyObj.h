#ifndef MENYOBJ_H
#define MENYOBJ_H

#include <QGraphicsPixmapItem>


//! denna klass är meny objektet
class menyObj :public QObject, public QGraphicsPixmapItem {


public:
    //! default konstruktorn sätter meny vaiabeln till true då det betyder att load game är selected
    menyObj();
    //! denna funktion analyserar om du vill gå upp eller ner i menyn
    //! @param event vilken knapp som har tryckts
    void keyPressEvent(QKeyEvent *event);
};

#endif // MENYOBJ_H
