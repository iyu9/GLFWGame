#pragma once
#ifndef GLOBJECT_HPP
#define GLOBJECT_HPP

namespace RenderType
{
  const int Rect = 0;
  const int Texture = 1;
  const int Polygon = 2;
  const int Shader = 3;
  const int Cube = 4;
};

class GLObject
{
public:
  int id;
  int type;
  int order;
  char* name;
  GLuint textureID;

  bool is_visible;

  GLVec2 siz;
  GLVec2 pos;

  GLVec2 tex_siz;
  GLVec2 tex_pos;

  GLColor color;

  GLObject(GLVec2 _pos, GLVec2 _siz)
  {
    siz = _siz;
    pos = _pos;
    is_visible = true;
    tex_siz = {1, 1};
    tex_pos = {0, 0};
  }

  void SetType(GLint _type)
  {
    type = _type;
  }

  void Set3DCube()
  {
    type = RenderType::Cube;
  }

  void Set2DTexture(GLuint _textureID)
  {
    type = RenderType::Texture;
    textureID = _textureID;
  }

  void Set2DTexture(GLuint _textureID, GLVec2 _tex_pos, GLVec2 _tex_siz)
  {
    type = RenderType::Texture;
    textureID = _textureID;
    tex_siz = _tex_siz;
    tex_pos = _tex_pos;
  }

  bool Render()
  {
    if (!is_visible)
    {
      return false;
    }

    switch (type)
    {
    case RenderType::Rect:
      GLUtils::DrawRect(pos, siz);
      break;

    case RenderType::Texture:
      glBindTexture(GL_TEXTURE_2D, textureID);
      //GLUtils::DrawTexture(pos, siz);
      GLUtils::DrawTexture(pos, siz, tex_pos, tex_siz);
      break;

    case RenderType::Shader:
      GLUtils::DrawShader(pos, siz);
      break;

    case RenderType::Cube:
      GLUtils::DrawCube(pos.x, pos.y, -1, siz.x, siz.y, 0.5);
      break;

    case RenderType::Polygon:
      //TBD
      break;
    }

    return true;
  }
};

#endif
