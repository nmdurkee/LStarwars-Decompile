/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59b0e0; label: FUN_0059b0e0
 */

int FUN_0059b0e0(int param_1,int param_2,short param_3,undefined4 *param_4,undefined4 param_5,
                int param_6)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = 0;
  if ((param_6 == 0) && ((*(byte *)((int)param_4 + 0x23) & 1) == 0)) {
    if ((param_1 != 0) && (param_2 != 0)) {
      local_c = *param_4;
      local_8 = param_4[1];
      local_4 = param_4[2];
      FUN_005b3620(&local_c,&local_c,param_3);
      FUN_005b37d0(&local_c,&local_c,param_2);
      iVar1 = FUN_0059afc0(param_1,&local_c,param_4[3],param_4[6],param_4[7],
                           *(short *)(param_4 + 8) + param_3,*(undefined1 *)((int)param_4 + 0x22),
                           param_5);
      if (iVar1 != 0) {
        *(float *)(iVar1 + 0x10) = (float)param_4[4] + *(float *)(param_2 + 4);
        *(float *)(iVar1 + 0x14) = (float)param_4[5] + *(float *)(param_2 + 4);
      }
    }
    return iVar1;
  }
  return 0;
}

