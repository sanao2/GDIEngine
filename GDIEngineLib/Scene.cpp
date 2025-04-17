#include "pch.h"
#include "Scene.h"
#include "Object.h"

void Scene::Clear()
{
	for (auto & object : m_Objects)
	{
		delete object;
	} 

	m_Objects.clear();// ��� ������Ʈ���� ����. 

	for (auto& object : m_DeletePendingObjects)			
	{
		// m_DeletePendingObjects = �߰��� �Ѿ�ó�� �����ϰ� ���� ������Ʈ�� ���� ��, ������ �ϴ� ó���� �Ͼ�� ���� Update() �� �Ͼ ��
	    // ���ϴ� ��ġ�� ����� � ������Ʈ ������ �ʿ��� �Ǵ��� ���� �� �ٸ� ������Ʈ�鿡�Ե� ������ ���� �� 
		// ��ź�� ������ �� �ٷ� ������� �� �ƴ϶�, �ٸ� ������Ʈ���� ������ �޾ƾ� �ϱ� ������ ���� �����ؾ� �ϴ� ������Ʈ���� �����ϴ� �� 
	    // ������ ���� ������ m_DeletePendingObjects �ȿ� �� �ִ� �ּҰ����� �������ִ� ��. 

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
