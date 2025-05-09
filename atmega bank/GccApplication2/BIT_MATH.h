


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, BIT)		(REG |= (1<<BIT))
#define CLR_BIT(REG, BIT)		(REG &= ~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)     (REG ^= (1<<BIT))

#define GET_BIT(REG, BIT)		((REG & (1<<BIT))>>BIT)	

#define GET_REG(REG)			(REG & 0xFF)

#endif /* BIT_MATH_H_ */