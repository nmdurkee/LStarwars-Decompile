/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x515ca0; label: FUN_00515ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00515ca0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,float param_7)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float local_8;
  float local_4;
  
  local_4 = 0.0;
  local_8 = 0.0;
  if (param_3 == 0) {
    return 1;
  }
  if (param_6 != 0) {
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"mintime");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"maxtime");
          if (iVar1 == 0) {
            fVar3 = (float10)FUN_00514920(param_3,param_2,*(undefined4 *)(param_4 + iVar2 * 4));
            *(float *)(param_2 + 0x9c) = (float)fVar3;
          }
          else {
            fVar3 = (float10)FUN_00514920(param_3,param_2,iVar1 + 8);
            local_8 = (float)fVar3;
          }
        }
        else {
          fVar3 = (float10)FUN_00514920(param_3,param_2,iVar1 + 8);
          local_4 = (float)fVar3;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
    }
    if ((*(float *)(param_2 + 0x9c) == 0.0) && (local_4 < local_8)) {
      fVar3 = (float10)FUN_005b9dd0();
      *(float *)(param_2 + 0x9c) =
           (float)(fVar3 * ((float10)local_8 - (float10)local_4) + (float10)local_4);
    }
  }
  if (*(int *)(param_1 + 0x138c) != 0) {
    *(int *)(param_3 + 0x1e4) = *(int *)(param_1 + 0x138c) + 0x5c;
  }
  if (0.0 < *(float *)(param_2 + 0x9c)) {
    param_7 = *(float *)(param_2 + 0x9c) - param_7;
    *(float *)(param_2 + 0x9c) = param_7;
    if (param_7 < 0.0 != (param_7 == 0.0)) {
      *(undefined4 *)(param_2 + 0x9c) = 0;
      return 1;
    }
  }
  return 0;
}

