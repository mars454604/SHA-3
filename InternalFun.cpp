#include <iostream>
#include <string>
#include <vector>
#include "InternalFun.h"




bitset<64> RC[24] = 
{ 
	0x0000000000000001,
	0x0000000000008082,
	0x800000000000808A,
	0x8000000080008000,
	0x000000000000808B,
	0x0000000080000001,
	0x8000000080008081,
	0x8000000000008009,
	0x000000000000008A,
	0x0000000000000088,
	0x0000000080008009,
	0x000000008000000A,
	0x000000008000808B,
	0x800000000000008B,
	0x8000000000008089,
	0x8000000000008003,
	0x8000000000008002,
	0x8000000000000080,
	0x000000000000800A,
	0x800000008000000A,
	0x8000000080008081,
	0x8000000000008080,
	0x0000000080000001,
	0x8000000080008008
};






Binary internalFun(Binary stateVar) 
{
	
	for(int i=0; i<24; i++)
		stateVar = roundFun( stateVar, RC[i] ) ;
		
	return stateVar ;
}




/*** Round function in SHA-3 ***/
Binary roundFun(Binary stateVar, bitset<64> singleRC)
{
	Binary test;
	/*** TODO: Implement your SHA3's 5 functions as follows ***/
	
	
	/*** Theta ***/
	
	
	/*** Rho  ***/
	
		
	/*** Pi ***/	
			
						
	/*** Xi ***/
	
	
	/*** Iota ***/
	return test;
	
}