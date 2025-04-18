#pragma once
#include "Singleton.h"

class TimeManager : public Singleton<TimeManager>
{
public:
	TimeManager() = default;
	~TimeManager() = default;
	void StartUp();
	void Shutdown();
	void Update();
};
