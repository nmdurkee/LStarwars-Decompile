/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d07a0; label: FUN_004d07a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004d07a0(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x5058) = 0;
  *(undefined4 *)(param_1 + 0x505c) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xe8) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x5058) = uVar1;
    *(uint *)(param_1 + 0x104) = uVar1 + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xe8) * 0x48;
    return *(undefined4 *)(param_1 + 0x5058);
  }
  return 0;
}

