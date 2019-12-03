#ifndef _APPLICATION_OBJECT_H_
#define _APPLICATION_OBJECT_H_

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

class Ray;

struct intersectionResult
{
  bool hit;
  float distance;
};

class Object
{
public:
  virtual intersectionResult intersection(Ray ray, glm::vec3 sphereCentre, float radius);
  virtual glm::vec3 shade(Ray ray, glm::vec3 distance);
};

#endif