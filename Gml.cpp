
#include "Gml.h"
#include <QDebug>
#include <QRegExp>
#include <QWidget>
#include <QHash>
#include <QStringList>

Gml::Gml(const QString &gmlText) :
    m_taglist(new QStringList),
    m_diaplay(new QTextEdit)
{
    Parse(gmlText);
    m_root_tag = new TagGroup(*m_taglist);
}

Gml::~Gml()
{
    if(nullptr != m_root_tag)
    {
        delete m_root_tag;
        m_root_tag = nullptr;
    }

    if(nullptr != m_taglist)
    {
        delete m_taglist;
        m_taglist = nullptr;
    }
}

Item* Gml::Create()
{
    if(nullptr == m_root_tag)
    {
        return nullptr;
    }

    return m_root_tag->Create(nullptr);
}

void Gml::Print()
{
    if(nullptr != m_root_tag)
    {
        m_diaplay->clear();
        m_diaplay->setText(m_root_tag->ToPrintString());
        m_diaplay->show();
    }
}

void Gml::Parse(const QString &gmlText)
{
    QRegExp rx("<[^>]*>");
    int pos = 0;

    while(-1 != (pos = rx.indexIn(gmlText, pos)))
    {
        *m_taglist << rx.cap(0).trimmed().remove("<").remove(">").trimmed();

        pos += rx.matchedLength();
    }
}
