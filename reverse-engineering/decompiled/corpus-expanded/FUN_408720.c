/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x408720; label: FUN_00408720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00408720(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0055f450();
  iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0x134) + 8) + 0x6a4);
  if (iVar1 != -1) {
    FUN_00684be0(iVar1,param_1 + 0x88,0x3c,_DAT_00925018,0,0,0);
  }
  return;
}

