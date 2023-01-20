// Write a C program to check whether a given string belongs to the language defined
// by a Context Free Grammar (CFG)
// S → 0S1 | ε

#include<stdio.h>
#include<string.h>

int checkValidity(char ip[], int l){

    int iv = 0;

    for(int i = 0;i<l;i++){
        if(ip[i] == '0' || ip[i] == '1')
            continue;
        else{
            iv = 1;
            break;
        }
    }

    return iv;
}

int main(){
    char input[100];
    while(1){

        printf("Enter a String : ");
        scanf("%s",&input);

        int l = strlen(input);

        int invalid = checkValidity(input,l);

        if(invalid != 1){

            int count_0 = 0;
            int count_1 = 0;
            int reject = 0;
            
            for(int i = 0;i<l/2;i++){
                if(input[i] == '0')
                    count_0+=1;
                else if(input[i] == '1'){
                    reject = 1;
                    break;
                }
            }

            for(int i = l/2;i<l;i++){
                if(input[i] == '1')
                    count_1+=1;
                else if(input[i] == '0'){
                    reject = 1;
                    break;
                }
            }

            if(count_0 > 0 && count_1 > 0){
                if(count_0 == count_1 && reject == 0)
                    printf("String Accepted ! \n\n");
                else if(reject == 1)  
                    printf("String Rejected ! \n\n");
            }
            else
                printf("String Rejected ! \n\n");
        }
        else
            printf("Enter a Valid String over E = {0,1} .\n\n");
    }

    return 0;
}