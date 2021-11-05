#ifndef __EnumInfo__
#define __EnumInfo__

#include <QObject>
#include <QMetaEnum>

class EnumInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList keys READ keys CONSTANT)
    Q_PROPERTY(QVariant values READ values CONSTANT)

public:
    EnumInfo(QObject* parent = nullptr): QObject(parent) { }
    EnumInfo(const QMetaEnum& metaEnum, QObject* parent = nullptr) : QObject(parent), m_MetaEnum(metaEnum) { }
    EnumInfo(const EnumInfo& enumInfo): QObject(nullptr), m_MetaEnum(enumInfo.m_MetaEnum) { }

    Q_INVOKABLE QString stringify(int value) const { return QString::fromUtf8(m_MetaEnum.valueToKey(value)); }
    Q_INVOKABLE int parse(const QString& key) const { return m_MetaEnum.keyToValue(key.toUtf8()); }

public:
    QStringList keys() const
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

    QVariant values()
    {
        QVariantList list;
        int keyCount = m_MetaEnum.keyCount();
        for (int index = 0; index < keyCount; index++)
        {
            int value = m_MetaEnum.keyToValue(m_MetaEnum.key(index));
            list.append(value);
        }
        return list;
    }

protected:
    QMetaEnum m_MetaEnum;

};

#endif
