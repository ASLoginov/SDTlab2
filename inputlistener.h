#ifndef INPUTTHREAD_H
#define INPUTTHREAD_H

#include <QThread>
#include <stdio.h>
#include <QTextStream>

class InputListener : public QThread
{
    Q_OBJECT
    void run();

public:
    void ReadCommand(QString str);

signals:
    void silence(bool value);
    void attachSignal(QString name);
    void detachSignal(QString name);
};

#endif // INPUTTHREAD_H
