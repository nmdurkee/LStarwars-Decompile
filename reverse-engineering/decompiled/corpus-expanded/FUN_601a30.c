/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x601a30; label: FUN_00601a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00601a30(void)

{
  DAT_028358a0 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_028358a0 + 0x54) = 0x3f800000;
  *(undefined4 *)(DAT_028358a0 + 0x58) = 0x3f800000;
  *(undefined4 *)(DAT_028358a0 + 0x5c) = 0x3f800000;
  *(uint *)(DAT_028358a0 + 0x40) = *(uint *)(DAT_028358a0 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_028358a0 + 0x40) = *(uint *)(DAT_028358a0 + 0x40) & 0xffff7fff | 0x4000;
  *(undefined4 *)(DAT_028358a0 + 0x70) = 0x3f7fbe77;
  *(uint *)(DAT_028358a0 + 0x40) = *(uint *)(DAT_028358a0 + 0x40) & 0xfffffff1 | 1;
  *(uint *)(DAT_028358a0 + 0x44) = *(uint *)(DAT_028358a0 + 0x44) & 0xfffffffd | 1;
  *(uint *)(DAT_028358a0 + 0x40) = *(uint *)(DAT_028358a0 + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_028358a0 + 0x40) = *(uint *)(DAT_028358a0 + 0x40) & 0xfffff7ff | 0x400;
  *(uint *)(DAT_028358a0 + 0x40) = *(uint *)(DAT_028358a0 + 0x40) & 0xfffeffff | 0x20000;
  *(undefined2 *)(DAT_028358a0 + 0x74) = 0;
  *(undefined2 *)(DAT_028358a0 + 0x76) = 0x100;
  FUN_005e4b00(DAT_028358a0);
  DAT_028490d8 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_028490d8 + 0x54) = 0x3f800000;
  *(undefined4 *)(DAT_028490d8 + 0x58) = 0x3f800000;
  *(undefined4 *)(DAT_028490d8 + 0x5c) = 0x3f800000;
  *(uint *)(DAT_028490d8 + 0x40) = *(uint *)(DAT_028490d8 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_028490d8 + 0x40) = *(uint *)(DAT_028490d8 + 0x40) & 0xffff7fff | 0x4000;
  *(undefined4 *)(DAT_028490d8 + 0x70) = 0x3f7fbe77;
  *(uint *)(DAT_028490d8 + 0x40) = *(uint *)(DAT_028490d8 + 0x40) & 0xfffffff2 | 2;
  *(uint *)(DAT_028490d8 + 0x44) = *(uint *)(DAT_028490d8 + 0x44) & 0xfffffffd | 1;
  *(uint *)(DAT_028490d8 + 0x40) = *(uint *)(DAT_028490d8 + 0x40) & 0xfffffdff | 0x100;
  *(uint *)(DAT_028490d8 + 0x40) = *(uint *)(DAT_028490d8 + 0x40) & 0xfffff7ff | 0x400;
  *(uint *)(DAT_028490d8 + 0x40) = *(uint *)(DAT_028490d8 + 0x40) & 0xfffeffff | 0x20000;
  *(undefined2 *)(DAT_028490d8 + 0x74) = 0;
  *(undefined2 *)(DAT_028490d8 + 0x76) = 0x100;
  FUN_005e4b00(DAT_028490d8);
  return;
}

