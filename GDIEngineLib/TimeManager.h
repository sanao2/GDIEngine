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

// �ܺο����� ����� �� �ֵ��� �� �� 
extern TimeManager g_TimeManager;