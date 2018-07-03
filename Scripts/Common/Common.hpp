#pragma once
#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#define REP(VAR, COUNT) for (int VAR = 0; i < COUNT; i++)
#define LOG(X) std::cout << X

std::string WaitInput()
{
  std::string input_str;
  std::cin >> input_str;
  return input_str;
}

#endif
