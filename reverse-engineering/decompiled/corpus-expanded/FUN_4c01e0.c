/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4c01e0; label: FUN_004c01e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004c01e0(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x5090) = 0;
  *(undefined4 *)(param_1 + 0x5094) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xf1) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x5090) = uVar1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf1) * 0x54 + uVar1;
  }
  return uVar1;
}

