#ifndef FILETRACKER_H
#define FILETRACKER_H

#include <QFile>
#include <QDateTime>

enum class FileEvent {
    NotExists,
    Exists,
    Changed
};

class FileTracker : public QFile {
    Q_OBJECT

    bool existance;
    QDateTime lastTime;

public:
    FileTracker() {};
    FileTracker(const QString& name);
    void Update();

    FileTracker& operator=(const FileTracker& other);
    FileTracker(const FileTracker& other);

signals:
    void fileChanged(FileEvent event, QString name, qint64 size);
};

#endif // FILETRACKER_H
