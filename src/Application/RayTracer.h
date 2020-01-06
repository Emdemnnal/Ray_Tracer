#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <memory>
#include <vector>

class Ray;
class Camera;
class Object;
class SphereObject;

class RayTracer
{
protected:
  std::vector<std::shared_ptr<Object>> list;
public:	
  glm::ivec3 trace(Ray ray);
};
