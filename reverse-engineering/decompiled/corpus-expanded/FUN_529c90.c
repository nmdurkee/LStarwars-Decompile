/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x529c90; label: FUN_00529c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00529c90(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_00528d00,"Select Script");
  if (iVar1 != 0) {
    iVar5 = 0;
    do {
      iVar6 = 0;
      iVar2 = FUN_00513160(*(undefined4 *)(DAT_009238e4 + 100),iVar5);
      if ((iVar2 != 0) && (iVar3 = FUN_004f8b10(iVar2,"Level"), iVar3 != 0)) {
        if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
           (iVar3 = FUN_004f8b10(*(int *)(DAT_009238e4 + 0x371b0) + 0x18,iVar2), iVar3 == 0)) {
          iVar6 = 1;
        }
        uVar4 = FUN_00627b80(iVar5,&DAT_00801cb4,iVar6,1,FUN_00529bb0,iVar2);
        FUN_00618e10(iVar1,uVar4);
        if (iVar6 != 0) {
          *(undefined4 *)(iVar1 + 8) = DAT_02900c84;
        }
        FUN_006279b0(param_1,iVar1);
      }
      iVar5 = iVar5 + 1;
    } while (iVar2 != 0);
  }
  return;
}

