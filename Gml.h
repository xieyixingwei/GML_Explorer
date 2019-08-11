#ifndef GTML_H_
#define GTML_H_

#include "CommType.h"
#include "Tag.h"
#include "Item.h"

#include <QString>
#include <QTextEdit>

using namespace std;

using Id_Tag_t = QHash<QString, Item*>;

class Gml
{
public:
    Gml(const QString &gmlText);
    virtual ~Gml();


    Item* Create();
    void Print();
    /*
    void AddIdItem(const QString& id, Item* item) { m_id_items[id] = item; }
    Item* GetIdItem(const QString& id)
    {
        if(m_id_items.find(id) != m_id_items.end())
        {
           return m_id_items[id];
        }

        return nullptr;
    }

    static void ClearBeginEnd(QString& tagText, char begin, char end);
*/

private:
    void Parse(const QString &gmlText);

private:
    TagInterface *m_root_tag;
    QStringList *m_taglist;
    Id_Tag_t m_id_items;
    QTextEdit *m_diaplay;
};

#endif // ITEM_H

