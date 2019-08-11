
#include "ItemTabWidget.h"
#include "Item.h"
#include "Gml.h"
#include <QString>
#include <QDebug>

ItemFactory& ItemFactory::Create(void)
{
    static ItemFactory itemFactory;

    return itemFactory;
}

bool ItemFactory::RegisterItem(const QString &type, ItemCreatorFunc hook)
{
    ItemCreatorMap_t::iterator it = m_item_creator_map.find(type);

    if(it == m_item_creator_map.end())
    {
        m_item_creator_map[type] = hook;
        return true;
    }

    return false;
}

Item *ItemFactory::NewItem(const QString &type, Item *parent)
{
    Item *newObject = nullptr;
    ItemCreatorMap_t::iterator it = m_item_creator_map.find(type);

    if(it != m_item_creator_map.end())
    {
        newObject = (*it)(type, parent);
    }
    else
    {
        qDebug() << "Can't find " << type << " ****************\r\n";
    }

    return newObject;
}

Item::Item(const QString &type, Item *parent) :
    m_parent(parent),
    m_type(type),
    m_name(""),
    m_stretch(0),
    m_layout(nullptr)
{

}

QBoxLayout* Item::NewLayout(const QString &align, Item *parent)
{
    if("vertical" == align)
    {
        return new QVBoxLayout(parent->Widget());
    }
    else if("horizontal" == align)
    {
        return new QHBoxLayout(parent->Widget());
    }
    else
    {
        return new QVBoxLayout(parent->Widget());
    }
}

void Item::AddChildItem(Item *item)
{
    m_layout->addWidget(item->Widget(), item->Stretch());
    m_children << item;
}

Item &Item::operator<<(Item *item)
{
    AddChildItem(item);
    return *this;
}

void Item::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    m_name = attrs["name"];
    m_stretch = attrs["stretch"].toInt();
    m_layout = NewLayout(attrs["align"], this);
}
