#include <iostream>
#include <string>
#include <string.h>
#include "Sponge.h"
#include "InternalFun.h"

using namespace std;

#define bitRate   576 
#define capacity  1024




void SpongeConstruction(string inputString, int outputLen) 
{
	// Transform the input string into binary bits
	BinaryTransfer( inputString ) ;
						
	// Padding using Multirate
	vector< Binary > Message = Padding( inputString ) ; 	

	//Initialize the state variable
	Binary stateVar ;
	
    
	// Absorbing phase
	/*** TODO: Implement your SHA3's absorbing phase here ***/
	stateVar.reset();
    stateVar=Message[0] ^ stateVar;
    cout <<"stateVar="<<endl ;
    cout <<stateVar<<endl ;
	
	// Squeezing phase
	string hashVal ; // The final output value 
	/*** TODO: Implement your SHA3's squeezing phase here ***/
	
	
	// Print the hash value to the stdout
	PrintHex( hashVal.substr(0, outputLen) ) ;
}


void BinaryTransfer(string& inputString)
{
	string binary = "" ;
	
	for(int i=0; i<inputString.length(); i++)
	{
		for(int k=7; k>=0; k--)
			if( ((inputString[i] >> k) & 0x01) )
				binary += "1" ;
			else
				binary += "0" ;
	}	
	
	inputString = binary ;
    cout << "inputString=" << inputString << endl;
     cout << "leghth=" << inputString.length() << endl;
}



vector< Binary > Padding(string inputString) 
{
    /*** TODO: Implement with Multirate padding ***/
    vector<Binary> test;
    int loss=0, now_count=0;
    loss=inputString.length() % bitRate;
    
    //576 bit pad
    int append_count=0;
    while( (now_count= (inputString.length() % (bitRate-1) )) != 0 )
    {
        if(append_count==0)
        {
            inputString.append("1",0,1);
            append_count++;
        }
        else
        {
            inputString.append("0",0,1);
        }
    }
    inputString.append("1",0,1);
    
    //1024 bit pad
    for(int i=0;i<capacity;i++)
    {
        inputString.append("0",0,1);
    }
    
    //cout << "inputString=" << inputString << endl;
    //cout << "leghth=" << inputString.length() << endl;
    test.push_back((Binary)inputString);
   
    /*
    for(int i=0;i<inputString.length();i++)
    {
        if(inputString[i] == '1')
        {
            //test.set(i,1);
            test.push_back(1);
        }
        else
        {
            test.push_back(0);
        }
    }
    */
   // cout << "test size=" << test.size() << endl;
    cout <<test[0]<<endl ;
    /*
   // vector<string> text;
    int iter;
    for (vector<Binary>::const_iterator iter = test.begin();
         iter != test.end(); ++iter)
        cout << *iter << endl;
    */
	
	return test;
}


/*** Print the hash value in hex ***/
void PrintHex(string hashVal) 
{
	
	for(int i=0; i<hashVal.length(); i+=4)
	{
		string Ahex = hashVal.substr(i, 4) ; 
		int Val = 0 ;
		
		for(int k=0; k<4; k++)
			if( Ahex[k]-'0' )	
				Val += (1 << (3-k)) ;
		
		if( Val < 10 )	cout << Val ;
		else	cout << (char)(Val+55) ;			
	}		
}
