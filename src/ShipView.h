#pragma once

#include <QWidget>
#include <QMouseEvent>

#include "Ship.h"

class ShipView : public QWidget {
private:
	Ship ship1;
	Ship ship2;

	std::pair<int, int> mouse_pos;
	Q_OBJECT

protected:
	void paintEvent(QPaintEvent *) override;

	void mouseMoveEvent(QMouseEvent *event) override;

public:
	explicit ShipView(QWidget *parent = nullptr);

	void setShips(const Ship &a, const Ship &b);
};
