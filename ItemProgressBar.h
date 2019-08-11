#ifndef ITEM_PROGRESS_BAR_H_
#define ITEM_PROGRESS_BAR_H_

#include "Item.h"
#include <QProgressBar>

class ItemProgressBar : public Item
{
public:
    ItemProgressBar(const QString &type, Item *parent = nullptr);
    ~ItemProgressBar();

    static Item *Creator(const QString &type, Item *parent);

    void SetValue(const QString &value);
    inline virtual QWidget *Widget() { return m_progressbar; }
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

private:
    static bool m_registered_in_ItemFactory;
    QProgressBar *m_progressbar;
};

#endif
