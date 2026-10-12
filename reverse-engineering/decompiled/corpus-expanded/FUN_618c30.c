/* Ghidra pseudocode, not original source.
 * ev_fbd0714d29abf1967b7a59c1140afabe8eda1c53d580ba604e59c833adf58051
 * Entry: 0x618c30; label: FUN_00618c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00618c30(void)

{
  DAT_02900c70 = FUN_005e4d00(1);
  *(uint *)(DAT_02900c70 + 0x40) = *(uint *)(DAT_02900c70 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02900c70 + 0x40) = *(uint *)(DAT_02900c70 + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02900c70 + 0x70) = 0x3f800000;
  *(uint *)(DAT_02900c70 + 0x40) = *(uint *)(DAT_02900c70 + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_02900c70);
  DAT_02900c74 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02900c74 + 0x54) = 0x3e4ccccd;
  *(undefined4 *)(DAT_02900c74 + 0x58) = 0x3e4ccccd;
  *(undefined4 *)(DAT_02900c74 + 0x5c) = 0x3e4ccccd;
  *(uint *)(DAT_02900c74 + 0x40) = *(uint *)(DAT_02900c74 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02900c74 + 0x40) = *(uint *)(DAT_02900c74 + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02900c74 + 0x70) = 0x3f7fbe77;
  *(uint *)(DAT_02900c74 + 0x40) = *(uint *)(DAT_02900c74 + 0x40) & 0xfffffff3 | 3;
  FUN_005e4b00(DAT_02900c74);
  DAT_02900c78 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02900c78 + 0x54) = 0x3e4ccccd;
  *(undefined4 *)(DAT_02900c78 + 0x58) = 0x3e4ccccd;
  *(undefined4 *)(DAT_02900c78 + 0x5c) = 0x3e4ccccd;
  *(uint *)(DAT_02900c78 + 0x40) = *(uint *)(DAT_02900c78 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02900c78 + 0x40) = *(uint *)(DAT_02900c78 + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02900c78 + 0x70) = 0x3f7fbe77;
  *(uint *)(DAT_02900c78 + 0x40) = *(uint *)(DAT_02900c78 + 0x40) & 0xfffffff2 | 2;
  FUN_005e4b00(DAT_02900c78);
  DAT_02900c7c = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02900c7c + 0x54) = 0x3e4ccccd;
  *(undefined4 *)(DAT_02900c7c + 0x58) = 0x3e4ccccd;
  *(undefined4 *)(DAT_02900c7c + 0x5c) = 0x3e4ccccd;
  *(uint *)(DAT_02900c7c + 0x40) = *(uint *)(DAT_02900c7c + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02900c7c + 0x40) = *(uint *)(DAT_02900c7c + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02900c7c + 0x70) = 0x3f7fbe77;
  *(uint *)(DAT_02900c7c + 0x40) = *(uint *)(DAT_02900c7c + 0x40) & 0xfffffff1 | 1;
  FUN_005e4b00(DAT_02900c7c);
  return;
}

