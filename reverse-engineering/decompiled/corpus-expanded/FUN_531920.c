/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x531920; label: FUN_00531920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00531920(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_00522450,"Select Locator Set");
  if (iVar1 != 0) {
    uVar2 = FUN_00627a80(0,&DAT_00801cb4,0,0,FUN_00531800,&DAT_007600a0);
    FUN_00618e10(iVar1,uVar2);
    iVar4 = 1;
    for (iVar3 = FUN_004f1440(DAT_009238e4 + 0x41200); iVar3 != 0;
        iVar3 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar3)) {
      uVar2 = FUN_00627a80(iVar4,&DAT_00801cb4,0,0,FUN_00531800,iVar3 + 8);
      FUN_00618e10(iVar1,uVar2);
      iVar4 = iVar4 + 1;
    }
    FUN_006279b0(param_1,iVar1);
  }
  return;
}

