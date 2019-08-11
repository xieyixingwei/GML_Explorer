#ifndef ITEM_GML_H_
#define ITEM_GML_H_

#include "ItemTabWidget.h"
#include <QFrame>

class ItemGml : public ItemTabWidget
{
public:
    ItemGml(const QString &type, Item *parent = nullptr);
    ~ItemGml();

    static Item *Creator(const QString &type, Item *parent);
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

private:
    static bool m_registered_in_ItemFactory;
};

#endif
