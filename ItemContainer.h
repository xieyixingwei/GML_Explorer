#ifndef ITEM_CONTAINER_H_
#define ITEM_CONTAINER_H_

#include "Item.h"
#include <QGroupBox>

class ItemContainer : public Item
{
public:
    ItemContainer(const QString &type, Item *parent = nullptr);
    ~ItemContainer();

    static Item* Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_groupbox; }

private:
    static bool m_registered_in_ItemFactory;
    QGroupBox *m_groupbox;
};

#endif
