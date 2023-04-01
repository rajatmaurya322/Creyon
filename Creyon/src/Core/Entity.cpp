#include "Entity.h"

namespace Creyon {
	
	//Initialise the KeyMap
	std::map<int, KeyData> Entity::KeyMap{
		{GLFW_KEY_W,{false,0,0}},
		{GLFW_KEY_S,{false,0,0}},
		{GLFW_KEY_A,{false,0,0}},
		{GLFW_KEY_D,{false,0,0}}
	};

	void Entity::update() {
		onKey();
		if (position.motion) {
			onMouseMotion();
		}
	}

	void Entity::changeKeyState(bool press, int key, int scancode, int mods) {
		if (KeyMap.find(key) != KeyMap.end()) {
			KeyMap[key].pressed = press;
			KeyMap[key].scancode = scancode;
			KeyMap[key].mods = mods;
		}
		else {
			std::cout << "Does not recognize this key";
		}
	}

	void Entity::changeMousePosition(float offsetX, float offsetY) {
		position.motion = true;
		position.offsetX = offsetX;
		position.offsetY = offsetY;
	}

	bool Entity::isPressed(int key) {
		if (KeyMap.find(key) != KeyMap.end()) {
			return KeyMap[key].pressed;
		}
		else {
			return false;
		}
	}

	void Entity::updateDelta() {
		float current = getTime();
		delta = current - lastFrame;
		lastFrame = current;
	}
}