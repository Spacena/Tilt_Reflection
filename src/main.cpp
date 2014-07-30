/*
 * main.cpp
 *
 *  Created on: Jul 25, 2014
 *      Author: Kunal
 */

#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include "applicationui.hpp"

#include <Qt/qdeclarativedebug.h>
#include "Calendar.hpp"
#include "timer.hpp"
#include "settings.hpp"

using namespace bb::cascades;

Q_DECL_EXPORT int main(int argc, char **argv)
{
    Application app(argc, argv);

    qmlRegisterType<Timer>("bb.device", 1, 0, "Timer");
    qmlRegisterType<Calendar>("bb.device", 1, 0, "Calendar");

    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml");

    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();

    qml->setContextProperty("mySettings", new Settings(&app));

    // Set created root object as the application scene
    Application::instance()->setScene(root);

    new ApplicationUI(&app);
    // Enter the application main event loop.
    return Application::exec();
}
