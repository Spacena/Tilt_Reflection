/*
 * settings.cpp
 *
 *  Created on: Jul 29, 2014
 *      Author: Kunal
 */

#include "settings.hpp"

#include <QCoreApplication>
#include <QSettings>

Settings::Settings(QObject *parent)
: QObject(parent)
{

	QCoreApplication::setOrganizationName("Kknows");
	QCoreApplication::setApplicationName("Tilt");

	QSettings settings;

    m_tilt = settings.value("tilt", 1).toInt();
    settings.setValue("tilt", m_tilt);
}

void Settings::onManualExit() {
	    qApp->exit(0);
}

int Settings::tilt() const
{
    return m_tilt;
}
void Settings::setTilt(int mode)
{
    if (m_tilt == mode)
        return;

    m_tilt = mode;

    QSettings settings;
    settings.setValue("tilt", m_tilt);

    emit tiltChanged();
}


