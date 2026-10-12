/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d5cd0; label: FUN_004d5cd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004d5cd0(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x4688) = 0;
  *(undefined4 *)(param_1 + 0x468c) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xed) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x4688) = uVar1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xed) * 0x7c + uVar1;
  }
  return uVar1;
}

