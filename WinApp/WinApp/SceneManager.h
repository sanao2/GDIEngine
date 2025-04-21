#pragma once
#include <vector>
using::std::vector; 

// 씬 전환관리. 
// 세개(play, Menu, End) 의 씬을 관리하고, 상황에 맞게 변경할 수 있도록 한다. 
enum struct Scenes
{
	PLAY,
	MENU,
	END
};

class SceneManager
{
public : 
	Scenes*			cur_Scene;	// 현재 씬 
	Scenes*			next_Scene; // 다음 씬 
	vector<Scenes*> v_Scene;	// 씬 리스트 

	void Setcur_Scene(Scenes* Sceneindex) {	next_Scene = Sceneindex;}

private : 
	// 각 씬의 함수 호출용. 
	void Initialize(); 
	void Update(); 
	void Render(); 
	
	void ChangeScene(); 

	
};

