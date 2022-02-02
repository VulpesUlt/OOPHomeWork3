#include <iostream>
#include <math.h>


// Task 1

class Figure 
{
protected:
	const float PI = 3.1415926535;
public:
	virtual float area() = 0;
};

class Parallelogram : public Figure
{
protected:
	uint32_t m_a;
	uint32_t m_h;
	float m_angle = 0; // degree
public:
	Parallelogram(uint32_t a, uint32_t h) : m_a(a), m_h(h) {}
	Parallelogram(uint32_t a, uint32_t h, float angle) : m_a(a), m_h(h), m_angle(angle) {}
	virtual float area () override
	{
		if (m_angle == 0)
			return m_a * m_h;
		else
			return m_a * m_h * sin(m_angle * PI / 180);
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(uint32_t a, uint32_t h) : Parallelogram (a, h){}
	float area () override
	{
		return Parallelogram::m_a * Parallelogram::m_h;
	}
};

class Square : public Parallelogram
{
public:
	Square(uint32_t a) : Parallelogram(a, 0) {};
	float area () override
	{
		return Parallelogram::m_a * Parallelogram::m_a;
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(uint32_t a, uint32_t h) : Parallelogram (a, h){}
	Rhombus(uint32_t a, float angle) : Parallelogram(a, 0, angle) {}
	float area () override
	{
		if (Parallelogram::m_angle == 0)
			return Parallelogram::m_a * Parallelogram::m_h / 2;
		else
			return Parallelogram::m_a * Parallelogram::m_a * sin(m_angle * PI / 180);
	}
};

class Circle : public Figure
{
private:
	uint32_t r;
public:
	Circle (uint32_t r) : r(r) {}
	float area () override
	{
		return 2 * PI * r;
	}
};

// Task 2

class Car 
{
protected:
	std::string company;
	std::string model;
public:
	Car(std::string comp, std::string mod) : company(comp), model(mod)
	{
		std::cout << "Car | company: " << company << " | model: " << model << std::endl;
	}
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(std::string comp, std::string mod) : Car(comp, mod)
	{
		std::cout << "PassengerCar | company: " << company << " | model: " << model << std::endl;
	}
};

class Bus : virtual public Car
{
public:
	Bus(std::string comp, std::string mod) : Car(comp, mod)
	{
		std::cout << "Bus | company: " << company << " | model: " << model << std::endl;
	}
};

class Minivan : public PassengerCar, Bus 
{
public:	
	Minivan(std::string comp, std::string mod) : Bus(comp, mod), PassengerCar(comp, mod), Car(comp, mod)
	{
		std::cout << "Minivan | company: " << Car::company << " | model: " << Car::model << std::endl;
	}
};

// Task 3

class Fraction
{
private:
	int32_t m_numenator;
	int32_t m_denumenator;
public:
	void setDenum ()
	{
		int32_t denum;
		do
		{
			std::cout << "Enter correct denominator: ";
			std::cin >> denum;
			std::cout << std::endl;
		} while (denum == 0);
		m_denumenator = denum;
	}
	
	Fraction(int32_t num, int32_t denum)
	{
		m_numenator = num;
		if (denum != 0)
			m_denumenator = denum;
		else
			setDenum();
	}

	int32_t getNum() { return m_numenator; }
	int32_t getDenum() { return m_denumenator; }
	
	void operator + (Fraction &frac2)
	{
		m_numenator = m_numenator * frac2.getDenum() + frac2.getNum() * m_denumenator;
		m_denumenator *= frac2.getDenum();
	}

	void operator - (Fraction &frac2)
	{
		m_numenator = m_numenator * frac2.getDenum() - frac2.getNum() * m_denumenator;
		m_denumenator *= frac2.getDenum();
	}

	void operator * (Fraction &frac2)
	{
		m_numenator *= frac2.getNum();
		m_denumenator *= frac2.getDenum();
	}

