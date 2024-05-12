#include "consolenotifyer.h"

ConsoleNotifyer::ConsoleNotifyer() {

}

ConsoleNotifyer &ConsoleNotifyer::Instance() {
    static ConsoleNotifyer instance;
    return instance;
}

QTextStream cin(stdin);
QTextStream cout(stdout);

void ConsoleNotifyer::ReadCommand() {
    QString comm, name;
    cin >> comm >> name;
    if (comm == "attach") {
        emit attachSignal(name);
        return;
    }
    if (comm == "detach") {
        emit detachSignal(QString(name));
        return;
    }
}

void ConsoleNotifyer::changeNotify(FileEvent event, QString name, qint64 size) {
    if (event == FileEvent::Changed) {
        cout << "File " << name << " has been changed, size " << size << Qt::endl;
        return;
    }
    if (event == FileEvent::Exists ) {
        cout << "File " << name << " is exists, size " << size << Qt::endl;
        return;
    }
    if (event == FileEvent::Exists ) {
        cout << "File " << name << " does not exist" << Qt::endl;
        return;
    }
}

void ConsoleNotifyer::attachNotify(QString name, bool existance, qint64 size) {
    cout << "File " << name << " has been attached, ";
    if (existance) cout << "size " << size;
    else cout << "is not exists";
    cout << Qt::endl;
}

void ConsoleNotifyer::detachNotify(QString name) {
    cout << "File " << name << " has been detached" << Qt::endl;
}
