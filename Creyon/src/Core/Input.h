#pragma once

namespace Creyon {

	struct KeyData {
		bool pressed;
		int scancode, mods;
	};

	struct MousePos {
		bool motion;
		float offsetX, offsetY;
	};
}
