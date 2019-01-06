#include "event.h"


Event::Event(QString name, QDate date) :
    m_id{-1},
    m_scorer{std::move(name)},
    m_start{std::move(date)}
{
}
