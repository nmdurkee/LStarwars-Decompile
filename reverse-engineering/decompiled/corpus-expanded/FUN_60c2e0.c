/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60c2e0; label: FUN_0060c2e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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
      _atexit(FUN_00750470);
    }
    if ((_DAT_028572dc & 2) == 0) {
      _DAT_028572dc = _DAT_028572dc | 2;
      FUN_006069a0();
      _atexit(FUN_00750450);
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

