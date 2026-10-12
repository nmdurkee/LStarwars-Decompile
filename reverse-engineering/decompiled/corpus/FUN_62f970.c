/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x62f970; label: FUN_0062f970
 */

void FUN_0062f970(void)

{
  DAT_029a99a8 = FUN_005e4d40(1);
  *(uint *)(DAT_029a99a8 + 0x40) = *(uint *)(DAT_029a99a8 + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_029a99a8 + 0x40) = *(uint *)(DAT_029a99a8 + 0x40) & 0xfffff7ff | 0x400;
  *(undefined4 *)(DAT_029a99a8 + 0x54) = 0;
  *(undefined4 *)(DAT_029a99a8 + 0x58) = 0;
  *(undefined4 *)(DAT_029a99a8 + 0x5c) = 0;
  *(undefined4 *)(DAT_029a99a8 + 0x70) = 0x3f800000;
  *(uint *)(DAT_029a99a8 + 0x40) = *(uint *)(DAT_029a99a8 + 0x40) & 0xfffffff2 | 2;
  *(uint *)(DAT_029a99a8 + 0x40) = *(uint *)(DAT_029a99a8 + 0x40) & 0xffff3fff;
  *(uint *)(DAT_029a99a8 + 0x40) = *(uint *)(DAT_029a99a8 + 0x40) & 0x807fffff;
  *(undefined2 *)(DAT_029a99a8 + 0x76) = 0;
  FUN_005e4b00(DAT_029a99a8);
  DAT_029a99ac = FUN_005e4d40(1);
  *(uint *)(DAT_029a99ac + 0x40) = *(uint *)(DAT_029a99ac + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_029a99ac + 0x40) = *(uint *)(DAT_029a99ac + 0x40) & 0xfffff7ff | 0x400;
  *(undefined4 *)(DAT_029a99ac + 0x54) = 0;
  *(undefined4 *)(DAT_029a99ac + 0x58) = 0;
  *(undefined4 *)(DAT_029a99ac + 0x5c) = 0;
  *(undefined4 *)(DAT_029a99ac + 0x70) = 0x3f800000;
  *(uint *)(DAT_029a99ac + 0x40) = *(uint *)(DAT_029a99ac + 0x40) & 0xfffffff2 | 2;
  *(uint *)(DAT_029a99ac + 0x40) = *(uint *)(DAT_029a99ac + 0x40) & 0xffff7fff | 0x4000;
  *(uint *)(DAT_029a99ac + 0x40) = *(uint *)(DAT_029a99ac + 0x40) & 0x807fffff;
  *(undefined2 *)(DAT_029a99ac + 0x76) = 0;
  FUN_005e4b00(DAT_029a99ac);
  return;
}

