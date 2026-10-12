/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7d60; label: FUN_006c7d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c7d60(undefined4 *param_1)

{
  int in_ECX;
  undefined4 *puVar1;
  
  DAT_02973e91 = 1;
  puVar1 = *(undefined4 **)(in_ECX + 8);
  if (puVar1 != (undefined4 *)0x0) {
    while ((puVar1 != param_1 || (param_1[0xd] != 0))) {
      puVar1 = (undefined4 *)puVar1[1];
      if (puVar1 == (undefined4 *)0x0) {
        return;
      }
    }
    if (param_1[1] == 0) {
      *(undefined4 *)(in_ECX + 0xc) = param_1[2];
    }
    else {
      *(undefined4 *)(param_1[1] + 8) = param_1[2];
    }
    if (param_1[2] == 0) {
      *(undefined4 *)(in_ECX + 8) = param_1[1];
    }
    else {
      *(undefined4 *)(param_1[2] + 4) = param_1[1];
    }
    param_1[1] = 0;
    param_1[2] = 0;
    *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -1;
    (**(code **)*param_1)(1);
  }
  return;
}

