/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5b0130; label: FUN_005b0130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005b0130(int param_1)

{
  uint uVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x5104) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0x103) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x5104) = uVar1;
    iVar2 = uVar1 + 0xc;
    *(int *)(param_1 + 0x104) = iVar2;
    **(int **)(param_1 + 0x5104) = iVar2;
    *(int *)(param_1 + 0x104) =
         *(int *)(param_1 + 0x104) + (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0x103) * 0x3c;
    *(uint *)(*(int *)(param_1 + 0x5104) + 8) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0x103);
  }
  return *(undefined4 *)(param_1 + 0x5104);
}

