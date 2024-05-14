#include <QCoreApplication>
#include <consolenotifyer.h>
#include <inputthread.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ConsoleNotifyer& console = ConsoleNotifyer::Instance();
    TrackingManager& manager = TrackingManager::Instance();

    QObject::connect(&console, &ConsoleNotifyer::attachSignal, &manager, &TrackingManager::Attach);
    QObject::connect(&console, &ConsoleNotifyer::detachSignal, &manager, &TrackingManager::Detach);
    QObject::connect(&manager, &TrackingManager::fileAttached, &console, &ConsoleNotifyer::attachNotify);
    QObject::connect(&manager, &TrackingManager::fileDetached, &console, &ConsoleNotifyer::detachNotify);
    QObject::connect(&manager, &TrackingManager::fileChanged, &console, &ConsoleNotifyer::changeNotify);

    InputThread in;

    QObject::connect(&in, &InputThread::stopSignal, &manager, &TrackingManager::stopTimer);
    QObject::connect(&in, &InputThread::getNewLine, &console, &ConsoleNotifyer::ReadCommand);

    in.start();

    return a.exec();
}
