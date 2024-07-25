#pragma once

#include <unordered_map>

namespace Creyon {
	
	class Subscriber {
	public:

		bool isKeyPressed(const std::unordered_map<int, bool>& keyStates, const int key) {
			return keyStates.find(key) != keyStates.end() && keyStates.at(key);
		}

		virtual void updateKeyboard(const std::unordered_map<int, bool>& keyStates, float deltaTime) = 0;
		virtual void updateCursor(float offsetX, float offsetY) = 0;
		virtual void updateMouseScroll(float offsetX, float offsetY) = 0;
	};
}
