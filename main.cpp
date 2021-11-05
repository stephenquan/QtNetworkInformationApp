#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QJSEngine>
#include "NetworkInformation.h"
#include "NetworkReachability.h"

template<typename T>
T *singletonProvider(QQmlEngine*, QJSEngine *)
{
    return new T();
}

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<NetworkInformation>("QtNetworkInformationApp", 1, 0, "NetworkInformation");
    qmlRegisterSingletonType<NetworkReachabilityEnum>("QtNetworkInformationApp", 1, 0, "NetworkReachability", singletonProvider<NetworkReachabilityEnum> );
    qmlRegisterUncreatableType<EnumInfo>("QtNetworkInformationApp", 1, 0, "EnumInfo", QStringLiteral("EnumInfo not creatable"));

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
