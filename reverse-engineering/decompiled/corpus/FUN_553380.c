/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x553380; label: FUN_00553380
 */

void FUN_00553380(void)

{
  DAT_0093b104 = FUN_005e4d00(1);
  *(uint *)(DAT_0093b104 + 0x40) = *(uint *)(DAT_0093b104 + 0x40) & 0xffff3fff;
  *(uint *)(DAT_0093b104 + 0x40) = *(uint *)(DAT_0093b104 + 0x40) & 0xfffffff0;
  *(uint *)(DAT_0093b104 + 0x40) = *(uint *)(DAT_0093b104 + 0x40) | 0x40000;
  FUN_005e4b00(DAT_0093b104);
  DAT_0093b108 = FUN_005e4d40(1);
  *(uint *)(DAT_0093b108 + 0x40) = *(uint *)(DAT_0093b108 + 0x40) & 0xffff3fff;
  *(uint *)(DAT_0093b108 + 0x40) = *(uint *)(DAT_0093b108 + 0x40) & 0xfffffff0;
  *(uint *)(DAT_0093b108 + 0x40) = *(uint *)(DAT_0093b108 + 0x40) | 0x40000;
  FUN_005e4b00(DAT_0093b108);
  return;
}

