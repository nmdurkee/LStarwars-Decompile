/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5af560; label: FUN_005af560
 */

undefined4 FUN_005af560(int param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
  *(uint *)(param_1 + 0x5110) = uVar1;
  *(uint *)(param_1 + 0x104) = uVar1 + 0x38;
  _memset(*(void **)(param_1 + 0x5110),0,0x38);
  **(undefined4 **)(param_1 + 0x5110) = 0xc0000000;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 4) = 0xc1200000;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 8) = 0xc0000000;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0xc) = 0x3e99999a;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x10) = 0x40000000;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x14) = 0x3f000000;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x18) = 0x3a03126f;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x1c) = 0x3c23d70a;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x20) = 0x41b00000;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x24) = 0x3f000000;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x28) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x2c) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x30) = 0xc0000000;
  *(undefined4 *)(*(int *)(param_1 + 0x5110) + 0x34) = 0;
  return *(undefined4 *)(param_1 + 0x5110);
}

