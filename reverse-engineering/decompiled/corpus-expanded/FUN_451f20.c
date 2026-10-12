/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x451f20; label: FUN_00451f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00451f20(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_8;
  float local_4;
  
  local_4 = 0.0;
  local_8 = 0.0;
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar2 = *piVar1;
    if (param_6 != 0) {
      iVar4 = 0;
      if (0 < param_5) {
        do {
          iVar3 = FUN_004f8b10("look_at_camera",*(undefined4 *)(param_4 + iVar4 * 4));
          if (iVar3 == 0) {
            *(undefined1 *)(param_2 + 0x68) = 1;
          }
          else {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"mintime");
            if (iVar3 == 0) {
              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"maxtime");
              if (iVar3 == 0) {
                fVar5 = (float10)FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar4 * 4));
                *(float *)(param_2 + 0x9c) = (float)fVar5;
              }
              else {
                fVar5 = (float10)FUN_00514920(param_3,param_2,iVar3 + 8);
                local_8 = (float)fVar5;
              }
            }
            else {
              fVar5 = (float10)FUN_00514920(param_3,param_2,iVar3 + 8);
              local_4 = (float)fVar5;
            }
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_5);
      }
      if ((*(float *)(param_2 + 0x9c) == 0.0) && (local_4 < local_8)) {
        fVar5 = (float10)FUN_005b9dd0();
        *(float *)(param_2 + 0x9c) =
             (float)(fVar5 * ((float10)local_8 - (float10)local_4) + (float10)local_4);
      }
    }
    iVar4 = FUN_005d6170();
    if ((iVar4 != 0) &&
       (*(int *)(param_3 + 0x1e4) = iVar4 + 0x30, *(char *)(param_2 + 0x68) != '\0')) {
      FUN_0058bee0(iVar2,*(undefined4 *)(iVar2 + 0x4ac),6,0x3f800000,0,0);
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
  return 1;
}

