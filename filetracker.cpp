#include "filetracker.h"

FileTracker::FileTracker(const QString &name) : QFile(name) {
    existance = exists();
    lastTime = fileTime(QFileDevice::FileModificationTime);
}

void FileTracker::Update() {
    if (existance == exists()) {
        if (existance && lastTime != fileTime(QFileDevice::FileModificationTime)) {
            lastTime = fileTime(QFileDevice::FileModificationTime);
            emit fileChanged(2, fileName(), size());
        }
    }
    else {
        existance = exists();
        if (existance) emit fileChanged(1, fileName(), size());
        else emit fileChanged(0, fileName(), size());
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
