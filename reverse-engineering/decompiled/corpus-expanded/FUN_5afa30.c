/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afa30; label: FUN_005afa30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005afa30(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x516c) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0x109) != '\0') {
    uVar2 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar2;
    puVar1 = (uint *)((uint)*(byte *)(*(int *)(param_1 + 0x128) + 0x109) * 0x34 + uVar2);
    *(uint **)(param_1 + 0x104) = puVar1;
    *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 8;
    *(uint **)(param_1 + 0x516c) = puVar1;
    *puVar1 = uVar2;
    puVar1[1] = 0;
  }
  return *(undefined4 *)(param_1 + 0x516c);
}

