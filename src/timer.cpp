#include "timer.h"

#include "window.h"

namespace toy {

Timer::Timer()
	: _elapsed(0.0)
	, _delta(0.0)
	, _paused(false)
{
	LARGE_INTEGER freq;
	::QueryPerformanceFrequency(&freq);
	_frequency = double(freq.QuadPart);
	LARGE_INTEGER counter;
	::QueryPerformanceCounter(&counter);
	_prev_time = counter.QuadPart;
}

void Timer::tick() {
	LARGE_INTEGER counter;
	::QueryPerformanceCounter(&counter);

	_time = counter.QuadPart;
	_delta = (_time - _prev_time) / _frequency;
	if (!_paused)
		_elapsed += _delta;
	_prev_time = _time;
}

void Timer::toggle() {
	_paused = !_paused;
}

void Timer::reset() {
	_elapsed = 0.0;
}

double Timer::delta() const {
	return _delta;
}

double Timer::elapsed() const {
	return _elapsed;
}

} // namespace toy