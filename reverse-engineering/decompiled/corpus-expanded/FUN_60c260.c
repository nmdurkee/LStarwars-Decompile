/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60c260; label: FUN_0060c260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060c260(undefined4 param_1,int param_2)

{
  char cVar1;
  
  if ((_DAT_028572a0 & 1) == 0) {
    _DAT_028572a0 = _DAT_028572a0 | 1;
    FUN_006069a0();
    _atexit(FUN_00750430);
  }
  FUN_005fb870(param_1,0,0);
  if ((*(short *)(param_2 + 0x14) == DAT_02857298) && (*(short *)(param_2 + 0x16) == DAT_0285729a))
  {
    cVar1 = '\0';
  }
  else {
    cVar1 = '\x01';
  }
  FUN_006e5820(DAT_0285728c,0,*(undefined4 *)(param_2 + 8),0,-cVar1 & 2);
  return;
}

