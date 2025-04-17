#pragma once
class TimeManager
{
public:
	TimeManager() = default;
	~TimeManager() = default;
	void StartUp();
	void ShutDown();

	void Update();
};

// 외부에서도 사용할 수 있도록 한 것 
extern TimeManager g_TimeManager;