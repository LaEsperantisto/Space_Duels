#include "bots.h"
#include "ShipView.h"
#include "../generated/version.h"

#include <QApplication>
#include <QStackedWidget>
#include <QLabel>


int main(int argc, char *argv[]) {
	// qputenv("QT_QPA_PLATFORM", "xcb");

	qDebug() << "Program started";

	QApplication app(argc, argv);
	QCoreApplication::setApplicationName("Space Duels");

	ShipView view;

	view.setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowSystemMenuHint);

	view.setWindowTitle(QString("Space Duels %1").arg(SPACE_DUELS_VERSION));


	view.setShips(bots.at(4), bots.at(5));


	auto *stack = new QStackedWidget();
	stack->addWidget(&view); // your ShipView
	stack->addWidget(new QLabel("Hello, this is a new screen"));

	// Show the first screen
	stack->setCurrentWidget(&view);
	stack->setWindowState(Qt::WindowMaximized);
	stack->show();

	// Later, to switch to the second screen
	// stack->setCurrentIndex(1);

	return QApplication::exec();
}
