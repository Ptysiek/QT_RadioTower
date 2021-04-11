#include <QApplication>
#include <FelgoApplication>

#include <QQmlApplicationEngine>
//#include <FelgoLiveClient> // uncomment this to add Live Client Module and use live reloading with custom C++ code


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FelgoApplication felgo;    
    felgo.setPreservePlatformFonts(true);   // Use platform-specific fonts instead of Felgo's default font

    QQmlApplicationEngine engine;
    felgo.initialize(&engine);
    felgo.setLicenseKey(PRODUCT_LICENSE_KEY); // Optional. Doesn't work with FelgoLive, only FelgoCloud Builds and local builds
    felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml")); // Use this during development, its entry point for PUBLISHING

    // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
    // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
    // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
    // also see the .pro file for more details
    //felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

    engine.load(QUrl(felgo.mainQmlFileName()));

    // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
    // and uncomment the line below
    //FelgoLiveClient client (&engine);

    return app.exec();
}

