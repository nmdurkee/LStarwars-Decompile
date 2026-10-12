/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x689670; label: FUN_00689670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00689670(char param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar1 = param_1 * 4;
  if (((&DAT_029211c8)[param_1] != 0) && (*(int *)(&DAT_0292fc3c + iVar1) != 0)) {
    iVar3 = 0;
    pcVar2 = &DAT_02947db4;
    do {
      if (*pcVar2 == param_1) {
        FUN_0065d630(iVar3,*(undefined4 *)(&DAT_0292fc3c + iVar1));
      }
      pcVar2 = pcVar2 + 0x44;
      iVar3 = iVar3 + 1;
    } while ((int)pcVar2 < 0x2948eb4);
  }
  return;
}

