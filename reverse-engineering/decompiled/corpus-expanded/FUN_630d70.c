/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x630d70; label: FUN_00630d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00630d70(void)

{
  int iVar1;
  
  if (DAT_02913150 != (code *)0x0) {
    iVar1 = FUN_005d4290(1);
    if (iVar1 != 0) {
      FUN_005d1740(0);
      (*DAT_02913150)();
      FUN_005f3950();
      return;
    }
  }
  return;
}

