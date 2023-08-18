#include "levelscene.h"
#include <iterator>
#include <QDebug>
#include <QtGui/QImage>


LevelScene::LevelScene(const RectF &bounds)
    : m_bounds(bounds)
{
    m_level = new Level();

    m_size_of_square = m_bounds.size.y / m_level->map()->mapSizes().y;
    m_level->player()->setSize({m_size_of_square * 3.0f / 4.0f, m_size_of_square * 3.0f / 4.0f});
    m_level->player()->setPosition(m_level->player()->spawnPosition());
    m_level->player()->setSpeed(m_size_of_square * 2);
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

    if (!isInObject((MovableObject) *player, dt)) {
        player->move(dt);
        player->marginPosition(m_bounds, dt);
    }

    Bullet *bullet = player->bullet();
    if (bullet != nullptr) {
        vector2f position_tmp = bullet->position();
        bullet->move(dt);
        if (bullet->position() != position_tmp || isInObject(*bullet, dt)) {
            bullet = nullptr;
        }
    }
}

/*
bool PoolTableScene::canMove(Man man, Direction move, float dt)
{
    vector2f position = man.position();
    vector2f size = man.size();
    float speed = man.speed();

    float column_left = ((position.x - (size.x) / 2)) / m_size_of_square;
    float row_top = (position.y - (size.y) / 2) / m_size_of_square;
    float row_down = (position.y + (size.y) / 2) / m_size_of_square;
    float column_right = (position.x + (size.x / 2)) / m_size_of_square;
    switch (move) {
    case Direction::DOWN:
        row_down += speed * dt / m_size_of_square;
        //qDebug() << row_down << column_left << column_right;
        return  m_map.at(column_left, row_down)->type() != WallType::water && m_map.at(column_right, row_down)->type() != WallType::water
                && m_map.at(column_left, row_down)->hp() <= 0 && m_map.at(column_right, row_down)->hp() <= 0;
    case Direction::LEFT:
        column_left -= speed * dt / m_size_of_square;
        //qDebug() << column_left << row_top << row_down;
        return m_map.at(column_left, row_top)->type() != WallType::water && m_map.at(column_left, row_down)->type() != WallType::water
                && m_map.at(column_left, row_top)->hp() <= 0 && m_map.at(column_left, row_down)->hp() <= 0;
    case Direction::RIGHT:
        column_right += speed * dt / m_size_of_square;
        //qDebug() << column_right << row_down << row_top;
        return m_map.at(column_right, row_down)->type() != WallType::water && m_map.at(column_right, row_top)->type() != WallType::water
                && m_map.at(column_right, row_down)->hp() <= 0 && m_map.at(column_right, row_top)->hp() <= 0;
        break;
    case Direction::UP:
        row_top -= speed * dt / m_size_of_square;
        //qDebug() << row_top << column_left << column_right;
        return m_map.at(column_left, row_top)->type() != WallType::water && m_map.at(column_right, row_top)->type() != WallType::water
                && m_map.at(column_left, row_top)->hp() <= 0 && m_map.at(column_right, row_top)->hp() <= 0;
        break;
    }
}*/
/*
bool PoolTableScene::isHitWall(Bullet bullet)
{
    vector2f position = bullet.position();
    vector2f size = bullet.size();

    float column_left = ((position.x - (size.x) / 2)) / m_size_of_square;
    float row_top = (position.y - (size.y) / 2) / m_size_of_square;
    float row_down = (position.y + (size.y) / 2) / m_size_of_square;
    float column_right = (position.x + (size.x) / 2) / m_size_of_square;

    switch(bullet.getMove()) {
    case Direction::DOWN:
        if (m_map.at(column_left, row_down)->hp() > 0) {
            return m_map.at(column_left, row_down)->hit();
        } else if (m_map.at(column_right, row_down)->hp() > 0) {
            return m_map.at(column_right, row_down)->hit();
        }
        break;
    case Direction::LEFT:
        if (m_map.at(column_left, row_down)->hp() > 0) {
            return m_map.at(column_left, row_down)->hit();
        } else if (m_map.at(column_left, row_top)->hp() > 0) {
            return m_map.at(column_left, row_top)->hit();
        }
        break;
    case Direction::UP:
        if (m_map.at(column_left, row_top)->hp() > 0) {
            return m_map.at(column_left, row_top)->hit();
        } else if (m_map.at(column_right, row_top)->hp() > 0) {
            return m_map.at(column_right, row_top)->hit();
        }
        break;
    case Direction::RIGHT:
        if (m_map.at(column_right, row_down)->hp() > 0) {
            return m_map.at(column_right, row_down)->hit();
        } else if (m_map.at(column_right, row_top)->hp() > 0) {
            return m_map.at(column_right, row_top)->hit();
        }
        break;
    }
    return false;
}
*/
/*
void PoolTableScene::redrawMap(QPainter &painter) {
    painter.setRenderHint(QPainter::Antialiasing);
    for(int i = 0; i < m_map.map_sizes().x; ++i) {
        QString str;
        for(int j = 0; j < m_map.map_sizes().y; ++j) {
            str.append(QString::number(m_map.at(i, j)->hp()));
            Wall* wall = m_map.at(i, j);
            if (wall->hp() != 0) {
                painter.drawImage(QRectF(m_size_of_square * i, m_size_of_square * j, m_size_of_square, m_size_of_square), wall->image());
            }
        }
    }
    return;
}
*/

void LevelScene::redraw(QPainter &painter) {
    painter.setRenderHint(QPainter::Antialiasing);
    Bullet *bullet = m_level->player()->bullet();
    if (bullet != nullptr) {
        painter.drawImage(QRectF(bullet->position().x - bullet->size().x / 2,
                                 bullet->position().y - bullet->size().y / 2,
                                 bullet->size().x, bullet->size().y), *bullet->image());
    }

    Tank *player = m_level->player();
    painter.drawImage(QRectF(player->position().x - player->size().x / 2,
                             player->position().y - player->size().y / 2,
                             player->size().x, player->size().y), *player->image());
    //redrawMap(painter);
}

void LevelScene::fireMan() {
    if (m_level->player()->bullet() == nullptr) {
        m_level->player()->fire();
    }
}

bool LevelScene::isInObject(MovableObject object, float dt)
{
    vector2f position = object.position();
    vector2f size = object.size();
    float speed = object.speed();

    float column_left = ((position.x - (size.x) / 2)) / m_size_of_square;
    float row_top = (position.y - (size.y) / 2) / m_size_of_square;
    float row_down = (position.y + (size.y) / 2) / m_size_of_square;
    float column_right = (position.x + (size.x / 2)) / m_size_of_square;

    Map *map = m_level->map();
    switch (object.direction()) {
    case Direction::DOWN:
        row_down += speed * dt / m_size_of_square;
        return     map->at(column_left,  row_down)->type() != ObjectType::SPACE
                && map->at(column_right, row_down)->type() != ObjectType::SPACE;
    case Direction::LEFT:
        column_left -= speed * dt / m_size_of_square;
        return     map->at(column_left,  row_top)->type() != ObjectType::SPACE
                && map->at(column_left, row_down)->type() != ObjectType::SPACE;
    case Direction::RIGHT:
        column_right += speed * dt / m_size_of_square;
        return     map->at(column_right, row_down)->type() != ObjectType::SPACE
                && map->at(column_right,  row_top)->type() != ObjectType::SPACE;
    case Direction::UP:
        row_top -= speed * dt / m_size_of_square;
        return     map->at(column_left,  row_top)->type() != ObjectType::SPACE
                && map->at(column_right, row_top)->type() != ObjectType::SPACE;
    }
    return true;
}
