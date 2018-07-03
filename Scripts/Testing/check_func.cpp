#include<stdio.h>
#include<iostream>

int main (int argc, char** argv)
{
  char FileName[] = "../Resources/sample.bmp";
  char *Data;
  FILE* File;
  size_t i;
  long size  = 0;
  long sizeX = 0;
  long sizeY = 0;
  char temp;
  
  unsigned short int planes;
  unsigned short int bpp;

  if ((File = fopen(FileName, "rb")) == NULL){
    printf("No File");
    return -1;
  }

  //Seek BMP Width
  fseek(File, 18, SEEK_CUR);

  if ((i = fread(&sizeX, 4, 1, File)) != 1) {
    printf("Read Width Error");
    return -1;
  }
  std::cout << "sizeX " << sizeX << std::endl;

  if ((i = fread(&sizeY, 4, 1, File)) != 1) {
    printf("Read Height Error");
    return -1;
  }
  std::cout << "sizeY " << sizeY << std::endl;

  //Calc BMP Image Size
  size = sizeX * sizeY * 3;
  if ((fread(&planes, 2, 1, File)) != 1) {
    printf("NOT READ PLANE NUM");
    return -1;
  }
  if (planes != 1) {
    printf("PLANE NOT 1");
    return -1;
  }

  //Read Pixel
  if ((i = fread(&bpp, 2, 1, File)) != 1) {
    printf("NOT Read BMP Pixel Nums");
    return -1;
  }
  if (bpp != 24) {
    printf("NOT 24bit BMP Image");
    return -1;
  }

  //Read RGB
  fseek(File, 24, SEEK_CUR);
  printf("memory allocated = %lu Bytes", size);
  Data = (char *)malloc(size);
  if (Data == NULL) {
    printf("Cannnot Allocate BMP Memory");
    return -1;
  }
  if ((i = fread(Data, size, 1, File)) != 1) {
    printf("Cannot Read BMP Data");
    return -1;
  }
    
  //BGR convert RGB
  for (i = 0; i < size; i += 3) {
    temp = Data[i];
    Data[i] = Data[i + 2];
    Data[i + 2] = temp;
  }
  return 0;   
}
