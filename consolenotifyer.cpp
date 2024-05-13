#include "consolenotifyer.h"

QTextStream cout(stdout);

ConsoleNotifyer::ConsoleNotifyer() {
    QDir dir;
    dir.current();
    cout << dir.absolutePath() << Qt::endl;
}

ConsoleNotifyer &ConsoleNotifyer::Instance() {
    static ConsoleNotifyer instance;
    return instance;
}

void ConsoleNotifyer::ReadCommand(QString str) {
    QString comm = str.section(' ', 0, 0);
    QString param = str.section(' ', 1);
    if (comm == "attach") {
        emit attachSignal(param);
    }
    else if (comm == "detach") {
        emit detachSignal(param);
    }
}

void ConsoleNotifyer::changeNotify(FileEvent event, QString name, qint64 size) {
    if (event == FileEvent::Changed) {
        cout << "File " << name << " has been changed, size " << size << Qt::endl;
        return;
    }
    if (event == FileEvent::Exists ) {
        cout << "File " << name << " exists, size " << size << Qt::endl;
        return;
    }
    if (event == FileEvent::NotExist ) {
        cout << "File " << name << " does not exist" << Qt::endl;
        return;
    }
}

void ConsoleNotifyer::attachNotify(QString name, bool existance, qint64 size) {
    cout << "File " << name << " has been attached, ";
    if (existance) cout << "size " << size;
    else cout << "does not exist";
    cout << Qt::endl;
}

void ConsoleNotifyer::detachNotify(QString name) {
    cout << "File " << name << " has been detached" << Qt::endl;
}
