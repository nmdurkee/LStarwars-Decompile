/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5b97f0; label: FUN_005b97f0
 */

undefined4 FUN_005b97f0(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  
  if (((((((*(float *)(param_3 + 8) - *(float *)(param_2 + 8)) *
           (*(float *)(param_1 + 4) - *(float *)(param_3 + 4)) -
           (*(float *)(param_3 + 4) - *(float *)(param_2 + 4)) *
           (*(float *)(param_1 + 8) - *(float *)(param_3 + 8)) <= 0.0) &&
         (fVar1 = (*(float *)(param_1 + 4) - *(float *)(param_4 + 4)) *
                  (*(float *)(param_4 + 8) - *(float *)(param_3 + 8)) -
                  (*(float *)(param_4 + 4) - *(float *)(param_3 + 4)) *
                  (*(float *)(param_1 + 8) - *(float *)(param_4 + 8)), fVar1 < 0.0 != (fVar1 == 0.0)
         )) && (fVar1 = (*(float *)(param_1 + 4) - *(float *)(param_2 + 4)) *
                        (*(float *)(param_2 + 8) - *(float *)(param_4 + 8)) -
                        (*(float *)(param_2 + 4) - *(float *)(param_4 + 4)) *
                        (*(float *)(param_1 + 8) - *(float *)(param_2 + 8)),
               fVar1 < 0.0 != (fVar1 == 0.0))) &&
       ((*(float *)(param_3 + 8) != *(float *)(param_2 + 8) ||
        (*(float *)(param_3 + 4) != *(float *)(param_2 + 4))))) &&
      ((*(float *)(param_4 + 8) != *(float *)(param_2 + 8) ||
       (*(float *)(param_4 + 4) != *(float *)(param_2 + 4))))) &&
     ((*(float *)(param_4 + 8) != *(float *)(param_3 + 8) ||
      (*(float *)(param_4 + 4) != *(float *)(param_3 + 4))))) {
    return 1;
  }
  return 0;
}

