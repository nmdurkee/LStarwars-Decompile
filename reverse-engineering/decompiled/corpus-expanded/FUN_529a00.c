/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x529a00; label: FUN_00529a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00529a00(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  
  if (((DAT_00923894 != (code *)0x0) && (DAT_0092389c != (code *)0x0)) &&
     (iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_00528d00,"Select AI Type"),
     iVar1 != 0)) {
    iVar4 = 0;
    iVar2 = (*DAT_00923894)(0);
    while (iVar2 != -1) {
      bVar5 = DAT_00921f34 == iVar2;
      uVar3 = (*DAT_0092389c)(iVar2);
      uVar3 = FUN_00627b80(iVar2,&DAT_00801cb4,bVar5,1,FUN_005298c0,uVar3);
      FUN_00618e10(iVar1,uVar3);
      if (bVar5) {
        *(undefined4 *)(iVar1 + 8) = DAT_02900c84;
      }
      FUN_006279b0(param_1,iVar1);
      iVar4 = iVar4 + 1;
      iVar2 = (*DAT_00923894)(iVar4);
    }
  }
  return;
}

