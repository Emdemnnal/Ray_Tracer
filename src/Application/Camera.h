#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

class Ray;

class Camera
{
	Ray createRay(glm::ivec2 position);
};