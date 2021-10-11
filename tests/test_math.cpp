#define _USE_MATH_DEFINES
#include <iostream>
#include "gtest/gtest.h"
#include "../src/myMath/vec2.hpp"
#include "../src/myMath/utils.hpp"
#include <vector>
#include <cmath>

// blank namespace to avoid implementation collision
namespace {

	/*TEST(Vec2, Init) {
		ASSERT_EQ(vec2(), vec2(0., 0.)) << "Initialization without arguments";
		vec2 a = vec2(2.5, 5.5);
		ASSERT_EQ(a, vec2(2.5, 5.5)) << "Initialization with arguments";
	}*/

	TEST(Vec2, Methods) {
		Vec2 a = Vec2(4., 3.);
		Vec2 b = Vec2(0., 1.);
		ASSERT_NEAR(a.norm(), 5., 1e-3) << "Norm";
		ASSERT_TRUE(a.normalize() == Vec2(0.8, 0.6)) << "Normalized vector";
		ASSERT_NEAR(a.angle(), 0.644, 1e-3) << "angle";
		ASSERT_NEAR(a.angle(b), 0.927, 1e-3) << "angle with other vector";
		ASSERT_NEAR(a.dot(b), 3., 1e-3) << "dot";
		ASSERT_NEAR(a.x(), 4., 1e-3) << "get x";
		ASSERT_NEAR(a.y(), 3., 1e-3) << "get y";
		Vec2 c = Vec2(1., 0.).rotate(M_PI / 3);
		ASSERT_NEAR(c.x(), 0.500000, 1e-3);
		ASSERT_NEAR(c.y(), 0.866025, 1e-3);
	}

	TEST(Functions, All) {
		Vec2 a = Vec2(4., 3.);
		Vec2 b = Vec2(0., 1.);
		ASSERT_NEAR(distance(a, b), 4.472, 1e-3) << "Distance";
		std::vector<Vec2> vecs;
		vecs.push_back(a);
		vecs.push_back(b);
		ASSERT_TRUE(barycenter(vecs) == Vec2(2., 2.)) << "Barycenter";
		ASSERT_NEAR(radians(90), M_PI / 2, 1e-3);
		ASSERT_NEAR(degrees(M_PI), 180, 1e-3);
	}
}
