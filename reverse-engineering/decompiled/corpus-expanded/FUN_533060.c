/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x533060; label: FUN_00533060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00533060(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_005256a0,"Select Path");
  if (iVar1 != 0) {
    for (iVar2 = FUN_004f1440(DAT_009238e4 + 0x4874); iVar2 != 0;
        iVar2 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar2)) {
      uVar3 = FUN_00627a80(iVar4,&DAT_00801cb4,0,0,FUN_00532e50,iVar2 + 8);
      FUN_00618e10(iVar1,uVar3);
      iVar4 = iVar4 + 1;
    }
    FUN_006279b0(param_1,iVar1);
  }
  return;
}

