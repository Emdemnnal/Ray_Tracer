#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

class Object;
class Ray;

class SphereObject : public Object
{
private:
  glm::vec3 position;
  float radius;
  
public:
  void intersection(Ray ray);
  void shade(Ray ray, glm::vec3 distance);
};