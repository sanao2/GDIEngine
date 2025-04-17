#include "pch.h"
#include "Scene.h"
#include "Object.h"

void Scene::Clear()
{
	for (auto & object : m_Objects)
	{
		delete object;
	} 

	m_Objects.clear();// 모든 오브젝트들을 삭제. 

	for (auto& object : m_DeletePendingObjects)			
	{
		// m_DeletePendingObjects = 중간에 총알처럼 삭제하고 싶은 오브젝트가 있을 때, 삭제를 하는 처리가 일어나는 것은 Update() 가 일어날 때
	    // 원하는 위치를 벗어나는 등에 오브젝트 삭제가 필요한 판단이 섰을 때 다른 오브젝트들에게도 영향이 들어갔을 때 
		// 폭탄이 터졌을 때 바로 사라지는 게 아니라, 다른 오브젝트들이 영향을 받아야 하기 때문에 따로 삭제해야 하는 오브젝트들을 보관하는 곳 
	    // 루프가 끝난 다음에 m_DeletePendingObjects 안에 들어가 있는 주소값들을 삭제해주는 것. 

		delete object;
	}
	m_DeletePendingObjects.clear();
}

void Scene::Update()
{
	for (auto& object : m_Objects)
	{
		object->Update();
	}
}

void Scene::Render()
{
	for (auto& object : m_Objects)
	{
		object->Render();
	}
}
