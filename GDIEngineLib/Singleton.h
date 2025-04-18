#pragma once

template <typename T>
class Singleton {
public:
	Singleton()
	{
		// assert = 아래의 내용을 실행하기 전에, 원하는 상황인지 확인할 수 있도록 하는 것 
		assert(s_instance == nullptr && "Singleton instance already created!");
		s_instance = static_cast<T*>(this);
	}
		
	virtual ~Singleton() = default;

	// 복사 및 이동 금지
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;

	static T& Get()
	{
		assert(s_instance != nullptr && "Singleton instance not created!");
		return *s_instance;
	}
private:
	static T* s_instance;
};

template <typename T>
T* Singleton<T>::s_instance = nullptr;