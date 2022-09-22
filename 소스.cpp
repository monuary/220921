//매크로 상수(#define) 역시 열거형(enum)을 사용하여 구조체에 포함시킬 수 있다.
//struct car
//{
//	enum
//	{
//		ID_LEN=20,
//		MAX_SPD=200
//	};
//};

//이름공간을 사용할 수도 있는데, 이 경우 가독성이 좋다.
//namespace CAR_CONST
//{
//	enum
//	{
//		ID_LEN=20,
//		MAX_SPD=200
//	};
//}
//struct Car
//{
//	char gamerID[CAR_CONST::ID_LEN];
//};

//함수는 밖으로 빼도 구조체에 포함시킬 수 있다.
//struct Car;
//void Car::show();
//단, 이 경우 인라인으로 처리되지 않는다. 인라인으로 처리하기 위해서는 다음과 같은 선언이 필요하다.
//inline void Car::show();

//class는 구조체와 차이가 거의 없다.
//있다면 보통의 선언으로는 클래스 내부의 변수를 바꿀 수 없다는 것.
//접근 허용범위를 별도로 선언해야 한다. 이를 선언하는 것을 접근제어 지시자라고 한다.

//접근제어 지시자는 세 가지 있다.
//public	어디서든 접근허용
//protected	상속관계에 놓였을 때, 유도 클래스에서 접근허용
//private	클래스 내(클래스 내에 정의된 함수)에서만 접근허용

#include<iostream>
#include<cstring>
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN=20,
		MAX_SPD=200,
		FUEL_STEP=2,
		ACC_STEP=10,
		BRK_STEP=10
	};
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;
public:
	void InitMembers(const char* ID, int fuel);//그냥 char*로는 오류가 발생했다.
	void Show();
	void Accel();
	void Break();
};

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}
void Car::Show()
{
	cout << "소유자ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}
void Car::Accel()
{
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}
void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}

int main()
{
	Car run99;
	run99.InitMembers("run99", 100);
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.Show();
	run99.Break();
	run99.Show();
	return 0;
}