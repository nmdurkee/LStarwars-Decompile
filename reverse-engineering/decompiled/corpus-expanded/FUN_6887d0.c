/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x6887d0; label: FUN_006887d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006887d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  DAT_029620f8 = FUN_00619250(0x46,0x46,0xfa,200,DAT_02912e80,FUN_0065adc0,"Highlighted Sound Type")
  ;
  if (DAT_029620f8 != 0) {
    iVar3 = 0;
    if (0 < DAT_02947b38) {
      do {
        iVar1 = (&DAT_02930018)[DAT_02962010 * 0xb5 + DAT_02920aa8];
        uVar2 = FUN_00627b80(iVar3,&local_10,iVar1 == iVar3,1,&LAB_00688630,0);
        FUN_00618e10(DAT_029620f8,uVar2);
        if (iVar1 == iVar3) {
          *(undefined4 *)(DAT_029620f8 + 8) = DAT_02900c84;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_02947b38);
    }
    FUN_006279b0(param_1,DAT_029620f8);
    *(int *)(DAT_029620f8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029620f8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

