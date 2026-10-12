/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x440030; label: FUN_00440030
 */

short FUN_00440030(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    if (DAT_007f182c != -1) {
      iVar1 = FUN_0062df80((int)DAT_007f182c);
      if (iVar1 != 0) {
        return DAT_007f182c;
      }
    }
    if (DAT_007f1834 != -1) {
      iVar1 = FUN_0062df80((int)DAT_007f1834);
      if (iVar1 != 0) {
        return DAT_007f1834;
      }
    }
    if (DAT_007f183c != -1) {
      iVar1 = FUN_0062df80((int)DAT_007f183c);
      if (iVar1 != 0) {
        return DAT_007f183c;
      }
    }
  }
  else {
    if (DAT_007f1830 != -1) {
      iVar1 = FUN_0062df80((int)DAT_007f1830);
      if (iVar1 != 0) {
        return DAT_007f1830;
      }
    }
    if (DAT_007f1838 != -1) {
      iVar1 = FUN_0062df80((int)DAT_007f1838);
      if (iVar1 != 0) {
        return DAT_007f1838;
      }
    }
    if (DAT_007f1840 != -1) {
      iVar1 = FUN_0062df80((int)DAT_007f1840);
      if (iVar1 != 0) {
        return DAT_007f1840;
      }
    }
  }
  return -1;
}

