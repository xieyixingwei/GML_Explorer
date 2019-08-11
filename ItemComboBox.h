#ifndef ITEM_COMBOBOX_H_
#define ITEM_COMBOBOX_H_

#include "Item.h"
#include <QComboBox>

class ItemComboBox : public Item
{
public:
    ItemComboBox(const QString &type, Item *parent = nullptr);
    ~ItemComboBox();

    static Item* Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_combobox; }
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

    QString Value();

private:
    static bool m_registered_in_ItemFactory;
    QComboBox *m_combobox;
};

#endif
