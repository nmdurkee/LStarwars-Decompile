/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x481bb0; label: FUN_00481bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00481bb0(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x50a8) = 0;
  *(undefined4 *)(param_1 + 0x50ac) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xf9) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x50a8) = uVar1;
    *(uint *)(param_1 + 0x104) = uVar1 + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf9) * 0x38;
    return *(undefined4 *)(param_1 + 0x50a8);
  }
  return 0;
}

