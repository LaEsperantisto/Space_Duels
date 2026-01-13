#include "bots.h"
#include "ShipView.h"
#include "MenuWindow.h"  // Your renamed GameWindow
#include "../generated/version.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[]) {
	qDebug() << "Program started";

	// ReSharper disable once CppLocalVariableWithNonTrivialDtorIsNeverUsed
	QApplication app(argc, argv);
	QCoreApplication::setApplicationName("Space Duels");


	MenuWindow menu;
	menu.setWindowTitle(QString("Space Duels %1").arg(SPACE_DUELS_VERSION));

	menu.setWindowState(Qt::WindowMaximized);
	menu.show();


	return QApplication::exec();
}
