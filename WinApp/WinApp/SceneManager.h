#pragma once
#include <vector>
using::std::vector; 

// �� ��ȯ����. 
// ����(play, Menu, End) �� ���� �����ϰ�, ��Ȳ�� �°� ������ �� �ֵ��� �Ѵ�. 
enum struct Scenes
{
	PLAY,
	MENU,
	END
};

class SceneManager
{
public : 
	Scenes*			cur_Scene;	// ���� �� 
	Scenes*			next_Scene; // ���� �� 
	vector<Scenes*> v_Scene;	// �� ����Ʈ 

	void Setcur_Scene(Scenes* Sceneindex) {	next_Scene = Sceneindex;}

private : 
	// �� ���� �Լ� ȣ���. 
	void Initialize(); 
	void Update(); 
	void Render(); 
	
	void ChangeScene(); 

	
};

