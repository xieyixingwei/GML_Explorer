#-------------------------------------------------
#
# Project created by QtCreator 2018-04-26T17:53:43
#
#-------------------------------------------------

QT       += core gui \
            serialport \
            network \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GML_Explorer
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp\
        Tag.cpp\
        Gml.cpp\
        AttrInterface.cpp\
        Item.cpp\
        ItemGml.cpp\
        ItemTabWidget.cpp\
        ItemLineEdit.cpp\
        ItemButton.cpp\
        ItemLabel.cpp\
        ItemGroupBox.cpp\
        ItemContainer.cpp\
        ItemTextEdit.cpp\
        ItemProgressBar.cpp\
        ItemComboBox.cpp\
        ItemCheckBox.cpp\
        ItemRadioButton.cpp\
        ProtocolInterface.cpp\
        CommunicateInterface.cpp\
        LoopBuf.cpp\
        CommUart.cpp\
        CommTcpClient.cpp\

HEADERS  += MainWindow.h\
        CommType.h\
        Tag.h\
        Gml.h\
        AttrInterface.h\
        Item.h\
        ItemGml.h\
        ItemTabWidget.h\
        ItemLineEdit.h\
        ItemButton.h\
        ItemLabel.h\
        ItemGroupBox.h\
        ItemContainer.h\
        ItemTextEdit.h\
        ItemProgressBar.h\
        ItemComboBox.h\
        ItemCheckBox.h\
        ItemRadioButton.h\
        ProtocolInterface.h\
        CommunicateInterface.h\
        LoopBuf.h\
        CommUart.h\
        CommTcpClient.h\
