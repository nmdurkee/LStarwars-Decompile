/* Ghidra pseudocode, not original source.
 * ev_172a74a519a068fcec2d928153122b73658882ad95b615edd404be76597302bc
 * Entry: 0x5b04f0; label: FUN_005b04f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b04f0(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x50f8) = 0;
  *(undefined4 *)(param_1 + 0x50fc) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xe9) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x50f8) = uVar1;
    *(uint *)(param_1 + 0x104) = uVar1 + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xe9) * 0x1c;
    return *(undefined4 *)(param_1 + 0x50f8);
  }
  return 0;
}

