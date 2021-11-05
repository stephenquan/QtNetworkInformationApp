#include "EnumInfo.h"
#include <QDebug>

//----------------------------------------------------------------------

QStringList EnumInfo::keys() const
{
    QStringList list;
    int keyCount = m_MetaEnum.keyCount();
    for (int index = 0; index < keyCount; index++)
    {
        QString key = QString::fromUtf8(m_MetaEnum.key(index));
        list.append(key);
    }
    return list;
}

//----------------------------------------------------------------------

QVariant EnumInfo::values() const
{
    qDebug() << Q_FUNC_INFO;
    QVariantList list;
    int keyCount = m_MetaEnum.keyCount();
    for (int index = 0; index < keyCount; index++)
    {
        int value = m_MetaEnum.keyToValue(m_MetaEnum.key(index));
        list.append(value);
    }
    return list;
}

//----------------------------------------------------------------------
