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
  virtual intersectionResult intersection(Ray ray, glm::ivec3 sphereCentre, float _radius);
  virtual void shade(Ray ray, glm::vec3 distance);
};
