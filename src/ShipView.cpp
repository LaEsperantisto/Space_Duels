#include "ShipView.h"

#include "utils.h"

ShipView::ShipView(QWidget *parent)
	: QWidget(parent) {
	setMinimumSize(800, 600);
	setMouseTracking(true);
}

void ShipView::setShips(const Ship &a, const Ship &b) {
	ship1 = a;
	ship2 = b;
	update(); // schedule repaint
}

void ShipView::paintEvent(QPaintEvent *) {
	// qDebug() << "paintEvent called";

	QPainter painter(this);

	if (const QPixmap bg(QString(":gfx/battle_bg.png")); bg.isNull()) {
		painter.fillRect(rect(), Qt::black);
	} else {
		painter.drawPixmap(0, 0, bg);
	}
	draw_ships(painter, ship1, ship2, this, mouse_pos);
}

void ShipView::mouseMoveEvent(QMouseEvent *event) {
	mouse_pos = {event->pos().x(), event->pos().y()};

	update();
}
