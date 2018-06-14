/*
 * =====================================================================================
 *
 *       Filename:  Camera.cpp
 *
 *    Description:
 *
 *        Created:  16/12/2014 12:21:19
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <glm/gtc/matrix_transform.hpp>

#include "Camera.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"

Camera::Camera() {
	m_x = 0;
	m_y = 16;
	m_z = -64;

	m_angleH = 90.0;
	m_angleV = 0.0;

	m_vx = 0;
	m_vz = 0;

	update();
}

void Camera::turnH(float angle) {
	m_angleH += angle;

	while(m_angleH >= 180.0f) {
		m_angleH -= 360.0f;
	}
	while(m_angleH < -180.0f) {
		m_angleH += 360.0f;
	}
}

void Camera::turnV(float angle) {
	m_angleV += angle;

	if(89.9f < m_angleV) {
		m_angleV = 89.9f;
	}
	else if(-89.9f > m_angleV) {
		m_angleV = -89.9f;
	}
}

void Camera::move(float direction) {
	direction += m_angleH;

	m_vx = 0.04f * cos(direction * RADIANS_PER_DEGREES);
	m_vz = 0.04f * sin(direction * RADIANS_PER_DEGREES);

	m_x += m_vx;
	m_z += m_vz;

	m_vx = 0;
	m_vz = 0;
}

glm::mat4 Camera::processInputs() {
	// if(Mouse::getDX() != 0 || Mouse::getDY() != 0) {
	// 	turnH(Mouse::getDX() * 0.2f);//0.02);
	// 	turnV(-Mouse::getDY() * 0.2f);//0.02);
	// 	// m_viewMatrix = update();
	// }

	if(Keyboard::isKeyPressed(Keyboard::Space)) {
		m_y += 0.1;
		update();
	}
	if(Keyboard::isKeyPressed(Keyboard::LeftShift)) {
		m_y -= 0.1;
		update();
	}

	if(Keyboard::isKeyPressed(Keyboard::Z)) {
		move(0.0f);
		update();
	}
	else if(Keyboard::isKeyPressed(Keyboard::S)) {
		move(180.0f);
		update();
	}

	if(Keyboard::isKeyPressed(Keyboard::Q)) {
		move(-90.0f);
		update();
	}
	else if(Keyboard::isKeyPressed(Keyboard::D)) {
		move(90.0f);
		update();
	}

	return m_viewMatrix;
}

void Camera::update() {
	m_viewMatrix = glm::lookAt(glm::vec3(m_x, m_y, m_z),
	                           glm::vec3(pointTargetedX(), pointTargetedY(), pointTargetedZ()),
	                           glm::vec3(0, 1, 0));
}
