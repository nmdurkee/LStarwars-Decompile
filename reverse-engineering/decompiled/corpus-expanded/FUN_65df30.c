/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65df30; label: FUN_0065df30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065df30(void)

{
  FUN_0065d470();
  DAT_02947d78 = FUN_005e4d40(1);
  *(undefined4 *)(DAT_02947d78 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02947d78 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02947d78 + 0x5c) = 0x3f000000;
  *(uint *)(DAT_02947d78 + 0x40) = *(uint *)(DAT_02947d78 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02947d78 + 0x40) = *(uint *)(DAT_02947d78 + 0x40) & 0xffff3fff;
  *(undefined4 *)(DAT_02947d78 + 0x70) = 0x3f800000;
  *(uint *)(DAT_02947d78 + 0x40) = *(uint *)(DAT_02947d78 + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_02947d78);
  DAT_02947c9c = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02947c9c + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_02947c9c + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_02947c9c + 0x5c) = 0x3f000000;
  *(uint *)(DAT_02947c9c + 0x40) = *(uint *)(DAT_02947c9c + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02947c9c + 0x40) = *(uint *)(DAT_02947c9c + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02947c9c + 0x70) = 0x3f800000;
  *(uint *)(DAT_02947c9c + 0x40) = *(uint *)(DAT_02947c9c + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_02947c9c);
  DAT_02920d80 = 0xffffffff;
  DAT_0292fdb4 = 0xffffffff;
  return;
}

