/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d3e0; label: FUN_0056d3e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0056d3e0(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x4690) = 0;
  *(undefined4 *)(param_1 + 0x4694) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xfb) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x4690) = uVar1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xfb) * 0x40 + uVar1;
  }
  return uVar1;
}

