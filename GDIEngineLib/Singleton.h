#pragma once

template <typename T>
class Singleton {
public:
	// ����� �ʱ�ȭ
	static void Create() { 
		// ������ ����ص� �޽����� ������, 
		// �̹� ������� �Ծƴ϶�� ���� �����ȴ�. 
		assert(s_instance == nullptr && "Singleton already created!");
		if (!s_instance)
			s_instance = new T();
	}

	// ����� ����
	static void Destroy() {
		assert(s_instance != nullptr && "Singleton not created or already destroyed!");
		delete s_instance;
		s_instance = nullptr;
	}

	// �̱��� �ν��Ͻ� ���� ��ȯ (���� ȣ�� ���� .���� ����)
	static T& Get() {
		return *s_instance; // ���� ����
	}

protected:
	Singleton() = default;
	virtual ~Singleton() = default;

	// ���� �� �̵� ����
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(Singleton&&) = delete;

private:
	static T* s_instance;
};

template <typename T>
T* Singleton<T>::s_instance = nullptr;