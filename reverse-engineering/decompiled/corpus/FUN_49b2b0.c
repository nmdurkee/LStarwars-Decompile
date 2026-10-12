/* Ghidra analysis pseudocode, not original source.
 * ev_e2fbe3df4bc4fbdf62093b0f900a9735f5717e0efc1b865b12ee91c40549ae6e
 * Entry: 0x49b2b0; label: FUN_0049b2b0
 */

void FUN_0049b2b0(int param_1)

{
  uint uVar1;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (((unaff_ESI == DAT_0093d7f0) || (unaff_ESI == DAT_0093d7f4)) &&
     (0.25 < ABS(*(float *)(*(int *)(unaff_ESI + 0xca4) + 0x3c)))) {
    return;
  }
  uVar1 = FUN_00550040(*(undefined2 *)(unaff_ESI + 0x27a));
  if ((0x71c6 < (int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f))) &&
     (*unaff_EDI = 1, *(char *)(unaff_ESI + 0x7b5) == '6')) {
    if (param_1 == 0) {
      *unaff_EDI = 0;
    }
    *(uint *)(unaff_ESI + 0xe24) = *(uint *)(unaff_ESI + 0xe24) | 4;
  }
  return;
}

