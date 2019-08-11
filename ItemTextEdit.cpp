
#include "ItemTextEdit.h"

REGISTER_ITEM("text_edit", ItemTextEdit);

ItemTextEdit::ItemTextEdit(const QString &type, Item* parent) :
    Item(type, parent)
{
    m_textedit = new QTextEdit(nullptr != parent ? parent->Widget() : nullptr);
}

ItemTextEdit::~ItemTextEdit()
{

}

Item* ItemTextEdit::Creator(const QString &type, Item* parent)
{
    return new ItemTextEdit(type, parent);
}

void ItemTextEdit::SetValue(const QString &value)
{
    m_textedit->insertPlainText(value);
    m_textedit->moveCursor(QTextCursor::End);
}

QString ItemTextEdit::Value()
{
    return m_textedit->toPlainText();
}

void ItemTextEdit::Clear()
{
    m_textedit->clear();
}

void ItemTextEdit::SetDirection(const QString& dir)
{
    if("rw" == dir || "wr" == dir)
    {
        m_textedit->setReadOnly(false);
    }
    else if("r" == dir)
    {
        m_textedit->setReadOnly(true);
    }
}

void ItemTextEdit::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);

    SetDirection(attrs["dir"]);
    SetValue(attrs["text"]);
}
