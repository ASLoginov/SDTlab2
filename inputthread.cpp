#include "inputthread.h"

void InputThread::run() {
    while(true) {
        QTextStream qin(stdin);
        qin.readLine();
        emit stopSignal();
        QString inputString = qin.readLine();
        emit getNewLine(inputString);
    }
}
