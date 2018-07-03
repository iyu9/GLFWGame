#pragma once
#ifndef GRIDMAP_HPP
#define GRIDMAP_HPP

#include <string>
#define MAX_MAP_W 99
#define MAX_MAP_H 99

namespace MapChip
{
  const int WALL = -1;
  const int NONE = 0;
  const int UP_STAIRS = 1;
  const int DW_STAIRS = 2;
};

class GridMap
{
public:
  int id;
  std::string name;

  int siz_x, siz_y;
  int pos_x, pos_y;
  int map[MAX_MAP_W][MAX_MAP_H];

  void CleanMap()
  {
    for (int j = 0; j < siz_y; j++)
    {
      for (int i = 0; i < siz_x; i++)
      {
        map[i][j] = 0;
      }
    }
  }

  GridMap(int siz_x_, int siz_y_, int pos_x_, int pos_y_)
  {
    siz_x = siz_x_; siz_y = siz_y_;
    pos_x = pos_x_; pos_y = pos_y_;
    
    CleanMap();
  }
};

#endif
