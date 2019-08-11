
#include "ItemGml.h"

REGISTER_ITEM("gml", ItemGml);

ItemGml::ItemGml(const QString &type, Item *parent) :
    ItemTabWidget(type, parent)
{

}

ItemGml::~ItemGml()
{

}

Item* ItemGml::Creator(const QString &type, Item* parent)
{
    return new ItemGml(type, parent);
}

void ItemGml::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);
}
