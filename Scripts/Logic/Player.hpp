#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

class Status
{
public:
  int lv;
  int lv_max;
  int hp;
  int hp_max;
  int mp;
  int mp_max;
  int cond;

  int atk_max;
  int def_max;
  int spd_max;
  int luk_max;
  int mov_max;

  int atk;
  int def;
  int spd;
  int luk;
  int mov;
};

class EquipBase
{
  int id;
  int type;

  int val1;
  int val2;
  int val3;
};

class Equipment
{
public:
  EquipBase weapon;
  EquipBase shield;
  EquipBase armor;
  EquipBase helmet;
  EquipBase accesary;

  void SetWeapon(){}
  void SetShield(){}
  void SetArmor(){}
  void SetHelmet(){}
  void SetAccessary(){}
};

class Skill
{
public:
  int id;
  int type;

  int val1;
  int val2;
  int val3;
};

class Player
{
public:
  int id;
  std::string name;
  Status status;
  Equipment equipment;
  int x, y;

  Player(){}
  Player(int id_, std::string name_)
  {
    id = id_;
    name = name_;
  }
};

class PlayerList
{
public:
  std::vector<Player> players;
  int siz;

  PlayerList(int siz_)
  {
    siz = siz_;
  }

  void Push(Player player)
  {
    players.push_back(player);
  }

  void Pop()
  {
    players.pop_back();
  }

  void Clear()
  {
    players.clear();
  }
};

#endif
