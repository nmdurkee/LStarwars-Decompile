/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61eed0; label: thunk_FUN_0061e8b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 thunk_FUN_0061e8b0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x14);
  bVar4 = false;
  if ((((byte)DAT_02912ec4 & 0x40) != 0) && (uVar3 = *(uint *)(iVar2 + 0x4c), (uVar3 & 10) == 0)) {
    if ((uVar3 & 1) == 0) {
      iVar5 = FUN_0061e770();
      if ((iVar5 != 0) && (*(code **)(iVar2 + 0x70) != (code *)0x0)) {
        (**(code **)(iVar2 + 0x70))(uVar1,iVar2,0);
      }
      iVar5 = FUN_0061e6f0();
      if (iVar5 != 0) {
        *(uint *)(iVar2 + 0x4c) = *(uint *)(iVar2 + 0x4c) | 6;
      }
      iVar5 = FUN_0061e7e0();
      if ((iVar5 != 0) && ((*(byte *)(iVar2 + 0x4c) & 1) == 0)) {
        if (*(code **)(iVar2 + 0x70) != (code *)0x0) {
          (**(code **)(iVar2 + 0x70))(uVar1,iVar2,0);
        }
        FUN_006d69a0();
        *(uint *)(iVar2 + 0x4c) = *(uint *)(iVar2 + 0x4c) | 1;
        FUN_004f1f10(&DAT_02900a70,*(undefined4 *)(iVar2 + 100));
        FUN_004f1f10(&DAT_02900b70,*(undefined4 *)(iVar2 + 100));
        DAT_0080f59c = FUN_004f1ff0(*(undefined4 *)(iVar2 + 100));
      }
      iVar5 = FUN_0061e850();
      if ((((iVar5 == 0) && (DAT_02912e8c == 0)) || (*(code **)(iVar2 + 0x74) == (code *)0x0)) ||
         ((**(code **)(iVar2 + 0x74))(uVar1,iVar2,0), (*(byte *)(iVar2 + 0x4c) & 0x20) == 0))
      goto LAB_0061e9b6;
    }
    else {
      iVar5 = FUN_0061e7e0();
      if (iVar5 == 0) goto LAB_0061e9b6;
      *(uint *)(iVar2 + 0x4c) = uVar3 | 1;
      DAT_0080f59c = 0xffffffff;
    }
    bVar4 = true;
  }
LAB_0061e9b6:
  if (((*(byte *)(iVar2 + 0x4c) & 0xb) == 0) && (!bVar4)) {
    return 0;
  }
  return 1;
}

