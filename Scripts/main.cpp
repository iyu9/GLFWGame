#pragma once
#ifdef WIN32
  #include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include "Common/Common.hpp"

//include My GL Classes
#include "GLComponents/GLComponents.hpp"

//include My Scenes
#include "MyView/InitView.hpp"
#include "MyView/TitleView.hpp"
#include "MyView/ConfigView.hpp"
#include "MyView/MainView.hpp"

GLScene* currentScene;
const GLIntVec2 g_winSize = {300, 300};
const GLIntVec2 g_winPos  = {1300, 640};

int main()
{
  if (!glfwInit())
  {
    LOG("init failed");
    WaitInput();
    return 1;
  }

  glfwSetErrorCallback(error_callback);
  GLFWwindow *window = glfwCreateWindow(g_winSize.x, g_winSize.y, "App", NULL, NULL);

  if (!window)
  {
    LOG("failed glfw3 create window");
    WaitInput();
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  glfwSetKeyCallback(window, key_callback);
  glfwSetCursorPosCallback(window, cursor_pos_callback);
  glfwSetWindowPos(window, g_winPos.x, g_winPos.y);

  currentScene = new InitView();
  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
      currentScene->Render();
    glFlush();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  delete currentScene;

  glfwTerminate();
  return 0;
}