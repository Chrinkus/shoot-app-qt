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

const QString date_format = "dd.MMM.yyyy";

class SHOOTAPPCORESHARED_EXPORT Event
{
public:
    Event(QString name, const QString& date);

    int id() const { return m_id; }
    void id(int id) { m_id = id; }

    QString scorer() const { return m_scorer; }
    void scorer(const QString& scorer) { m_scorer = scorer; }

    QDate start() const { return m_start; }
    void start(const QDate& start) { m_start = start; }

    QString start_str() const;
    void start_str(const QString& start);

private:
    int m_id;
    QString m_scorer;
    QDate m_start;
};

#endif // EVENT_H
