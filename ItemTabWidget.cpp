
#include "ItemTabWidget.h"
#include <QObject>
#include <QDebug>

REGISTER_ITEM("tabpage", ItemTabWidgetPage);

ItemTabWidgetPage::ItemTabWidgetPage(const QString &type, Item *parent) :
    Item(type, parent)
{
    m_tabpage = new QFrame(nullptr != m_parent ? m_parent->Widget() : nullptr);
}

ItemTabWidgetPage::~ItemTabWidgetPage()
{

}

Item *ItemTabWidgetPage::Creator(const QString &type, Item *parent)
{
    return new ItemTabWidgetPage(type, parent);
}

REGISTER_ITEM("tab", ItemTabWidget);

ItemTabWidget::ItemTabWidget(const QString &type, Item *parent) :
    Item(type, parent)
{
    m_tabwdg = new QTabWidget(nullptr != m_parent ? m_parent->Widget() : nullptr);
}

ItemTabWidget::~ItemTabWidget()
{

}

Item *ItemTabWidget::Creator(const QString &type, Item *parent)
{
    return new ItemTabWidget(type, parent);
}

void ItemTabWidget::AddChildItem(Item *item)
{
    if("tabpage" == item->Type())
    {
        m_tabwdg->addTab(item->Widget(), item->Name());
        m_children << item;
    }
    else
    {
        Item::AddChildItem(item);
    }
}

Item &ItemTabWidget::operator<<(Item *item)
{
    AddChildItem(item);

    return *this;
}
