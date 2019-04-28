#include <stdio.h>
//Function Prototypes
char encryptionRotation (int encryptionKey, int length, char text[]);
char decryptionRotation (int encryptionKey, int length, char text[]);
char Substitution (int length, char text[]);


int main ()
{
    
  
  int encryptionKey, i;
  int programControl = 0, length = 0;
  char text[1024];

  while (programControl <= 0) //Was orriginally going to set up a more user friendly, looping interface, but that wasnt required for the project
    {
      printf ("What action would you like to perform?\n");
      printf ("Encode with Rotation (1), Rotation decryption with Key (2),Rotation decryption without key (3), Substitution encryption (4), Substitution decryption with key (5), Substituiton decryption without key (6), Exit (7).\n");
      scanf ("%d", &programControl);
	  //The above is a simple variable to control the state of the program through the followign switch statement
    }

 
  switch (programControl)
    {
    case 1:
      {
          
            printf("Please enter the text to be encoded: \n");
            //useless scanf used next to discard blank newline- code will skip input without this
            scanf("%*d");
            scanf("%[^\n]%*c", text); //[^\n] records all text up to the newline (Enter) letter is found. *c discards the newline character
            
            //Encryption key is created
            printf ("Please enter the encryption key: \n");
        	scanf ("%d", &encryptionKey);
        	printf ("You're key is %d\n", encryptionKey);
           // Decoding Loop, discarding blank space of initial array using length. Not really required, was going to do over things but they were uneeded
              for (i = 0; text[i] != '\0'; i++)
             {
             

             encryptionRotation (encryptionKey, length, text);
                          ++length;
             }  
            printf("%c\n", text[length]);
            break;
      }
    case 2: 
    {
         printf("Please enter the text to be decoded: \n");
            //useless scanf to discard blank newline from selection
            scanf("%*d");
            scanf("%[^\n]%*c", text);
            
           
            printf ("Please enter the encryption key: \n");
        	scanf ("%d", &encryptionKey);
        	printf ("You're key is %d\n", encryptionKey);
           // Decoding Loop, discarding blank space of initial array 
              for (i = 0; text[i] != '\0'; i++)
             {
             

             decryptionRotation (encryptionKey, length, text);
                          ++length;
             }  
            printf("%c\n", text[length]);
            break;
      }
    case 4:
    {
         printf("Please enter the text to be Encrypted: \n");
            //useless scanf to discard blank newline from selection
            scanf("%*d");
            scanf("%[^\n]%*c", text);
            
             // Decoding Loop, discarding blank space of initial array 
              for (i = 0; text[i] != '\0'; i++)
             {
             

            Substitution (length, text);
                          ++length;
             }  
            printf("%c\n", text[length]);
            break;
        
    }
    case 5:
    {
         printf("Please enter the text to be decoded: \n");
            //useless scanf to discard blank newline from selection
            scanf("%*d");
            scanf("%[^\n]%*c", text);
            
             // Decoding Loop, discarding blank space of initial array 
              for (i = 0; text[i] != '\0'; i++)
             {
             

            Substitution (length, text);
                          ++length;
             }  
            printf("%c\n", text[length]);
            break;
        
    }
      
      
      
      
      
      
      case 7: break;
    
      return 0;
    }

}

//Rotation Cipher Encryption Function

char encryptionRotation (int encryptionKey, int length, char text[])
{
    //Changes between capitals and lowercase to ensure correct results
    if ( text[length] >= 65 && text[length] <= 122) {
	if (text[length] >= 97 && text[length] <= 122){
	                          text[length] -= 32;
	                         
	  }
     text[length] -= 65;
     //The above bit essentially just reduces the numbers to 1-26 ascii value, just to make my printf test statements (not present in this version) more coherent
     	//alphabet overflow, used to make sure z (#26) plus the key doesnt go into random symbols                     
	if((text[length] + encryptionKey) >= 26)
	   text[length] -=26;

     text[length] += encryptionKey;
     text[length] += 65;
    }
      printf ("%c", text[length]);
}
//Rotation Cipher decryption w/key function

char decryptionRotation (int encryptionKey, int length, char text[])
{
    //Changes between capitals and lowercase to ensure correct results
    if ( text[length] >= 65 && text[length] <= 122) {
	if (text[length] >= 97 && text[length] <= 122){
	                          text[length] -= 32;
	                         
	  }
     text[length] -= 65;
        //The decryption is pretty much just the reverse of the previous function
     	//alphabet overflow                      
	if((text[length] - encryptionKey) < 0)
	   text[length] +=26;

     text[length] -= encryptionKey;
     text[length] += 65;
 
    }
      printf ("%c", text[length]);
}

char Substitution (int length, char text[])
{
    int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7, i = 8, j = 9, k = 10, l = 11, m = 12, n = 13, o = 14, p = 15, q = 16, r = 17;
  int s = 18, t = 19, u = 20, v = 21, w = 22, x = 23, y = 24, z = 25;
  
    //Assuming for sub we dont need to make something that randomises each time
	
      //Changes between capitals and lowercase to ensure correct results
    if ( text[length] >= 65 && text[length] <= 122) {
	if (text[length] >= 97 && text[length] <= 122){
	                          text[length] -= 32;
	}
	
	text[length] -= 65;
    //Heres a lookup table for the substitution cipher. Each letter is assigned another one. Yay.
    if(text[length] == a)
    text[length] = z;
    
    else if(text[length] == b)
    text[length] = y;
    
    else if(text[length] == c)
    text[length] = x;
    
    else if(text[length] == d)
    text[length] = w;
    
    else if(text[length] == e)
    text[length] = v;
    
    else if(text[length] == f)
    text[length] = u;
    
    else if(text[length] == g)
    text[length] = t;
    
    else if(text[length] == h)
    text[length] = s;
    
    else if(text[length] == i)
    text[length] = r;
    
    else if(text[length] == j)
    text[length] = q;
    
    else if(text[length] == k)
    text[length] = p;
    
    else if(text[length] == l)
    text[length] = o;
    
    else if(text[length] == m)
    text[length] = n;
    
    else if(text[length] == n)
    text[length] = m;
    
    else if(text[length] == o)
    text[length] = l;
    
    else if(text[length] == p)
    text[length] = k;
    
    else if(text[length] == q)
    text[length] = j;
    
    else if(text[length] == r)
    text[length] = i;
    
    else if(text[length] == s)
    text[length] = h;
    
    else if(text[length] == t)
    text[length] = g;
    
    else if(text[length] == u)
    text[length] = f;
    
    else if(text[length] == v)
    text[length] = e;
    
    else if(text[length] == w)
    text[length] = d;
    
    else if(text[length] == x)
    text[length] = c;
    
    else if(text[length] == y)
    text[length] = b;
    
    else if(text[length] == z)
    text[length] = a;
    
    
    text[length] += 65;
    }
    
	printf("%c",text[length]);             
    
	}

