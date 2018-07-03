#pragma once
#ifndef MESSAGE_WINDOW_HPP
#define MESSAGE_WINDOW_HPP

#include <string>
#include <vector>

namespace MWOption
{
  const double WaitCharTime = 0.25;
  const double WaitMsgTime = 0.25;
};

class MessageWindow
{
private:
  bool IsEndMessageWindow()
  {
    return (msg_idx >= msg_siz);
  }

  bool IsEndCharIndex()
  {
    return (char_idx >= messages[msg_idx].size());
  }

  void NextSubString()
  {
    if (char_idx + 1 <= messages[msg_idx].size())
    {
      char_idx++;
    }
  }

public:
  int msg_idx;
  int msg_siz;

  int char_idx;
  std::vector<std::string> messages;

  double timer;

  MessageWindow()
  {
  }

  MessageWindow(std::vector<std::string> messages)
  {
    messages = messages;
  }

  std::string GetMessage()
  {
    return messages[msg_idx];
  }

  void NextMessage()
  {
    if (msg_siz + 1 <= msg_siz)
    {
      msg_idx++;
    }
  }

  void PrevMessage()
  {
    if (msg_siz - 1 >= 0)
    {
      msg_idx--;
    }
  }

  void SetMessage(int msg_idx_)
  {
    timer = 0;
    char_idx = 0;
    msg_idx = msg_idx_;
  }

  void Update(double frameTime)
  {
    timer += frameTime;

    //Next char
    if (timer >= MWOption::WaitCharTime)
    {
      timer = 0;
      NextSubString();
    }

    //Next message
    if (IsEndCharIndex())
    {
      timer = 0;
      NextMessage();
    }
  }

  void Open()
  {
    //Begin Render
  }

  void Close()
  {
    //End Render
  }

};

#endif
