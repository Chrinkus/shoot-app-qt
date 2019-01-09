#ifndef SHOOTER_H
#define SHOOTER_H

#include <QString>

#include "shoot-app-core_global.h"

class SHOOTAPPCORESHARED_EXPORT Shooter
{
public:
    explicit Shooter(const QString& name);

    int id() const { return m_id; }
    void id(int id) { m_id = id; }

    QString name() const { return m_name; }
    void name(const QString& name) { m_name = name; }

private:
    int m_id;
    QString m_name;
};

#endif // SHOOTER_H
