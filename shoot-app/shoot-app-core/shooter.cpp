#include "shooter.h"

Shooter::Shooter(QString name) :
    m_id{-1},
    m_name{std::move(name)}
{

}
