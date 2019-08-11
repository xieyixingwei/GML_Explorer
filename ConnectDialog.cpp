#include "ConnectDialog.h"
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QGridLayout>

struct pui {
    QComboBox *uart_port;
};

ConnectDialog::ConnectDialog()
{
    m_pui = new struct pui;

    QStringList uartPort;
    uartPort << "COM1" << "COM2" << "COM3" << "COM4" << "COM5";

    m_pui->uart_port = new QComboBox(this);
    m_pui->uart_port->addItems(uartPort);

    QGridLayout *mainLayout= new QGridLayout(this);
    mainLayout->addWidget(new QLabel(tr("Uart Port"), this), 0, 0);
    mainLayout->addWidget(m_pui->uart_port,                   0, 1);
}

ConnectDialog::~ConnectDialog()
{

}
