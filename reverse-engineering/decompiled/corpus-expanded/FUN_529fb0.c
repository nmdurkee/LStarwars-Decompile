/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x529fb0; label: FUN_00529fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00529fb0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_00528d00,"Select Locator");
  if (iVar1 != 0) {
    uVar2 = FUN_00627b80(0xffffffff,&DAT_00801cb4,
                         *(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x84) == 0,1,FUN_00529f20,
                         &DAT_007600a0);
    FUN_00618e10(iVar1,uVar2);
    iVar4 = 0;
    for (iVar3 = FUN_004f1440(DAT_009238e4 + 0x3cbd8); iVar3 != 0;
        iVar3 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar3)) {
      if (*(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x3c) == *(int *)(iVar3 + 0x2c)) {
        bVar5 = *(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x84) == iVar3;
        uVar2 = FUN_00627b80(iVar4,&DAT_00801cb4,bVar5,1,FUN_00529f20,iVar3 + 8);
        FUN_00618e10(iVar1,uVar2);
        if (bVar5) {
          *(undefined4 *)(iVar1 + 8) = DAT_02900c84;
        }
        FUN_006279b0(param_1,iVar1);
        iVar4 = iVar4 + 1;
      }
    }
  }
  return;
}

