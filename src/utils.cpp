#include "utils.h"

#include "Ship.h"
#include "globals.h"
#include "ShipView.h"

#include <QPainter>
#include <QString>

void draw_ships(QPainter& painter,
                const Ship& ship1,
                const Ship& ship2,
                const int width,
                const int height)
{
    const auto [fst, snd] = align_ships(ship1, ship2);

    const auto& s1 = fst.get_cards();
    const auto& s2 = snd.get_cards();

    x_offset = width / 2 - fst.get_width() * card_width / 2;
    y_offset = height / 2 - (fst.get_height() + snd.get_height() + gap_between_ships) * card_height / 2;

    painter.setPen(Qt::white);

    // First ship
    for (size_t x = 0; x < s1.size(); ++x) {
        for (size_t y = 0; y < s1.at(x).size(); ++y) {
            if (const auto& card = s1.at(x).at(y); !card->isEmpty()) {
                const QString text = QString("%1 power: %2 rank: %3")
                    .arg(QString::fromStdString(card->get_short_name()))
                    .arg(card->get_power())
                    .arg(card->get_rank());

                painter.drawText(
                    x * card_width
                        + x_offset,
                    y * card_height
                        + y_offset,
                    text
                );
            }
        }
    }

    // Second ship (mirrored vertically)
    for (size_t x = 0; x < s2.size(); ++x) {
        for (size_t y = 0; y < s2.at(x).size(); ++y) {
            const auto& card =
                s2.at(x).at(ship2.get_height() - 1 - y);

            if (!card->isEmpty()) {
                const QString text = QString("%1 power: %2 rank: %3")
                    .arg(QString::fromStdString(card->get_short_name()))
                    .arg(card->get_power())
                    .arg(card->get_rank());

                painter.drawText(
                    x * card_width + x_offset,
                    (y + gap_between_ships) * card_height
                        + ship1.get_height() * card_height
                        + y_offset,
                    text
                );
            }
        }
    }
}

std::pair<Ship, Ship> align_ships(Ship ship1, Ship ship2) {
    int align_1 = ship1.get_alignment_index();
    int align_2 = ship2.get_alignment_index();

    while (align_1 != align_2) {
        if (align_1 > align_2) {
            ship2.add_column_front();
            // ship2.update_data();
            align_2 = ship2.get_alignment_index();
        } else {
            ship1.add_column_front();
            // ship1.update_data();
            align_1 = ship1.get_alignment_index();
        }
    }

    return {ship1, ship2};
}
