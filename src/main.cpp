#include "bots.h"
#include "ShipView.h"
#include "../generated/version.h"

#include <QApplication>
#include <QGuiApplication>

#include "globals.h"

int main(int argc, char *argv[]) {
	qputenv("QT_QPA_PLATFORM", "xcb");

	qDebug() << "Program started";

	// ReSharper disable once CppLocalVariableWithNonTrivialDtorIsNeverUsed
	QApplication app(argc, argv);
	QCoreApplication::setApplicationName("Space Duels");

	ShipView view;
	view.setWindowTitle(QString("Space Duels %1").arg(SPACE_DUELS_VERSION));

	qDebug() << bots.at(4).is_legal();

	view.setShips(bots.at(4), bots.at(3));

	view.setWindowState(Qt::WindowMaximized);
	view.show();

	return QApplication::exec();
}
