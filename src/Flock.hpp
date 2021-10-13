#pragma once

#include "myMath/Vec2.hpp"
#include "vector"
#include "Bird.hpp"
// #include "myMath/utils.hpp"

class Flock {
private :
	int m_popSize;
	std::vector<Bird> m_birdsVec;
	// std::vector<Vec2> m_nextPos;

public:
	void print();
	int getPopSize() const;
	Bird getAgent(int index) const;
	void createPopulation();
	void calculatePositions();
	void updatePositions();
	std::vector<Bird> computeNeighbors(const Bird& bird, const float& range, const float& angle);
	void addAgent();
	void addAgent(float xpos, float ypos);

	void addAgent(Bird b);
	void destroyAgent(Vec2 position);
	void moveAgents();

public:
	Flock(); // Constructeur avec argument par d�faut
	Flock(int popsize);
	~Flock() {}; // Destructeur

};