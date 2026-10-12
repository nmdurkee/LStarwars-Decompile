/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d91b0; label: FUN_005d91b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d91b0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar1 = (undefined4 *)FUN_005d9140();
  puVar4 = param_1;
  puVar6 = puVar1;
  for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar2 = 0;
  if (0 < *(short *)(param_1 + 0x27)) {
    iVar5 = 0;
    do {
      iVar3 = param_1[0x20] + iVar5;
      puVar4 = (undefined4 *)(puVar1[0x20] + iVar5);
      *puVar4 = *(undefined4 *)(param_1[0x20] + iVar5);
      puVar4[1] = *(undefined4 *)(iVar3 + 4);
      puVar4[2] = *(undefined4 *)(iVar3 + 8);
      puVar4[3] = *(undefined4 *)(iVar3 + 0xc);
      iVar2 = iVar2 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iVar2 < *(short *)(param_1 + 0x27));
  }
  return;
}

