#ifndef ITEM_LINE_EDIT_H_
#define ITEM_LINE_EDIT_H_

#include "Item.h"
#include <QLineEdit>

class ItemLineEdit : public Item
{
public:
    ItemLineEdit(const QString &type, Item *parent = nullptr);
    ~ItemLineEdit();

    static Item *Creator(const QString &type, Item *parent);

    ItemLineEdit &operator<<(const QString &text);
    QString Value();
    void Clear();
    void SetDirection(const QString &dir);

    inline virtual QWidget *Widget() { return m_ledit; }
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

private:
    static bool m_registered_in_ItemFactory;
    QLineEdit *m_ledit;
};

#endif
