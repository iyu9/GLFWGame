#pragma once
#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

class Menu
{
public:
  int idx;
  int siz;
  std::vector<std::string> menues;
  std::vector<void*> callbacks;

  Menu(int siz_)
  {
    siz = siz_;
  }

  void Next()
  {
    idx = (idx + 1 >= siz) ? 0 : idx++;
  }

  void Prev()
  {
    idx = (idx - 1 < 0) ? siz : idx--;
  }

  std::string GetName()
  {
    return menues[idx];
  }

  void SelectMenu()
  {
    //current idx
  }
};

#endif
