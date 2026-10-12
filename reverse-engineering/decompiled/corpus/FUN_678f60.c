/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x678f60; label: FUN_00678f60
 */

undefined4 FUN_00678f60(undefined1 *param_1)

{
  float fVar1;
  int iVar2;
  
  FUN_006783a0();
  iVar2 = DAT_0292186c;
  switch(*(undefined1 *)(DAT_0292186c + 0x88)) {
  case 0:
    *param_1 = 0;
    *(float *)(iVar2 + 0x1c) = *(float *)(iVar2 + 0x28) + *(float *)(iVar2 + 0x1c);
    *(float *)(iVar2 + 0x20) = *(float *)(iVar2 + 0x2c) + *(float *)(iVar2 + 0x20);
    *(float *)(iVar2 + 0x24) = *(float *)(iVar2 + 0x30) + *(float *)(iVar2 + 0x24);
    return 0;
  case 1:
  case 2:
  case 3:
  case 4:
    break;
  default:
    return 1;
  }
  fVar1 = *(float *)(DAT_0292186c + 0x98) - *(float *)(DAT_0292186c + 0xa0);
  *(float *)(DAT_0292186c + 0x98) = fVar1;
  if (fVar1 < 0.0) {
    *(undefined4 *)(iVar2 + 0x98) = 0;
  }
  *(float *)(iVar2 + 0x1c) =
       *(float *)(iVar2 + 0x28) * *(float *)(iVar2 + 0x98) + *(float *)(iVar2 + 0x1c);
  *(float *)(iVar2 + 0x20) =
       *(float *)(iVar2 + 0x2c) * *(float *)(iVar2 + 0x98) + *(float *)(iVar2 + 0x20);
  *(float *)(iVar2 + 0x24) =
       *(float *)(iVar2 + 0x30) * *(float *)(iVar2 + 0x98) + *(float *)(iVar2 + 0x24);
  if (*(float *)(iVar2 + 0xb8) < 0.707) {
    *param_1 = 0;
    return 0;
  }
  *param_1 = 1;
  param_1[1] = 1;
  *(float *)(iVar2 + 0x20) = *(float *)(iVar2 + 0xac) * 0.004 + *(float *)(iVar2 + 0x20);
  return 0;
}

