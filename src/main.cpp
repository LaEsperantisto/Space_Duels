#include "bots.h"
#include "ShipView.h"
#include "MenuWindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
	bool maximize = true;
	for (int arg_num = 0; arg_num < argc; ++arg_num) {
		if (*argv[arg_num] == *"-m") {
			maximize = false;
		}
	}


	// ReSharper disable once CppLocalVariableWithNonTrivialDtorIsNeverUsed
	QApplication app(argc, argv);
	QCoreApplication::setApplicationName("Space Duels");

	qDebug() << "Space Duels Initialized";

	MenuWindow menu;
	// menu.setWindowTitle(QString("Space Duels %1").arg(SPACE_DUELS_VERSION));

	if (maximize) {
		menu.setWindowState(Qt::WindowMaximized);
	}
	menu.show();


	const int output = QApplication::exec();

	if (output == 0) {
		qDebug() << "Space Duels successfully ran";
	} else {
		qDebug() << "Space Duels encountered some kind of problem";
	}
	return output;
}
