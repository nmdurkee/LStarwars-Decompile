/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65ce60; label: FUN_0065ce60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065ce60(char param_1)

{
  int *piVar1;
  
  if ((&DAT_029211c8)[param_1] != 0) {
    piVar1 = &DAT_02947d98;
    do {
      if (((char)piVar1[7] == param_1) && (*piVar1 != -1)) {
        FUN_00543fd0(*piVar1);
        *piVar1 = -1;
      }
      piVar1 = piVar1 + 0x11;
    } while ((int)piVar1 < 0x2948e98);
  }
  return;
}

