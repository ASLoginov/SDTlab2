#ifndef TRACKINGMANAGER_H
#define TRACKINGMANAGER_H

#include "filetracker.h"
#include <QObject>
#include <QTimer>
#include <QHash>

class TrackingManager : public QObject {

    Q_OBJECT

    QHash<QString, FileTracker> fileList;
    QTimer timer;

    TrackingManager(const TrackingManager&);
    TrackingManager& operator=(const TrackingManager&);

public:

    TrackingManager();

public slots:
    void Attach(QString fileName);
    void Detach(QString fileName);
    void resendSignal(int event, QString name, qint64 size);
    void Update();

signals:
    void fileAttached(QString fileName, bool existance, qint64 size);
    void fileDetached(QString fileName);
    void fileChanged(int event, QString name, qint64 size);

};

#endif // TRACKINGMANAGER_H
