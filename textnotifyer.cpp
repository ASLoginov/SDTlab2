#include "textnotifyer.h"

TextNotifyer::TextNotifyer(QTextStream* stream) {
    ostream = stream;
    QDir dir;
    dir.current();
    QTextStream& qout = *ostream;
    qout << dir.absolutePath() << Qt::endl;
}

void TextNotifyer::setStream(QTextStream *stream) {
    ostream = stream;
}

void TextNotifyer::changeNotify(int event, QString name, qint64 size) {
    if (silent) return;
    QTextStream& qout = *ostream;
    if (event == 2) {
        qout << "File " << name << " has been changed, size " << size << Qt::endl;
        return;
    }
    if (event == 1) {
        qout << "File " << name << " exists, size " << size << Qt::endl;
        return;
    }
    if (event == 0) {
        qout << "File " << name << " does not exist" << Qt::endl;
        return;
    }
}

void TextNotifyer::attachNotify(QString name, bool existance, qint64 size) {
    if (silent) return;
    QTextStream& qout = *ostream;
    qout << "File " << name << " has been attached, ";
    if (existance) qout << "size " << size;
    else qout << "does not exist";
    qout << Qt::endl;
}

void TextNotifyer::detachNotify(QString name) {
    if (silent) return;
    QTextStream& qout = *ostream;
    qout << "File " << name << " has been detached" << Qt::endl;
}

void TextNotifyer::setSilent(bool value) {
    silent = value;
    QTextStream& qout = *ostream;
    if (silent) qout << "stop output" << Qt::endl;
    else qout << "continue output" << Qt::endl;
}
