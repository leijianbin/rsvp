//
//  vector.h
//  rsvp
//
//  Created by Jianbin Lei on 11/22/13.
//  Copyright (c) 2013 Alberto. All rights reserved.
//

#ifndef rsvp_vector_h
#define rsvp_vector_h

void initialize(int **CRNs, char ***subject, char ***courseNum);
void resize(int **CRNs, char ***subject, char ***courseNum, int count);
void deallocate(int *CRNs, char **subject, char **courseNum);

#endif
