#include <iostream>
#include <numeric> // for std::gcd

class Fraction
{
private:
	int m_numerator{};
	int m_denominator{};
public:
	Fraction(int numerator = 0, int denominator = 1) :
		m_numerator{ numerator }, m_denominator{ denominator }
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
	}

	void reduce()
	{
		int gcd{ std::gcd(m_numerator, m_denominator) };
		if (gcd)
		{
			m_numerator /= gcd;
			m_denominator /= gcd;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);
    friend bool operator== (const Fraction& f1, const Fraction& f2);
    friend bool operator< (const Fraction& f1, const Fraction& f2);
    friend bool operator<= (const Fraction& f1, const Fraction& f2);
    friend bool operator>= (const Fraction& f1, const Fraction& f2);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << '/' << f1.m_denominator;
	return out;
}

bool operator== (const Fraction& f1, const Fraction& f2){
    return (f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator);
}

bool operator< (const Fraction& f1, const Fraction& f2){
    if(f1.m_denominator == f2.m_denominator){
        return f1.m_numerator < f2.m_numerator;
    }else{
        return f1.m_denominator > f2.m_denominator;
    }
}

bool operator> (const Fraction& f1, const Fraction& f2){
    return f2 < f1;
}

bool operator>= (const Fraction& f1, const Fraction& f2){
    return !(f1 < f2);
}

bool operator<= (const Fraction& f1, const Fraction& f2){
    return !(f1 > f2);
}


int main()
{
	Fraction f1{ 3, 2 };
	Fraction f2{ 5, 8 };

	std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
	std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
	std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
	std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
	std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
	std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
	return 0;
}