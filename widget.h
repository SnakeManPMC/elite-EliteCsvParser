#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

private:
	Ui::Widget *ui;

	void OpenFile();
	void DisplayShit();
	QVector<QString> commodities;
	QStringList myComboBoxStuff;
};

#endif // WIDGET_H
