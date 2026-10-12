/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x515890; label: FUN_00515890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00515890(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float local_10;
  float local_c;
  
  local_10 = 0.0;
  local_c = 0.0;
  fVar1 = 0.0;
  if (param_6 == 0) {
    return 1;
  }
  iVar3 = 0;
  if (0 < param_5) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"mintime");
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"maxtime");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),&DAT_00757ca8);
          if (iVar2 != 0) {
            fVar4 = (float10)FUN_00514920(param_3,param_2,iVar2 + 5);
            fVar1 = (float)fVar4;
          }
        }
        else {
          fVar4 = (float10)FUN_00514920(param_3,param_2,iVar2 + 8);
          local_c = (float)fVar4;
        }
      }
      else {
        fVar4 = (float10)FUN_00514920(param_3,param_2,iVar2 + 8);
        local_10 = (float)fVar4;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_5);
    if ((local_10 != 0.0) || (local_c != 0.0)) {
      fVar4 = (float10)FUN_005b9dd0();
      fVar5 = (float10)FUN_005b9dd0();
      *(float *)(param_2 + 0x24) =
           (float)(fVar5 * (float10)local_c +
                  (float10)(double)(((float10)1 - fVar4) * (float10)local_10));
      return 1;
    }
  }
  *(float *)(param_2 + 0x24) = fVar1;
  return 1;
}

