/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c9140; label: FUN_005c9140
 */

void FUN_005c9140(void)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    (&DAT_00971760)[uVar1] = 0;
    if ((uVar1 & 1) != 0) {
      (&DAT_00971760)[uVar1] = 1;
    }
    if ((uVar1 & 2) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 4) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 8) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 0x10) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 0x20) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((uVar1 & 0x40) != 0) {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    if ((char)uVar1 < '\0') {
      (&DAT_00971760)[uVar1] = (&DAT_00971760)[uVar1] + '\x01';
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x100);
  DAT_00973868 = 1;
  return;
}

