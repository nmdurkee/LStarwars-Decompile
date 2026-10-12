/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c6470; label: FUN_005c6470
 */

int * FUN_005c6470(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = DAT_00973850;
  if (0 < DAT_0097384c) {
    do {
      if (param_1 == *piVar2) {
        return DAT_00973850 + iVar1 * 10;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 10;
    } while (iVar1 < DAT_0097384c);
  }
  return (int *)0x0;
}

