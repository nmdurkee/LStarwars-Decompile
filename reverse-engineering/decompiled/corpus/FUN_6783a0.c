/* Ghidra analysis pseudocode, not original source.
 * ev_acb06b3e4b799a53163de8490d9831a732be2977530d73e58478bea7efdd9d98
 * Entry: 0x6783a0; label: FUN_006783a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006783a0(void)

{
  int iVar1;
  
  iVar1 = DAT_0292186c;
  switch(*(undefined1 *)(DAT_0292186c + 0x88)) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
    if (*(short *)(DAT_0292186c + 0x6c) != -1) {
      FUN_00678340();
      _DAT_0292fdc8 = (int)*(short *)(iVar1 + 0x6c);
      _DAT_02947d88 = &DAT_02947b78;
    }
  }
  return;
}

