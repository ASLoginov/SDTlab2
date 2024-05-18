#include "inputlistener.h"

void InputListener::run() {
    while(true) {
        QTextStream qin(stdin);
        qin.readLine();
        emit silence(true);
        QString inputString = qin.readLine();
        emit silence(false);
        ReadCommand(inputString);
    }
}

void InputListener::ReadCommand(QString str) {
    QString comm = str.section(' ', 0, 0);
    QString param = str.section(' ', 1);
    if (comm == "attach") {
        emit attachSignal(param);
    }
    else if (comm == "detach") {
        emit detachSignal(param);
    }
}
