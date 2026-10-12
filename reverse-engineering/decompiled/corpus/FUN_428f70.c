/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x428f70; label: FUN_00428f70
 */

int FUN_00428f70(int param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x280) != -1) {
    iVar1 = FUN_0056e160(0x19);
    if (iVar1 != 0) {
      return 1;
    }
    if (*(char *)(param_1 + 0x280) != -1) {
      iVar1 = FUN_0041af30(param_1);
      if (iVar1 != 0) {
        return 4;
      }
    }
  }
  if (*(short *)(param_1 + 0x1064) == DAT_007f1968) {
    iVar1 = FUN_0054fa60();
    return (0x7fff < iVar1) + 2;
  }
  if (param_2 == -1) {
    param_2 = 2;
  }
  return param_2;
}

