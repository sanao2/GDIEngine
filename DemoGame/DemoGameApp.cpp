#include "framework.h"
#include "DemoGameApp.h"
#include "MenuScene.h"
#include "PlayScene.h"

#include "../GDIEngineLib/SceneManager.h"

void DemoGameApp::Initialize()
{
	__super::Initialize(); //  WinGameApp::Initialize();

	SceneManager::Get().CreateScene<MenuScene>(); // 씬 생성
	SceneManager::Get().CreateScene<PlayScene>(); // 씬 생성
	SceneManager::Get().ChangeScene(1); // 씬 변경
}

void DemoGameApp::Shutdown()
{
	__super::Shutdown(); //  WinGameApp::Shutdown();
}

void DemoGameApp::MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	__super::MessageProc(hwnd, uMsg, wParam, lParam); // WM_DESTROY 기본처리

	// DemoGameApp에서만 처리하고싶은 내용
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	}
}
