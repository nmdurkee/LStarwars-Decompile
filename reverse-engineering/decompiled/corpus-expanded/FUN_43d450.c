/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43d450; label: FUN_0043d450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0043d450(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = (uint)*(char *)(*(int *)(param_1 + 0x3ac) + 0x280);
  iVar4 = 0;
  iVar5 = 0;
  if (8 < uVar2) {
    return (float10)0.75;
  }
  iVar1 = (&DAT_00876858)[uVar2 * 0x22];
  iVar3 = 0;
  while ((iVar1 != 0 && (iVar3 < 0x11))) {
    if (iVar1 == param_1) {
      return (float10)((float)iVar5 * _DAT_007f6720 + _DAT_007f6724);
    }
    if (*(char *)(iVar1 + 0x1084) == -1) {
      iVar4 = iVar4 + 1;
    }
    if (DAT_007f671c <= iVar4) {
      iVar5 = iVar5 + 1;
      iVar4 = 0;
    }
    iVar3 = iVar3 + 1;
    iVar1 = (&DAT_00876858)[(uVar2 * 0x11 + iVar3) * 2];
  }
  return (float10)_DAT_007f6724;
}

