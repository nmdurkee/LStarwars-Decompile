/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d91b0; label: FUN_005d91b0
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

