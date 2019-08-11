#ifndef ATTR_INTERFACE_H_
#define ATTR_INTERFACE_H_

#include <QString>
#include <QWidget>
#include <QBoxLayout>

using namespace std;

#define ATTR_ALIGN       "align"
#define ATTR_NAME        "name"
#define ATTR_ID          "id"
#define ATTR_VALUE       "value"
#define ATTR_STRETCH     "stretch"
#define ATTR_ACCESS      "access"
#define ATTR_DIR         "dir"
#define ATTR_BACKCOLOR   "backcolor"
#define ATTR_FORECOLOR   "forecolor"
#define ATTR_FONT        "font"
#define ATTR_PROTOCOL    "protocol"

#define ATTR_INTERFACES \
        virtual QBoxLayout* AttrGetAlign(const QString& align, QWidget* parent);\
        virtual void AttrSetName(const QString& name);\
        virtual void AttrSetId(const QString& id, Gml* gml);\
        virtual void AttrSetValue(const QString& value);\
        virtual void AttrSetStretch(const QString& stretch);\
        virtual void AttrSetAccess(const QString& access);\
        virtual void AttrSetDir(const QString& dir);\
        virtual void AttrSetBackColor(const QString& color);\
        virtual void AttrSetForeColor(const QString& color);\
        virtual void AttrSetFont(const QString& font);\
        virtual void AttrSetProtocol(const QString& protocol);

class Gml;
class AbstractTag;

class AttrInterface
{
protected:
    AttrInterface() = default;

public:
    virtual ~AttrInterface() = default;

    virtual QBoxLayout* AttrGetAlign(const QString& align, QWidget* parent) = 0;

    virtual void AttrSetName(const QString& name) = 0;
    virtual void AttrSetId(const QString& id, Gml* gml) = 0;
    virtual void AttrSetValue(const QString& value) = 0;
    virtual void AttrSetStretch(const QString& stretch) = 0;
    virtual void AttrSetAccess(const QString& access) = 0;
    virtual void AttrSetDir(const QString& dir) = 0;
    virtual void AttrSetBackColor(const QString& color) = 0;
    virtual void AttrSetForeColor(const QString& color) = 0;
    virtual void AttrSetFont(const QString& font) = 0;
    virtual void AttrSetProtocol(const QString& protocol) = 0;
};


#endif // ABSTRACT_ATTR_H_

