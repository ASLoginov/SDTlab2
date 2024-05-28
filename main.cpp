#include <QCoreApplication>
#include <textnotifyer.h>
#include <inputlistener.h>
#include <trackingmanager.h>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    TrackingManager manager;
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &manager, &TrackingManager::Update);
    timer.setInterval(100);
    timer.start();

    QTextStream out(stdout);
    TextNotifyer notifyer(&out);

    QObject::connect(&manager, &TrackingManager::fileAttached, &notifyer, &TextNotifyer::attachNotify);
    QObject::connect(&manager, &TrackingManager::fileDetached, &notifyer, &TextNotifyer::detachNotify);
    QObject::connect(&manager, &TrackingManager::fileChanged, &notifyer, &TextNotifyer::changeNotify);

    InputListener in;

    QObject::connect(&in, &InputListener::silence, &notifyer, &TextNotifyer::setSilent);
    QObject::connect(&in, &InputListener::attachSignal, &manager, &TrackingManager::Attach);
    QObject::connect(&in, &InputListener::detachSignal, &manager, &TrackingManager::Detach);

    in.start();

    return a.exec();
}
