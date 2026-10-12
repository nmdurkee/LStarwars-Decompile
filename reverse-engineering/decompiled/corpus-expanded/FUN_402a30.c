/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x402a30; label: FUN_00402a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00402a30(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x5098) = 0;
  *(undefined4 *)(param_1 + 0x509c) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xf6) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x5098) = uVar1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf6) * 0x74 + uVar1;
  }
  return uVar1;
}

