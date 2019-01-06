#ifndef SHOOTER_H
#define SHOOTER_H

#include <QString>

class Shooter
{
public:
    explicit Shooter(QString name);

    void id(int id) { m_id = id; }

    int id() const { return m_id; }
    QString name() const { return m_name; }

private:
    int m_id;
    QString m_name;
};

#endif // SHOOTER_H
