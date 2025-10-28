#pragma once

#ifndef BOUNDSCHECK_H
#define BOUNDSCHECK_H

#include "Config/pch.h"
#include "ECS/ECS.h"

namespace Octrees {
	struct Bounds {
		glm::vec3 center, size, min, max;

		bool Intersects(Bounds otherBounds);
		void SetMinMax(glm::vec3 _min, glm::vec3 _max);
	};
}

#endif