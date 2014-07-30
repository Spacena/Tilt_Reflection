/*
 * settings.hpp
 *
 *  Created on: Jul 29, 2014
 *      Author: Kunal
 */

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_
#include <QObject>

class Settings : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int tilt READ tilt WRITE setTilt NOTIFY tiltChanged)

public:
	Settings(QObject *parent = 0);

	Q_SIGNALS:

	void tiltChanged();

	private Q_SLOTS:
	        void onManualExit();

	private:
	     int tilt() const;
	     void setTilt(int mode);

	     int m_tilt;

};


#endif /* SETTINGS_HPP_ */
