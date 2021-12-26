#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "Config.h"

int
main(int argc, char *argv[])
{
	if (argc < 2) {
		// report version
		std::cout << argv[0] << " Version " << HelloWorld_VERSION_MAJOR << "."
				  << HelloWorld_VERSION_MINOR << std::endl;
		std::cout << "Usage: " << argv[0] << " number" << std::endl;
		return 1;
	}
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
