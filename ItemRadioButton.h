#ifndef ITEM_BUTTON_H_
#define ITEM_BUTTON_H_

#include "Item.h"
#include <QRadioButton>

class ItemRadioButton : public Item
{
public:
    ItemRadioButton(const QString &type, Item *parent = nullptr);
    ~ItemRadioButton();

    static Item *Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_rdbtn; }
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

    void SetValue(const QString &value);
    bool Value();

private:
    static bool m_registered_in_ItemFactory;
    QRadioButton *m_rdbtn;
};

#endif
