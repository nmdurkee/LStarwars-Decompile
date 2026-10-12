/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x5719f0; label: FUN_005719f0
 */

undefined4 FUN_005719f0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != (int *)0x0) && (iVar2 = *param_1, iVar2 < param_1[1])) {
    iVar3 = iVar2 * 0x14;
    do {
      iVar1 = FUN_004f8b10(param_2,iVar3 + 4 + param_1[2]);
      if (iVar1 == 0) {
        return *(undefined4 *)(param_1[2] + iVar2 * 0x14);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x14;
    } while (iVar2 < param_1[1]);
  }
  return 0xffffffff;
}

