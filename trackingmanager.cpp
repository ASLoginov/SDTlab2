#include "trackingmanager.h"

TrackingManager::TrackingManager() {

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

void TrackingManager::resendSignal(int event, QString name, qint64 size) {
    emit fileChanged(event, name, size);
}

void TrackingManager::Update() {
    for (auto& entry : fileList) entry.Update();
}
