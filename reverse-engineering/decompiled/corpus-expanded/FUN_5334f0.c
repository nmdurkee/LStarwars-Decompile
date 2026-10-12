/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x5334f0; label: FUN_005334f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005334f0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (((*(int *)(DAT_009238e4 + 0x4868) != 0) &&
      (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) != 0)) &&
     (iVar2 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_005256a0,"Share node with..."),
     iVar2 != 0)) {
    uVar3 = FUN_00627a80(0,&DAT_00801cb4,0,1,FUN_00533100,"All paths");
    FUN_00618e10(iVar2,uVar3);
    iVar4 = FUN_004f1440(DAT_009238e4 + 0x4874);
    iVar1 = 1;
    while (iVar4 != 0) {
      iVar5 = iVar1;
      if (*(int *)(DAT_009238e4 + 0x4868) != iVar4) {
        uVar3 = 0;
        if (*(int *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0xb0) != 0) {
          for (iVar5 = FUN_004f1440(iVar4 + 0x18); iVar5 != 0;
              iVar5 = FUN_004f1460(iVar4 + 0x18,iVar5)) {
            if (*(int *)(iVar5 + 0xb0) ==
                *(int *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) + 0xb0)) {
              uVar3 = 1;
              break;
            }
          }
        }
        iVar5 = iVar1 + 1;
        uVar3 = FUN_00627bc0(iVar1,&DAT_00801cb4,uVar3,iVar5,FUN_00533100,iVar4 + 8);
        FUN_00618e10(iVar2,uVar3);
      }
      iVar4 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar4);
      iVar1 = iVar5;
    }
    FUN_006279b0(param_1,iVar2);
  }
  return;
}

