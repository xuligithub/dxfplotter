#pragma once

#include <ui_task.h>

#include <model/task.h>

#include <QWidget>
#include <QItemSelectionModel>

namespace View
{

class TaskListModel;

class Task : public QWidget, private Ui::Task
{
private:
	Model::Task *m_task;
	TaskListModel *m_model;
	bool m_outsideSelectionBlocked;

	void setupModel();

	void changeItemSelection(Model::Path *path, QItemSelectionModel::SelectionFlag flag);

public:
	explicit Task(Model::Task *task);

protected Q_SLOTS:
	void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
	void pathSelected(Model::Path *path);
	void pathDeselected(Model::Path *path);
};

}
