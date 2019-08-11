#ifndef ITEM_CHECK_BOX_H_
#define ITEM_CHECK_BOX_H_

#include "Item.h"
#include <QCheckBox>

class ItemCheckBox : public Item
{
public:
    ItemCheckBox(const QString &type, Item *parent = nullptr);
    ~ItemCheckBox();

    static Item *Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_checkbox; }
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

    bool Value();
    void SetValue(const QString &value);

private:
    static bool m_registered_in_ItemFactory;
    QCheckBox *m_checkbox;
};

#endif
