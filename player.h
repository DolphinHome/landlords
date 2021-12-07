#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "cards.h"

class Player : public QObject
{
    Q_OBJECT
public:
    enum Role{Lord, Farmer};    // 角色
    enum Sex{Man, Woman};       // 性别
    enum Direction{Left, Right};    // 头像的显示方位
    enum Type{Robot, User, UnKnow}; // 玩家的类型
    explicit Player(QObject *parent = nullptr);
    explicit Player(QString name, QObject *parent = nullptr);

    void setName(QString name);
    QString getName();

    void setRole(Role role);
    Role getRole();

    void setSex(Sex sex);
    Sex getSex();

    void setDirection(Direction direction);
    Direction getDirection();

    void setType(Type type);
    Type getType();

    void setScore(int score);
    int getScore();

    void setWin(bool flag);
    bool isWin();

    void setPrevPlayer(Player* player);
    void setNextPlayer(Player* player);
    Player* getPrevPlayer();
    Player* getNextPlayer();

    void grabLordBet(int point);

    void storeDispatchCard(Card& card);
    void storeDispatchCard(Cards& cards);

    Cards getCards();
    void clearCards();
    void playHand(Cards& cards);

    void setPendingInfo(Player* player, Cards& cards);
    Player* getPendPlayer();
    Cards getPendCards();

    void storePendingInfo(Player* player, Cards& cards);

    virtual void prepareCallLord();
    virtual void preparePlayHand();
    virtual void thinkCallLord();
    virtual void thinkPlayHand();



signals:
    void notifyGrabLordBet(Player* player, int bet);
    void notifyPlayHand(Player* player, Cards& card);
    void notifyPickCards(Player* player, Cards& cards);

protected:
    int m_score;
    QString m_name;
    Role m_role;
    Sex m_sex;
    Direction m_direction;
    Type m_type;
    bool m_isWin;
    Player* m_prev;
    Player* m_next;
    Cards m_cards;
    Cards m_pendCards;
    Player* m_pendPlayer;
};

#endif // PLAYER_H
