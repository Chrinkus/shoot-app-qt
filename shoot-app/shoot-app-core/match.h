#ifndef MATCH_H
#define MATCH_H

#include "shoot-app-core_global.h"

class SHOOTAPPCORESHARED_EXPORT Match
{
public:
    Match();

    int id() const { return m_id; }
    void id(int id) { m_id = id; }
    double score() const { return m_score; }
    void score(double score) { m_score = score; }
    int shooter_id() const { return m_shooter_id; }
    void shooter_id(int id) { m_shooter_id = id; }
    int event_id() const { return m_event_id; }
    void event_id(int id) { m_event_id = id; }
    int aggregate_id() const { return m_aggregate_id; }
    void aggregate_id(int id) { m_aggregate_id = id; }
    int match_number() const { return m_number; }
    void match_number(int num) { m_number = num; }

private:
    int m_id;
    double m_score;
    int m_shooter_id;
    int m_event_id;
    int m_aggregate_id;
    int m_number;
};

#endif // MATCH_H
