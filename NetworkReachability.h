#ifndef __NetworkReachability__
#define __NetworkReachability__

#include <QNetworkInformation>
#include "EnumInfo.h"

class NetworkReachabilityEnum : public EnumInfo
{
    Q_OBJECT
public:
    enum class NetworkReachability
    {
        ReachabilityUnknown = static_cast<int>(QNetworkInformation::Reachability::Unknown),
        ReachabilityDisconnected = static_cast<int>(QNetworkInformation::Reachability::Disconnected),
        ReachabilityLocal = static_cast<int>(QNetworkInformation::Reachability::Local),
        ReachabilitySite = static_cast<int>(QNetworkInformation::Reachability::Site),
        ReachabilityOnline = static_cast<int>(QNetworkInformation::Reachability::Online)
    };
    Q_ENUM(NetworkReachability)

public:
    NetworkReachabilityEnum(QObject* parent = nullptr) :
        EnumInfo(QMetaEnum::fromType<NetworkReachability>(), parent) { }
    virtual ~NetworkReachabilityEnum() { }

};

#endif
