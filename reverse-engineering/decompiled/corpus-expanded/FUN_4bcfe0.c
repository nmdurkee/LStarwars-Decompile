/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bcfe0; label: FUN_004bcfe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004bcfe0(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x50b0) = 0;
  *(undefined4 *)(param_1 + 0x50b4) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xfa) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x50b0) = uVar1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xfa) * 0xc0 + uVar1;
  }
  return uVar1;
}

