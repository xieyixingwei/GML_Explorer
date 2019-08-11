
#include "ItemContainer.h"

REGISTER_ITEM("container", ItemContainer);

ItemContainer::ItemContainer(const QString &type, Item *parent) :
    Item(type, parent)
{
    m_groupbox = new QGroupBox(nullptr != parent ? parent->Widget() : nullptr);
    m_groupbox->setStyleSheet("QGroupBox{border:none;}");
}

ItemContainer::~ItemContainer()
{

}

Item *ItemContainer::Creator(const QString &type, Item *parent)
{
    return new ItemContainer(type, parent);
}

