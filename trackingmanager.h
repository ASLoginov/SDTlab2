#ifndef TRACKINGMANAGER_H
#define TRACKINGMANAGER_H

#include "filetracker.h"
#include <QObject>
#include <QTimerEvent>
#include <QHash>

class TrackingManager : public QObject {
    Q_OBJECT

    QString name;
    QHash<QString, FileTracker> fileList;
    int timer;

    TrackingManager();

    TrackingManager(const TrackingManager&);
    TrackingManager& operator=(const TrackingManager&);

public:
    static TrackingManager& Instance();

public slots:
    void Attach(QString fileName);
    void Detach(QString fileName);
    void resendSignal(FileEvent event, QString name, qint64 size);

signals:
    void fileAttached(QString fileName, bool existance, qint64 size);
    void fileDetached(QString fileName);
    void fileChanged(FileEvent event, QString name, qint64 size);

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // TRACKINGMANAGER_H
