#pragma once

#include "MathEngine/vector3d.h"
#include "MathEngine/matrix4x4.h"
#include "MathEngine/transforms.h"
#include "Utilities/Utility.h"

//Namespace is Creyon
namespace Creyon {
	
	class Camera{	//Class to represent a camera
		private:
			vector3d m_pos, m_target, m_up, m_front;
			float m_speed, m_yaw, m_pitch;

		public:
			//Initializes the camera position and target using setCamera()
			Camera();

			//Get m_speed
			float getSpeed() { return m_speed; }
			
			//Sets camera to view at some specific target from specified position
			void setCamera(const vector3d& pos, const vector3d& front, const vector3d& up, const float speed);

			//Moves camera forward
			void moveForward(const float camSpeed);

			//Moves camera forward
			void moveBackward(const float camSpeed);

			//Moves camera forward
			void moveRight(const float camSpeed);

			//Moves camera forward
			void moveLeft(const float camSpeed);

			//Updates horizontal and vertical angle
			void increaseAngle(const float x, const float y);

			//Rotates camera according to mouse
			void rotateCamera();

			//Updates the camera target
			void UpdateTarget();

			//Generates the lookAt matrix
			Mat44 lookAt();
	};
	//Reference: OglDev for camera's quaternion rotation and learnOpengl.com
}

