/*        Generated by TAPENADE     (INRIA, Tropics team)
    Tapenade 3.7 (r4786) - 21 Feb 2013 15:53
*/
#include "cstd.h"

extern void pushinteger4(int x);
extern void popinteger4(int *x);

/*
  Differentiation of acdpml_2d_2 in reverse (adjoint) mode:
   gradient     of useful results: **uc **phi0 **up **phi1
   with respect to varying inputs: **csq **uc **phi0 **up **phi1
   RW status of diff variables: **csq:out **uc:incr **phi0:in-out
                **up:in-out **phi1:in-out
   Plus diff mem management of: csq:in *csq:in uc:in *uc:in phi0:in
                *phi0:in up:in *up:in phi1:in *phi1:in
*/
void acdpml_2d_2_b(float **uc, float **ucb, float **up, float **upb, float **
        csq, float **csqb, float **phi1, float **phi1b, float **phi0, float **
        phi0b, float *dp1, float *dp0, float *di, float dt, int *s, int *e, 
        float c0, float *c1, int *lbc, int *rbc) {
    // current field
    // previous field
    // csq
    // phi1
    // phi0
    // damping profile zeta_x
    // damping profile zeta_x
    // start index
    // end index
    int i1, i0;
    float temp3;
    float temp2;
    float temp1;
    float temp0;
    float temp7b;
    float temp9b0;
    float temp4b0;
    float tempb5;
    float tempb4;
    float tempb3;
    float tempb2;
    float tempb1;
    float tempb0;
    float temp0b;
    float temp3b;
    float temp7b0;
    float temp2b0;
    float temp6b;
    float temp10;
    float temp9b;
    float temp5b0;
    float tempb;
    float temp0b1;
    float temp0b0;
    float temp2b;
    float temp5b;
    float temp8b0;
    float temp8b;
    float temp3b0;
    float temp1b;
    float temp;
    float temp6b0;
    float temp9;
    float temp8;
    float temp1b0;
    float temp7;
    float temp10b;
    float temp4b;
    float temp6;
    float temp5;
    float temp10b0;
    float temp4;
    //fprintf(stderr, "dp0[%d] = %f\n",e[0], dp0[e[0]]);
    // PML
    //fprintf(stderr, " after computing Du_x Du_z acdpml_2d_2!!!\n");
    // \phi separate loops along boundary !!!!!!!!!!!!!!!! csq and damp profile
    // compute interior of the domain
    // update wavefield up
    for (i1 = s[1]; i1 < e[1]+1; ++i1)
        for (i0 = s[0]; i0 < e[0]+1; ++i0)
            up[i1][i0] = 1.0/(1.0+(dp1[i1]+dp0[i0])*dt/2.0)*(uc[i1][i0]*(2.0-
                dp1[i1]*dp0[i0]*dt*dt)+up[i1][i0]*((dp1[i1]+dp0[i0])/2.0*dt-
                1.0)+csq[i1][i0]*(c0*uc[i1][i0]+c1[0]*(uc[i1][i0+1]+uc[i1][i0-
                1])+c1[1]*(uc[i1+1][i0]+uc[i1-1][i0]))+dt*dt*(phi1[i1][i0-1]+
                phi1[i1][i0]-phi1[i1-1][i0-1]-phi1[i1-1][i0])/2.0/di[1]+dt*dt*
                (phi0[i1-1][i0]+phi0[i1][i0]-phi0[i1-1][i0-1]-phi0[i1][i0-1])/
                2.0/di[0]);
    pushinteger4(i0);
    pushinteger4(i1);
    pushinteger4(i0);
    // compute i0=e[0]
    i0 = e[0];
    pushinteger4(i1);
//    **csqb = 0.0;
    for (i1 = e[1]-1; i1 > s[1]-1; --i1) {
        temp10 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp10b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
        temp10b0 = csq[i1][i0]*temp10b/temp10;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp10b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp10b0;
        ucb[i1][i0] = ucb[i1][i0] - temp10b0;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp10b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp10b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp10b0;
        upb[i1][i0] = upb[i1][i0] - temp10b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp10b0;
        csqb[i1][i0] = csqb[i1][i0] + (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-
            uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])*
            temp10b/temp10;
        phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
        temp9 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp9b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
        temp9b0 = csq[i1][i0]*temp9b/temp9;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp9b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp9b0;
        ucb[i1][i0] = ucb[i1][i0] - temp9b0;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp9b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp9b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp9b0;
        upb[i1][i0] = upb[i1][i0] - temp9b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp9b0;
        csqb[i1][i0] = csqb[i1][i0] + (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-
            uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])*
            temp9b/temp9;
        phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
    }
    popinteger4(&i1);
    i1 = e[1];
    for (i0 = e[0]; i0 > s[0]-1; --i0) {
        temp8 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp8b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
        temp8b0 = csq[i1][i0]*temp8b/temp8;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp8b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp8b0;
        ucb[i1][i0] = ucb[i1][i0] - temp8b0;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp8b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp8b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp8b0;
        upb[i1][i0] = upb[i1][i0] - temp8b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp8b0;
        csqb[i1][i0] = csqb[i1][i0] + (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-
            uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])*
            temp8b/temp8;
        phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
        temp7 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp7b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
        temp7b0 = csq[i1][i0]*temp7b/temp7;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp7b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp7b0;
        ucb[i1][i0] = ucb[i1][i0] - temp7b0;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp7b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp7b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp7b0;
        upb[i1][i0] = upb[i1][i0] - temp7b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp7b0;
        csqb[i1][i0] = csqb[i1][i0] + (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-
            uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])*
            temp7b/temp7;
        phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
    }
    popinteger4(&i0);
    i0 = s[0] - 1;
    for (i1 = e[1]; i1 > s[1]-1; --i1) {
        temp6 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp6b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
        temp6b0 = csq[i1][i0+1]*temp6b/temp6;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp6b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp6b0;
        ucb[i1][i0] = ucb[i1][i0] - temp6b0;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp6b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp6b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp6b0;
        upb[i1][i0] = upb[i1][i0] - temp6b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp6b0;
        csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[
            i1][i0]-uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+
            1][i0])*temp6b/temp6;
        phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
        temp5 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp5b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
        temp5b0 = csq[i1][i0+1]*temp5b/temp5;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp5b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp5b0;
        ucb[i1][i0] = ucb[i1][i0] - temp5b0;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp5b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp5b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp5b0;
        upb[i1][i0] = upb[i1][i0] - temp5b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp5b0;
        csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[
            i1][i0]-uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1]
            [i0+1])*temp5b/temp5;
        phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
    }
    popinteger4(&i1);
    i1 = s[1] - 1;
    for (i0 = e[0]; i0 > s[0]-1; --i0) {
        temp4 = 4.0*di[0]*(dt*dp0[i0]+2.0);
        temp4b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
        temp4b0 = csq[i1+1][i0]*temp4b/temp4;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp4b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp4b0;
        ucb[i1][i0] = ucb[i1][i0] - temp4b0;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp4b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp4b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp4b0;
        upb[i1][i0] = upb[i1][i0] - temp4b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp4b0;
        csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[
            i1][i0]-uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+
            1][i0])*temp4b/temp4;
        phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
        temp3 = 4.0*di[1]*(dt*dp1[i1]+2.0);
        temp3b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
        temp3b0 = csq[i1+1][i0]*temp3b/temp3;
        ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp3b0;
        ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp3b0;
        ucb[i1][i0] = ucb[i1][i0] - temp3b0;
        ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp3b0;
        upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp3b0;
        upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp3b0;
        upb[i1][i0] = upb[i1][i0] - temp3b0;
        upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp3b0;
        csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[
            i1][i0]-uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1]
            [i0+1])*temp3b/temp3;
        phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
    }
    popinteger4(&i0);
    i0 = s[0] - 1;
    i1 = s[1] - 1;
    temp2 = 4.0*di[0]*(dt*dp0[i0]+2.0);
    temp2b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
    temp2b0 = csq[i1+1][i0+1]*temp2b/temp2;
    ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp2b0;
    ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp2b0;
    ucb[i1][i0] = ucb[i1][i0] - temp2b0;
    ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp2b0;
    upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp2b0;
    upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp2b0;
    upb[i1][i0] = upb[i1][i0] - temp2b0;
    upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp2b0;
    csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + (uc[i1][i0+1]+uc[i1+1][i0+1]
        -uc[i1][i0]-uc[i1+1][i0]+up[i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+
        1][i0])*temp2b/temp2;
    phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
    temp1 = 4.0*di[1]*(dt*dp1[i1]+2.0);
    temp1b = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
    temp1b0 = csq[i1+1][i0+1]*temp1b/temp1;
    ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + temp1b0;
    ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp1b0;
    ucb[i1][i0] = ucb[i1][i0] - temp1b0;
    ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - temp1b0;
    upb[i1 + 1][i0] = upb[i1 + 1][i0] + temp1b0;
    upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp1b0;
    upb[i1][i0] = upb[i1][i0] - temp1b0;
    upb[i1][i0 + 1] = upb[i1][i0 + 1] - temp1b0;
    csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + (uc[i1+1][i0]+uc[i1+1][i0+1]
        -uc[i1][i0]-uc[i1][i0+1]+up[i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1]
        [i0+1])*temp1b/temp1;
    phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
    for (i1 = e[1]-1; i1 > s[1]-1; --i1)
        for (i0 = e[0]-1; i0 > s[0]-1; --i0) {
            temp0 = 4.0*4.0*di[0]*(dt*dp0[i0]+2.0);
            temp0b = (dp1[i1]-dp0[i0])*dt*2.0*phi0b[i1][i0];
            temp0b0 = (csq[i1][i0]+csq[i1+1][i0]+csq[i1][i0+1]+csq[i1+1][i0+1]
                )*temp0b/temp0;
            temp0b1 = (uc[i1][i0+1]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1+1][i0]+up[
                i1][i0+1]+up[i1+1][i0+1]-up[i1][i0]-up[i1+1][i0])*temp0b/temp0
            ;
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + temp0b0;
            ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + temp0b0;
            ucb[i1][i0] = ucb[i1][i0] - temp0b0;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] - temp0b0;
            upb[i1][i0 + 1] = upb[i1][i0 + 1] + temp0b0;
            upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + temp0b0;
            upb[i1][i0] = upb[i1][i0] - temp0b0;
            upb[i1 + 1][i0] = upb[i1 + 1][i0] - temp0b0;
            csqb[i1][i0] = csqb[i1][i0] + temp0b1;
            csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + temp0b1;
            csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + temp0b1;
            csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + temp0b1;
            phi0b[i1][i0] = (2.0-dt*dp0[i0])*phi0b[i1][i0]/(dt*dp0[i0]+2.0);
            temp = 4.0*4.0*di[1]*(dt*dp1[i1]+2.0);
            tempb3 = (dp0[i0]-dp1[i1])*dt*2.0*phi1b[i1][i0];
            tempb4 = (csq[i1][i0]+csq[i1+1][i0]+csq[i1][i0+1]+csq[i1+1][i0+1])
                *tempb3/temp;
            tempb5 = (uc[i1+1][i0]+uc[i1+1][i0+1]-uc[i1][i0]-uc[i1][i0+1]+up[
                i1+1][i0]+up[i1+1][i0+1]-up[i1][i0]-up[i1][i0+1])*tempb3/temp;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + tempb4;
            ucb[i1 + 1][i0 + 1] = ucb[i1 + 1][i0 + 1] + tempb4;
            ucb[i1][i0] = ucb[i1][i0] - tempb4;
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] - tempb4;
            upb[i1 + 1][i0] = upb[i1 + 1][i0] + tempb4;
            upb[i1 + 1][i0 + 1] = upb[i1 + 1][i0 + 1] + tempb4;
            upb[i1][i0] = upb[i1][i0] - tempb4;
            upb[i1][i0 + 1] = upb[i1][i0 + 1] - tempb4;
            csqb[i1][i0] = csqb[i1][i0] + tempb5;
            csqb[i1 + 1][i0] = csqb[i1 + 1][i0] + tempb5;
            csqb[i1][i0 + 1] = csqb[i1][i0 + 1] + tempb5;
            csqb[i1 + 1][i0 + 1] = csqb[i1 + 1][i0 + 1] + tempb5;
            phi1b[i1][i0] = (2.0-dt*dp1[i1])*phi1b[i1][i0]/(dt*dp1[i1]+2.0);
        }
    for (i1 = e[1]; i1 > s[1]-1; --i1)
        for (i0 = e[0]; i0 > s[0]-1; --i0) {
            tempb = upb[i1][i0]/((dp1[i1]+dp0[i0])*(dt/2.0)+1.0);
            tempb0 = csq[i1][i0]*tempb;
            tempb1 = dt*dt*tempb/(2.0*di[1]);
            tempb2 = dt*dt*tempb/(2.0*di[0]);
            ucb[i1][i0] = ucb[i1][i0] + c0*tempb0 + (2.0-dp1[i1]*dp0[i0]*(dt*
                dt))*tempb;
            csqb[i1][i0] = csqb[i1][i0] + (c0*uc[i1][i0]+c1[0]*(uc[i1][i0+1]+
                uc[i1][i0-1])+c1[1]*(uc[i1+1][i0]+uc[i1-1][i0]))*tempb;
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + c1[0]*tempb0;
            ucb[i1][i0 - 1] = ucb[i1][i0 - 1] + c1[0]*tempb0;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + c1[1]*tempb0;
            ucb[i1 - 1][i0] = ucb[i1 - 1][i0] + c1[1]*tempb0;
            phi1b[i1][i0 - 1] = phi1b[i1][i0 - 1] + tempb1;
            phi1b[i1][i0] = phi1b[i1][i0] + tempb1;
            phi1b[i1 - 1][i0 - 1] = phi1b[i1 - 1][i0 - 1] - tempb1;
            phi1b[i1 - 1][i0] = phi1b[i1 - 1][i0] - tempb1;
            phi0b[i1 - 1][i0] = phi0b[i1 - 1][i0] + tempb2;
            phi0b[i1][i0] = phi0b[i1][i0] + tempb2;
            phi0b[i1 - 1][i0 - 1] = phi0b[i1 - 1][i0 - 1] - tempb2;
            phi0b[i1][i0 - 1] = phi0b[i1][i0 - 1] - tempb2;
            upb[i1][i0] = ((dp1[i1]+dp0[i0])*(dt/2.0)-1.0)*tempb;
        }
}
