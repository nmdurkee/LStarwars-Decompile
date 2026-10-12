/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x6783a0; label: FUN_006783a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

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
      DAT_0292fdc8 = (int)*(short *)(iVar1 + 0x6c);
      DAT_02947d88 = &DAT_02947b78;
    }
  }
  return;
}

