/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b1c30; label: FUN_006b1c30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b1c30(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  if (*param_2 < 2) {
    FUN_006a3570(param_3,0,1);
  }
  else {
    FUN_006a3570(param_3,1,1);
    FUN_006a3570(param_3,*param_2 + -1,4);
  }
  if (param_2[0x121] < 1) {
    FUN_006a3570(param_3,0,1);
  }
  else {
    FUN_006a3570(param_3,1,1);
    FUN_006a3570(param_3,param_2[0x121] + -1,8);
    iVar3 = 0;
    if (0 < param_2[0x121]) {
      piVar4 = param_2 + 0x222;
      do {
        iVar1 = 0;
        if (*(int *)(param_1 + 4) != 0) {
          for (uVar2 = *(int *)(param_1 + 4) - 1; uVar2 != 0; uVar2 = uVar2 >> 1) {
            iVar1 = iVar1 + 1;
          }
        }
        FUN_006a3570(param_3,piVar4[-0x100],iVar1);
        iVar1 = 0;
        if (*(int *)(param_1 + 4) != 0) {
          for (uVar2 = *(int *)(param_1 + 4) - 1; uVar2 != 0; uVar2 = uVar2 >> 1) {
            iVar1 = iVar1 + 1;
          }
        }
        FUN_006a3570(param_3,*piVar4,iVar1);
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar3 < param_2[0x121]);
    }
  }
  FUN_006a3570(param_3,0,2);
  if ((1 < *param_2) && (iVar3 = 0, piVar4 = param_2, 0 < *(int *)(param_1 + 4))) {
    do {
      FUN_006a3570(param_3,piVar4[1],4);
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  if (0 < *param_2) {
    piVar4 = param_2 + 0x111;
    iVar3 = 0;
    do {
      FUN_006a3570(param_3,0,8);
      FUN_006a3570(param_3,piVar4[-0x10],8);
      FUN_006a3570(param_3,*piVar4,8);
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < *param_2);
  }
  return;
}

