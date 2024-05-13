#include "trackingmanager.h"

TrackingManager::TrackingManager() {
    connect(&timer, &QTimer::timeout, this, &TrackingManager::Update);
}

TrackingManager::~TrackingManager() {

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
        if (!fileList.empty()) timer.start(100);
    }
}

void TrackingManager::Detach(QString fileName) {
    if (fileList.remove(fileName)) emit fileDetached(fileName);
    if (fileList.empty()) timer.stop();
}

void TrackingManager::resendSignal(FileEvent event, QString name, qint64 size) {
    emit fileChanged(event, name, size);
}

void TrackingManager::stopTimer() {
    timer.stop();
}

void TrackingManager::Update() {
    for (auto& entry : fileList) entry.Update();
}
