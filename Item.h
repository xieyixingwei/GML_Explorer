#ifndef ITEM_H_
#define ITEM_H_

#include "AttrInterface.h"
#include "CommType.h"
#include <QString>
#include <QHash>
#include <QWidget>
#include <QStringList>
#include <QList>
#include <QPair>

#define NEW_ITEM(type, parent) \
                ItemFactory::Create().NewItem(type, parent)

#define REGISTER_ITEM(type, itemClass) \
            bool itemClass::m_registered_in_ItemFactory = \
                ItemFactory::Create().RegisterItem(type, &itemClass::Creator)

class Item;
class Gml;

typedef Item* (*ItemCreatorFunc) (const QString &type, Item *parent);
using ItemCreatorMap_t = QHash<QString, ItemCreatorFunc>;

class ItemFactory
{
private:
    ItemFactory() = default;

public:
    ~ItemFactory() = default;

    static ItemFactory &Create(void);
    bool RegisterItem(const QString &type, ItemCreatorFunc hook);
    Item* NewItem(const QString &type, Item *parent);

private:
    ItemCreatorMap_t m_item_creator_map;
};

using Protocol_t = QList<QPair<QString,QString>>;

class Item
{
protected:
    Item(const QString &type, Item *parent = nullptr);

public:
    virtual ~Item() = default;

    inline Item *Parent() { return m_parent; }
    inline QString Type() { return m_type; }
    inline QString Name() { return m_name; }
    inline int Stretch() { return m_stretch; }

    virtual QWidget *Widget() = 0;
    virtual void AddChildItem(Item *item);
    virtual Item &operator<<(Item *item);
    virtual void ImplementAttrs(const QMap<QString, QString> &attrs);

protected:
    QBoxLayout* NewLayout(const QString &align, Item *parent = nullptr);

protected:
    Item *m_parent;
    QString m_type;
    QString m_name;
    int m_stretch;
    QBoxLayout *m_layout;
    QVector<Item *> m_children;
};

#endif
