#include "NetworkInformation.h"
#include <QDebug>

NetworkInformation::NetworkInformation(QObject* parent) :
    QObject(parent),
    m_Reachability(NetworkReachabilityEnum::NetworkReachability::ReachabilityUnknown)
{
    /*bool ok = QNetworkInformation::load(QNetworkInformation::Feature::Reachability
                                        | QNetworkInformation::Feature::CaptivePortal);
                                        */

    bool ok = true;
    QStringList backends = QNetworkInformation::availableBackends();
    if (backends.count() > 0)
    {
        QString backend = backends[0];
        ok = QNetworkInformation::load(backend);
    }
    qDebug() << ok;

    QNetworkInformation* instance = QNetworkInformation::instance();
    connect(instance, &QNetworkInformation::reachabilityChanged, this, &NetworkInformation::onReachabilityChanged);

    setReachability(instance->reachability());
}

NetworkInformation::~NetworkInformation()
{
}

void NetworkInformation::onReachabilityChanged(QNetworkInformation::Reachability newReachability)
{
    setReachability(newReachability);
}

void NetworkInformation::setReachability(QNetworkInformation::Reachability newReachability)
{
    setReachability(static_cast<NetworkReachabilityEnum::NetworkReachability>(newReachability));
}

void NetworkInformation::setReachability(NetworkReachabilityEnum::NetworkReachability newReachability)
{
    if (m_Reachability == newReachability)
    {
        return;
    }

    qDebug() << Q_FUNC_INFO << newReachability;

    m_Reachability = newReachability;

    emit reachabilityChanged();
}
