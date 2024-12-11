#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include<unistd.h>

char *arr[]={"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
int resistor[4];
void loadAnim();
int isBandColourValid(char band[7],int bandnumber){
    int i,flag=0;
    for(i=0;i<10;i++){
        if(strcmp(band,arr[i])==0){
            flag=1;
            resistor[bandnumber-1]=i;
        }
    }
    return flag;
}

int main(){
    int i,flag=0;
    char band1[7],band2[7],band3[7],tol[7];
    char buffer[10],temp[7];


    printf("\n\t\tRESISTANCE CALCULATOR\n\n");
    
    //Resistor Picture
    

    //Getting band colour values of the resistor and Validation
    label1:printf("Enter the colour of the first band: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%s",temp);
    for(i=0;i<7;i++){
        band1[i]=tolower(temp[i]);
    }
    if(!isBandColourValid(band1,1)){
        printf("INVALID BAND 1 COLOUR! TRY AGAIN!\n");
        goto label1;
    }

    label2:printf("Enter the colour of the second band: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%s",temp);
    for(i=0;i<7;i++){
        band2[i]=tolower(temp[i]);
    }
    if(!isBandColourValid(band2,2)){
        printf("INVALID BAND 2 COLOUR! TRY AGAIN!\n");
        goto label2;
    }

    label3:printf("Enter the colour of the third band: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%s",temp);
    for(i=0;i<7;i++){
        band3[i]=tolower(temp[i]);
    }
    if(!isBandColourValid(band3,3)){
        printf("INVALID BAND 3 COLOUR! TRY AGAIN!\n");
        goto label3;
    }

    tolcheck:printf("Enter the colour of the tolerance band: ");
    fgets(buffer,sizeof(buffer),stdin);
    sscanf(buffer,"%s",temp);
    for(i=0;i<7;i++){
        tol[i]=tolower(temp[i]);
    }
    if(strcmp(tol,"gold")==0){
        resistor[3]=5;
    }
    else if(strcmp(tol,"silver")==0){
        resistor[3]=10;
    }
    else{
        printf("INVALID TOLERANCE INPUT! TRY AGAIN!\n");
        goto tolcheck;
    }
    loadAnim();
    //Printing value of resistor
    printf("\n\n\t\tRESISTANCE: ");
    printf("%d%d",resistor[0],resistor[1]);
    printf(" X 10^%d +- %d\n\n",resistor[2],resistor[3]);
    system("pause");
}


void loadAnim(){
    char *arr[]={"Finding my glasses", "Getting comfortable", "Performing complex integrations", "Coffee break!", "Writing final result", "Rewriting neatly", "Writing value to terminal"};
    int i,j,prog;
    printf("\n\n");
    for(j=0;j<7;j++){
        for(prog=0;prog<26;prog++){
            printf("\r%+35s: [",arr[j]);
            for(i=0;i<prog;i++){
                printf("#");
            }
            for(i=prog;i<25;i++){
                printf(" ");
            }
            printf("] %d%%",4*prog);
            usleep(10000);
        }
        printf("\n");
    }
}