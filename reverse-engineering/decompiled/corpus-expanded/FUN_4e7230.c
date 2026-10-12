/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e7230; label: FUN_004e7230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e7230(void)

{
  int *piVar1;
  
  piVar1 = &DAT_0093d7f0;
  do {
    if ((DAT_0088a531 != '\0') && (*piVar1 != 0)) {
      FUN_004e6d40(*piVar1);
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x93d7f8);
  return;
}

