#pragma once
#include "Singleton.h"

class SoundManager : public Singleton<SoundManager>
{
public:
	SoundManager() = default;
	~SoundManager() = default;
	void Startup() {};
	void Shutdown() {};

	void Update() {};
};

