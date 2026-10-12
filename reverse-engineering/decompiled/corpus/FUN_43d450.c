/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43d450; label: FUN_0043d450
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