	void operator / (Fraction &frac2)
	{
		m_numenator *= frac2.getDenum();
		m_denumenator *= frac2.getNum();
	}

	bool operator < (Fraction &frac2)
	{
		if (m_numenator * frac2.getDenum() < frac2.getNum() * m_denumenator)
			return true;
		else
			return false;
	}

	bool operator > (Fraction &frac2)
	{
		if (m_numenator * frac2.getDenum() > frac2.getNum() * m_denumenator)
			return true;
		else
			return false;
	}

	bool operator >= (Fraction &frac2)
	{
		return !(*this < frac2);
	}
	
	bool operator <= (Fraction& frac2)
	{
		return !(*this > frac2);
	}

	bool operator == (Fraction& frac2)
	{
		if (m_numenator * frac2.getDenum() == frac2.getNum() * m_denumenator)
			return true;
		else
			return false;
	}

	bool operator != (Fraction& frac2)
	{
		return !(*this == frac2);
	}
	
	void operator - ()
	{
		m_numenator *= -1;
	}
};

// Task 4

class Card
{
private:
	enum class suit 
	{
		SPADES,
		CLUBS, 
		HEARTS, 
		DIAMONDS
	};

	enum class rank
	{ 
		TWO, 
		THREE, 
		FOUR, 
		FIVE, 
		SIX, 
		SEVEN, 
		EIGHT, 
		NINE, 
		TEN, 
		JACK, 
		QUEEN, 
		KING, 
		ACE,
	};

	suit m_suit;
	rank m_rank;
	bool m_faceUp;

public:

	void Flip()
	{
		m_faceUp = !m_faceUp;
	}

	uint32_t GetValue()
	{
		switch (m_rank)
		{
		case Card::rank::TWO:
			return 2;
		case Card::rank::THREE:
			return 3;
		case Card::rank::FOUR:
			return 4;
		case Card::rank::FIVE:
			return 5;
		case Card::rank::SIX:
			return 6;;
		case Card::rank::SEVEN:
			return 7;
		case Card::rank::EIGHT:
			return 8;
		case Card::rank::NINE:
			return 9;
		case Card::rank::TEN:
			return 10;
		case Card::rank::JACK:
			return 10;
		case Card::rank::QUEEN:
			return 10;
		case Card::rank::KING:
			return 10;
		case Card::rank::ACE:
			return 1;
		default:
			return 0;
		}
	}
};

int main()
{
	// Task 2
	Minivan mini("UAZ", "2206");
	Bus bus("PAZ", "4234");
	PassengerCar passCar("VAZ", "2106");
	Car car("someCar", "someModel");

	Fraction fr1(1, 2);
	Fraction fr2(3, 5);

	// Task 3
	fr1 + fr2;
	std::cout << "new Fraction: " << fr1.getNum() << "/" << fr1.getDenum() << std::endl;
	fr1 - fr2;
	std::cout << "new Fraction: " << fr1.getNum() << "/" << fr1.getDenum() << std::endl;
	fr1 * fr2;
	std::cout << "new Fraction: " << fr1.getNum() << "/" << fr1.getDenum() << std::endl;
	fr1 / fr2;
	std::cout << "new Fraction: " << fr1.getNum() << "/" << fr1.getDenum() << std::endl;

	if (fr1 < fr2)
		std::cout << "Fraction1 < Fraction2" << std::endl;
	if (fr1 > fr2)
		std::cout << "Fraction1 > Fraction2" << std::endl;
	if (fr1 >= fr2)
		std::cout << "Fraction1 >= Fraction2" << std::endl;
	if (fr1 <= fr2)
		std::cout << "Fraction1 <= Fraction2" << std::endl;

	if (fr1 == fr2)
		std::cout << "Fraction1 == Fraction2" << std::endl;
	if (fr1 != fr2)
		std::cout << "Fraction1 != Fraction2" << std::endl;

	-fr1;
	std::cout << "-1 * Fraction: " << fr1.getNum() << "/" << fr1.getDenum() << std::endl;

	return 0;
}