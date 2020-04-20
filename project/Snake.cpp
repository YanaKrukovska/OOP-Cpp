#include "Field.h"
#include "Snake.h"
#include "GameException.h"

void Snake::die() {
    isDead = true;
}

void Snake::eatFood() {
    points++;
}

int Snake::getPoints() const {
    return points;
}

bool Snake::hasDied() const {
    return isDead;
}


void Snake::drawSnake(Field *field) const {
    if (body == nullptr || isDead) {
        return;
    }

    const Body *currentBodyPosition = body;

    do {
        field->setPoints(currentBodyPosition->point, 'o');

        if (currentBodyPosition->next == nullptr) {
            field->setPoints(currentBodyPosition->point, 'O');
        }

        currentBodyPosition = currentBodyPosition->next;

    } while (currentBodyPosition != nullptr);
}

Snake::Snake(Field *field, const Point &startPosition)
        : points(0), isDead(false) {
    if ((startPosition.x == 0 || startPosition.y == 0 ||
         startPosition.x == field->getCols() - 1 || startPosition.y == field->getRows() - 1) ||
        (startPosition.x < 0 || startPosition.y < 0 ||
         startPosition.x >= field->getCols() || startPosition.y >= field->getRows())) {
        throw GameException("Snake is out of the border");
    }

    body = new Body{startPosition};
    field->setFood();
    move(field, startPosition);
}


Snake::~Snake() {
    if (body == nullptr) {
        return;
    }

    Body *next;

    do {
        next = body->next;
        delete body;
        body = next;

    } while (next != nullptr);
}

void Snake::move(Field *field, const Point &point) {
    if (isDead) {
        return;
    }

    char fieldCell = field->getElement(point);

    Body *current;

    switch (fieldCell) {
        case '$':
            eatFood();
            field->setFood();
            current = body;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Body{point};
            drawSnake(field);
            break;

        case ' ':
            field->setPoints(body->point, ' ');
            if (body->next == nullptr) {
                body->point = point;
            } else {
                current = body;
                while (current->next != nullptr) {
                    current->point = current->next->point;
                    current = current->next;
                }
                current->point = point;
            }

            drawSnake(field);
            break;
        case '*':
        case 'o':
            die();
            break;
        default:;
    }
}

