/**
Copyright (c) 2014, Florent Hedin
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

  Neither the name of the University of Basel nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **/
#ifndef RMSD_H
#define	RMSD_H

#ifdef	__cplusplus
extern "C"
{
#endif

    double rmsd(int natom, float **crd, float **ref, int crd_size, int index_c[], int index_r[]);

    POINT_3D getCentroid(int natom, float **crd, int index_c[], int index_r[]);
    void center_sys(int natom, float **crd, int crd_size, int index_c[], int index_r[]);
    void center_sys2(int natom, float **crd, int crd_size, int index_c[], int index_r[]);

    void get_cov_mat(int natom, float **crd, float **ref, int index_c[], int index_r[], float covmat[9]);
    double determinant_3x3(float inp[9]);
    void matmul_3x3(float a[9], float b[9], float c[9]);

    void svd_f(float a[9], float u[9], float vt[9]);
    void rot_mat(double d, float u[9], float vt[9], float **crd, int crd_size);

    // for the lapack routine sgesvd : singular values decomposition fo floats
    extern void sgesvd_(char *jobu, char *jobvt, int *m, int *n, float *a, int *lda, float *s, float *u, int *ldu,
                        float *vt, int *ldvt, float *work, int *lwork, int *info);
    //for the blas routine dgemm : matrix multiplication for floats
    extern void sgemm_(char* transA, char* transB, int *M, int *N, int * K, float *alpha, float *A, int *ldA, float *B, int *ldB, float *beta, float *C, int *ldC);

#ifdef	__cplusplus
}
#endif

#endif	/* RMSD_H */

