/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65ce60; label: FUN_0065ce60
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

