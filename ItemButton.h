#ifndef ITEM_BUTTON_H_
#define ITEM_BUTTON_H_

#include "Item.h"
#include <QPushButton>
#include <QObject>

class ItemButton :  public QObject, public Item
{
    Q_OBJECT

public:
    ItemButton(const QString &type, Item *parent = nullptr);
    ~ItemButton();

    static Item* Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_pushbtn; }
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

private:
    void SetTextAttr(const QString &text);
    void SetBackColorAttr(const QString &color);

private slots:
    void ButtonPressed_Slot(void);

private:
    static bool m_registered_in_ItemFactory;
    QPushButton *m_pushbtn;
};

#endif
