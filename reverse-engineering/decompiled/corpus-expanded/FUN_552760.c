/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x552760; label: FUN_00552760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00552760(int *param_1,float param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar2 = (undefined4 *)FUN_005d0420(param_1);
  if (puVar2 != (undefined4 *)0x0) {
    iVar1 = *param_1;
    iVar4 = *(int *)(*(int *)(iVar1 + 0x54) + (uint)*(ushort *)(puVar2 + 0x17) * 4);
    if ((iVar4 != 0) && (param_2 != (float)puVar2[0x16])) {
      iVar3 = FUN_005d0370(param_1);
      FUN_005f3390(iVar4,0,param_2,puVar2);
      puVar2[0x16] = param_2;
      puVar5 = puVar2;
      puVar6 = (undefined4 *)
               ((((int)puVar2 - *(int *)(iVar1 + 0x4c)) / 0x60) * 0x40 + *(int *)(iVar1 + 0x50));
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar2[0xc] = *(float *)(iVar3 + 0x30) + (float)puVar2[0xc];
      puVar2[0xd] = *(float *)(iVar3 + 0x34) + (float)puVar2[0xd];
      puVar2[0xe] = *(float *)(iVar3 + 0x38) + (float)puVar2[0xe];
      FUN_005ea660(param_1);
    }
  }
  return;
}

