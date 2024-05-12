#include <QCoreApplication>
#include <consolenotifyer.h>

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

    while(true) {
        console.ReadCommand();
    }

    return a.exec();
}
