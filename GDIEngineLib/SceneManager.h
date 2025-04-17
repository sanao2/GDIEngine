#pragma once

#include "Singleton.h"



class Scene;
class SceneManager : public Singleton<SceneManager>
{
	friend class Singleton<SceneManager>; // �� Ŭ������ ������ ���� ���
private:
	SceneManager() = default;			// �ٸ� ������ ���� ������ ȣ���� ����
	~SceneManager();

	std::vector<Scene*> m_vScenes;	  // �� ����Ʈ

	Scene* m_pCurrentScene = nullptr; // ���� ��
	Scene* m_pNextScene = nullptr;    // ���� ��

public:
	void Init();
	void Update();
	void Render();
	void ChangeScene(size_t index);

	Scene* GetCurrentScene() { return m_pCurrentScene; }

	template<typename T> // createScene <TestScene>(); 
	void CreateScene()
	{
		Scene* pScene = new T(); // ���� 
		m_vScenes.push_back(pScene); // �� ����� ���Ϳ� ���� 
	}
};