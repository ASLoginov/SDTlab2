#include "filetracker.h"

FileTracker::FileTracker(const QString &name) : QFile(name) {
    existance = exists();
    lastTime = fileTime(QFileDevice::FileModificationTime);
}

void FileTracker::Update() {
    if (existance == exists()) {
        if (existance && lastTime != fileTime(QFileDevice::FileModificationTime)) {
            lastTime = fileTime(QFileDevice::FileModificationTime);
            emit fileChanged(FileEvent::Changed, fileName(), size());
        }
    }
    else {
        existance = exists();
        if (existance) emit fileChanged(FileEvent::Exists, fileName(), size());
        else emit fileChanged(FileEvent::NotExists, fileName(), size());
    }
}

FileTracker &FileTracker::operator=(const FileTracker &other) {
    existance = other.existance;
    lastTime = other.lastTime;
    return *this;
}

FileTracker::FileTracker(const FileTracker &other) : QFile(other.fileName()) {
    existance = other.existance;
    lastTime = other.lastTime;
}
