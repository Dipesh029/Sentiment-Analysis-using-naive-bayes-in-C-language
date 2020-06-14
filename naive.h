#include<stdio.h>
int bayes(float poswords,float negwords,float cmpsad ,float cmphappy)
    {
    float totalwords,probhappy,probsad,probcmpsad,probcmphappy,probpos,probneg,cmptotal;
    float positiveprobability,negativeprobability;
    totalwords=negwords+poswords;
    cmptotal=cmpsad+cmphappy;

    //probhappy=(poswords/totalwords);
    //probsad=(negwords/totalwords);
    //probcmpsad=(cmpsad/cmptotal);
    //probcmphappy=(cmphappy/cmptotal);

    probpos=(poswords/totalwords)*(cmphappy/cmptotal);
    probneg=(negwords/totalwords)*(cmpsad/cmptotal);

    positiveprobability=probpos/(probpos+probneg);
    negativeprobability=probneg/(probpos+probneg);

    printf("\nprobablity of positive  sentiments %f\n",positiveprobability);
    printf("probablity of negative  sentiments %f\n",negativeprobability);

    if(probneg>probpos)
        {
            
            if(probneg>=0 &&probpos==0)
            printf("\nThe Person is Feeling SAD\n");
            else
            {
                printf("\nThe Person Is Feeling PArtially sad\n");
            }
            
        }

    else if(probpos>probneg)
        {
            
            if(probpos>=0 && probneg==0)
            printf("\nThe Person Is Feeling HAPPY\n");
            else
            {
                printf("\nThe Person Is Feeling PArtially HAPPY\n");
            }
            
        }
    else
    {
        printf("\nPerson is Feeling confused\n");
    }
    printf("\n**********************************************\n");
}