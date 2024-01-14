#pragma once



/*
 *
 * Add anything you want global access to in here. Allows the Level to control the turning on and off of hitboxes.
 * 
 * SUGGESTED BUT NOT REQUIRED: Have a vector called when using the keys, not just a pointer to the Object. That way, 
 * keys do not need to be unique, and you only need ONE for each class. (Call a vector, and access whichever obj needed).
 * 
 */


struct Keys {

	static constexpr int characterKey = 0;
	static constexpr int entityKey = 1;
	static constexpr int itemKey = 2;


};