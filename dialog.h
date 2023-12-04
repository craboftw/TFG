#ifndef DIALOG_H
#define DIALOG_H

#include "qtreewidget.h"
#include <QDialog>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_VistaObjetos_doubleClicked(const QModelIndex &index);

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
