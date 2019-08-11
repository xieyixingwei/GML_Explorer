
#include "ItemLineEdit.h"

REGISTER_ITEM("line_edit", ItemLineEdit);

ItemLineEdit::ItemLineEdit(const QString &type, Item *parent) :
    Item(type, parent)
{
    m_ledit = new QLineEdit(nullptr != parent ? parent->Widget() : nullptr);
}

ItemLineEdit::~ItemLineEdit()
{

}

Item *ItemLineEdit::Creator(const QString &type, Item *parent)
{
    return new ItemLineEdit(type, parent);
}

ItemLineEdit &ItemLineEdit::operator<<(const QString &text)
{
    m_ledit->setText(m_ledit->text() + text);
    return *this;
}

QString ItemLineEdit::Value()
{
    return m_ledit->text();
}

void ItemLineEdit::Clear()
{
    m_ledit->clear();
}

void ItemLineEdit::SetDirection(const QString &dir)
{
    if("rw" == dir || "wr" == dir)
    {
        m_ledit->setReadOnly(false);
    }
    else if("r" == dir)
    {
        m_ledit->setReadOnly(true);
    }
}

void ItemLineEdit::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);

    m_ledit->setText(attrs["text"]);
    SetDirection(attrs["dir"]);
}
