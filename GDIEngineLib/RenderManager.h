#pragma once
#include "Singleton.h"

class RenderManager : public Singleton<RenderManager>
{
public:
	RenderManager() = default;
	~RenderManager() = default;
	void Startup() {};
	void Shutdown() {};
	void DrawImage() {};

	void BeginDraw()
	{
		// Clear
	}
	void EndDraw()
	{
		// Copy
	}
};
