/* Ghidra analysis pseudocode, not original source.
 * ev_84e2b506f29363daa42df6f934b4c92b1585b3e8a57a6b6866ee0e5470757f5b
 * Entry: 0x516c70; label: FUN_00516c70
 */

undefined4 FUN_00516c70(int param_1,int param_2,int param_3,undefined4 *param_4,int param_5)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined8 uVar7;
  int local_14;
  int local_10;
  
  if (((param_3 != 0) && (param_2 != 0)) && (*(int *)(param_2 + 4) != 0)) {
    if (*(byte *)(param_3 + 0x138) == 0xff) {
      local_10 = 0;
    }
    else {
      local_10 = (uint)*(byte *)(param_3 + 0x138) * 0xa4 + *(int *)(param_1 + 0x18);
    }
    local_14 = 0;
    if (0 < param_5 + -1) {
      do {
        iVar4 = 0;
        iVar5 = 0x18;
        do {
          iVar3 = FUN_004f8b10(*param_4,*(undefined4 *)(*(int *)(param_2 + 4) + iVar5));
          if (iVar3 == 0) {
            iVar5 = FUN_004f8b10(param_4[1],"default");
            if (iVar5 == 0) {
              if ((local_10 == 0) ||
                 (uVar2 = *(uint *)(local_10 + 0x48), uVar7 = __allshl(),
                 (uVar2 & (uint)uVar7) == 0 &&
                 ((int)uVar2 >> 0x1f & (uint)((ulonglong)uVar7 >> 0x20)) == 0)) {
                fVar6 = (float10)*(float *)(*(int *)(param_2 + 4) + 0x1c + iVar4 * 8);
              }
              else {
                fVar6 = (float10)*(float *)(local_10 + 100 + iVar4 * 4);
              }
            }
            else {
              iVar5 = FUN_004f8a70(param_4[1],&DAT_00760080);
              if (iVar5 == 0) {
                iVar5 = FUN_004f8a70(param_4[1],&DAT_00760078);
                if (iVar5 == 0) {
                  fVar6 = (float10)FUN_00514920(param_3,param_3,param_4[1]);
                }
                else {
                  iVar3 = FUN_004f1ff0(&DAT_00760078);
                  fVar1 = *(float *)(param_2 + 0x14 + iVar4 * 4);
                  fVar6 = (float10)FUN_00514920(param_3,param_3,iVar5 + iVar3);
                  fVar6 = (float10)fVar1 - fVar6;
                }
              }
              else {
                iVar3 = FUN_004f1ff0(&DAT_00760080);
                fVar6 = (float10)FUN_00514920(param_3,param_3,iVar5 + iVar3);
                fVar6 = fVar6 + (float10)*(float *)(param_2 + 0x14 + iVar4 * 4);
              }
            }
            local_14 = local_14 + 1;
            *(float *)(param_2 + 0x14 + iVar4 * 4) = (float)fVar6;
            param_4 = param_4 + 1;
            break;
          }
          iVar5 = iVar5 + 8;
          iVar4 = iVar4 + 1;
        } while (iVar5 < 0x38);
        local_14 = local_14 + 1;
        param_4 = param_4 + 1;
      } while (local_14 < param_5 + -1);
    }
  }
  return 1;
}

