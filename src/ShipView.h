#pragma once

#include <QWidget>
#include <QMouseEvent>

#include "Ship.h"

class ShipView : public QWidget {
	Q_OBJECT
public:
	explicit ShipView(QWidget* parent = nullptr);

	void setShips(const Ship& a, const Ship& b);

protected:
	void paintEvent(QPaintEvent*) override;

	void mouseMoveEvent(QMouseEvent* event) override;

private:
	Ship ship1;
	Ship ship2;

	std::pair<int,int> mouse_pos;
};
