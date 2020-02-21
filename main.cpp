#include <QApplication>
#include <QCommandLineParser>
#include <QWebEngineView>

QUrl commandLineUrlArgument(const QStringList args)
{
    if ( args.length() > 0) return QUrl::fromUserInput(args.at(0));
    else return QUrl(QStringLiteral("http://localhost"));
}

int main(int argc, char *argv[])
{
    // safely set the environment variable to support virtual keyboard
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationName("almedso GmbH");
    QCoreApplication::setApplicationName("Qt5-Browser-Single-View-app");
    QCoreApplication::setApplicationVersion("1.0");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QCommandLineParser parser;
    parser.addPositionalArgument("URL", QCoreApplication::translate("main", "URL to load into browser"));
    parser.addHelpOption();
    parser.addVersionOption();

    // Height
    QCommandLineOption heightOption(QStringList() << "l" << "height",
            QCoreApplication::translate("main", "Height of the application window (default 800"),
            QCoreApplication::translate("main", "height"), "800");
    parser.addOption(heightOption);
    // Width
    QCommandLineOption widthOption(QStringList() << "w" << "width",
            QCoreApplication::translate("main", "Width of the application window (default 480)"),
            QCoreApplication::translate("main", "width"), "480");
    parser.addOption(widthOption);

    QApplication app(argc, argv);

    // Process the actual command line arguments given by the user
    parser.process(app);
    const QStringList args = parser.positionalArguments();

    int height = parser.value(heightOption).toInt();
    if ( height == 0 ) height = 800;
    int width = parser.value(widthOption).toInt();
    if ( width == 0 ) height = 480;

    QWebEngineView view;
    view.setUrl(commandLineUrlArgument(args));
    view.resize(width, height);
    view.show();

    return app.exec();
}
