/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x689e70; label: FUN_00689e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00689e70(char param_1)

{
  int iVar1;
  
  if ((&DAT_029211a8)[param_1] != 0) {
    (&DAT_029211a8)[param_1] = 0;
    DAT_029629d8 = 0;
    FUN_00545e10();
    FUN_00545540();
    iVar1 = 0;
    do {
      if ((&DAT_029211a8)[iVar1] != 0) {
        (&DAT_029211a8)[iVar1] = 0;
        FUN_00689c80(iVar1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
  }
  return;
}

