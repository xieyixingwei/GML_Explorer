#ifndef ITEM_TEXT_EDIT_H_
#define ITEM_TEXT_EDIT_H_

#include "Item.h"
#include <QTextEdit>

class ItemTextEdit : public Item
{
public:
    ItemTextEdit(const QString &type, Item *parent = nullptr);
    ~ItemTextEdit();

    static Item *Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_textedit; }
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

    void SetValue(const QString &value);
    QString Value();
    void Clear();
    void SetDirection(const QString &dir);

private:
    static bool m_registered_in_ItemFactory;
    QTextEdit *m_textedit;
};

#endif
