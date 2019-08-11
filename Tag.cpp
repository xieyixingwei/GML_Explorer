
#include "Tag.h"
#include "Item.h"

#include <QString>
#include <QVBoxLayout>
#include <QDebug>

TagInterface::~TagInterface()
{

}

Tag::Tag(const QString &tagText, int indent, TagInterface *parent) :
    m_indent(indent),
    m_parent(parent)
{
    Parse(tagText);
}

void Tag::Parse(const QString &tagText)
{
    m_type = GetType(tagText);

    QStringList list = tagText.split(',');

    for(int i = 1; i < list.count(); i++)
    {
        QStringList attr = list[i].split("=");
        if(2 == attr.count())
        {
            m_attrs[attr[0].trimmed()] = attr[1].trimmed();
        }
    }
}

QString Tag::ToPrintString()
{
    return ToIndentString() + "<" + m_type + ToAttrsString() + ", />\n";
}

QString Tag::ToIndentString()
{
    QString out;

    for(int i = 0; i < m_indent; i++)
    {
        out += "    ";
    }

    return out;
}

QString Tag::ToAttrsString()
{
    QString out;

    for(QMap<QString, QString>::iterator it = m_attrs.begin(); it != m_attrs.end(); it++)
    {
        out += ", " + it.key() + " = " + it.value();
    }

    return out;
}

QString Tag::GetType(const QString &tagText)
{
    return tagText.split(',')[0].trimmed();
}

Item* Tag::Create(Item *parent)
{
    Item* pItem = NEW_ITEM(m_type, parent);

    if(nullptr == pItem)
    {
        return nullptr;
    }

    pItem->ImplementAttrs(m_attrs);

    return pItem;
}

TagGroup::TagGroup(const QStringList &tagList, int indent, TagInterface *parent) :
    Tag(tagList[0], indent, parent)
{
    Parse(tagList);
}

void TagGroup::Parse(const QStringList &tagList)
{
    if(tagList.count() < 1)
    {
        return;
    }

    QList<QStringList> tagChildren = GetTagGroupList(tagList);

    for(int i = 0; i < tagChildren.count(); i++)
    {
        if(1 == tagChildren[i].count() && Tag::IsTag(tagChildren[i].at(0)))
        {
            m_children << new Tag(tagChildren[i].at(0), m_indent + 1, this);
        }
        else if(1 < tagChildren[i].count())
        {
            m_children << new TagGroup(tagChildren[i], m_indent + 1, this);
        }
    }
}

QList<QStringList> TagGroup::GetTagGroupList(const QStringList &tagList)
{
    QList<QStringList> tagGroups;
    QStringList tagGroup;
    QString tmpType;
    int inset = 0;

    for(int i = 1; i < tagList.count() - 1; i++)
    {
        tagGroup << tagList[i];

        if(tmpType.isEmpty() && !Tag::IsTag(tagList[i]))
        {
            tmpType = GetType(tagList[i]);
        }
        else if(tmpType.isEmpty() && Tag::IsTag(tagList[i]))
        {
            tagGroups << tagGroup;
            tagGroup.clear();
        }
        else if(!tmpType.isEmpty() && !Tag::IsTag(tagList[i]) && tmpType == GetType(tagList[i]))
        {
            inset++;
        }
        else if(!tmpType.isEmpty() && TagGroup::IsTagGroupEnd(tmpType, tagList[i]) && inset > 0)
        {
            inset--;
        }
        else if(!tmpType.isEmpty() && 0 == inset && TagGroup::IsTagGroupEnd(tmpType, tagList[i]))
        {
            tagGroups << tagGroup;
            tagGroup.clear();
            tmpType.clear();
        }
    }

    return tagGroups;
}

QString TagGroup::ToPrintString()
{
    QString out = ToIndentString() + "<" + m_type + ToAttrsString() + ">\n";

    for(QVector<TagInterface *>::iterator it = m_children.begin() ; it != m_children.end(); it++)
    {
        out += (*it)->ToPrintString();
    }

    out += ToIndentString() + "</" + m_type + ">\n";

    return out;
}

Item *TagGroup::Create(Item *parent)
{
    Item *itemGroup = NEW_ITEM(m_type, parent);

    if(nullptr == itemGroup)
    {
        return nullptr;
    }

    itemGroup->ImplementAttrs(m_attrs);

    for(QVector<TagInterface *>::Iterator it = m_children.begin() ; it != m_children.end(); it++)
    {
        itemGroup->AddChildItem((*it)->Create(itemGroup));
    }

    return itemGroup;
}



