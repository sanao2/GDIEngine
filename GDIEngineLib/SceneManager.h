#pragma once

#include "Singleton.h"



class Scene;
class SceneManager : public Singleton<SceneManager>
{
	friend class Singleton<SceneManager>; // 이 클래스만 생성자 접근 허용
private:
	SceneManager() = default;			// 다른 생성을 통한 생성자 호출은 금지
	~SceneManager();

	std::vector<Scene*> m_vScenes;	  // 씬 리스트

	Scene* m_pCurrentScene = nullptr; // 현재 씬
	Scene* m_pNextScene = nullptr;    // 다음 씬

public:
	void Init();
	void Update();
	void Render();
	void ChangeScene(size_t index);

	Scene* GetCurrentScene() { return m_pCurrentScene; }

	template<typename T> // createScene <TestScene>(); 
	void CreateScene()
	{
		Scene* pScene = new T(); // 생성 
		m_vScenes.push_back(pScene); // 씬 저장용 벡터에 저장 
	}
};