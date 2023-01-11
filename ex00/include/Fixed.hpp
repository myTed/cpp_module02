#ifndef _FIXED_HPP
#define _FIXED_HPP

class	Fixed
{
public:
	enum {NB_FRACTIONAL_BITS = 8};
private:
	int	_fixedPointValue;
	static const int fractionBit;
public:
	Fixed();
	Fixed(const Fixed &rFixed);
	Fixed& operator=(const Fixed &rFixed);
	~Fixed();
	int	getRawBits(void) const;
	void	setRawBits(int const raw);	
};
#endif
