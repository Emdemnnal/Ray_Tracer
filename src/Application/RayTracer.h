#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

class Ray;
class Camera;

class RayTracer
{
public:	
  glm::ivec3 trace(Ray ray);
};
