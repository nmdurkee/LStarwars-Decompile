/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5b9510; label: FUN_005b9510
 */

undefined4 FUN_005b9510(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  if (((((((*param_3 - *param_2) * (param_1[2] - param_3[2]) -
           (*param_1 - *param_3) * (param_3[2] - param_2[2]) <= 0.0) &&
         (fVar1 = (param_1[2] - param_4[2]) * (*param_4 - *param_3) -
                  (param_4[2] - param_3[2]) * (*param_1 - *param_4), fVar1 < 0.0 != (fVar1 == 0.0)))
        && (fVar1 = (param_1[2] - param_2[2]) * (*param_2 - *param_4) -
                    (*param_1 - *param_2) * (param_2[2] - param_4[2]), fVar1 < 0.0 != (fVar1 == 0.0)
           )) && ((*param_3 != *param_2 || (param_3[2] != param_2[2])))) &&
      ((*param_4 != *param_2 || (param_4[2] != param_2[2])))) &&
     ((*param_4 != *param_3 || (param_4[2] != param_3[2])))) {
    return 1;
  }
  return 0;
}

