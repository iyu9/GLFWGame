#pragma once
#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>

class Enemy
{
public:
  int id;
  std::string name;

  Enemy(){}
  Enemy(int id_, std::string name_)
  {
    id = id_;
    name = name_;
  }
};

#endif
