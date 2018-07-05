#pragma once
#ifndef SAVEDATA_HPP
#define SAVEDATA_HPP
#include <string>
#include <fstream>

class SaveData
{
public:
  int key;
  std::string date;
  int save_count;

  SaveData(){}
  ~SaveData(){}
};

class SaveManager
{
private:
  SaveData save_data;

public:
  bool Save(const char* name)
  {
    //TODO
    return true;
  };

  bool Load(const char* name)
  {
    //TODO
    return true;
  };

  bool Delete(const char* name)
  { 
    //TODO
    return true;
  };
};

#endif