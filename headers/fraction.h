#ifndef CAM_FRACTION
#define CAM_FRACTION

#include <boost/math/common_factor_rt.hpp>
#include <string>

class Fraction {
	
public:
	long numerator;
	long denominator;

	Fraction(long numerator, long denominator) {
		this->numerator = numerator;
		this->denominator = denominator;

		this->reduce();
	}

	void reduce() { 
		int divisor = boost::math::gcd(numerator,denominator);
		numerator /= divisor;
		denominator /= divisor;
	}

	std::string to_string() {
		return std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
	}

	Fraction operator*(const Fraction& f) {
		Fraction new_fraction(this->numerator * f.numerator,this->denominator * f.denominator);
		return new_fraction;
	}

	Fraction operator/(const Fraction& f) {
		Fraction new_fraction(this->numerator * f.denominator,this->denominator * f.numerator);
		return new_fraction;
	}
	
};






















#endif
