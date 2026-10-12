/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x637860; label: FUN_00637860
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00637860(int param_1,undefined4 param_2)

{
  int iVar1;
  
  _DAT_0291398c = param_2;
  if (_DAT_02913970 != 0) {
    for (iVar1 = FUN_00547580(_DAT_02913970,0); iVar1 != 0;
        iVar1 = FUN_00547580(_DAT_02913970,iVar1)) {
      FUN_006374a0(param_2);
    }
  }
  if (param_1 != 0) {
    param_1 = param_1 + 4;
    iVar1 = 0;
    do {
      if (*(char *)(param_1 + 0x58) == '\0') {
        return;
      }
      if (*(char *)(param_1 + 0x7a) == -1) {
        FUN_006374a0(param_2);
      }
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 0x8c;
    } while (iVar1 < 0x80);
  }
  return;
}

