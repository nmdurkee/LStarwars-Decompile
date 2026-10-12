/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7f10; label: FUN_006c7f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c7f10(int *param_1)

{
  undefined4 *puVar1;
  
  DAT_02973e91 = 1;
  puVar1 = (undefined4 *)param_1[0x10];
  if (*param_1 == 0) {
    puVar1[0xc] = param_1[1];
  }
  else {
    *(int *)(*param_1 + 4) = param_1[1];
  }
  if ((int *)param_1[1] == (int *)0x0) {
    puVar1[0xb] = *param_1;
  }
  else {
    *(int *)param_1[1] = *param_1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  puVar1[0xd] = puVar1[0xd] + -1;
  FUN_006334d0(param_1,0x50);
  if (puVar1[0xd] == 0) {
    if (puVar1[1] == 0) {
      DAT_0081fdfc = puVar1[2];
    }
    else {
      *(undefined4 *)(puVar1[1] + 8) = puVar1[2];
    }
    if (puVar1[2] == 0) {
      DAT_0081fdf8 = puVar1[1];
    }
    else {
      *(undefined4 *)(puVar1[2] + 4) = puVar1[1];
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    _DAT_0081fe00 = _DAT_0081fe00 + -1;
    (**(code **)*puVar1)(1);
  }
  return;
}

