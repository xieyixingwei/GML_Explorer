#ifndef ITEM_TAB_WIDGET_H_
#define ITEM_TAB_WIDGET_H_

#include "Item.h"
#include <QTabWidget>
#include <QFrame>
#include <QVector>

class ItemTabWidgetPage : public Item
{
public:
    ItemTabWidgetPage(const QString &type, Item *parent = nullptr);
    ~ItemTabWidgetPage();

    static Item *Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_tabpage; }

private:
    static bool m_registered_in_ItemFactory;
    QFrame *m_tabpage;
};

class ItemTabWidget : public Item
{
public:
    ItemTabWidget(const QString &type, Item *parent = nullptr);
    ~ItemTabWidget();

    static Item *Creator(const QString &type, Item *parent);

    inline virtual QWidget *Widget() { return m_tabwdg; }
    virtual void AddChildItem(Item *item);
    virtual Item &operator<<(Item *item);

protected:
    QTabWidget *m_tabwdg;

private:
    static bool m_registered_in_ItemFactory;
};

#endif
