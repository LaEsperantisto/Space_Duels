#pragma once

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>

#include "ShipView.h"
#include "Ship.h"

class MenuWindow : public QWidget {
	Q_OBJECT

public:
	~MenuWindow() override;

	explicit MenuWindow(QWidget *parent = nullptr);

private slots:
	void start_game(); // called when the user clicks "Start"
	void paintEvent(QPaintEvent *event) override;

private:
	QStackedWidget *stack;

	QWidget *start_screen;
	ShipView *ship_view;

	Ship ship1;
	Ship ship2;

	std::pair<int, int> mouse_pos;

	void create_start_screen();

	void createShipView();

	void mousePressEvent(QMouseEvent *event) override;
};
