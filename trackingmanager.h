#ifndef TRACKINGMANAGER_H
#define TRACKINGMANAGER_H

#include "filetracker.h"
#include <QObject>
#include <QTimer>
#include <QHash>

class TrackingManager : public QObject {
    Q_OBJECT

    QString name;
    QHash<QString, FileTracker> fileList;
    QTimer timer;

    TrackingManager();
    ~TrackingManager();

    TrackingManager(const TrackingManager&);
    TrackingManager& operator=(const TrackingManager&);

public:
    static TrackingManager& Instance();

public slots:
    void Attach(QString fileName);
    void Detach(QString fileName);
    void resendSignal(FileEvent event, QString name, qint64 size);
    void stopTimer();
    void Update();

signals:
    void fileAttached(QString fileName, bool existance, qint64 size);
    void fileDetached(QString fileName);
    void fileChanged(FileEvent event, QString name, qint64 size);

};

#endif // TRACKINGMANAGER_H
