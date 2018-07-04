#pragma once
#ifndef PHYSICS_HPP
#define PHYSICS_HPP

namespace PhysicsDef
{
  const double GRV    = 0.001;
  const double N = 0.05;

  const double WALL_L = -1;
  const double WALL_R = 1;
  const double FLOOR  = -0.5;
  const double JUMP_V = 0.05;

  const double ADD_VELOCITY = 0.01;

  const int JMP_LIM = 9;
};
using namespace PhysicsDef;

namespace Dir2D
{
  const int UP    = 0x001;
  const int RIGHT = 0x002;
  const int LEFT  = 0x004;
  const int DOWN  = 0x008;
};
using namespace Dir2D;

class Physics
{
private:
  void CheckFall()
  {
    if (is_unuse_gravity)
    {
      return;
    }

    if (y > FLOOR)
    {
      t = 0;
      is_fall = true;
    }

    if (y <= FLOOR)
    {
      t = 0; vy = 0;
      y = FLOOR;
      is_fall = false;
      jmp_cnt = 0;
    }
  }

  void UpdateMoving()
  {
    if (vy != 0)
    {
      vy -= GRV;
      y += vy;
    }

    if (vx != 0)
    {
      vx *= (1 - N);
      x += vx;
    }
  }

public:
  bool is_unuse_gravity;
  bool is_fall;
  bool is_jump;

  int jmp_cnt;

  double t;
  double x, y;
  double vx, vy;
  double ax, ay;

  Physics()
  {
    t = x = y = vx = vy = ax = ay = 0;
    is_fall = false;
    is_jump = false;
    is_unuse_gravity = false;
  }

  void Jump()
  {
    if (jmp_cnt <= JMP_LIM)
    {
      jmp_cnt++;

      y += 0.01;
      vy = JUMP_V;
    }
  }

  void AddVelocity(const int dir)
  {
    switch (dir)
    {
    case UP:
      vy = ADD_VELOCITY;
      break;
    case DOWN:
      vy = -ADD_VELOCITY;
      break;
    case LEFT:
      vx = -ADD_VELOCITY;
      break;
    case RIGHT:
      vx = ADD_VELOCITY;
      break;
    }
  }

  void Update()
  {
    CheckFall();
    UpdateMoving();
  }
};

#endif
