/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50ef80; label: FUN_0050ef80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050ef80(int param_1)

{
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_0050ef10();
    return;
  }
  switch(*(undefined2 *)(param_1 + 10)) {
  case 0:
    if (*(int *)(param_1 + 0x60) != 0) {
      DAT_00800940 = DAT_00800950;
      FUN_006e1df0();
      return;
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      DAT_00800940 = DAT_00800950;
      FUN_006e1f00();
      return;
    }
    break;
  case 1:
    if (*(int *)(param_1 + 0x60) != 0) {
      DAT_00800940 = DAT_00800950;
      FUN_006e2010();
      return;
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      DAT_00800940 = DAT_00800950;
      FUN_006e2080();
      return;
    }
    break;
  case 2:
    if (*(int *)(param_1 + 0x60) == 0) {
      if (*(int *)(param_1 + 0x5c) != 0) {
        DAT_00921d04 = DAT_00921d04 + -1;
        DAT_00800940 = DAT_00800950;
        if (DAT_00921d04 < 0) {
          DAT_00921d04 = 3;
          return;
        }
      }
    }
    else {
      DAT_00921d04 = DAT_00921d04 + 1;
      DAT_00800940 = DAT_00800950;
      if (3 < DAT_00921d04) {
        DAT_00921d04 = 0;
      }
    }
    break;
  case 3:
    if (((*(int *)(param_1 + 0x60) != 0) || (*(int *)(param_1 + 0x5c) != 0)) ||
       (*(int *)(param_1 + 100) != 0)) {
      if (DAT_008264c9 != '\0') {
        DAT_00800940 = DAT_00800950;
        DAT_00921d14 = 1 - DAT_00921d14;
        return;
      }
      DAT_00800940 = DAT_0080095c;
      return;
    }
    break;
  case 4:
    if (*(int *)(param_1 + 100) != 0) {
      FUN_0050ee70();
      return;
    }
  }
  return;
}

