#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int StringLength(char string[]){
    int length = 0;
    for (length;string[length]!=0;length++);
    return length;
}

int CountVowel(char string[]){
    int count=0;
    char vowels[]="AaEeIiOoUu";
    for (int i = 0;string[i]!=0;i++){
        for (int j=0;vowels[j]!=0;j++){
            if (string[i]==vowels[j])
                count++;
            }
    }
    return count;
}

void SpaceRemove(char string[]){
    int length=StringLength(string);
    char aux[length];

    int start=0;
    while(string[start]==' ')
        start++;

    int end=length-1;
    while(string[end]==' ')
        end--;

    int indexes[length];
    int index=0;
    for (int i=start;i<=end;i++){
        if (string[i]==' '){
            int c=1;
            while (string[i+c]==' '){
                indexes[index]=i+c;
                index++;
                c++;
            }
        }
    }


    int counter=0;
    for (int i=start;i<=end;i++){
        int print=1;
        for (int j=0;j<length;j++){
            if (indexes[j]==i)
                print=0;
        }
        if (print==1){
            aux[counter]=string[i];
            counter++;
        }
    }
    strcpy(string,aux);
}

int main(){
    /*char str[]=" c       inco vog ais ";
    int vowels=CountVowel(str);
    SpaceRemove(str);
    printf("%s \n", str);*/
    return 0;
}