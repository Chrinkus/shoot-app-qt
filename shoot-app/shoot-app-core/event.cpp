#include "event.h"

Event::Event(QString name, const QString& date) :
    m_id{-1},
    m_scorer{std::move(name)},
    m_start{QDate::fromString(date, date_format)}
{
}

QString Event::start_str() const
{
    return m_start.toString(date_format);
}

void Event::start_str(const QString& start)
{
    m_start = QDate::fromString(start, date_format);
}
