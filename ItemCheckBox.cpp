
#include "ItemCheckBox.h"

REGISTER_ITEM("check_box", ItemCheckBox);

ItemCheckBox::ItemCheckBox(const QString &type, Item *parent) :
    Item(type, parent)
{
    m_checkbox = new QCheckBox(nullptr != parent ? parent->Widget() : nullptr);
}

ItemCheckBox::~ItemCheckBox()
{

}

Item *ItemCheckBox::Creator(const QString &type, Item *parent)
{
    return new ItemCheckBox(type, parent);
}

void ItemCheckBox::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);
    m_checkbox->setText(attrs["text"]);
    SetValue(attrs["value"]);
}

void ItemCheckBox::SetValue(const QString &value)
{
    bool check = false;

    if("true" == value)
    {
        check = true;
    }
    else if("false" == value)
    {
        check = false;
    }
    else
    {
        check = value.toInt() ? true : false;
    }

    m_checkbox->setChecked(check);
}

bool ItemCheckBox::Value()
{
    return m_checkbox->isChecked();
}
