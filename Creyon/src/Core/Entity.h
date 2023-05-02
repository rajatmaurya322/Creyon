#pragma once

#include "Utilities/Utility.h"
#include "Input.h"
#include <map>
#include <iostream>

namespace Creyon {

	class Entity {
	private:
		static std::map<int, KeyData> m_KeyMap;
		static MousePos m_position;
		static float m_delta;

	protected:
		//defines behaviour to perform when key is pressed
		virtual void onKey(float delta) = 0;

		//defines behaviour to perform when mouse moves
		virtual void onMouseMotion(float offsetX, float offsetY) = 0;

	public:

		//Updates behaviours of the entity
		void update();

		//Records Keyboard's state changes
		static void changeKeyState(bool press, int key, int mods);
		
		//Records Mouse movement changes
		static void changeMousePosition(float offsetX, float offsetY);
				
		//Updates deltaTime value
		static void updateDelta();

		//Checks if a key is in pressed state
		static bool isPressed(int key);
		
		//Resets flags
		static void resetFlags() { m_position.motion = false; }
	};
}