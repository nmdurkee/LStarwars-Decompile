/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5da640; label: FUN_005da640
 */

void FUN_005da640(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  iVar2 = *(int *)(param_2 + 0x110);
  uVar3 = FUN_004fb750(param_1);
  *(undefined2 *)(param_2 + 0x48) = uVar3;
  FUN_004fb750(param_1);
  iVar4 = FUN_004f0360(param_1);
  *(int *)(param_2 + 0x4c) = iVar4;
  if ((iVar4 != 0) && (iVar5 = 0, 0 < *(int *)(iVar2 + 0x6c))) {
    iVar8 = 0;
    do {
      piVar1 = (int *)(*(int *)(iVar2 + 0x70) + 0xc4 + iVar8);
      iVar7 = *piVar1;
      if (iVar7 == -1) {
        *piVar1 = 0;
      }
      else {
        *(int *)(*(int *)(iVar2 + 0x70) + 0xc4 + iVar8) = iVar7 * 0x60 + iVar4;
        puVar9 = (undefined4 *)(*(int *)(iVar2 + 0x70) + iVar8);
        puVar10 = *(undefined4 **)(*(int *)(iVar2 + 0x70) + 0xc4 + iVar8);
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        *(short *)(*(int *)(*(int *)(iVar2 + 0x70) + 0xc4 + iVar8) + 0x5e) = (short)iVar5;
      }
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + 0xd0;
    } while (iVar5 < *(int *)(iVar2 + 0x6c));
  }
  if (*(short *)(param_2 + 0x48) != 0) {
    uVar6 = FUN_00601de0((int)*(short *)(param_2 + 0x48) << 6,0x10);
    *(undefined4 *)(param_2 + 0x50) = uVar6;
  }
  return;
}

