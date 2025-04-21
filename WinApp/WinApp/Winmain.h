#pragma once
#include "pch.h"
//������ â�� ��µǴ� ���� â. 



class Winmain
{
private : 
	HWND			m_hWnd; 
	HINSTANCE		m_hInstance; 
	int				m_width = 1076;
	int				m_height = 800;
	wstring			m_WindowName = L"GDIWinmain"; 
	wstring			m_TitleName = L"MainWindow"; 
	string			ModulPath;
	string			WorkingPath; 

	
public : 
	void Initialize(); 
	void MessageProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Run(); 
	Winmain(); 
	~Winmain(); 

private : 
	void Update();
	void Render();
};

