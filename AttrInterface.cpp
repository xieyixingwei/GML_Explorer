
#include "Gml.h"
#include "Tag.h"
#include "AttrInterface.h"
#include "Item.h"

#include <iostream>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QPalette>
#include <QColor>
#include <QFont>

using namespace std;
#if 0
void Item::RealizeAttrs(AbstractTag* tag)
{

    QString name = tag->GetAttr(ATTR_NAME);
    if(!name.isEmpty())
    {
        AttrSetName(name);
    }

    QString value = tag->GetAttr(ATTR_VALUE);
    if(!value.isEmpty())
    {
        AttrSetValue(value);
    }

    QString id = tag->GetAttr(ATTR_ID);
    if(!id.isEmpty())
    {
        AttrSetId(id, tag->GetOwnGml());
    }

    QString stretch = tag->GetAttr(ATTR_STRETCH);
    if(!stretch.isEmpty())
    {
        AttrSetStretch(stretch);
    }

    QString access = tag->GetAttr(ATTR_ACCESS);
    if(!access.isEmpty())
    {
        AttrSetAccess(access);
    }

    QString dir = tag->GetAttr(ATTR_DIR);
    if(!dir.isEmpty())
    {
        AttrSetDir(dir);
    }

    QString bgcolor = tag->GetAttr(ATTR_BACKCOLOR);
    if(!bgcolor.isEmpty())
    {
        AttrSetBackColor(bgcolor);
    }

    QString fgcolor = tag->GetAttr(ATTR_FORECOLOR);
    if(!fgcolor.isEmpty())
    {
        AttrSetForeColor(fgcolor);
    }

    QString font = tag->GetAttr(ATTR_FONT);
    if(!font.isEmpty())
    {
        AttrSetFont(font);
    }

    QString protocol = tag->GetAttr(ATTR_PROTOCOL);
    if(!protocol.isEmpty())
    {
        AttrSetProtocol(protocol);
    }

}

QBoxLayout* Item::AttrGetAlign(const QString& align, QWidget* parent = nullptr)
{
    if("vertical" == align)
    {
        return new QVBoxLayout(parent);
    }
    else if("horizontal" == align)
    {
        return new QHBoxLayout(parent);
    }
    else
    {
        return new QVBoxLayout(parent);
    }
}

void Item::AttrSetName(const QString& name)
{

}

void Item::AttrSetId(const QString& id, Gml* gml)
{
    //gml->AddIdItem(id, this);
}

void Item::AttrSetValue(const QString& value)
{

}

void Item::AttrSetStretch(const QString& stretch)
{
    this->m_stretch = stretch.toInt();
}

void Item::AttrSetAccess(const QString& access)
{
    bool enable = false;

    if("true" == access)
    {
        enable = true;
    }
    else if("false" == access)
    {
        enable = false;
    }
    else
    {
        enable = access.toInt() ? true : false;
    }

    if(nullptr != m_widget)
    {
        m_widget->setEnabled(enable);
    }
}

void Item::AttrSetDir(const QString& dir)
{

}

void Item::AttrSetBackColor(const QString& color)
{
    QPalette palette(m_widget->palette());
    palette.setColor(QPalette::Background, QColor(color.toInt()));

    m_widget->setAutoFillBackground(true);
    m_widget->setPalette(palette);
}

void Item::AttrSetForeColor(const QString& color)
{
    QPalette palette(m_widget->palette());
    palette.setColor(QPalette::WindowText, QColor(color.toInt()));

    m_widget->setAutoFillBackground(true);
    m_widget->setPalette(palette);
}

void Item::AttrSetFont(const QString& font)
{
    m_widget->setFont(QFont(font));
}

void Item::AttrSetProtocol(const QString& protocol)
{
    QString tmp = protocol;

    //Gml::ClearBeginEnd(tmp, '[', ']');
    QStringList protocolList = tmp.split(';', QString::SkipEmptyParts);

    for(int i = 0; i < protocolList.count(); i++)
    {
        QStringList val = protocolList[i].trimmed().split('%', QString::SkipEmptyParts);

        if(2 == val.count())
        {
            m_protocol.append(qMakePair(val[0].trimmed(), val[1].trimmed()));
        }
    }
}
#endif
