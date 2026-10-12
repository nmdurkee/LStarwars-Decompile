/* Ghidra analysis pseudocode, not original source.
 * ev_101b67aa7badcd34fc3aca69d932f1af6fd7c0870f1a0aed34e591760076c155
 * Entry: 0x505a80; label: FUN_00505a80
 */

int * FUN_00505a80(undefined4 param_1,int *param_2,int param_3,uint *param_4,uint *param_5,
                  int param_6)

{
  int iVar1;
  
  if (9 < *param_2) {
    iVar1 = param_2[1];
    if (iVar1 == 0) {
      iVar1 = FUN_004fff00();
    }
    param_2[0x16] = param_3;
    param_2[1] = (int)param_2 - iVar1;
    param_2[10] = (int)param_2 - param_2[10];
    if ((*(byte *)(param_2 + 0xe) & 8) == 0) {
      FUN_00505780(0);
      if (((*(byte *)(param_2 + 0xe) & 1) != 0) && (param_6 == 0)) {
        FUN_004fff00();
      }
    }
    else {
      FUN_00505780(0);
    }
    FUN_00500140(param_2,param_4);
    if (*param_5 < *param_4) {
      FUN_004fff00(param_1,*param_4 - *param_5);
    }
    param_2[1] = 0;
    return param_2;
  }
  FUN_004fff00();
  return (int *)0x0;
}

