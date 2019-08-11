#ifndef ITEM_GROUP_BOX_H_
#define ITEM_GROUP_BOX_H_

#include "Item.h"
#include <QGroupBox>

class ItemGroupBox : public Item
{
public:
    ItemGroupBox(const QString &type, Item *parent = nullptr);
    ~ItemGroupBox();

    static Item *Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_groupbox; }
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

private:
    static bool m_registered_in_ItemFactory;
    QGroupBox *m_groupbox;
};

#endif
