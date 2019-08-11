
#include "ItemButton.h"
#include <QColor>

REGISTER_ITEM("button", ItemButton);

ItemButton::ItemButton(const QString &type, Item* parent) :
    Item(type, parent)
{
    m_pushbtn = new QPushButton(nullptr != parent ? parent->Widget() : nullptr);

    connect(m_pushbtn, SIGNAL(clicked(bool)), this, SLOT(ButtonPressed_Slot()));
}

ItemButton::~ItemButton()
{

}

Item *ItemButton::Creator(const QString &type, Item* parent)
{
    return new ItemButton(type, parent);
}

void ItemButton::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);

    m_pushbtn->setText(attrs["text"]);
    SetBackColorAttr(attrs["backcolor"]);
}

void ItemButton::SetBackColorAttr(const QString &color)
{
    QPalette palette(m_pushbtn->palette());
    palette.setColor(QPalette::Background, QColor(color.toUInt()));

    m_pushbtn->setAutoFillBackground(true);
    m_pushbtn->setPalette(palette);
    m_pushbtn->setFlat(true);
}

void ItemButton::ButtonPressed_Slot()
{

}
