#include "MenuWindow.h"

#include <QPainter>
#include <QTextBlock>
#include <QVBoxLayout>

#include "bots.h"
#include "globals.h"

MenuWindow::MenuWindow(QWidget *parent)
	: QWidget(parent),
	  stack(new QStackedWidget(this)) {
	create_start_screen();
	createShipView();

	stack->addWidget(start_screen);
	stack->addWidget(ship_view);

	stack->setCurrentWidget(start_screen); // show the start screen first

	const auto layout = new QVBoxLayout(this);
	layout->addWidget(stack);
	setLayout(layout);
}

// ---------------- Start Screen ----------------

void MenuWindow::create_start_screen() {
	start_screen = new QWidget();
	const auto layout = new QVBoxLayout(start_screen);
}

void MenuWindow::paintEvent(QPaintEvent *) {
	QPainter painter(this);

	if (const QPixmap bg(QString(":gfx/menu_bg.png")); bg.isNull()) {
		painter.fillRect(rect(), Qt::black);
	} else {
		painter.drawPixmap(0, 0, bg);
	}

	constexpr int padding = 6;

	{
		const int x = width() / 2 + title_top_left_x_offset;
		const int y = height() / 2 + title_top_left_y_offset;

		const QFont font("Consolas", 50);
		painter.setFont(font);
		const QFontMetrics fm(font);

		// ---------- title box ----------
		const QRect titleTextRect = fm.boundingRect("Space Duels");
		const QRect titleBox(
			x,
			y,
			titleTextRect.width() + padding * 2 + 25,
			titleTextRect.height() + padding * 2 + 25
		);

		painter.setBrush(QColor(50, 50, 50, 220));
		painter.setPen(Qt::blue);
		painter.drawRect(titleBox);

		painter.drawText(
			titleBox.adjusted(padding, padding, -padding, -padding),
			"Space Duels"
		);
	}

	{
		const int x = width() / 2 + start_button_top_left_x_offset;
		const int y = height() / 2 + start_button_top_left_y_offset;

		const QFont font("Consolas", 10);
		painter.setFont(font);
		const QFontMetrics fm(font);
		// ---------- start box ----------
		const QRect startTextRect = fm.boundingRect("Start Game");
		const QRect startBox(
			x,
			y,
			startTextRect.width() + padding * 2 + 5,
			startTextRect.height() + padding * 2 + 5
		);

		if (startBox.contains(mouse_pos.first, mouse_pos.second)) {
			start_game();
			return;
		}

		painter.setBrush(QColor(105, 214, 255, 240));
		painter.setPen(Qt::black);
		painter.drawRect(startBox);

		painter.drawText(
			startBox.adjusted(padding, padding, -padding, -padding),
			"Start Game"
		);
	}
}

// ---------------- Ship View ----------------

void MenuWindow::createShipView() {
	ship_view = new ShipView();

	// Example: pick ships from your bots array
	ship1 = bots.at(4);
	ship2 = bots.at(5);

	ship_view->setShips(ship1, ship2);
}

// ---------------- Slot ----------------

// ReSharper disable once CppMemberFunctionMayBeConst
void MenuWindow::start_game() {
	// Switch to the ShipView screen
	stack->setCurrentWidget(ship_view);
}

MenuWindow::~MenuWindow() {
	delete stack;
	delete start_screen;
	delete ship_view;
}

void MenuWindow::mousePressEvent(QMouseEvent *event) {
	mouse_pos = {event->pos().x(), event->pos().y()};
	update();
}
