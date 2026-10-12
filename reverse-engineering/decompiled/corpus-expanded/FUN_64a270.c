/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64a270; label: FUN_0064a270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064a270(void)

{
  DAT_0291f7a4 = 1;
  DAT_02913a54 = FUN_005e4d40(1);
  *(undefined4 *)(DAT_02913a54 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02913a54 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02913a54 + 0x5c) = 0x3f000000;
  *(uint *)(DAT_02913a54 + 0x40) = *(uint *)(DAT_02913a54 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02913a54 + 0x40) = *(uint *)(DAT_02913a54 + 0x40) & 0xffff3fff;
  *(undefined4 *)(DAT_02913a54 + 0x70) = 0x3f800000;
  *(uint *)(DAT_02913a54 + 0x40) = *(uint *)(DAT_02913a54 + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_02913a54);
  DAT_02913a50 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02913a50 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02913a50 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02913a50 + 0x5c) = 0x3f000000;
  *(uint *)(DAT_02913a50 + 0x40) = *(uint *)(DAT_02913a50 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02913a50 + 0x40) = *(uint *)(DAT_02913a50 + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02913a50 + 0x70) = 0x3f800000;
  *(uint *)(DAT_02913a50 + 0x40) = *(uint *)(DAT_02913a50 + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_02913a50);
  DAT_02920888 = 0xffffffff;
  _DAT_0291f668 = 0xffffffff;
  DAT_00810194 = 0xffffffff;
  DAT_02920974 = 0;
  DAT_02920a40 = 0;
  DAT_02920a44 = 0;
  DAT_02920a48 = 0;
  return;
}

