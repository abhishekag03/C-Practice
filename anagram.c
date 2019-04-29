#include <stdio.h>

void main() {
	int i=0;
	int char_array1[52] = {0};  //initialising an array of size 52 so that it can store the character count of all the 52 caharacters from A-Z and a-z for word 1.
	int char_array2[52] = {0};	//initialising another array of size 52 so that it can store the character count of all the 52 caharacters from A-Z and a-z for word 2.
	
	char word1[15];		//character array for the characters of word 1
	char word2[15];		//character array for the characters of word 2
	int flag=0;
	scanf ("%s %s", word1, word2);  //input of word 1 and 2

	while (word1[i] != '\0'){ 		//runs till we reach the end of the string
		
		if (word1[i]-'A'<26){								//if the character is an upper case one then storing its index count in the first 26 indices
			char_array1[word1[i]-'A']++;		
		}
		else{
			char_array1[word1[i] - 'a'+26]++;				//if the character is a lower case one then storing its index count in the last 26 indices
		}
		
		i++;
	}
	i=0;
	while (word2[i] != '\0'){						//Similarly for word 2.
		if (word2[i]-'A'<26){		
			char_array2[word2[i]-'A']++;			
		}
		else{
			char_array2[word2[i] - 'a'+26]++;
		}
		
		i++;
	}
	i=0;
	for (i=0;i<52;i++){										//In the end checking whether both the words have the same character count for each character or not
		if (char_array1[i]!=char_array2[i]){
			flag=1;											//If it wasn't equal for any character then breaking the loop and making flag=1;
			break;
		}
	}

	if (flag==0){
		printf("%s","Yes" );
	}
	else{
		printf("%s","No" );

	}
}