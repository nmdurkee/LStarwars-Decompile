/* Ghidra analysis pseudocode, not original source.
 * ev_736d016f9ed2fadbfa7f3950efe555b6c19e61f5838dfc9040f9274543b1106f
 * Entry: 0x515e70; label: FUN_00515e70
 */

undefined4
FUN_00515e70(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            float param_7)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float local_14;
  float local_10;
  float afStack_c [3];
  
  local_10 = 0.0;
  local_14 = 0.0;
  if (param_3 == 0) {
    return 1;
  }
  if (param_6 != 0) {
    iVar2 = 0;
    if (0 < param_5) {
      do {
        if ((DAT_009238b0 == (code *)0x0) ||
           (iVar1 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar2 * 4),param_3 + 0x13f),
           iVar1 == 0)) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"mintime");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"maxtime");
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"faceoffset");
              if (iVar1 == 0) {
                iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar2 * 4),"nearest_opponent");
                if (iVar1 == 0) {
                  *(undefined1 *)(param_2 + 0x68) = 1;
                }
                else {
                  fVar3 = (float10)FUN_00514920(param_3,param_2,*(undefined4 *)(param_4 + iVar2 * 4)
                                               );
                  *(float *)(param_2 + 0x9c) = (float)fVar3;
                }
              }
              else {
                fVar3 = (float10)FUN_00514920(param_3,param_2,iVar1 + 0xb);
                *(float *)(param_2 + 0x70) = (float)fVar3;
              }
            }
            else {
              fVar3 = (float10)FUN_00514920(param_3,param_2,iVar1 + 8);
              local_14 = (float)fVar3;
            }
          }
          else {
            fVar3 = (float10)FUN_00514920(param_3,param_2,iVar1 + 8);
            local_10 = (float)fVar3;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
    }
    if ((*(float *)(param_2 + 0x9c) == 0.0) && (local_10 < local_14)) {
      fVar3 = (float10)FUN_005b9dd0();
      *(float *)(param_2 + 0x9c) =
           (float)(fVar3 * ((float10)local_14 - (float10)local_10) + (float10)local_10);
    }
  }
  if (*(char *)(param_2 + 0x68) == '\0') {
    iVar2 = *(int *)(param_3 + 0xe4);
  }
  else {
    iVar2 = *(int *)(param_3 + 0xd4);
  }
  if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
    if (*(float *)(param_2 + 0x70) == 0.0) {
      *(int *)(param_3 + 0x1e4) = iVar2 + 0x5c;
    }
    else {
      afStack_c[0] = *(float *)(iVar2 + 100) - *(float *)(*(int *)(param_3 + 0xd0) + 100);
      afStack_c[2] = *(float *)(*(int *)(param_3 + 0xd0) + 0x5c) - *(float *)(iVar2 + 0x5c);
      afStack_c[1] = 0.0;
      FUN_005b3b30(afStack_c,afStack_c);
      *(float *)(param_2 + 0x78) =
           *(float *)(param_2 + 0x70) * afStack_c[0] + *(float *)(iVar2 + 0x5c);
      *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(iVar2 + 0x60);
      *(float *)(param_2 + 0x80) =
           *(float *)(param_2 + 0x70) * afStack_c[2] + *(float *)(iVar2 + 100);
      *(float **)(param_3 + 0x1e4) = (float *)(param_2 + 0x78);
    }
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

