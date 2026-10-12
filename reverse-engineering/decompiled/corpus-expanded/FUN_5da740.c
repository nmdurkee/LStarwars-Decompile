/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5da740; label: FUN_005da740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005da740(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar1 = FUN_004fb750(param_1);
  *(undefined2 *)(param_2 + 0x48) = uVar1;
  iVar2 = FUN_004fb750(param_1);
  iVar3 = FUN_004f0360(param_1);
  *(int *)(param_2 + 0x4c) = iVar3;
  if (iVar2 == 0) {
    if ((iVar3 != 0) && (iVar2 = 0, 0 < *(int *)(param_2 + 0x1c))) {
      iVar4 = 0;
      do {
        if (*(int *)(iVar4 + 0x48 + *(int *)(param_2 + 0x20)) != 0) {
          *(int *)(iVar4 + 0x48 + *(int *)(param_2 + 0x20)) = iVar3;
          puVar7 = (undefined4 *)(iVar4 + *(int *)(param_2 + 0x20));
          puVar8 = *(undefined4 **)(iVar4 + 0x48 + *(int *)(param_2 + 0x20));
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          iVar3 = iVar3 + 0x60;
          *(short *)(*(int *)(iVar4 + 0x48 + *(int *)(param_2 + 0x20)) + 0x5e) = (short)iVar2;
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x50;
      } while (iVar2 < *(int *)(param_2 + 0x1c));
    }
  }
  else if ((iVar3 != 0) && (iVar2 = 0, 0 < *(short *)(param_2 + 0x48))) {
    iVar3 = 0;
    do {
      puVar8 = (undefined4 *)(*(int *)(param_2 + 0x4c) + iVar3);
      *(undefined4 **)
       ((uint)*(ushort *)(*(int *)(param_2 + 0x4c) + 0x5e + iVar3) * 0x50 + 0x48 +
       *(int *)(param_2 + 0x20)) = puVar8;
      puVar7 = (undefined4 *)
               ((uint)*(ushort *)((int)puVar8 + 0x5e) * 0x50 + *(int *)(param_2 + 0x20));
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x60;
    } while (iVar2 < *(short *)(param_2 + 0x48));
  }
  if (*(short *)(param_2 + 0x48) != 0) {
    uVar5 = FUN_00601de0((int)*(short *)(param_2 + 0x48) << 6,0x10);
    *(undefined4 *)(param_2 + 0x50) = uVar5;
  }
  return;
}

