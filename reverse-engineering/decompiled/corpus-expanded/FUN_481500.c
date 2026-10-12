/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x481500; label: FUN_00481500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00481500(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *param_3;
  *(float *)(iVar1 + 0x1090) = *(float *)(iVar1 + 0x1090) - _DAT_00925018;
  if (*(int *)(iVar1 + 0x44c) != 0) {
    iVar2 = FUN_0043c9a0(iVar1,*(int *)(iVar1 + 0x44c),0);
    if (iVar2 == 0) {
      if ((code *)(&PTR_FUN_007fa2a8)[*(char *)(iVar1 + 0x1086)] != (code *)0x0) {
        uVar3 = (*(code *)(&PTR_FUN_007fa2a8)[*(char *)(iVar1 + 0x1086)])(param_1,param_2,param_3);
        return uVar3;
      }
    }
    else {
      FUN_0043cbf0(iVar1);
    }
  }
  return 0;
}

