#pragma once

#include <vector>
#include <array>
#include "../../lib/myMath/Vec2.hpp"
#include "oglTypes.hpp"
#include "../Bird.hpp"

mat2x6 drawAgent(Vec2 position, Vec2 velocity);

void keepPositionInScreen(Bird& bird, float width, float height);