#include "pch.h"
#include "TimeManager.h"

// 객체 인스턴스 하나 만든 것 

TimeManager g_TimeManager; // 전역변수로 TimeManager 객체 생성
// 다른 매니저들을 전역으로 만들면 이 인스턴스가 만들어지는 시점을 제어가 불가. 
// 다른 매니저 간에 생성하는 시점을 제어하고 싶을 때 사용 

void TimeManager::StartUp()
{
	// 쿼리 컴포넌트 
}

void TimeManager::ShutDown()
{

}

void TimeManager::Update()
{
	//델타 타임 구하는 함수 
}
