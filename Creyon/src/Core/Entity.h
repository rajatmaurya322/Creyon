#pragma once

#include <map>
#include "Utilities/Utility.h"
#include "Input.h"

namespace Creyon {

	class Entity {
	private:
		static std::map<int, KeyData> m_KeyMap;
		static inline MousePos m_position{ false ,0.0f, 0.0f };
		static inline float m_delta{ 0.0f };

	protected:
		//defines behaviour to perform when key is pressed
		virtual void onKey(float delta) {};

		//defines behaviour to perform when mouse moves
		virtual void onMouseMotion(float offsetX, float offsetY) {};

	public:

		//Updates behaviours of the entity
		virtual void update();

		//Records Keyboard's state changes
		static void changeKeyState(bool press, int key, int scancode, int mods);
		
		//Records Mouse movement changes
		static void changeMousePosition(float offsetX, float offsetY);
		
		//Checks if a key is in pressed state
		static bool isPressed(int key);
		
		//Updates deltaTime value 
		static void updateDelta();
		
		//Resets flags
		static void resetMotion() { m_position.motion = false; }
	};

}
