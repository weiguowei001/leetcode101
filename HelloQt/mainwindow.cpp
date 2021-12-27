#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <functional>
#include <sqlite3.h>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(
		ui->pushButton, &QPushButton::clicked, this, &MainWindow::sqlite_test);
	QFile file("resource/qss/public_svg.qss");
	if (file.open(QIODevice::ReadOnly)) {
		QTextStream in(&file);
		setStyleSheet(in.readAll());
	}
}

MainWindow::~MainWindow() { delete ui; }

int
MainWindow::sqlite_test()
{
	auto callback = [](void *NotUsed, int argc, char **argv, char **azColName) {
		int i;
		for (i = 0; i < argc; i++) {
			printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		}
		printf("\n");
		return 0;
	};

	sqlite3 *db;
	char *zErrMsg = 0;
	int rc = sqlite3_open("test.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return (1);
	}

	rc = sqlite3_exec(db, ui->textEdit->toPlainText().toStdString().c_str(),
		callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	ui->textBrowser->setText(zErrMsg);
	sqlite3_close(db);
	return 0;
}