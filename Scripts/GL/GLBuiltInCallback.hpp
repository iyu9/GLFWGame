#pragma once
#ifndef GLBUILTINCALLBACK_HPP
#define GLBUILTINCALLBACK_HPP

static void error_callback(int error, const char* description)
{
  std::cout << "Error description = " << description << std::endl;
  std::cout << "Error code = " << error << std::endl;

  switch (error)
  {
  case GLFW_NOT_INITIALIZED:
    std::cout << "GLFW_NOT_INITIALIZED";
    break;

  case GLFW_NO_CURRENT_CONTEXT:
    std::cout << "GLFW_NO_CURRENT_CONTEXT";
    break;

  case GLFW_INVALID_ENUM:
    std::cout << "GLFW_INVALID_ENUM";
    break;

  case GLFW_INVALID_VALUE:
    std::cout << "GLFW_INVALID_VALUE";
    break;

  case GLFW_OUT_OF_MEMORY:
    std::cout << "GLFW_OUT_OF_MEMORY";
    break;

  case GLFW_API_UNAVAILABLE:
    std::cout << "GLFW_API_UNAVAILABLE";
    break;

  case GLFW_VERSION_UNAVAILABLE:
    std::cout << "GLFW_VERSION_UNAVAILABLE";
    break;

  case GLFW_PLATFORM_ERROR:
    std::cout << "GLFW_PLATFORM_ERROR";
    break;

  case GLFW_FORMAT_UNAVAILABLE:
    std::cout << "GLFW_FORMAT_UNAVAILABLE";
    break;
  }

  WaitInput();
}

static void cursor_pos_callback(GLFWwindow* window, double x, double y)
{
  g_keyInput.ScanMouseState(x, y);
}

static void key_callback(GLFWwindow* window, int key, int scanmode, int action, int mods)
{
  g_keyInput.ScanKeyState(key, action);

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }
}

#endif
