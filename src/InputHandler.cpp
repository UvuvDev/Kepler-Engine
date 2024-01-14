
#include "include/InputHandler.hpp"

InputHandlerClass::InputHandlerClass() {
	mousePos = GetMousePosition();
}

Vector2 InputHandlerClass::getMousePos() {
	return mousePos;
}

void InputHandlerClass::update() {
	mousePos = GetMousePosition();

}

