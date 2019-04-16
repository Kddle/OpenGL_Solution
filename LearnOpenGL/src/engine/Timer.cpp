#pragma once
#include "Timer.h"

using namespace Kaddle::Engine;

void Timer::init()
{
	lastLoopTime = getTime();
}

double Timer::getTime()
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
	auto nanosecs = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
	return (double)nanosecs / 1000000000.0;
}

float Timer::getElapsedTime()
{
	double time = getTime();
	float elapsedTime = (float)(time - lastLoopTime);
	lastLoopTime = time;
	return elapsedTime;
}

double Timer::getLastLoopTime()
{
	return lastLoopTime;
}