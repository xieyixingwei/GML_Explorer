#ifndef TAG_H_
#define TAG_H_

#include "Item.h"
#include "AttrInterface.h"
#include "CommType.h"

#include <QString>
#include <QVector>
#include <QWidget>
#include <QMap>

class Gml;

class TagInterface
{
protected:
    TagInterface() = default;

public:
    virtual ~TagInterface();

    virtual TagInterface *GetParent() = 0;
    virtual int GetIndent() = 0;

    virtual void AddChildTag(TagInterface *tag) = 0;
    virtual TagInterface &operator<<(TagInterface *tag) = 0;

    virtual QString ToPrintString() = 0;

    virtual Item* Create(Item *parent = nullptr) = 0;
/*
    virtual void AddAttr(const QString& attrname, const QString& attrvalue) = 0;
    virtual QString GetAttr(const QString& attrname) = 0;
    virtual void SetOwnGml(Gml* gml) = 0;
    virtual Gml* GetOwnGml() = 0;
    */
};

class Tag : public TagInterface
{
public:
    Tag(const QString &tagText, int indent = 0, TagInterface *parent = nullptr);

    virtual ~Tag() = default;

    inline virtual TagInterface* GetParent() { return m_parent; }
    inline virtual int GetIndent() { return m_indent; }

    virtual void AddChildTag(TagInterface* tag) { }
    virtual TagInterface &operator<<(TagInterface *tag) { return *this; }

    virtual QString ToPrintString();

    virtual Item* Create(Item* parent = nullptr);
/*
    virtual void AddAttr(const QString& attrname, const QString& attrvalue) { m_attrs[attrname] = attrvalue; }
    virtual QString GetAttr(const QString& attrname)
    {
        if(m_attrs.find(attrname) != m_attrs.end())
        {
            return m_attrs[attrname];
        }

        return "";
    }

    virtual void SetOwnGml(Gml* gml) { m_gml = gml; }
    virtual Gml* GetOwnGml() { return m_gml; }
*/
    static bool IsTag(const QString &tagText) {
        return '/' == tagText.back();
    }

protected:
    QString ToIndentString();
    QString ToAttrsString();
    QString GetType(const QString &tagText);

private:
    void Parse(const QString &tagText);

protected:
    int m_indent;
    TagInterface *m_parent;
    //Gml* m_gml;
    QString m_type;
    QMap<QString, QString> m_attrs;
};

class TagGroup : public Tag
{
public:
    TagGroup(const QStringList &tagList, int indent = 0, TagInterface *parent = nullptr);
    virtual ~TagGroup() = default;

    inline virtual void AddChildTag(TagInterface *tag) { m_children << tag; }
    inline virtual TagInterface &operator<<(TagInterface *tag) { m_children << tag; return *this; }

    virtual QString ToPrintString();

    virtual Item *Create(Item *parent = nullptr);

    static bool IsTagGroupEnd(const QString &type, const QString &tagText)
    {
        return "/" + type == tagText;
    }

private:
    void Parse(const QStringList &tagList);
    QList<QStringList> GetTagGroupList(const QStringList &tagList);

private:
    QVector<TagInterface *> m_children;
};

#endif // TAG_H_

