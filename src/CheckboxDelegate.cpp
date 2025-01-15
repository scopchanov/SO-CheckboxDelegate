#include "CheckboxDelegate.h"
#include <QCheckBox>

CheckboxDelegate::CheckboxDelegate(QObject *parent) :
    QItemDelegate{parent}
{

}

void CheckboxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    drawBackground(painter, option, index);
    drawCheck(painter, option, option.rect, index.data().toBool() ? Qt::Checked : Qt::Unchecked);
    drawFocus(painter, option, option.rect);
}

QWidget *CheckboxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const
{
    return new QCheckBox(parent);
}

void CheckboxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const
{
    editor->move(option.rect.center() - QPoint(8, 8));
    editor->resize(16, 16);
}

void CheckboxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    static_cast<QCheckBox *>(editor)->setCheckState(index.data().toBool() ? Qt::Checked : Qt::Unchecked);
}

void CheckboxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    model->setData(index, static_cast<QCheckBox *>(editor)->checkState() == Qt::Checked);
}
