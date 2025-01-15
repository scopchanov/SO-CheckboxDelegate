/**
MIT License

Copyright (c) 2025 Michael Scopchanov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
