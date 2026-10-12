/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c9b20; label: FUN_004c9b20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c9b20(void)

{
  int iVar1;
  
  iVar1 = FUN_004f5260();
  FUN_004f1f10();
  if (iVar1 == 2) {
    if ((DAT_0080235c == 1) || (DAT_0080235c == 0x12)) {
      FUN_004f1e80();
      goto LAB_004c9bad;
    }
    if (DAT_0080235c == 2) {
      FUN_004f1e80();
      goto LAB_004c9bad;
    }
    if (DAT_0080235c == 3) {
      FUN_004f1e80();
      goto LAB_004c9bad;
    }
  }
  FUN_004f1e80();
  FUN_0054b5a0(DAT_0080235c);
  FUN_004f1e80();
LAB_004c9bad:
  if (DAT_0080235c == 0) {
    _DAT_008015ac = 0x400ccccd;
    _DAT_008015b0 = 0x400ccccd;
  }
  return;
}

