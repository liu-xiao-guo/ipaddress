#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QNetworkInterface>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    QStringList datalist;

    for(int nIter = 0; nIter < list.count(); nIter++) {
        qDebug() << list[ nIter ].toString();
        datalist.append(list[ nIter ].toString());
    }

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:///Main.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    QQmlContext *ctxt = view.rootContext();
    ctxt->setContextProperty("myModel", QVariant::fromValue(datalist));

    view.show();
    return app.exec();
}

