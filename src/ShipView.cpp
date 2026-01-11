#include "ShipView.h"

#include "utils.h"

ShipView::ShipView(QWidget* parent)
	: QWidget(parent)
{
	setMinimumSize(800, 600);
}

void ShipView::setShips(const Ship& a, const Ship& b) {
	ship1 = a;
	ship2 = b;
	update();  // schedule repaint
}

void ShipView::paintEvent(QPaintEvent*) {
	// qDebug() << "paintEvent called";

	QPainter painter(this);
	painter.fillRect(rect(), Qt::black);

	draw_ships(painter, ship1, ship2, this);
}
