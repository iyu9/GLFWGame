#pragma once
#ifndef GLVEC_HPP
#define GLVEC_HPP

struct GLPoint
{
  GLdouble x;
};

struct GLVec2
{
  GLdouble x;
  GLdouble y;
};

struct GLVec3
{
  GLdouble x;
  GLdouble y;
  GLdouble z;
};

struct GLVec4
{
  GLdouble x;
  GLdouble y;
  GLdouble z;
  GLdouble w;
};

struct GLColor
{
  GLdouble r;
  GLdouble g;
  GLdouble b;
  GLdouble a;
};

struct GLIntVec2
{
  GLint x;
  GLint y;
};

struct GLIntVec3
{
  GLint x;
  GLint y;
  GLint z;
};

struct GLIntVec4
{
  GLint x;
  GLint y;
  GLint z;
  GLint w;
};

#endif
