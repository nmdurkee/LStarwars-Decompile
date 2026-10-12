/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x536dc0; label: FUN_00536dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00536dc0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float10 fVar6;
  float local_4;
  
  fVar1 = 0.0;
  local_4 = 0.0;
  iVar4 = 0;
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     (**(int **)(param_3 + 0xd0) != 0)) {
    if ((*(int *)(param_3 + 0x158) != 0) && (*(int *)(param_3 + 0x15c) != 0)) {
      if (param_6 != 0) {
        *(undefined4 *)(param_3 + 0x188) = 0;
        if (0 < param_5) {
          do {
            if ((DAT_009238b0 == (code *)0x0) ||
               (iVar3 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar4 * 4),param_3 + 0x13f),
               iVar3 == 0)) {
              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"mintime");
              if (iVar3 == 0) {
                iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"maxtime");
                if (iVar3 == 0) {
                  fVar5 = (float10)FUN_00514920(param_3,param_2,*(undefined4 *)(param_4 + iVar4 * 4)
                                               );
                  *(float *)(param_2 + 0x9c) = (float)fVar5;
                }
                else {
                  fVar5 = (float10)FUN_00514920(param_3,param_2,iVar3 + 8);
                  local_4 = (float)fVar5;
                }
              }
              else {
                fVar5 = (float10)FUN_00514920(param_3,param_2,iVar3 + 8);
                fVar1 = (float)fVar5;
              }
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < param_5);
        }
        if (fVar1 < local_4) {
          fVar5 = (float10)FUN_005b9dd0();
          fVar6 = (float10)FUN_005b9dd0();
          *(float *)(param_2 + 0x9c) =
               (float)(fVar6 * (float10)local_4 +
                      (float10)(double)(((float10)1 - fVar5) * (float10)fVar1));
        }
      }
      piVar2 = *(int **)(param_3 + 0x144);
      if ((piVar2 == (int *)0x0) || ((*(byte *)(piVar2 + 0x14) & 8) == 0)) {
        *(undefined4 *)(param_3 + 0x1c0) = 0;
        *(undefined4 *)(param_3 + 0x1c4) = *(undefined4 *)(param_3 + 0x180);
        *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffffc | 4;
      }
      else {
        if (*piVar2 == *(int *)(param_3 + 0xd0)) {
          FUN_0051d130(FUN_0051c6a0);
        }
        FUN_0052fda0(param_3);
      }
      if (0.0 < *(float *)(param_2 + 0x9c)) {
        param_7 = *(float *)(param_2 + 0x9c) - param_7;
        *(float *)(param_2 + 0x9c) = param_7;
        if (param_7 < 0.0 != (param_7 == 0.0)) {
          return 1;
        }
      }
      return 0;
    }
    return 0;
  }
  return 1;
}

