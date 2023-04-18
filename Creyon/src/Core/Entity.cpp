#include "Entity.h"

namespace Creyon {
	
	//Initialise the KeyMap
	std::map<int, KeyData> Entity::m_KeyMap{
		{GLFW_KEY_W,{false,0,0}},
		{GLFW_KEY_S,{false,0,0}},
		{GLFW_KEY_A,{false,0,0}},
		{GLFW_KEY_D,{false,0,0}}
	};

	void Entity::update() {
		//Calls the defined behaviours
		onKey(m_delta);
		if (m_position.motion) {   //Checks if mouse has moved
			onMouseMotion(m_position.offsetX, m_position.offsetY);
		}
	}

	void Entity::changeKeyState(bool press, int key, int scancode, int mods) {
		if (m_KeyMap.find(key) != m_KeyMap.end()) {
			m_KeyMap[key].pressed = press;
			m_KeyMap[key].scancode = scancode;
			m_KeyMap[key].mods = mods;
		}
		else {
			std::cout << "Does not recognize this key";
		}
	}

	void Entity::changeMousePosition(float offsetX, float offsetY) {
		m_position.motion = true;
		m_position.offsetX = offsetX;
		m_position.offsetY = offsetY;
	}

	bool Entity::isPressed(int key) {
		if (m_KeyMap.find(key) != m_KeyMap.end()) {
			return m_KeyMap[key].pressed;
		}
		else {
			return false;
		}
	}

	void Entity::updateDelta() {
		static float lastFrame = 0.0f;
		float current = getTime();
		m_delta = current - lastFrame;
		lastFrame = current;
	}
}