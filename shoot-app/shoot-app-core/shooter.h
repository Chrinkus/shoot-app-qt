#ifndef SHOOTER_H
#define SHOOTER_H

#include <QString>

#include "shoot-app-core_global.h"

class SHOOTAPPCORESHARED_EXPORT Shooter
{
public:
    explicit Shooter(const QString& first = "", const QString& last = "");

    int id() const { return m_id; }
    void id(int id) { m_id = id; }

    QString first() const { return m_first_name; }
    void first(const QString& first_name) { m_first_name = first_name; }

    QString last() const { return m_last_name; }
    void last(const QString& last_name) { m_last_name = last_name; }

private:
    int m_id;
    QString m_first_name;
    QString m_last_name;
};

#endif // SHOOTER_H
