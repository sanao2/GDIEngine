#pragma once

template <typename T>
class Singleton {
public:
	// 명시적 초기화
	static void Create() { 
		// 여러번 사용해도 메시지가 나오고, 
		// 이미 만들어진 게아니라면 새로 생성된다. 
		assert(s_instance == nullptr && "Singleton already created!");
		if (!s_instance)
			s_instance = new T();
	}

	// 명시적 해제
	static void Destroy() {
		assert(s_instance != nullptr && "Singleton not created or already destroyed!");
		delete s_instance;
		s_instance = nullptr;
	}

	// 싱글톤 인스턴스 참조 반환 (간접 호출 없이 .으로 접근)
	static T& Get() {
		return *s_instance; // 생성 해제
	}

protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	// 복사 및 이동 금지
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;

private:
	static T* s_instance;
};

template <typename T>
T* Singleton<T>::s_instance = nullptr;