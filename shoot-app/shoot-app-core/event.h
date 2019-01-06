/*
 * Event data class
 *
 * What information is needed for the event?
 * - who the scorer is
 * - when the event occurs
 * - where the event takes place? (only one location as of now)
 */

#ifndef EVENT_H
#define EVENT_H

#include <QDate>
#include <QString>

#include "shoot-app-core_global.h"

class SHOOTAPPCORESHARED_EXPORT Event
{
public:
    Event(QString name, QDate date);

    void id(int id) { m_id = id; }

    int id() const { return m_id; }
    QString scorer() const { return m_scorer; }
    QDate start() const { return m_start; }

private:
    int m_id;
    QString m_scorer;
    QDate m_start;
};

#endif // EVENT_H
