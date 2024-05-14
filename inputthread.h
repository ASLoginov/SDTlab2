#ifndef INPUTTHREAD_H
#define INPUTTHREAD_H

#include <QThread>
#include <stdio.h>
#include <QTextStream>

class InputThread : public QThread
{
    Q_OBJECT
    void run();

public:

signals:
    void getNewLine(QString str);
    void stopSignal();
};

#endif // INPUTTHREAD_H
