#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

class Ray;

class Camera
{
public:
  Camera();
  ~Camera();

  Ray createRay(glm::ivec2 position);
protected:
  glm::mat4 viewMat, projMat, invViewMat, invProjMat;
};
