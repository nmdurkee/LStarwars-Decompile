/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x689f70; label: FUN_00689f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00689f70(void)

{
  int iVar1;
  
  DAT_029629d8 = 0;
  FUN_00545e10();
  FUN_00545540();
  DAT_029211a8 = 0;
  DAT_029211ac = 0;
  _DAT_029211b0 = 0;
  _DAT_029211b4 = 0;
  _DAT_029211b8 = 0;
  _DAT_029211bc = 0;
  _DAT_029211c0 = 0;
  _DAT_029211c4 = 0;
  iVar1 = 0;
  do {
    if ((&DAT_02920acc)[iVar1] != 0) {
      (&DAT_0292fc0c)[iVar1] = 0;
      (&DAT_0292fd10)[iVar1] = 0;
      FUN_00689c80(iVar1);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}

