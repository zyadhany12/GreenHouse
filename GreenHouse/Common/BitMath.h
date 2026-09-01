#ifndef _BITMATH_H_
#define _BITMATH_H_


#define SetBit(Reg, BitNo)           Reg |= (1 << BitNo)
#define ClearBit(Reg,BitNo)          Reg &= ~(1 << BitNo)
#define ToggleBit(Reg,BitNo)         Reg ^= (1 << BitNo)
#define ReadBit(Reg,BitNo)           (Reg>>BitNo) & 0x01


#define ClearFlag(Reg,BitNo)         Reg |= (1 << BitNo)
#define SetFlag(Reg,BitNo)          Reg &= ~(1 << BitNo)


#endif