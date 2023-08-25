#include "levelscene.h"
#include <iterator>
#include <QDebug>
#include <QtGui/QImage>
#include <Model/unmovableobject.h>

LevelScene::LevelScene(const QRectF &bounds)
    : m_windowBounds(bounds)
{
    m_level = new Level();        
}

void LevelScene::update(pressedKeys keys, float dt) {
    Tank *player = m_level->player();
    if (keys.down) {
        player->setDirection(Direction::DOWN);
    } else if (keys.left) {
        player->setDirection(Direction::LEFT);
    } else if (keys.right) {
        player->setDirection(Direction::RIGHT);
    } else if (keys.up) {
        player->setDirection(Direction::UP);
    } else {
        player->setIsMoving(false);
    }

    if (player->isMoving() && !m_level->map()->hasCollision(*player, dt)) {
        player->move(dt);
    }

    m_level->marginPosition(player, m_windowBounds);

    Bullet *bullet = player->bullet();
    if (bullet != nullptr) {        
        bullet->move(dt);
        if (m_level->marginPosition(bullet, m_windowBounds) || m_level->map()->hasCollision(*bullet, 0)) {
            player->setBullet(nullptr);
        }
    }
}

void LevelScene::redraw(QPainter &painter) {
    painter.setRenderHint(QPainter::Antialiasing);
    for(auto brick : *m_level->map()->bricks()) {
        painter.drawImage(brick->bounds(), *brick->image());
    }

    for(auto iron : *m_level->map()->irons()) {
        painter.drawImage(iron->bounds(), *iron->image());
    }

    for(auto water : *m_level->map()->water()) {
        painter.drawImage(water->bounds(), *water->image());
    }

    for(auto player : *m_level->map()->players()) {
        painter.drawImage(player->bounds(), *player->image());
        if (player->bullet() != nullptr) {
            painter.drawImage(player->bullet()->bounds(), *player->bullet()->image());
        }
    }

    for(auto grass : *m_level->map()->grass()) {
        painter.drawImage(grass->bounds(), *grass->image());
    }
}

void LevelScene::fireMan() {
    if (m_level->player()->bullet() == nullptr) {
        m_level->player()->fire();
    }
}

//bool LevelScene::isInObject(MovableObject object, float dt)
//{
//    vector2f position = object.position();
//    vector2f size = object.size();
//    float speed = object.speed();

//    float column_left = ((position.x - (size.x) / 2)) / m_size_of_square;
//    float row_top = (position.y - (size.y) / 2) / m_size_of_square;
//    float row_down = (position.y + (size.y) / 2) / m_size_of_square;
//    float column_right = (position.x + (size.x / 2)) / m_size_of_square;

//    Map *map = m_level->map();

//    bool isIn = false;
//    switch (object.direction()) {
//    case Direction::DOWN:
//        row_down += speed * dt / m_size_of_square;
//        //isIn = row_down < map->mapSizes().x;
//        if (row_down > map->mapSizes().x) {
//            return false;
//        }
//        if (map->at(column_left, row_down)->type() != ObjectType::SPACE) {
//            isIn = true;
//            if (object.movableType() == MovableObjectType::BULLET) {
//                map->at(column_left, row_down)->setType(ObjectType::SPACE);
//            }
//        }
//        if (map->at(column_right, row_down)->type() != ObjectType::SPACE) {
//            isIn = true;
//            if (object.movableType() == MovableObjectType::BULLET) {
//                map->at(column_right, row_down)->setType(ObjectType::SPACE);
//            }
//        }
//        break;
//    case Direction::LEFT:
//        column_left -= speed * dt / m_size_of_square;
//        //isIn = column_left >= 0;
//        if (column_left <= 0) {
//            return false;
//        }
//        if ((map->at(column_left, row_top)->type() != ObjectType::SPACE)) {
//            isIn = true;
//            if (object.movableType() == MovableObjectType::BULLET) {
//                map->at(column_left,  row_top)->setType(ObjectType::SPACE);
//            }
//        }
//        if (map->at(column_left, row_down)->type() != ObjectType::SPACE) {
//            isIn = true;
//            if (object.movableType() == MovableObjectType::BULLET) {
//                map->at(column_left, row_down)->setType(ObjectType::SPACE);
//            }
//        }
//        break;
//    case Direction::RIGHT:
//        column_right += speed * dt / m_size_of_square;
//        //isIn = column_right < map->mapSizes().y;
//        if (column_right > map->mapSizes().y) {
//            return false;
//        }
//        if ((map->at(column_right, row_down)->type() != ObjectType::SPACE)) {
//            isIn = true;
//            if (object.movableType() == MovableObjectType::BULLET) {
//                map->at(column_right, row_down)->setType(ObjectType::SPACE);
//            }
//        }
//        if (map->at(column_right, row_top)->type() != ObjectType::SPACE) {
//            isIn = true;
//            if (object.movableType() == MovableObjectType::BULLET) {
//                map->at(column_right,  row_top)->setType(ObjectType::SPACE);
//            }
//        }
//        break;
//    case Direction::UP:
//        row_top -= speed * dt / m_size_of_square;
//        //isIn = row_top >= 0;
//        if (row_top <= 0) {
//            return false;
//        }
//        if ((map->at(column_left,  row_top)->type() != ObjectType::SPACE)) {
//            isIn = true;
//            if (object.movableType() == MovableObjectType::BULLET) {
//                map->at(column_left,  row_top)->setType(ObjectType::SPACE);
//            }
//        }
//        if (map->at(column_right, row_top)->type() != ObjectType::SPACE) {
//            isIn = true;
//            if (object.movableType() == MovableObjectType::BULLET) {
//                map->at(column_right, row_top)->setType(ObjectType::SPACE);
//            }
//        }
//        break;
//    }
//    return isIn;
//}
