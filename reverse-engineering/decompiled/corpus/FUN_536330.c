/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x536330; label: FUN_00536330
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00536330(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,float param_7)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_18;
  float local_14;
  undefined1 auStack_c [12];
  
  local_14 = 0.0;
  local_18 = 0.0;
  if (((((param_3 == 0) || (*(int *)(param_3 + 0xd0) == 0)) || (*(int *)(param_3 + 0x158) == 0)) ||
      ((*(int *)(param_3 + 0x15c) == 0 ||
       ((*(uint *)(*(int *)(param_3 + 0xd0) + 0x1f8) & 0x400) == 0)))) ||
     (*(byte *)(param_3 + 0x138) == 0xff)) {
    return 1;
  }
  iVar5 = (uint)*(byte *)(param_3 + 0x138) * 0xa4 + *(int *)(param_1 + 0x18);
  if ((DAT_00923908 == (code *)0x0) || (iVar2 = (*DAT_00923908)(param_1,param_3), iVar2 == 0)) {
    iVar2 = iVar5 + 0x20;
  }
  if (param_6 != 0) {
    *(undefined4 *)(param_3 + 0x180) = 0x3e4ccccd;
    if ((param_5 != 0) && (iVar6 = 0, 0 < param_5)) {
      do {
        if ((DAT_009238b0 == (code *)0x0) ||
           (iVar3 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar6 * 4),param_3 + 0x13f),
           iVar3 == 0)) {
          iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"waittime");
          if (iVar3 == 0) {
            iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"mintime");
            if (iVar3 == 0) {
              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"maxtime");
              if (iVar3 == 0) {
                iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"xz_rangecheck");
                if (iVar3 == 0) {
                  *(undefined1 *)(param_2 + 0x69) = 1;
                }
                else {
                  iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"goalrange");
                  if (iVar3 == 0) {
                    fVar7 = (float10)FUN_00514920(param_3,param_2,
                                                  *(undefined4 *)(param_4 + iVar6 * 4));
                  }
                  else {
                    iVar4 = FUN_004f1ff0("goalrange");
                    fVar7 = (float10)FUN_00514920(param_3,param_2,iVar3 + 1 + iVar4);
                  }
                  *(float *)(param_3 + 0x180) = (float)fVar7;
                }
              }
              else {
                iVar4 = FUN_004f1ff0("maxtime");
                fVar7 = (float10)FUN_00514920(param_3,param_2,iVar3 + 1 + iVar4);
                local_18 = (float)fVar7;
              }
            }
            else {
              iVar4 = FUN_004f1ff0("mintime");
              fVar7 = (float10)FUN_00514920(param_3,param_2,iVar3 + 1 + iVar4);
              local_14 = (float)fVar7;
            }
          }
          else {
            iVar4 = FUN_004f1ff0("waittime");
            fVar7 = (float10)FUN_00514920(param_3,param_2,iVar3 + 1 + iVar4);
            *(float *)(param_2 + 0x9c) = (float)fVar7;
          }
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_5);
    }
    if (*(float *)(param_2 + 0x9c) == 0.0) {
      if (local_18 <= local_14) {
        fVar7 = (float10)0.01;
      }
      else {
        fVar7 = (float10)FUN_005b9dd0();
        fVar7 = fVar7 * ((float10)local_18 - (float10)local_14) + (float10)local_14;
      }
      *(float *)(param_2 + 0x9c) = (float)fVar7;
    }
    FUN_0052fcb0(param_3,iVar2,0,iVar5 + 0x30,1,*(undefined4 *)(param_3 + 0x180));
    *(undefined4 *)(param_2 + 0x78) = 0;
    iVar6 = param_2 + 0x78;
    *(undefined4 *)(param_2 + 0x7c) = 0;
    *(undefined4 *)(param_2 + 0x80) = 0x3f800000;
    FUN_005b3620(iVar6,iVar6,*(undefined4 *)(iVar5 + 0x2c));
    FUN_005b37d0(iVar6,iVar6,iVar2);
    return 0;
  }
  FUN_0052fcb0(param_3,iVar2,0,iVar5 + 0x30,1,*(undefined4 *)(param_3 + 0x180));
  if (*(char *)(param_2 + 0x69) == '\0') {
    fVar7 = (float10)FUN_005b3c50(param_3 + 0x14c,iVar2,auStack_c);
  }
  else {
    fVar7 = (float10)FUN_005b3cf0(param_3 + 0x14c,iVar2,auStack_c);
  }
  fVar1 = param_7 * *(float *)(*(int *)(param_3 + 0xd0) + 0x22c) +
          _DAT_00801c6c + *(float *)(param_3 + 0x180);
  if ((float)fVar7 < fVar1 * fVar1) {
    *(int *)(param_3 + 0x1e4) = param_2 + 0x78;
    if (*(float *)(param_2 + 0x9c) <= 0.0) {
      return 1;
    }
    param_7 = *(float *)(param_2 + 0x9c) - param_7;
    *(float *)(param_2 + 0x9c) = param_7;
    if (param_7 < 0.0) {
      *(undefined4 *)(param_2 + 0x9c) = 0;
      return 0;
    }
  }
  return 0;
}

