#include "TreeView.h"
#include "TreeModel.h"
#include <QHeaderView>

TreeView::TreeView(TreeModel *model)
{
    setModel(model);
    TreeView();
}

TreeView::TreeView()
{
    connect(this, &QTreeView::pressed, this, &QTreeView::expandAll);
    setDragEnabled(true);
    setAcceptDrops(true);
    resizeColumnToContents(0);
    resize(400, 500);
    setSelectionMode(QAbstractItemView::SingleSelection);
    expandAll();
    connect(this, &QTreeView::pressed, this, &QTreeView::expandAll);
    header()->setVisible(false);
    setIndentation(5);
    setEditTriggers(QAbstractItemView::EditTriggers());
}

void TreeView::setModel(TreeModel *model)
{
    //Kick what's already selected (http://doc.qt.io/qt-4.8/qabstractitemview.html#setModel)
    QItemSelectionModel *m = selectionModel();
    delete m;
}
