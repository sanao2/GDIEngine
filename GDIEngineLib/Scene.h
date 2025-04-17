#pragma once

#include <vector>
#include <type_traits>
#include "Object.h"

class Object;

class Scene
{
private:
std::vector<Object*>	m_Objects;				//기본적으로 필수적으로 존재해야 하는 오브젝트들을 저장 
std::vector<Object*>	m_DeletePendingObjects; // 어떤 특정한 조건 하에 업데이트 이후 삭제될 오브젝트들을 임시로 저장 
public:
Scene() = default;
virtual ~Scene()
{
	Clear();
}

template<typename T>
T* CreateObject()			// 새로운 오브젝트 생성. 플레이어인지, 몬스터인지 구분해서 생성할 필요 있음. 
{
	static_assert(std::is_base_of<Object, T>::value, "T must derive from Object");
	T* pObject = new T();	
	m_Objects.push_back(pObject);
	return pObject; 
}	

void Clear();

virtual void Update();
virtual void Render();	// 어떤 오브젝트 인지 모르겠지만, 호출에 맞는 오브젝트의 렌더 함수 호출. 즉, 

virtual void Enter() = 0;
virtual void Exit() { Clear(); }
};
