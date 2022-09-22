//��ũ�� ���(#define) ���� ������(enum)�� ����Ͽ� ����ü�� ���Խ�ų �� �ִ�.
//struct car
//{
//	enum
//	{
//		ID_LEN=20,
//		MAX_SPD=200
//	};
//};

//�̸������� ����� ���� �ִµ�, �� ��� �������� ����.
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

//�Լ��� ������ ���� ����ü�� ���Խ�ų �� �ִ�.
//struct Car;
//void Car::show();
//��, �� ��� �ζ������� ó������ �ʴ´�. �ζ������� ó���ϱ� ���ؼ��� ������ ���� ������ �ʿ��ϴ�.
//inline void Car::show();

//class�� ����ü�� ���̰� ���� ����.
//�ִٸ� ������ �������δ� Ŭ���� ������ ������ �ٲ� �� ���ٴ� ��.
//���� �������� ������ �����ؾ� �Ѵ�. �̸� �����ϴ� ���� �������� �����ڶ�� �Ѵ�.

//�������� �����ڴ� �� ���� �ִ�.
//public	��𼭵� �������
//protected	��Ӱ��迡 ������ ��, ���� Ŭ�������� �������
//private	Ŭ���� ��(Ŭ���� ���� ���ǵ� �Լ�)������ �������

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
	void InitMembers(const char* ID, int fuel);//�׳� char*�δ� ������ �߻��ߴ�.
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
	cout << "������ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
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