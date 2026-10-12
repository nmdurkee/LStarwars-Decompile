/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x62f970; label: FUN_0062f970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

