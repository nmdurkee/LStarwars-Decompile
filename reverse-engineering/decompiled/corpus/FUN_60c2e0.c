/* Ghidra analysis pseudocode, not original source.
 * ev_49dad5f20e053bf764d7eecccea7d519a0835f455b7dcdd298ee46307ff6e048
 * Entry: 0x60c2e0; label: FUN_0060c2e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060c2e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  char cVar1;
  
  if (param_5 == DAT_009737fc) {
    if ((_DAT_028572dc & 1) == 0) {
      _DAT_028572dc = _DAT_028572dc | 1;
      FUN_006069a0();
      _atexit((_func_4879 *)&LAB_00750470);
    }
    if ((_DAT_028572dc & 2) == 0) {
      _DAT_028572dc = _DAT_028572dc | 2;
      FUN_006069a0();
      _atexit((_func_4879 *)&LAB_00750450);
    }
    FUN_005fb870(param_3,param_4,0);
    FUN_005fb870(param_1,param_2,0);
    if ((DAT_028572b8 == DAT_028572d4) && (DAT_028572ba == DAT_028572d6)) {
      cVar1 = '\0';
    }
    else {
      cVar1 = '\x01';
    }
    FUN_006e5820(DAT_028572c8,0,DAT_028572ac,0,-cVar1 & 2);
    return;
  }
  FUN_005c3bb0();
  return;
}

