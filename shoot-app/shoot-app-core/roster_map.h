#ifndef ROSTER_MAP_H
#define ROSTER_MAP_H

#include "shoot-app-core_global.h"

class SHOOTAPPCORESHARED_EXPORT Roster_map
{
public:
    Roster_map();

    int event_id() const { return m_event_id; }
    void event_id(int id) { m_event_id = id; }

    int shooter_id() const { return m_shooter_id; }
    void shooter_id(int id) { m_shooter_id = id; }
private:
    int m_event_id = -1;
    int m_shooter_id = -1;
};

#endif // ROSTER_MAP_H
