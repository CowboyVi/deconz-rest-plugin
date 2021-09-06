#ifndef DDF_TREEVIEW_H
#define DDF_TREEVIEW_H

#include <QTreeView>

class DeviceDescription;
class QStandardItemModel;
class QItemSelectionModel;

class DDF_TreeView : public QTreeView
{
    Q_OBJECT
public:
    DDF_TreeView(QWidget *parent = nullptr);

    void setDDF(const DeviceDescription &ddf);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

Q_SIGNALS:
    void itemSelected(uint subDevice, uint item);
    void addItem(uint subDevice, const QString &suffix);
    void subDeviceSelected(uint subDevice);
    void deviceSelected();

private Q_SLOTS:
    void currentIndexChanged(const QModelIndex &current, const QModelIndex &prev);

private:
    QStandardItemModel *m_model = nullptr;
};

#endif // DDF_TREEVIEW_H
