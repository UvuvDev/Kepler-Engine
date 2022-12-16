#pragma once

#include <vector>
#include "Tag.hpp"


bool updateAllClasses();


class BaseClass {

	/*
	
	 When making new custom game objects, you must always inherit from the BaseClass at least.
	 Otherwise, the object will not update ever.
	
	*/

	virtual void update() = 0;

	virtual void reset() = 0;






};

