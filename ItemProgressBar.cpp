
#include "ItemProgressBar.h"
#include "Gml.h"
#include <QStringList>

using namespace std;

REGISTER_ITEM("progress_bar", ItemProgressBar);

ItemProgressBar::ItemProgressBar(const QString &type, Item *parent) :
    Item(type, parent)
{
    m_progressbar = new QProgressBar(nullptr != parent ? parent->Widget() : nullptr);
}

ItemProgressBar::~ItemProgressBar()
{

}

Item *ItemProgressBar::Creator(const QString &type, Item *parent)
{
    return new ItemProgressBar(type, parent);
}

void ItemProgressBar::ImplementAttrs(const QMap<QString, QString> &attrs)
{
    Item::ImplementAttrs(attrs);

    SetValue(attrs["value"]);
}

void ItemProgressBar::SetValue(const QString &value)
{
    QString tmp = value;

    QStringList values = tmp.remove("[").remove("]").trimmed().split(';', QString::SkipEmptyParts);

    if(2 == values.count())
    {
        m_progressbar->setMinimum(values[0].toInt());
        m_progressbar->setMaximum(values[1].toInt());
    }
    else if(3 == values.count())
    {
        m_progressbar->setMinimum(values[0].toInt());
        m_progressbar->setMaximum(values[2].toInt());
        m_progressbar->setValue(values[1].toInt());
    }
}
