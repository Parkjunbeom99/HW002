// HW02.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstdlib>
#include <ctime>



class Animal
{

public:
	virtual void MakeSound() = 0;
	virtual ~Animal() = default;

};


class Dog :public Animal
{

public:
	void MakeSound() override;

};

class Cat :public Animal
{

public:
	void MakeSound() override;
};

class Cow :public Animal
{

public:
	void MakeSound() override;
};

Animal* createRandomAnimal();


class Zoo {
private:
	Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
public:
	// 동물을 동물원에 추가하는 함수
	// - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
	// - 같은 동물이라도 여러 번 추가될 수 있습니다.
	// - 입력 매개변수: Animal* (추가할 동물 객체)
	// - 반환값: 없음
	void addAnimal(Animal* animal);

	// 동물원에 있는 모든 동물의 행동을 수행하는 함수
	// - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
	// - 입력 매개변수: 없음
	// - 반환값: 없음
	void performActions();

	// Zoo 소멸자
	// - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
	// - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
	// - 입력 매개변수: 없음
	// - 반환값: 없음
	~Zoo();
};

class AnimalFactory {
public:
	static Animal* CreateRandomAnimal() {
		int num = rand() % 3;
		switch (num) {
		case 0: return new Dog();
		case 1: return new Cat();
		case 2: return new Cow();
		default: return nullptr;
		}
	}
};

int main()
{

	srand((unsigned int)time(NULL));


	//Animal* animals[3];

	//Dog* dog = new Dog();
	//animals[0] = dog;

	//Cat* cat = new Cat();
	//animals[1] = cat;

	//Cow* cow = new Cow();
	//animals[2] = cow;


	//for (int i = 0; i < 3; i++)
	//{
	//	animals[i]->MakeSound();
	//}

	//Zoo* zoo = new Zoo();
	//zoo->addAnimal(dog);
	//zoo->addAnimal(cat);
	//zoo->addAnimal(cow);

	//zoo->performActions();

	for (int i = 0; i < 5; i++)
	{
		Animal* ani = AnimalFactory::CreateRandomAnimal();
		ani->MakeSound();
	}


}

void Dog::MakeSound()
{
	std::cout << "WOOF!!" << std::endl;
}
void Cat::MakeSound()
{
	std::cout << "MEW!!!" << std::endl;
}
void Cow::MakeSound()
{
	std::cout << "MOW!!!" << std::endl;
}

void Zoo::addAnimal(Animal* animal)
{
	// 동물을 동물원에 추가하는 함수
// - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
// - 같은 동물이라도 여러 번 추가될 수 있습니다.
// - 입력 매개변수: Animal* (추가할 동물 객체)
// - 반환값: 없음
	for (int i = 0; i < 10; i++)
	{
		if (animals[i] == nullptr)
		{
			animals[i] = animal;
			return;
		}
	}
	std::cout << "동물의 수가 가득차버려서 추가를 못했습니다" << std::endl;
}

void Zoo::performActions()
{
	for (int i = 0; i < 10; i++)
	{
		if (animals[i] == nullptr)
		{
			continue;
		}
		else
		{
			animals[i]->MakeSound();
		}
	}
}

Zoo::~Zoo()
{
	// Zoo 소멸자
	// - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
	// - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
	// - 입력 매개변수: 없음
	// - 반환값: 없음
	for (int i = 0; i < 10; ++i)
	{
		if (animals[i] != nullptr)
		{
			delete animals[i];
		}
	}

}

Animal* createRandomAnimal()
{

	int num = rand() % 3;

	Animal* randomAnimal = nullptr;
	switch (num)
	{
	case 0:
		randomAnimal = new Dog();
		break;
	case 1:
		randomAnimal = new Cat();
		break;
	case 2:
		randomAnimal = new Cow();
		break;
	default:
		break;
	}
	return randomAnimal;

}
