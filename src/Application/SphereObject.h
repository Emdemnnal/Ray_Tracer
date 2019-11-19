#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <utility>

class Object;
class Ray;

struct intersectionResult
{
  bool hit;
  float distance;
};

class SphereObject : public Object
{
private:
  glm::ivec3 position;
  float radius;
  
  //glm::ivec3 pointToLine(Ray ray, glm::ivec3 queryPoint);
  intersectionResult intersection(Ray ray, glm::ivec3 sphereCentre, float _radius);
  void shade(Ray ray, glm::vec3 distance);
};