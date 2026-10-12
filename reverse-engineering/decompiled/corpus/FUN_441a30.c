/* Ghidra analysis pseudocode, not original source.
 * ev_2697994747b9808d778082a46d5d52329d06fdf80cefad3ab22f972b93f6240a
 * Entry: 0x441a30; label: FUN_00441a30
 */

float10 FUN_00441a30(undefined4 param_1,int param_2,float param_3,undefined4 param_4,int param_5)

{
  float10 fVar1;
  float local_10;
  undefined1 local_c [12];
  
  if (((param_3 == 0.0) || (*(int *)((int)param_3 + 0xd0) == 0)) ||
     ((param_5 == 0 && (param_5 = *(int *)(param_2 + 0xa4), param_5 == 0)))) {
    return (float10)(float)0x4e6e6b28;
  }
  param_3 = 1e+09;
  local_10 = 1e+09;
  if (DAT_0093d810 != 0) {
    fVar1 = (float10)FUN_005bed80(DAT_0093d810 + 0x5c,param_5 + 0x10,local_c);
    param_3 = (float)fVar1;
  }
  if (DAT_0093d814 != 0) {
    fVar1 = (float10)FUN_005bed80(DAT_0093d814 + 0x5c,param_5 + 0x10,local_c);
    local_10 = (float)fVar1;
  }
  if (param_3 < local_10) {
    return (float10)param_3;
  }
  return (float10)local_10;
}

