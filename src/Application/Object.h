#ifndef _APPLICATION_OBJECT_H_
#define _APPLICATION_OBJECT_H_

#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

class Ray;

struct intersectionResult
{
  bool hit;
  float distance;
  glm::vec3 intersectionPoint;
};

class Object
{
public:
  virtual intersectionResult intersection(Ray ray);
  virtual glm::vec3 shade(glm::vec3 sphereNormal);
  virtual glm::vec3 getNormal(glm::vec3 intersectionPoint);
};

#endif