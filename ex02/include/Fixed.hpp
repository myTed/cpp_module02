#ifndef _FIXED_HPP
#define _FIXED_HPP
#include <iostream>
class	Fixed
{
public:
	enum {NB_FRACTIONAL_BITS = 8};
private:
	int	_fixedPointValue;
	static const int fractionBit;
	void	displayForFixed(void) const;
	void	displayForFloat(void) const;
public:
	Fixed();
	Fixed(const Fixed &rFixed);
	Fixed(const int d);
	Fixed(const float f);
	~Fixed();
	Fixed& operator=(const Fixed &rFixed);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);	
	// comparison operator
	bool	operator>(const Fixed &rFixed) const;
	bool	operator<(const Fixed &rFixed) const;
	bool	operator>=(const Fixed &rFixed) const;
	bool	operator<=(const Fixed &rFixed) const;
	bool	operator==(const Fixed &rFixed) const;
	bool	operator!=(const Fixed &rFixed) const;
	// arithmetic operator
	Fixed	operator+(const Fixed &rFixed) const;
	Fixed	operator-(const Fixed &rFixed) const;
	Fixed	operator*(const Fixed &rFixed) const;
	Fixed	operator/(const Fixed &rFixed) const;
	// increment/decrement operator
	Fixed	operator++(int x);
	Fixed&	operator++();
	Fixed	operator--(int x);
	Fixed&	operator--();
	// static member
	static Fixed& min(Fixed &r1, Fixed &r2);
	static const Fixed& min(const Fixed &r1, const Fixed &r2);
	static Fixed& max(Fixed &r1, Fixed &r2);
	static const Fixed& max(const Fixed &r1, const Fixed &r2);
};

std::ostream& operator<<(std::ostream &os, const Fixed &rFixed);	
#endif
