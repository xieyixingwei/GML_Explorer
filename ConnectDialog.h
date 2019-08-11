#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

struct pui;

class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    ConnectDialog();
    ~ConnectDialog();

private:
    struct pui *m_pui;
};

#endif // CONNECTDIALOG_H
