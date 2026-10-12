/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x594960; label: FUN_00594960
 */

undefined4 FUN_00594960(int param_1)

{
  int iVar1;
  short *psVar2;
  
  DAT_00955884 = (short *)0x0;
  iVar1 = param_1;
  psVar2 = DAT_00955884;
  if (DAT_0095587c != (short *)0x0) {
    iVar1 = 0;
    psVar2 = DAT_0095587c;
    if (DAT_00955878 < 1) {
      DAT_00955884 = (short *)0x0;
      return 0;
    }
    while (*psVar2 != param_1) {
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0xe;
      if (DAT_00955878 <= iVar1) {
        return 0;
      }
    }
  }
  DAT_00955884 = psVar2;
  if (iVar1 != -1) {
    iVar1 = FUN_00574d00(param_1);
    if (iVar1 == -1) {
      if ((DAT_0093b288 == 0) || ((*(byte *)(DAT_0093b288 + param_1) & 1) != 0)) {
        return 1;
      }
    }
    else if ((DAT_0095136c != 0) && (*(char *)(DAT_0095136c + 4 + iVar1 * 0xc) != '\0')) {
      return 2;
    }
  }
  return 0;
}

