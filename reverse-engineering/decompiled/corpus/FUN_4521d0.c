/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x4521d0; label: FUN_004521d0
 */

undefined4
FUN_004521d0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_c;
  float local_8;
  short local_4;
  
  local_8 = 0.0;
  local_c = 0.0;
  if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    iVar3 = *piVar2;
    if (param_6 != 0) {
      iVar5 = 0;
      if (0 < param_5) {
        do {
          iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"mintime=");
          if (iVar4 == 0) {
            iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"maxtime=");
            if (iVar4 == 0) {
              iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"time=");
              if (iVar4 == 0) {
                iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"rot_rate=");
                if (iVar4 != 0) {
                  FUN_00514920(param_3,param_2,iVar4 + 9);
                  iVar4 = FUN_006e6b90();
                  *(float *)(param_2 + 0x70) = (float)iVar4;
                }
              }
              else {
                fVar6 = (float10)FUN_00514920(param_3,param_2,iVar4 + 5);
                *(float *)(param_2 + 0x9c) = (float)fVar6;
              }
            }
            else {
              fVar6 = (float10)FUN_00514920(param_3,param_2,iVar4 + 8);
              local_c = (float)fVar6;
            }
          }
          else {
            fVar6 = (float10)FUN_00514920(param_3,param_2,iVar4 + 8);
            local_8 = (float)fVar6;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < param_5);
      }
      if (local_c != local_8) {
        fVar6 = (float10)FUN_005b9dd0();
        *(float *)(param_2 + 0x9c) =
             (float)(fVar6 * ((float10)local_c - (float10)local_8) + (float10)local_8);
      }
      *(undefined2 *)(param_2 + 0x6a) = *(undefined2 *)(iVar3 + 0x27a);
    }
    puVar1 = (undefined4 *)(param_2 + 0x78);
    local_4 = (short)(int)ROUND(*(float *)(param_2 + 0x70) * param_7);
    *(short *)(param_2 + 0x6a) = *(short *)(param_2 + 0x6a) + local_4;
    *puVar1 = 0;
    *(undefined4 *)(param_2 + 0x7c) = 0;
    *(undefined4 *)(param_2 + 0x80) = 0x3f800000;
    FUN_005b3620(puVar1,puVar1,*(undefined2 *)(param_2 + 0x6a));
    FUN_005b37d0(puVar1,puVar1,iVar3 + 0x80);
    *(undefined4 **)(param_3 + 0x1e4) = puVar1;
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

