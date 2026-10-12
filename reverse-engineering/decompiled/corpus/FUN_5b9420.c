/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b9420; label: FUN_005b9420
 */

undefined4 FUN_005b9420(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  
  if (((((((*param_1 - *param_3) * (param_3[1] - param_2[1]) -
           (*param_3 - *param_2) * (param_1[1] - param_3[1]) <= 0.0) &&
         (fVar1 = (param_4[1] - param_3[1]) * (*param_1 - *param_4) -
                  (*param_4 - *param_3) * (param_1[1] - param_4[1]), fVar1 < 0.0 != (fVar1 == 0.0)))
        && (fVar1 = (param_2[1] - param_4[1]) * (*param_1 - *param_2) -
                    (*param_2 - *param_4) * (param_1[1] - param_2[1]), fVar1 < 0.0 != (fVar1 == 0.0)
           )) && ((param_3[1] != param_2[1] || (*param_3 != *param_2)))) &&
      ((param_4[1] != param_2[1] || (*param_4 != *param_2)))) &&
     ((param_4[1] != param_3[1] || (*param_4 != *param_3)))) {
    return 1;
  }
  return 0;
}

