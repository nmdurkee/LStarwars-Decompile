/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40e690; label: FUN_0040e690
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

