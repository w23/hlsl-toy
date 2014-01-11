#include "application.h"

#include "directx.h"

namespace toy {

bool Application::init(HINSTANCE instance) {
	_instance = instance;

	Window::register_class(instance);

	_main_window.open(instance, L"HLSL Toy", 1280, 720);
	if (!_render_device.init(_main_window)) {
		return false;
	}

	return true;
}

void Application::shutdown() {
}

bool Application::work() {
	_main_window.update();

	return !_main_window.is_closing();
}

} // namespace toy