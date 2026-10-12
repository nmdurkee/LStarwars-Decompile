/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56ce30; label: FUN_0056ce30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0056ce30(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x50a0) = 0;
  *(undefined4 *)(param_1 + 0x50a4) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xf8) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x50a0) = uVar1;
    *(uint *)(param_1 + 0x104) = uVar1 + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf8) * 0x24;
    return *(undefined4 *)(param_1 + 0x50a0);
  }
  return 0;
}

