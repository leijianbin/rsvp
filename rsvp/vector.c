//
//  vector.c
//  rsvp
//
//  Created by Jianbin Lei on 11/21/13.
//  Copyright (c) 2013 Alberto. All rights reserved.
//

#include "vector.h"
#include <stdlib.h>

void initialize(int **CRNs, char ***subject, char ***courseNum)
{
    int i;
    int count = 1000; //init
    *CRNs = (int*) malloc(count * sizeof(int*));
    *subject = (char**) malloc(count * sizeof(char*));
    *courseNum = (char**) malloc(count * sizeof(char*));
    
    for(i = 0; i < count; i++)
    {
        (*subject)[i] = (char*) malloc(4 * sizeof(char));
        (*courseNum)[i] = (char*) malloc(6 * sizeof(char));
    } // for i
}
void resize(int **CRNs, char ***subject, char ***courseNum, int count)
{
    int i;
    int *newCRNs;
    char **newSubject, **newCourseNum;
    
    newCRNs = (int*) malloc(count * sizeof(int*));
    newSubject = (char**) malloc(count * sizeof(char*));
    newCourseNum = (char**) malloc(count * sizeof(char*));
    
    for(i = 0; i < count/2; i++)
    {
        newCRNs[i] = (*CRNs)[i];
        newSubject[i] = (*subject)[i];
        newCourseNum[i] = (*courseNum)[i];
    } // for i
    
    for(i = count/2; i < count; i++)
    {
        newSubject[i] = (char*) malloc(4 * sizeof(char));
        newCourseNum[i] = (char*) malloc(6 * sizeof(char));
    } // for i
    
    *CRNs = newCRNs;
    *subject = newSubject;
    *courseNum = newCourseNum;
    
    //deallocate(*CRNs, *subject, *courseNum);
}

void deallocate(int *CRNs, char **subject, char **courseNum)
{
    free(CRNs);
    free(subject);
    free(courseNum);
}