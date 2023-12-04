#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QObject>
#include <QTreeView>
#include "TreeModel.h"

class TreeView : public QTreeView
{
public:
    TreeView(TreeModel *model);
    TreeView();
    void setModel(TreeModel *model);
};

#endif // TREEVIEW_H
