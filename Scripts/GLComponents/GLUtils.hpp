#ifndef GLUTILS_HPP
#define GLUTILS_HPP

namespace GLUtils
{
  //-------------------------------
  // World Space: x = [-0.5, 0.5]
  //              y = [-0.5, 0.5]
  //-------------------------------
  static void DrawTexture(GLdouble x, GLdouble y, GLdouble w, GLdouble h)
  {
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBegin(GL_QUADS);
      glTexCoord2d(0.0, 0.0); glVertex3d(x, y, 0.0);
      glTexCoord2d(0.0, 1.0); glVertex3d(x, y + h, 0.0);
      glTexCoord2d(1.0, 1.0); glVertex3d(x + w, y + h, 0.0);
      glTexCoord2d(1.0, 0.0); glVertex3d(x + w, y, 0.0);
      glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  }
  static void DrawTexture(GLdouble x, GLdouble y, GLdouble w, GLdouble h,
    GLdouble ux, GLdouble uy, GLdouble uw, GLdouble uh)
  {
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glBegin(GL_QUADS);
      glTexCoord2d(ux, uy);           glVertex3d(x, y, 0.0);
      glTexCoord2d(ux, uy + uh);      glVertex3d(x, y + h, 0.0);
      glTexCoord2d(ux + uw, uy + uh); glVertex3d(x + w, y + h, 0.0);
      glTexCoord2d(ux + uw, uy);      glVertex3d(x + w, y, 0.0);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
  }


  static void DrawRect(GLdouble x, GLdouble y, GLdouble w, GLdouble h)
  {
    glPushMatrix();

    glBegin(GL_POLYGON);
      glVertex2d(x, y);
      glVertex2d(x + w, y);
      glVertex2d(x + w, y + h);
      glVertex2d(x, y + h);
    glEnd();

    glPopMatrix();
  }

  static void DrawLine(GLdouble start_x, GLdouble start_y, GLdouble end_x, GLdouble end_y, GLdouble width)
  {
    glLineWidth((GLfloat)width);

    glBegin(GL_LINES);
      glVertex2d(start_x, start_y);
      glVertex2d(end_x, end_y);
    glEnd();
  }

  static void DrawPoint(GLdouble x, GLdouble y, GLdouble width)
  {
    glLineWidth((GLfloat)width);

    glBegin(GL_POINTS);
      glVertex2d(x, y);
    glEnd();
  }

  static void DrawCube(GLdouble x, GLdouble y, GLdouble z, GLdouble w, GLdouble h, GLdouble u)
  {
    GLVec3 v[8] = 
    {
      {x, y, z}, {x + w, y, z}, {x + w, y + h, z}, {x, y + h, z},
      {x, y, z + u}, {x + w, y, z + u}, {x + w, y + h, z + u}, {x, y + h, z + u},
    };

    glPushMatrix();
    glBegin(GL_QUADS);
      //left(fixed x)
      glVertex3d(v[0].x, v[0].y, v[0].z);
      glVertex3d(v[3].x, v[3].y, v[3].z);
      glVertex3d(v[7].x, v[7].y, v[7].z);
      glVertex3d(v[4].x, v[4].y, v[4].z);

      //right(fixed x+w)
      glVertex3d(v[1].x, v[1].y, v[1].z);
      glVertex3d(v[2].x, v[2].y, v[2].z);
      glVertex3d(v[6].x, v[6].y, v[6].z);
      glVertex3d(v[5].x, v[5].y, v[5].z);

      //bottom(fixed y)
      glVertex3d(v[0].x, v[0].y, v[0].z);
      glVertex3d(v[1].x, v[1].y, v[1].z);
      glVertex3d(v[5].x, v[5].y, v[5].z);
      glVertex3d(v[4].x, v[4].y, v[4].z);

      //top(fixed y+h)
      glVertex3d(v[2].x, v[2].y, v[2].z);
      glVertex3d(v[3].x, v[3].y, v[3].z);
      glVertex3d(v[7].x, v[7].y, v[7].z);
      glVertex3d(v[6].x, v[6].y, v[6].z);

      //forward(fixed z)
      glVertex3d(v[0].x, v[0].y, v[0].z);
      glVertex3d(v[1].x, v[1].y, v[1].z);
      glVertex3d(v[2].x, v[2].y, v[2].z);
      glVertex3d(v[3].x, v[3].y, v[3].z);

      //backward(fixed z+u)
      glVertex3d(v[4].x, v[4].y, v[4].z);
      glVertex3d(v[5].x, v[5].y, v[5].z);
      glVertex3d(v[6].x, v[6].y, v[6].z);
      glVertex3d(v[7].x, v[7].y, v[7].z);
    glEnd();
    glPopMatrix();
  }

  static void DrawShader(GLdouble x, GLdouble y, GLdouble w, GLdouble h)
  {
    //glUseProgram(shader_program);
    DrawRect(x, y, w, h);
    //glUseProgram(0);
  }

  //for Custom Classes
  static void DrawTexture(GLVec2 pos, GLVec2 siz)
  {
    DrawTexture(pos.x - (0.5 * siz.x), pos.y - (0.5 * siz.y), siz.x, siz.y);
  }
  static void DrawTexture(GLVec2 pos, GLVec2 siz, GLVec2 tex_pos, GLVec2 tex_siz)
  {
    DrawTexture(pos.x - (0.5 * siz.x), pos.y - (0.5 * siz.y), siz.x, siz.y,
      tex_pos.x, tex_pos.y, tex_siz.x, tex_siz.y);
  }

  static void DrawRect(GLVec2 pos, GLVec2 siz)
  {
    DrawRect(pos.x - (0.5 * siz.x), pos.y - (0.5 * siz.y), siz.x, siz.y);
  }

  static void DrawLine(GLVec2 start_pos, GLVec2 end_pos, GLint width)
  {
    DrawLine(start_pos.x, start_pos.y, end_pos.x, end_pos.y, width);
  }

  static void DrawPoint(GLVec2 pos, GLint width)
  {
    DrawPoint(pos.x, pos.y, width);
  }

  static void DrawShader(GLVec2 pos, GLVec2 siz)
  {
    DrawShader(pos.x, pos.y, siz.x, siz.y);
  }

  static void DrawCube(GLVec3 pos, GLVec3 siz)
  {
    DrawCube(pos.x, pos.y, pos.z, siz.x, siz.y, siz.z);
  }
};
#endif

