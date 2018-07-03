#ifdef UNITTEST_GLFW

#include <GLFW/glfw3.h>
#include <iostream>

int hoge()
{
  if (!glfwInit())
  {
    return 1;
  }

  GLFWwindow *window = glfwCreateWindow(680, 480, "GLFW3_RunCheck", NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

#endif

#ifdef UNITTEST_LIBPNG

#include "libpng/zlib.h"
#include "libpng/png.h"
#include <memory.h>
#include <iostream>

int main()
{
  const char filename[] = "test.png";

  png_image image;
  memset(&image, 0, sizeof(image));
  image.version = PNG_IMAGE_VERSION;

  std::cout << "Try to load: " << filename << std::endl;
  if (png_image_begin_read_from_file(&image, filename) != NULL)
  {
    std::cout << "png: w=" << image.width
      << " h=" << image.height << std::endl;
  }
  else
  {
    std::cout << "ERROR: " << std::endl;
    if (PNG_IMAGE_FAILED(image))
    {
      std::cout << image.message << std::endl;
    }
  }

  png_uint_32 stride = PNG_IMAGE_ROW_STRIDE(image);
  png_uint_16* buffer = new png_uint_16[PNG_IMAGE_BUFFER_SIZE(image, stride)];

  delete buffer;
  png_image_free(&image);

  int temp;
  std::cin >> temp;
  return 0;
}
#endif
