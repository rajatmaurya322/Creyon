#pragma once

#include <map>
#include "Utilities/Utility.h"
#include "Input.h"

namespace Creyon {

	class Entity {
	private:
		static std::map<int, KeyData> KeyMap;
		static inline MousePos position{ false ,0.0f, 0.0f };
		static inline float delta{ 0.0f }, lastFrame{ 0.0f };

	protected:
		virtual void onKey() {};
		virtual void onMouseMotion() {};

	public:
		virtual void update();

		//Static functions to modify static variables
		static void changeKeyState(bool press, int key, int scancode, int mods);
		static void changeMousePosition(float offsetX, float offsetY);
		static bool isPressed(int key);
		static void updateDelta();
		static void resetMotion() { position.motion = false; }
		static float getDelta() { return delta; }
		static float getOffsetX() { return position.offsetX; }
		static float getOffsetY() { return position.offsetY; }
	};

}
