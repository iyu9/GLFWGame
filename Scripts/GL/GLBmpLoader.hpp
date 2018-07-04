#pragma once
#ifndef GLBMPLOADER_HPP
#define GLBMPLOADER_HPP

class BMP
{
public:
  int sizeX;
  int sizeY;
  char *data;
  GLuint texture;

  bool Load(const char *filename);
  void SetTexture();
  BMP(const char *FileName);
  ~BMP();
  void Release();
};

BMP::BMP(const char *FileName)
{
  Load(FileName);
  SetTexture();
}

BMP::~BMP()
{
  free(data);
}

bool BMP::Load(const char *FileName)
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

  if ((i = fread(&sizeY, 4, 1, File)) != 1) {
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

void BMP::SetTexture()
{
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, 3, sizeX, sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
}

void BMP::Release()
{
  delete[] data;
}

//NOT WORK
class BMPMultiple
{
public:
  int w_slice;
  int h_slice;
  std::vector<BMP*> bmps;

  int sizeX;
  int sizeY;
  char *Data;
  bool Load(const char *filename);
  GLuint texture;

  bool Load(const char* FileName, int w_slice_, int h_slice_)
  {
    FILE *File;
    unsigned long size;
    size_t i;
    unsigned short int planes;
    unsigned short int bpp;
    char temp;

    //set division 
    w_slice = w_slice_;
    h_slice = h_slice_;

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

    if ((i = fread(&sizeY, 4, 1, File)) != 1) {
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
    Data = (char *)malloc(size);
    if (Data == NULL) {
      printf("Cannnot Allocate BMP Memory");
      return false;
    }
    if ((i = fread(Data, size, 1, File)) != 1) {
      printf("Cannot Read BMP Data");
      return false;
    }

    //BGR convert RGB
    for (i = 0; i < size; i += 3) {
      temp = Data[i];
      Data[i] = Data[i + 2];
      Data[i + 2] = temp;
    }

    ////////////////////////////////
    //edit W and H
    const int RGBChunk = 3;
    int rowCount = 0;
    for (i = 0; i < size; i += RGBChunk)
    {
      if (rowCount <= w_slice_)
      {
        rowCount = 0;
        i += w_slice_ * RGBChunk;
      }
      rowCount++;
    }
    ////////////////////////////////

    return true;
  }
};
#endif
