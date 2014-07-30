/*
 * Calendar.cpp
 *
 *  Created on: Jul 25, 2014
 *      Author: Kunal
 */

#include "Calendar.hpp"

#include <bb/pim/calendar/CalendarEvent>
#include <bb/pim/calendar/CalendarFolder>
#include <bb/pim/calendar/EventKey>
#include <bb/pim/calendar/EventSearchParameters>

using namespace bb;
using namespace bb::cascades;
using namespace bb::pim::calendar;

Q_DECLARE_METATYPE(bb::pim::calendar::CalendarEvent)

//! [0]
Calendar::Calendar(QObject *parent)
    : bb::cascades::CustomControl()
    , m_model(new GroupDataModel(this))
    , m_calendarService(new CalendarService())
{
    // Disable grouping in data model
    m_model->setGrouping(ItemGrouping::None);

    // Ensure to invoke the filterEvents() method whenever an event has been added, changed or removed
    bool ok = connect(m_calendarService, SIGNAL(eventsRefreshed(bb::pim::calendar::EventRefresh)), SLOT(filterEvents()));
    Q_ASSERT(ok);
    Q_UNUSED(ok);

    filterEvents();
}

bb::cascades::GroupDataModel* Calendar::model() const
{
    return m_model;
}

QString Calendar::filter() const
{
    return m_filter;
}

//! [6]
void Calendar::setFilter(const QString &filter)
{
    if (m_filter == filter)
        return;


    // Calculate the search range depending on the filter input


    // Update the model now that the filter criterion has changed
    filterEvents();
}

void Calendar::filterEvents()
{
	const QDate today = QDate::currentDate();
	const QTime midnight(0, 0, 0);

	m_searchStartTime = QDateTime(today, midnight);
	m_searchEndTime = QDateTime(today.addDays(7), midnight);

    // Setup the search parameters with time range as specified by filter criterion
    EventSearchParameters searchParameters;
    QPair<SortField::Type,bool> sort;
            sort.first = bb::pim::calendar::SortField::StartTime;
            sort.second = false;
    searchParameters.setStart(m_searchStartTime);
    searchParameters.setEnd(m_searchEndTime);
    searchParameters.setSort(sort);
    searchParameters.setDetails(DetailLevel::Weekly);

    const QList<CalendarEvent> events = m_calendarService->events(searchParameters);

    // Clear the old events information from the model
    m_model->clear();
    foreach (const CalendarEvent &event, events) {
                // Copy the data into a model entry
                QVariantMap entry;
                entry["eventId"] = event.id();
                entry["accountId"] = event.accountId();
                entry["subject"] = event.subject();
                entry["startTime"] = event.startTime().toString(Qt::DefaultLocaleShortDate);
                entry["endTime"] = event.endTime().toString(Qt::DefaultLocaleShortDate);

                // Add the entry to the model
                m_model->insert(entry);
            }
}
//! [7]
