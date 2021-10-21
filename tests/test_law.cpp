#include <iostream>
#include "gtest/gtest.h"
#include "../src/resources/model/Bird.hpp"
#include "../src/resources/model/Flock.hpp"
#include "../src/resources/model/Agent.hpp"
#include <vector>
#include "../src/lib/myLaws/AlignmentLaw.hpp"
#include "../src/lib/myMath/Vec2.hpp"

namespace {
	TEST(AlignmentLaw,BasicsTests) {
        int size = 2;
        Flock* flockPtr = nullptr;
        std::vector<Agent*> mainFlock;

        mainFlock.reserve(size);
        mainFlock.push_back(new Bird{ Vec2(0.f, 0.f), Vec2(0.f, 1.f) });
        mainFlock.push_back(new Bird{ Vec2(0.5f, 0.5f), Vec2(1.f, -1.f) });
        mainFlock.push_back(new Bird{ Vec2(-0.5f, 0.5f), Vec2(0.f, -1.f) });


        Flock flock{ mainFlock };
        flockPtr = &flock;

        std::vector<Vec2> alignments;

        for (auto& bird : *flockPtr) {

            std::vector<Agent*> aVec = (*flockPtr).computeNeighbors(*bird);
            AlignmentLaw law;
            Vec2 vecAlignment = law.compute(*bird, aVec);
            alignments.push_back(vecAlignment);
            //std::cout << "Bird " << (*bird)._id << " | Alignment Law : " << vecAlignment << '\n';
        }

        EXPECT_EQ(alignments[0].x, 0.5f);
        EXPECT_EQ(alignments[0].y, -1.f);
        EXPECT_EQ(alignments[1].x, 0.f);
        EXPECT_EQ(alignments[1].y, 0.f);
        EXPECT_EQ(alignments[2].x, 1.f);
        EXPECT_EQ(alignments[2].y, -1.f);
	}

    TEST(CohesionLaw, BasicTests) {
        int size = 2;
        Flock* flockPtr = nullptr;
        std::vector<Agent*> mainFlock;

        mainFlock.reserve(size);
        mainFlock.push_back(new Bird{ Vec2(0.f, 0.f), Vec2(0.f, 1.f) });
        mainFlock.push_back(new Bird{ Vec2(30.0f, 30.0f), Vec2(1.f, -1.f) });
        mainFlock.push_back(new Bird{ Vec2(-30.0f, 30.0f), Vec2(0.f, -1.f) });

        Flock flock{ mainFlock };
        flockPtr = &flock;

        std::vector<Vec2> cohesions;

        for (auto& bird : *flockPtr) {

            std::vector<Agent*> aVec = (*flockPtr).computeNeighbors(*bird);
            CohesionLaw cLaw;
            Vec2 vecCohesion = cLaw.compute(*bird, aVec);
            cohesions.push_back(vecCohesion);
            //std::cout << "Bird " << (*bird)._id << " | Cohesion Law : " << vecCohesion << '\n';
        }

        EXPECT_EQ(cohesions[0].x, 0.f);
        EXPECT_NEAR(cohesions[0].y, 250.f, 5);
        EXPECT_NEAR(cohesions[1].x, -125.f, 5);
        EXPECT_NEAR(cohesions[1].y, -125.f, 5);
        EXPECT_NEAR(cohesions[2].x, 0.f, 5); //0 because out of range from [1] (60 > 50) and angle from [0] (135,001 > 135 or 135 !< 270/2)
        EXPECT_NEAR(cohesions[2].y, 0.f, 5);
    }

    TEST(SeparationLaw, BasicTests) {
        int size = 2;
        Flock* flockPtr = nullptr;
        std::vector<Agent*> mainFlock;

        mainFlock.reserve(size);
        mainFlock.push_back(new Bird{ Vec2(0.f, 0.f), Vec2(0.f, 1.f) });
        mainFlock.push_back(new Bird{ Vec2(0.5f, 0.5f), Vec2(1.f, -1.f) });
        mainFlock.push_back(new Bird{ Vec2(-0.5f, 0.5f), Vec2(0.f, -1.f) });


        Flock flock{ mainFlock };
        flockPtr = &flock;

        std::vector<Vec2> separations;

        for (auto& bird : *flockPtr) {

            std::vector<Agent*> aVec = (*flockPtr).computeNeighbors(*bird);
            SeparationLaw law;
            Vec2 vecSeparation = law.compute(*bird, aVec);
            separations.push_back(vecSeparation);
            //std::cout << "Bird " << (*bird)._id << " | Separation Law : " << vecSeparation << '\n';
        }

        EXPECT_EQ(separations[0].x, 0.f);
        EXPECT_NEAR(separations[0].y, -2.f, 0.1f);
        EXPECT_NEAR(separations[1].x, 2.f, 0.1f);
        EXPECT_NEAR(separations[1].y, 1.f, 0.1f);
        EXPECT_NEAR(separations[2].x, -1.f, 0.1f);  //-1.f and not -2.f because a neighbor is not a viable neighbor
        EXPECT_NEAR(separations[2].y, 0.f, 0.1f);   //0.f and not -1.f because a neighbor is not a viable neighbor
    }
}