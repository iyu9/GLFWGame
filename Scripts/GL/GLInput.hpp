#pragma once
#ifndef GLINPUT_HPP
#define GLINPUT_HPP

class GLInput
{
private:
  GLint keyPrevState[GLFW_KEY_LAST];    //1�t���[���O�̃L�[�������
  GLint keyState[GLFW_KEY_LAST];        //���݂̃t���[���̃L�[�������
  GLdouble mouse_x, mouse_y;            //�}�E�X���W

public:
  GLInput()
  {
    for (int idx = 0; idx < GLFW_KEY_LAST; idx++)
    {
      keyState[idx] = GLFW_RELEASE;
    }
  }

  void ScanKeyState(GLint key, GLint action)
  {
    keyState[key] = action;
  }

  void ScanMouseState(GLdouble x, GLdouble y)
  {
    mouse_x = x; mouse_y = y;
  }

  bool GetKey(GLint key)
  {
    return (keyState[key] == GLFW_PRESS || keyState[key] == GLFW_REPEAT);
  }

  bool GetKeyDown(GLint key)
  {
    return (keyState[key] == GLFW_PRESS);
  }

  bool GetKeyUp(GLint key)
  {
    return (keyPrevState[key] == GLFW_PRESS && keyState[key] == GLFW_RELEASE);
  }

  bool GetKeyRepeat(GLint key)
  {
    return (keyState[key] == GLFW_REPEAT);
  }
};

GLInput g_keyInput;

#endif
