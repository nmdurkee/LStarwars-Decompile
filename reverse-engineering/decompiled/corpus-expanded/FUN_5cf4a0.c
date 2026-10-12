/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5cf4a0; label: FUN_005cf4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005cf4a0(int param_1)

{
  int iVar1;
  int iVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined4 *puVar3;
  undefined8 uVar4;
  
  if (param_1 != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 0x24)) {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x28) + 0x44);
      do {
        uVar4 = FUN_005c1300(iVar1,*puVar3);
        iVar1 = (int)uVar4 + 1;
        puVar3 = (undefined4 *)((int)((ulonglong)uVar4 >> 0x20) + 0x4c);
        param_1 = extraout_ECX;
      } while (iVar1 < *(int *)(extraout_ECX + 0x24));
    }
    iVar1 = *(int *)(param_1 + 0x110);
    if (iVar1 != 0) {
      iVar2 = 0;
      if (0 < *(int *)(iVar1 + 0x6c)) {
        puVar3 = (undefined4 *)(*(int *)(iVar1 + 0x70) + 0xb4);
        do {
          uVar4 = FUN_005c1300(iVar2,*puVar3);
          iVar2 = (int)uVar4 + 1;
          puVar3 = (undefined4 *)((int)((ulonglong)uVar4 >> 0x20) + 0xd0);
        } while (iVar2 < *(int *)(*(int *)(extraout_ECX_00 + 0x110) + 0x6c));
      }
    }
  }
  return;
}

