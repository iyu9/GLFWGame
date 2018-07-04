#pragma once
#ifndef GLSCENE_HPP
#define GLSCENE_HPP

class GLScene
{
protected:
  std::vector<GLObject*> objects;

public:
  GLScene()
  {
    Start();
  }

  ~GLScene()
  {
    
  }

  void Search(const char* name)
  {
    //TBD...
  }

  void AddScene(GLObject* obj)
  {
    objects.push_back(obj);
  }

  void Pop()
  {
    objects.pop_back();
  }

  virtual bool Render()
  {
    for (int idx = 0; idx < objects.size(); idx++)
    {
      objects[idx]->Render();
    }

    Update();
    return false;
  }

  virtual void Start(){}
  virtual void Update(){}

  virtual void Release()
  {
    for (int idx = 0; idx < objects.size()-1; idx++)
    {
      delete objects[idx];
    }
  }
};
#endif