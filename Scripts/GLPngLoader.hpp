#pragma once
#ifndef GLPNGLOADER_HPP
#define GLPNGLOADER_HPP

#include "libpng/zlib.h"
#include "libpng/png.h"

class PNG
{
public:
  int sizeX;
  int sizeY;
  char *data;
  GLuint texture;

  bool Load(const char *filename);
  void SetTexture();
  PNG(const char *FileName);
  ~PNG();
  void Release();
};

PNG::PNG(const char *FileName)
{
  Load(FileName);
  SetTexture();
}

PNG::~PNG()
{
  free(data);
}

bool PNG::Load(const char *FileName)
{
  FILE *File;
  unsigned long size;
  size_t i;
  unsigned short int planes;
  unsigned short int bpp;
  char temp;

  if ((File = fopen(FileName, "rb")) == NULL)
  {
    printf("No File");
    return false;
  }

  //Seek BMP Width
  fseek(File, 18, SEEK_CUR);

  if ((i = fread(&sizeX, 4, 1, File)) != 1)
  {
    printf("Read Width Error");
    return false;
  }
  std::cout << "sizeX = " << sizeX << std::endl;

  if ((i = fread(&sizeY, 4, 1, File)) != 1)
  {
    printf("Read Height Error");
    return false;
  }
  std::cout << "sizeY = " << sizeY << std::endl;

  //Calc BMP Image Size
  size = sizeX * sizeY * 3;
  if ((fread(&planes, 2, 1, File)) != 1) {
    printf("NOT READ PLANE NUM");
    return false;
  }
  if (planes != 1) {
    printf("PLANE NOT 1");
    return false;
  }

  //Read Pixel
  if ((i = fread(&bpp, 2, 1, File)) != 1) {
    printf("NOT Read BMP Pixel Nums");
    return false;
  }
  if (bpp != 24) {
    printf("NOT 24bit BMP Image");
    return false;
  }

  //Read RGB
  fseek(File, 24, SEEK_CUR);
  printf("memory allocated = %lu Bytes", size);
  data = (char *)malloc(size);
  if (data == NULL) {
    printf("Cannnot Allocate BMP Memory");
    return false;
  }
  if ((i = fread(data, size, 1, File)) != 1) {
    printf("Cannot Read BMP Data");
    return false;
  }

  //BGR convert RGB
  for (i = 0; i < size; i += 3) {
    temp = data[i];
    data[i] = data[i + 2];
    data[i + 2] = temp;
  }
  return true;
}

void PNG::SetTexture()
{
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, 3, sizeX, sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
}

void PNG::Release()
{
  delete[] data;
}

#endif
