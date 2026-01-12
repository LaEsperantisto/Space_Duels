#include "utils.h"

#include "Ship.h"
#include "globals.h"
#include "ShipView.h"

#include <QPainter>
#include <QString>

void draw_ships(QPainter &painter,
                const Ship &ship1,
                const Ship &ship2,
                const QWidget *widget,
                const std::pair<int, int> &mouse_pos) {
    const auto [fst, snd] = align_ships(ship1, ship2);

    const auto &s1 = fst.get_cards();
    const auto &s2 = snd.get_cards();

    const auto width = widget->width();
    const auto height = widget->height();

    x_offset = width / 2 - fst.get_width() * card_width / 2;
    y_offset = height / 2 -
               (fst.get_height() + snd.get_height() + gap_between_ships) * card_height / 2;

    QString card_details;
    QString card_description;

    // ---------- First ship ----------
    for (size_t x = 0; x < s1.size(); ++x) {
        for (size_t y = 0; y < s1.at(x).size(); ++y) {
            if (const auto &card = s1.at(x).at(y); !card->isEmpty()) {
                const int drawX = x * card_width + x_offset;
                const int drawY = y * card_height + y_offset;

                painter.save();
                painter.translate(drawX, drawY + card_height);
                const auto scale = get_card_scale(card_png_width, card_png_height, card_width, card_height);
                painter.scale(scale.first, -scale.second);
                painter.drawPixmap(0, 0, card->get_texture());
                painter.restore();

                if (QRect cardRect(drawX, drawY, card_width, card_height); cardRect.contains(
                    mouse_pos.first, mouse_pos.second)) {
                    card_details = card->get_details();
                    card_description = card->get_description();
                }
            }
        }
    }

    // ---------- Second ship ----------
    for (size_t x = 0; x < s2.size(); ++x) {
        for (size_t y = 0; y < s2.at(x).size(); ++y) {
            const auto &card = s2.at(x).at(snd.get_height() - 1 - y);
            if (!card->isEmpty()) {
                const int drawX = x * card_width + x_offset;
                const int drawY =
                        (y + gap_between_ships) * card_height +
                        fst.get_height() * card_height +
                        y_offset;

                painter.save();
                const auto scale = get_card_scale(card_png_width, card_png_height, card_width, card_height);
                painter.scale(scale.first, scale.second);
                painter.drawPixmap(drawX, drawY, card->get_texture());
                painter.restore();

                if (QRect cardRect(drawX, drawY, card_width, card_height); cardRect.contains(
                    mouse_pos.first, mouse_pos.second)) {
                    card_details = card->get_details();
                    card_description = card->get_description();
                }
            }
        }
    }

    if (card_details.isEmpty())
        return;

    if (card_description.isEmpty())
        card_description = "No description available";

    painter.save();

    constexpr int padding = 6;
    constexpr int x_mouse_offset = 12;
    constexpr int y_mouse_offset = 12;
    constexpr int max_description_width = 350; // <<< wrap width

    const int x = mouse_pos.first + x_mouse_offset;
    const int y = mouse_pos.second + y_mouse_offset;

    QFont font("Consolas", 10);
    painter.setFont(font);
    QFontMetrics fm(font);

    // ---------- Details box ----------
    QRect detailsTextRect = fm.boundingRect(card_details);
    QRect detailsBox(
        x,
        y,
        detailsTextRect.width() + padding * 2 + 5,
        detailsTextRect.height() + padding * 2 + 5
    );

    painter.setBrush(QColor(50, 50, 50, 220));
    painter.setPen(Qt::blue);
    painter.drawRect(detailsBox);

    painter.drawText(
        detailsBox.adjusted(padding, padding, -padding, -padding),
        card_details
    );

    // ---------- Description box (wrapped) ----------
    QRect descriptionTextRect = fm.boundingRect(
        QRect(0, 0, max_description_width, 1000),
        Qt::TextWordWrap,
        card_description
    );

    const QRect descriptionBox(
        x,
        y + detailsBox.height(),
        descriptionTextRect.width() + padding * 2,
        descriptionTextRect.height() + padding * 2
    );

    painter.setBrush(QColor(50, 50, 50, 220));
    painter.setPen(Qt::blue);
    painter.drawRect(descriptionBox);

    painter.drawText(
        descriptionBox.adjusted(padding, padding, -padding, -padding),
        Qt::TextWordWrap,
        card_description
    );

    painter.restore();
}

std::pair<Ship, Ship> align_ships(Ship ship1, Ship ship2) {
    int align_1 = ship1.get_alignment_index();
    int align_2 = ship2.get_alignment_index();

    while (align_1 != align_2) {
        if (align_1 > align_2) {
            ship2.add_column_front();
            align_2 = ship2.get_alignment_index();
        } else {
            ship1.add_column_front();
            align_1 = ship1.get_alignment_index();
        }
    }

    return {ship1, ship2};
}

std::pair<int, int> get_card_scale(const int png_width, const int png_height, const int wanted_width,
                                   const int wanted_height) {
    return {
        wanted_width / png_width,
        wanted_height / png_height
    };
}
