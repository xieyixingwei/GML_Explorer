
#include "ItemGroupBox.h"

REGISTER_ITEM("group_box", ItemGroupBox);

ItemGroupBox::ItemGroupBox(const QString &type, Item *parent) :
    Item(type, parent)
{
    m_groupbox = new QGroupBox(nullptr != parent ? parent->Widget() : nullptr);
}

ItemGroupBox::~ItemGroupBox()
{

}

Item *ItemGroupBox::Creator(const QString &type, Item *parent)
{
    return new ItemGroupBox(type, parent);
}

void ItemGroupBox::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);
    m_groupbox->setTitle(attrs["title"]);
}
