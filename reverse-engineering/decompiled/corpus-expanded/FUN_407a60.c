/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x407a60; label: FUN_00407a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00407a60(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *param_3;
  *(float *)(iVar1 + 0x1090) = *(float *)(iVar1 + 0x1090) - _DAT_00925018;
  if (*(int *)(iVar1 + 0x44c) != 0) {
    if ((*(char *)(iVar1 + 0x1086) != '\x04') &&
       (iVar2 = FUN_0043c9a0(iVar1,*(int *)(iVar1 + 0x44c),0), iVar2 != 0)) {
      FUN_0043cbf0(iVar1);
      return 0;
    }
    if ((code *)(&PTR_FUN_007ef2a0)[*(char *)(iVar1 + 0x1086)] != (code *)0x0) {
      uVar3 = (*(code *)(&PTR_FUN_007ef2a0)[*(char *)(iVar1 + 0x1086)])(param_1,param_2,param_3);
      return uVar3;
    }
  }
  return 0;
}

