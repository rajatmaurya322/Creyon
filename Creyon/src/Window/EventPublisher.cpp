#include "EventPublisher.h"

namespace Creyon {

	EventPublisher::EventPublisher() 
		:m_firstMouse{true},
		m_lastCursorX{0.0f},
		m_lastCursorY{0.0f},
		m_sensitivity{0.1f},
		m_keyStates{}
	{}

	void EventPublisher::addSubscriber(const std::shared_ptr<Subscriber>& subscriber) {
		m_subscriberList.push_back(subscriber);
	}

	void EventPublisher::notifyKeyboard(float deltaTime) {
		for (std::shared_ptr<Subscriber>& subscriber : m_subscriberList) {
			subscriber->updateKeyboard(m_keyStates, deltaTime);
		}
	}

	void EventPublisher::notifyCursor(float cursorX, float cursorY) {
		if (m_firstMouse) {
			m_lastCursorX = cursorX;
			m_lastCursorY = cursorY;
			m_firstMouse = false;
		}

		float offsetX = cursorX - m_lastCursorX;
		float offsetY = m_lastCursorY - cursorY;
		offsetX *= m_sensitivity;
		offsetY *= m_sensitivity;
		
		m_lastCursorX = cursorX;
		m_lastCursorY = cursorY;

		for (std::shared_ptr<Subscriber>& subscriber : m_subscriberList) {
			subscriber->updateCursor(offsetX, offsetY);
		}
	}

	void EventPublisher::notifyMouseScroll(float offsetX, float offsetY) {
		for (std::shared_ptr<Subscriber>& subscriber : m_subscriberList) {
			subscriber->updateMouseScroll(offsetX, offsetY);
		}
	}

}