/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x565700; label: FUN_00565700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565700(void)

{
  int iVar1;
  
  if (_DAT_00950760 <= 0.0) {
    return;
  }
  FUN_005d4290(1);
  FUN_006e6b90();
  iVar1 = FUN_006e6b90();
  FUN_005db880(0,0,0x2800,iVar1,0x80ffffff,DAT_009506fc);
  FUN_005db880(0,0xe20 - iVar1,0x2800,iVar1,0x80ffffff,DAT_009506fc);
  FUN_005f3950();
  return;
}

