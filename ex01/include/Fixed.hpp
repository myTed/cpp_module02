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
};


std::ostream& operator<<(std::ostream &os, const Fixed &rFixed);	
#endif
