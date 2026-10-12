/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x488630; label: FUN_00488630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00488630(void)

{
  int *piVar1;
  
  piVar1 = &DAT_0093d7f0;
  do {
    if (*piVar1 != 0) {
      FUN_004882d0(*piVar1,0);
    }
    piVar1 = piVar1 + 1;
  } while ((int)piVar1 < 0x93d810);
  return;
}

