/*
 * Calendar.hpp
 *
 *  Created on: Jul 25, 2014
 *      Author: Kunal
 */

#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <bb/cascades/GroupDataModel>
#include <bb/pim/calendar/CalendarService>
#include <bb/pim/calendar/EventKey>
#include <bb/system/InvokeManager>
#include <bb/cascades/TabbedPane>

#include <QtCore/QObject>
#include <bb/cascades/CustomControl>

class EventEditor;
class EventViewer;

/**
 * @short The controller class that makes access to calendar data available to the UI.
 */
//! [0]
class Calendar : public bb::cascades::CustomControl
{
    Q_OBJECT

    // The model that provides the filtered list of events
    Q_PROPERTY(bb::cascades::GroupDataModel *model READ model CONSTANT);

    // The pattern to filter the list of events
    Q_PROPERTY(QString filter READ filter WRITE setFilter NOTIFY filterChanged);



public:
    Calendar(QObject *parent = 0);


Q_SIGNALS:
    // The change notification signal for the property
    void filterChanged();

private Q_SLOTS:
    // Filters the events in the model according to the filter property
    void filterEvents();

private:
    // The accessor methods of the properties
    bb::cascades::GroupDataModel* model() const;
    QString filter() const;
    void setFilter(const QString &filter);

    // The property values
    bb::cascades::GroupDataModel* m_model;
    QString m_filter;

    // The central object to access the calendar service
    bb::pim::calendar::CalendarService* m_calendarService;

    // The time range for event lookups (based on the filter criterion)
    QDateTime m_searchStartTime;
    QDateTime m_searchEndTime;
};
//! [0]

#endif
