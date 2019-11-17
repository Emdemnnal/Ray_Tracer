#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

class Ray;

class Object
{
public:
  virtual void intersection(Ray ray);
  virtual void shade(Ray ray, glm::vec3 distance);
};
