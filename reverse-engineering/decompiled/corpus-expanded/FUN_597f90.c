/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x597f90; label: FUN_00597f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00597f90(int param_1,float *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_c [12];
  
  *param_2 = *(float *)(param_1 + 0x80);
  param_2[1] = *(float *)(param_1 + 0x84);
  param_2[2] = *(float *)(param_1 + 0x88);
  iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  iVar1 = (int)*(char *)(iVar2 + 0x108);
  if ((((iVar1 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar1 * 4) != 0)) &&
      (iVar2 = (int)*(char *)(iVar2 + 0x109), iVar2 != -1)) &&
     (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar2 * 4) != 0)) {
    iVar1 = iVar1 * 0x40;
    *param_2 = *(float *)(iVar1 + 0x834 + param_1);
    param_2[1] = *(float *)(iVar1 + 0x838 + param_1);
    param_2[2] = *(float *)(iVar1 + param_1 + 0x83c);
    iVar1 = iVar2 * 0x40 + param_1;
    *param_2 = *param_2 + (*(float *)(iVar2 * 0x40 + 0x834 + param_1) - *param_2) * 0.5;
    param_2[1] = (*(float *)(iVar1 + 0x838) - param_2[1]) * 0.5 + param_2[1];
    param_2[2] = (*(float *)(iVar1 + 0x83c) - param_2[2]) * 0.5 + param_2[2];
  }
  if (DAT_008051d0 != 0) {
    if (param_3 != 0) {
      FUN_005b3620(local_c,param_1 + 0x754,*(undefined2 *)(param_1 + 0x27a));
      FUN_005b37d0(param_3,param_2,local_c);
    }
    FUN_005b3620(local_c,param_1 + 0x748,*(undefined2 *)(param_1 + 0x27a));
    FUN_005b37d0(param_2,param_2,local_c);
  }
  return;
}

