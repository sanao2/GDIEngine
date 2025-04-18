#pragma once

class Object;
class Scene
{
private:
	std::vector<Object*> m_Objects;
	std::vector<Object*> m_DeletePendingObjects;
public:
	Scene() = default;
	virtual ~Scene()
	{
		Clear();
	}

	template<typename T>
	T* CreateObject()
	{
		T* pObject = new T();	
		m_Objects.push_back(pObject);
		return pObject;
	}	

	void Clear();
	
	virtual void Update();
	virtual void Render();	
	virtual void Enter() { } ;
	virtual void Exit() { Clear(); }
};

