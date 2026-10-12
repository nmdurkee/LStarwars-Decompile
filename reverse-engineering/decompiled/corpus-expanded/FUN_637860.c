/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x637860; label: FUN_00637860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

