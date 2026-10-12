/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4fb490; label: FUN_004fb490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004fb490(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00800544 == 0) {
    return 0;
  }
  iVar1 = FUN_004f5e30(param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_004faea0(param_1 + 0xc,param_2,*(uint *)(param_1 + 8) & _DAT_00800540,iVar1);
    return uVar2;
  }
  return 0;
}

