/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5b96f0; label: FUN_005b96f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b96f0(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  
  if (((((((*(float *)(param_1 + 8) - *(float *)(param_3 + 8)) *
           (*(float *)(param_3 + 4) - *(float *)(param_2 + 4)) -
           (*(float *)(param_3 + 8) - *(float *)(param_2 + 8)) *
           (*(float *)(param_1 + 4) - *(float *)(param_3 + 4)) <= 0.0) &&
         (fVar1 = (*(float *)(param_1 + 8) - *(float *)(param_4 + 8)) *
                  (*(float *)(param_4 + 4) - *(float *)(param_3 + 4)) -
                  (*(float *)(param_4 + 8) - *(float *)(param_3 + 8)) *
                  (*(float *)(param_1 + 4) - *(float *)(param_4 + 4)), fVar1 < 0.0 != (fVar1 == 0.0)
         )) && (fVar1 = (*(float *)(param_2 + 4) - *(float *)(param_4 + 4)) *
                        (*(float *)(param_1 + 8) - *(float *)(param_2 + 8)) -
                        (*(float *)(param_2 + 8) - *(float *)(param_4 + 8)) *
                        (*(float *)(param_1 + 4) - *(float *)(param_2 + 4)),
               fVar1 < 0.0 != (fVar1 == 0.0))) &&
       ((*(float *)(param_3 + 4) != *(float *)(param_2 + 4) ||
        (*(float *)(param_3 + 8) != *(float *)(param_2 + 8))))) &&
      ((*(float *)(param_4 + 4) != *(float *)(param_2 + 4) ||
       (*(float *)(param_4 + 8) != *(float *)(param_2 + 8))))) &&
     ((*(float *)(param_4 + 4) != *(float *)(param_3 + 4) ||
      (*(float *)(param_4 + 8) != *(float *)(param_3 + 8))))) {
    return 1;
  }
  return 0;
}

