#include "widget.h"
#include "ui_widget.h"

#include <QtWidgets>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
	OpenFile();
	DisplayShit();
}

Widget::~Widget()
{
	delete ui;
}


void Widget::OpenFile()
{
	QFile file( ("d://elite.dangerous//elite_csv_1.csv") );

	if (!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::information(this, tr("Unable to open file"),
		file.errorString());
		return;
	}

	QString line;
	QTextStream in(&file);

	while (!in.atEnd())
	{
		line = in.readLine();
		commodities.push_back(line);
	}
	file.close();
}


void Widget::DisplayShit()
{
	QStringList list;
	int i = 0;
	while (i < commodities.size())
	{
		list = commodities[i].split(";");
		i++;

		ui->textEdit->append("System: " + list[0] + "\nStation: " + list[1] + "\nCommodity: " + list[2] + "\nSell: " + list[3] + "\nBuy: " + list[4]
				+ "\nDemand: " + list[5] + "\nDemand chars???: " + list[6] + "\nSupply: " + list[7] + "\nSupply chars???: " + list[8]
				+ "\nDateTime: " + list[9]);
	}
}
