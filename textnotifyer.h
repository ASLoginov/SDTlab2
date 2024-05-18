#ifndef CONSOLENOTIFYER_H
#define CONSOLENOTIFYER_H

#include <QObject>
#include <QTextStream>
#include <QDir>

class TextNotifyer : public QObject
{
    Q_OBJECT

    QTextStream* ostream;
    bool silent = false;

public:
    TextNotifyer(QTextStream* stream);
    void setStream(QTextStream* stream);

public slots:
    void changeNotify(int event, QString name, qint64 size);
    void attachNotify(QString name, bool existance, qint64 size);
    void detachNotify(QString name);
    void setSilent(bool value);
};

#endif // CONSOLENOTIFYER_H
