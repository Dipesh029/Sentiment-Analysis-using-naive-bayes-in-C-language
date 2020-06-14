#include<stdio.h>
#include<string.h> 
#include"naive.h"
int count = 0, i, j = 0, k=0, space = 0,naive;

float poswords=0,negwords=0 ,totalwords, cmpsad=0,cmphappy=0;    
char str[100], p[50][100], str1[20], ptr1[50][100], happy[5000][100],sad[5000][100];
 
char *ptr;

int compare(char str[])
{
    for (i = 0;i<strlen(str);i++)
    {
        if ((str[i] == ' ')||(str[i] == ',')||(str[i] == '.'))
        {
            space++;
        }
    }
    //printf("space--%d",space);
    for (i = 0, j = 0, k = 0;j < strlen(str);j++)
    {
        if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))  
        {    
            p[i][k] = '\0';
            i++;
            k = 0;
            
        }        
        else
            p[i][k++] = str[j];
            //printf(" %s ",p[i]); 
    }
 
    k = 0;
 
    for (i = 0;i < space;i++)
    {
        for (j = 0;j < space;j++)
        {
            if (i == j)
            {
                strcpy(ptr1[k], p[i]);
                k++;
                count++;
 
                break;
            }
            else
            {
                if (strcmp(ptr1[j], p[i]) != 0)
                    continue;
                else
                    break;
            }
        }
    }
 
    for (i = 0;i < count;i++) 
    {
        for (j = 0;j <negwords ;j++)
        {
            if (strcmp(ptr1[i], sad[j]) == 0)
            {
                cmpsad++;
            }    
        }
        //printf("%s -> %f cmpsad times\n ", ptr1[i],cmpsad );
        
    }
    for (i = 0;i <count;i++) 
    {
        for (j = 0;j <poswords ;j++)
        {
            //printf("%d",j);
            if (strcmp(ptr1[i], happy[j]) == 0)
            {
                cmphappy++;
            }
        }
        //printf("%s -> %f cmphappy times\n ", ptr1[i],cmphappy );
    } 
    count=0 ;
    memset(ptr1, 0, sizeof(ptr1)); 
    memset(p, 0, sizeof(p)); 
}


int gloss(char str[])
{
    for (i = 0;i<strlen(str);i++)
    {
        if ((str[i] == ' ')||(str[i] == ',' && str[i+1] == ' ')||(str[i] == '.'))
        {
            poswords++;
        }
        
    }
    printf("positive words    %f\n",poswords);
    
    for (i = 0, j = 0, k = 0;j <=strlen(str);j++)
        {
            if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))  
            {  
            //    printf("%s ", happy[i]);
            //    printf("\n");
                k = 0;
                i++;
            }        
            else
            {
                happy[i][k] = str[j];
            //    printf("%s ", happy[i]);
            //    printf("\n");
                k++;
            }         
        }

}  
int gloss2(char str[])
{
    for (i = 0;i<strlen(str);i++)
    {
        if ((str[i] == ' ')||(str[i] == ',' && str[i+1] == ' ')||(str[i] == '.'))
        {
            negwords++;
        }   
    }
     printf("negative words   %f",negwords);
    for (i = 0, j = 0, k = 0;j <=strlen(str);j++)
        {
            if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))  
            {  
              //printf("%s ", sad[i]);
              //printf("\n");
                k = 0;
                i++;
            }        
            else
            {
                sad[i][k] = str[j];
              //printf("%s ", sad[i]);
              //printf("\n");
                k++;
            }         
        }

}  


int main( ) 
{
    int naive;
    // Declare the file pointer 
    FILE *filePointer ; 
    // Declare the variable for the data to be read from file  
    char string[1000];
    char positive[10000]; 
    char negative[10000]; 
  
    // Opening existing file positive.txt using fopen() in read mode using "r" attribute
    filePointer = fopen("positive.txt", "r") ; 
      
    // Check if this filePointer is null 
     if ( filePointer == NULL ) 
    { 
        printf( "positive.txt file failed to open." ) ; 
    } 
    else
    {
        // Read the positive words from the file using fgets()
        while( fgets ( positive, 10000, filePointer ) != NULL ) 
        { 
            gloss(positive);
        } 
          
    // Closing the file using fclose() 
    fclose(filePointer) ; 
    } 

    //Opening existing file negative.txt using fopen() in read mode using "r" attribute
    filePointer = fopen("negative.txt", "r") ; 
     
    // Check if this filePointer is null 
    if ( filePointer == NULL ) 
    { 
        printf( "negative.txt file failed to open." ) ; 
    } 
    else
    { 
        // Read the negative words from the file using fgets()
        while( fgets ( negative, 10000, filePointer ) != NULL ) 
        { 
           gloss2(negative);
        } 
    // Closing the file using fclose()   
    fclose(filePointer) ; 
           
    } 
    //Opening existing file string.txt using fopen() in read mode using "r" attribute 
    filePointer = fopen("string.txt", "r") ; 
 
    // Check if this filePointer is null 
    if ( filePointer == NULL ) 
    { 
        printf( "string.txt file failed to open." ) ; 
    } 
    else
    { 
        // Read the positive words from the file using fgets()
        while( fgets ( string, 1000, filePointer ) != NULL ) 
        { 
  
            printf( "\n\n%s" , string ) ; 
            compare(string);
            naive=bayes(poswords,negwords,cmpsad ,cmphappy);

            // Clearing ptr1 array using memset() function and cmphappy,cmpsad for next line
            cmphappy=0,cmpsad= 0; 

        } 
    // Closing the file using fclose()       
    fclose(filePointer) ; 
    } 


    return 0;         
} 