
#include "ItemLabel.h"

REGISTER_ITEM("label", ItemLabel);

ItemLabel::ItemLabel(const QString &type, Item *parent) :
    Item(type, parent)
{
    m_label = new QLabel(nullptr != parent ? parent->Widget() : nullptr);
}

ItemLabel::~ItemLabel()
{

}

Item *ItemLabel::Creator(const QString &type, Item *parent)
{ 
    return new ItemLabel(type, parent);
}

void ItemLabel::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);
    m_label->setText(attrs["text"]);
}

QString ItemLabel::Value()
{
    return m_label->text();
}
