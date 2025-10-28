#include "BoundsCheck.h"

namespace Octrees {
	bool Bounds::Intersects(Bounds otherBounds) {
		return ((std::abs(center.x - otherBounds.center.x) < (size.x + otherBounds.size.x)) &&
			(std::abs(center.y - otherBounds.center.y) < (size.y + otherBounds.size.y)) &&
			(std::abs(center.z - otherBounds.center.z) < (size.z + otherBounds.size.z)));
	}

	void Bounds::SetMinMax(glm::vec3 _min, glm::vec3 _max) {
		min = _min;
		max = _max;
		center = (min + max) * 0.5f;
		size = (max - min);
	}
}