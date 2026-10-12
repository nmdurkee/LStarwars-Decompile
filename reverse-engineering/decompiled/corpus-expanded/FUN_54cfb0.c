/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54cfb0; label: FUN_0054cfb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0054cfb0(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x5080) = 0;
  *(undefined4 *)(param_1 + 0x5084) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xee) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x5080) = uVar1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xee) * 0xf8 + uVar1;
  }
  return uVar1;
}

