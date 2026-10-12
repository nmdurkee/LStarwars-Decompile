/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5b9e90; label: FUN_005b9e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005b9e90(uint *param_1)

{
  uint uVar1;
  
  if (param_1 == (uint *)0x0) {
    param_1 = &DAT_008066c0;
  }
  else if (*param_1 == 0) {
    *param_1 = 1;
  }
  uVar1 = (*param_1 ^ 0x75bd924) * 0x41a7 + ((int)(*param_1 ^ 0x75bd924) / 0x1f31d) * -0x7fffffff;
  *param_1 = uVar1;
  if ((int)uVar1 < 0) {
    *param_1 = uVar1 + 0x7fffffff;
  }
  *param_1 = *param_1 ^ 0x75bd924;
  return *param_1;
}

