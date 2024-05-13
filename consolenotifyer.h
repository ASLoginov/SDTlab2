#ifndef CONSOLENOTIFYER_H
#define CONSOLENOTIFYER_H

#include <QObject>
#include <QTextStream>
#include <QDir>
#include <trackingmanager.h>

class ConsoleNotifyer : public QObject
{
    Q_OBJECT
    ConsoleNotifyer();

    ConsoleNotifyer(const ConsoleNotifyer&);
    ConsoleNotifyer& operator=(const ConsoleNotifyer&);

public:
    static ConsoleNotifyer& Instance();

public slots:
    void ReadCommand(QString str);
    void changeNotify(FileEvent event, QString name, qint64 size);
    void attachNotify(QString name, bool existance, qint64 size);
    void detachNotify(QString name);

signals:
    void attachSignal(QString name);
    void detachSignal(QString name);
};

#endif // CONSOLENOTIFYER_H
