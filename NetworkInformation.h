#ifndef __NetInfo__
#define __NetInfo__

#include <QObject>
#include <QNetworkInformation>
#include "NetworkReachability.h"

class NetworkInformation : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList availableBackends READ availableBackends CONSTANT)
    Q_PROPERTY(NetworkReachabilityEnum::NetworkReachability reachability READ reachability NOTIFY reachabilityChanged)

public:
    NetworkInformation(QObject* parent = nullptr);
    virtual ~NetworkInformation();

signals:
    void reachabilityChanged();

private slots:
     void onReachabilityChanged(QNetworkInformation::Reachability newReachability);

protected:
    QStringList availableBackends() const { return QNetworkInformation::availableBackends(); }
    NetworkReachabilityEnum::NetworkReachability m_Reachability;

    NetworkReachabilityEnum::NetworkReachability reachability() const { return m_Reachability; }
    void setReachability(NetworkReachabilityEnum::NetworkReachability newReachability);
    void setReachability(QNetworkInformation::Reachability newReachability);

};

#endif
