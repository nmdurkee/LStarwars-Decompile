/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56f930; label: FUN_0056f930
 */

void FUN_0056f930(void)

{
  ushort uVar1;
  int in_EAX;
  
  DAT_00950f60 = 0x3f800000;
  if ((-1 < in_EAX) && (in_EAX < DAT_00951360)) {
    uVar1 = *(ushort *)(in_EAX * 0x9c + 0x7a + DAT_00951354);
    if ((uVar1 & 0x200) != 0) {
      DAT_00950f60 = 0x40c00000;
      return;
    }
    if ((uVar1 & 1) != 0) {
      if (DAT_00951154 != 0) {
        DAT_00950f60 = 0x40400000;
        return;
      }
      DAT_00950f60 = 0x40a00000;
    }
  }
  return;
}

