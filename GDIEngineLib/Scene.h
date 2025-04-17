#pragma once

#include <vector>
#include <type_traits>
#include "Object.h"

class Object;

class Scene
{
private:
std::vector<Object*>	m_Objects;				//�⺻������ �ʼ������� �����ؾ� �ϴ� ������Ʈ���� ���� 
std::vector<Object*>	m_DeletePendingObjects; // � Ư���� ���� �Ͽ� ������Ʈ ���� ������ ������Ʈ���� �ӽ÷� ���� 
public:
Scene() = default;
virtual ~Scene()
{
	Clear();
}

template<typename T>
T* CreateObject()			// ���ο� ������Ʈ ����. �÷��̾�����, �������� �����ؼ� ������ �ʿ� ����. 
{
	static_assert(std::is_base_of<Object, T>::value, "T must derive from Object");
	T* pObject = new T();	
	m_Objects.push_back(pObject);
	return pObject; 
}	

void Clear();

virtual void Update();
virtual void Render();	// � ������Ʈ ���� �𸣰�����, ȣ�⿡ �´� ������Ʈ�� ���� �Լ� ȣ��. ��, 

virtual void Enter() = 0;
virtual void Exit() { Clear(); }
};
