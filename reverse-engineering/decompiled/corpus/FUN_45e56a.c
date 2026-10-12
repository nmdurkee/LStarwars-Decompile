/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x45e56a; label: FUN_0045e56a
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045e56a(void)

{
  float fVar1;
  int unaff_ESI;
  float fStack0000000c;
  int in_stack_00000010;
  float in_stack_00000014;
  
  FUN_00482f10(in_stack_00000010,(int)*(char *)(in_stack_00000010 + 0xb8));
  if ((*(byte *)(in_stack_00000010 + 0xb0) & 4) == 0) {
    fStack0000000c =
         (*(float *)(in_stack_00000010 + 0x50) * 100.0) / *(float *)(in_stack_00000010 + 0x54);
    if (99.0 < fStack0000000c) {
      fStack0000000c = 99.0;
    }
  }
  else {
    fStack0000000c = 100.0;
  }
  *(float *)(unaff_ESI + 0x18) = in_stack_00000014 + *(float *)(unaff_ESI + 0x18);
  fVar1 = in_stack_00000014 * (100.0 / *(float *)(unaff_ESI + 0x1c)) +
          *(float *)(in_stack_00000010 + 0x58);
  *(float *)(in_stack_00000010 + 0x58) = fVar1;
  if (fVar1 <= fStack0000000c) {
    if (_DAT_007f8660 < fVar1 != (_DAT_007f8660 == fVar1)) {
      FUN_00681f40("Status_GoldBarDec",0);
      _DAT_007f8660 = _DAT_007f8660 + 10.0;
    }
  }
  else {
    *(float *)(in_stack_00000010 + 0x58) = fStack0000000c;
  }
  if (*(float *)(unaff_ESI + 0x18) <= *(float *)(unaff_ESI + 0x1c)) {
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined4 *)(unaff_ESI + 0x1c) = 0x3f800000;
  if (*(int *)(unaff_ESI + 0xc) != 2) {
    *(undefined4 *)(unaff_ESI + 0x14) = 3;
    FUN_00681f40("TrueJedi_100pc",0);
    return;
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 6;
  FUN_00681f40("TrueJedi_NOT",0);
  return;
}

