#include "trackingmanager.h"

TrackingManager::TrackingManager() {
    timer = startTimer(100);
}

TrackingManager& TrackingManager::Instance() {
    static TrackingManager instance;
    return instance;
}

void TrackingManager::Attach(QString fileName) {
    if (!fileList.contains(fileName)) {
        fileList.insert(fileName, FileTracker(fileName));
        connect(&fileList[fileName], &FileTracker::fileChanged, this, &TrackingManager::fileChanged);
        emit fileAttached(fileList[fileName].fileName(), fileList[fileName].exists(), fileList[fileName].size());
    }
}

void TrackingManager::Detach(QString fileName) {
    if (fileList.remove(fileName)) emit fileDetached(fileName);
}

void TrackingManager::resendSignal(FileEvent event, QString name, qint64 size) {
    emit fileChanged(event, name, size);
}

void TrackingManager::timerEvent(QTimerEvent *event) {
    if (event->timerId() == timer) {
        for (auto& entry : fileList) {
            entry.Update();
        }
    }
    else QObject::timerEvent(event);
}
