/* Ghidra pseudocode, not original source.
 * ev_428398453750e294ede80d9f87d5cfcdf804466d2d70f27e1ba752c78f326fd9
 * Entry: 0x40e690; label: FUN_0040e690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0040e690(int param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0xe3c) != '\0') {
    uVar1 = FUN_00550040(*(undefined2 *)(param_1 + 0x696),*(undefined2 *)(param_1 + 0x27a));
    uVar1 = (uint)((int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) < 0x4000);
    if ((*(char *)(param_1 + 0x7b5) == '*') &&
       (*(float *)(param_1 + 0x77c) < *(float *)(param_1 + 0x784) * 0.8)) {
      uVar1 = 1 - uVar1;
    }
    return uVar1;
  }
  return 0;
}

