
#include "ItemFrame.h"
#include <QTabWidget>

ItemTabFrame::ItemTabFrame(Item* parent = NULL)
    : Item(parent)
{
    m_qframe = new QFrame(NULL != parent ? parent->GetWidget() : NULL);
    this->SetWidget(m_qframe);

    m_is_item_tab = true;
}

ItemTabFrame::~ItemTabFrame()
{

}

Item* ItemTabFrame::Creator(Item* parent)
{
    return new ItemTabFrame(parent);
}

void ItemTabFrame::AttrSetName(const string& name)
{
    QTabWidget* pTabWidget = dynamic_cast<QTabWidget*>(this->GetParent()->GetWidget());

    pTabWidget->setTabText(pTabWidget->count() - 1, QString(name.data()));
}

