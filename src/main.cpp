#include "bots.h"
#include "ShipView.h"
#include "../generated/version.h"

#include <QApplication>
#include <QGuiApplication>

#include "globals.h"

int main(int argc, char *argv[]) {
	qputenv("QT_QPA_PLATFORM", "xcb");

	qDebug() << "Program started";

	QApplication app(argc, argv);
	QCoreApplication::setApplicationName("Space Duels");

	ShipView view;
	view.setWindowTitle(QString("Space Duels %1").arg(SPACE_DUELS_VERSION));

	// qDebug() << bot0.is_legal();
	// qDebug() << bot1.is_legal();
	// qDebug() << bot2.is_legal();
	// qDebug() << bot3.is_legal();

	view.setShips(bot2, bot1);

	view.setWindowState(Qt::WindowMaximized);
	view.show();

	return QApplication::exec();
}
