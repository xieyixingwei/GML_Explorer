
#include "Gml.h"
#include "ItemComboBox.h"
#include <QString>
#include <vector>
#include <QStringList>

REGISTER_ITEM("combo_box", ItemComboBox);

ItemComboBox::ItemComboBox(const QString &type, Item *parent) :
    Item(type, parent)
{
    m_combobox = new QComboBox(nullptr != parent ? parent->Widget() : nullptr);
}

ItemComboBox::~ItemComboBox()
{

}

Item *ItemComboBox::Creator(const QString &type, Item *parent)
{
    return new ItemComboBox(type, parent);
}

void ItemComboBox::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);

    QString value = attrs["value"];

    m_combobox->addItems(value.remove("[").remove("]").trimmed().split(";"));
}

QString ItemComboBox::Value()
{
    return m_combobox->currentText();
}
