#ifndef ITEM_Label_H_
#define ITEM_Label_H_

#include "Item.h"
#include <QLabel>

class ItemLabel : public Item
{
public:
    ItemLabel(const QString &type, Item *parent = nullptr);
    ~ItemLabel();

    static Item *Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_label; }
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);
    QString Value();

private:
    static bool m_registered_in_ItemFactory;
    QLabel *m_label;
};

#endif
