
#include "ItemRadioButton.h"

REGISTER_ITEM("radio_button", ItemRadioButton);

ItemRadioButton::ItemRadioButton(const QString &type, Item* parent) :
    Item(type, parent)
{
    m_rdbtn = new QRadioButton(parent ? parent->Widget() : nullptr);
}

ItemRadioButton::~ItemRadioButton()
{

}

Item *ItemRadioButton::Creator(const QString &type, Item *parent)
{
    return new ItemRadioButton(type, parent);
}

void ItemRadioButton::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);
    SetValue(attrs["value"]);
}

void ItemRadioButton::SetValue(const QString &value)
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

    m_rdbtn->setChecked(check);
}

bool ItemRadioButton::Value()
{
    return m_rdbtn->isChecked();
}
