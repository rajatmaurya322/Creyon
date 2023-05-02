#pragma once

namespace Creyon {
	
	struct KeyData {
		bool pressed;
		int mods;
	};

	struct MousePos {
		bool motion;
		float offsetX, offsetY;
	};
}
