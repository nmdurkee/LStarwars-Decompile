/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b30f0; label: FUN_006b30f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b30f0(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  FUN_006a3570(param_2,*param_1,0x18);
  FUN_006a3570(param_2,param_1[1],0x18);
  FUN_006a3570(param_2,param_1[2] + -1,0x18);
  FUN_006a3570(param_2,param_1[3] + -1,6);
  FUN_006a3570(param_2,param_1[4],8);
  iVar5 = 0;
  if (0 < (int)param_1[3]) {
    puVar4 = param_1 + 5;
    do {
      uVar2 = *puVar4;
      iVar3 = 0;
      uVar1 = uVar2;
      if (uVar2 == 0) {
LAB_006b3192:
        FUN_006a3570(param_2,uVar2,4);
      }
      else {
        do {
          iVar3 = iVar3 + 1;
          uVar1 = uVar1 >> 1;
        } while (uVar1 != 0);
        if (iVar3 < 4) goto LAB_006b3192;
        FUN_006a3570(param_2,uVar2,3);
        FUN_006a3570(param_2,1,1);
        FUN_006a3570(param_2,(int)*puVar4 >> 3,5);
      }
      iVar3 = 0;
      for (uVar2 = *puVar4; uVar2 != 0; uVar2 = uVar2 >> 1) {
        iVar3 = iVar3 + (uVar2 & 1);
      }
      iVar3 = local_4 + iVar3;
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 1;
      local_4 = iVar3;
    } while (iVar5 < (int)param_1[3]);
  }
  if (0 < iVar3) {
    param_1 = param_1 + 0x45;
    do {
      FUN_006a3570(param_2,*param_1,8);
      param_1 = param_1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}

