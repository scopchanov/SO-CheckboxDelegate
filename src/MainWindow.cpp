#include "MainWindow.h"
#include "CheckboxDelegate.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    auto *model{new QStandardItemModel(this)};
    auto *view{new QTableView(this)};
    auto *l{new QVBoxLayout(this)};

    for (int n{0}; n < 10; n++)
        model->appendRow(new QStandardItem(QString::number(n < 5)));

    view->setModel(model);
    view->setFrameStyle(QTableView::NoFrame);
    view->setItemDelegateForColumn(0, new CheckboxDelegate(this));
    view->setEditTriggers(QTableView::CurrentChanged);

    l->addWidget(view);
    l->setContentsMargins(0, 0, 0, 0);

    resize(640, 480);
}
