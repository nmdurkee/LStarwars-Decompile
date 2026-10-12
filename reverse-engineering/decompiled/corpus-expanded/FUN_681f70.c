/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x681f70; label: FUN_00681f70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float * FUN_00681f70(int param_1,int param_2,float param_3)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  uint uVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float10 fVar10;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 uStack_40;
  undefined4 uStack_2c;
  undefined4 uStack_18;
  
  iVar1 = param_1;
  if (*(short *)(param_1 + 0x186) <= *(short *)(param_1 + 0x18a)) {
    *(undefined2 *)(param_1 + 0x18a) = 0;
  }
  sVar2 = *(short *)(param_1 + 0x18a);
  if (*(char *)(param_2 + 0x2e) == '\a') {
    iVar3 = (int)sVar2 / 0xc;
    uVar5 = (int)sVar2 % 0xc;
  }
  else {
    uVar5 = (uint)sVar2;
    iVar3 = (int)(uVar5 + ((int)uVar5 >> 0x1f & 0x1fU)) >> 5;
    uVar5 = uVar5 & 0x8000001f;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xffffffe0) + 1;
    }
  }
  pfVar7 = (float *)((uVar5 + 1) * 0x20 + *(int *)(param_1 + 0x100 + iVar3 * 4));
  *(short *)(param_1 + 0x18a) = sVar2 + 1;
  pfVar7[3] = param_3;
  *(float *)(param_1 + 0x324) = param_3;
  pfVar7[7] = 64.0 / *(float *)(param_2 + 0xa4);
  fVar10 = (float10)FUN_005b9d90(&DAT_00810900);
  fVar10 = (float10)FUN_005c0240((float)fVar10);
  local_4c = (float)fVar10;
  local_44 = 0.0;
  local_48 = 0.0;
  FUN_005b9d90(&DAT_00810900);
  uVar4 = FUN_006e6b90();
  fVar10 = (float10)FUN_005b9d90(&DAT_00810900);
  sVar2 = FUN_0064fe20((float)((fVar10 + fVar10) - (float10)1.0));
  FUN_005b3690(&local_4c,&local_4c,(int)sVar2);
  FUN_005b3620(&local_4c,&local_4c,uVar4);
  FUN_0064ff80();
  uStack_40 = *(undefined4 *)(param_2 + 0x58);
  uStack_2c = *(undefined4 *)(param_2 + 0x5c);
  uStack_18 = *(undefined4 *)(param_2 + 0x60);
  FUN_005c11d0(&local_4c,&local_4c,extraout_ECX);
  FUN_005c11d0(&local_4c,&local_4c,param_1 + 0x80);
  *pfVar7 = local_4c;
  pfVar7[1] = local_48;
  pfVar7[2] = local_44;
  fVar10 = (float10)FUN_005b9d90(&DAT_00810900);
  local_4c = (float)((fVar10 + fVar10) * (float10)*(float *)(param_2 + 0x4c) -
                    (float10)*(float *)(param_2 + 0x4c));
  fVar10 = (float10)FUN_005b9d90(&DAT_00810900);
  local_48 = (float)(((fVar10 + fVar10) * (float10)*(float *)(param_2 + 0x50) -
                     (float10)*(float *)(param_2 + 0x50)) + (float10)*(float *)(param_2 + 0x48));
  fVar10 = (float10)FUN_005b9d90(&DAT_00810900);
  local_44 = (float)((fVar10 + fVar10) * (float10)*(float *)(param_2 + 0x54) -
                    (float10)*(float *)(param_2 + 0x54));
  FUN_005c11d0(&local_4c,&local_4c,param_1 + 0x80);
  pfVar7[4] = local_4c;
  pfVar7[5] = local_48;
  pfVar7[6] = local_44;
  if (*(code **)(param_1 + 0x1c4) != (code *)0x0) {
    (**(code **)(param_1 + 0x1c4))(param_1,param_2,pfVar7);
  }
  pfVar8 = (float *)(param_1 + 0x19c);
  param_1 = 0;
  *pfVar7 = *pfVar8 + *pfVar7;
  pfVar7[1] = *(float *)(iVar1 + 0x1a0) + pfVar7[1];
  pfVar7[2] = *(float *)(iVar1 + 0x1a4) + pfVar7[2];
  pfVar7[4] = *(float *)(iVar1 + 0x1a8) + pfVar7[4];
  pfVar7[5] = *(float *)(iVar1 + 0x1ac) + pfVar7[5];
  pfVar7[6] = *(float *)(iVar1 + 0x1b0) + pfVar7[6];
  if ('\0' < *(char *)(param_2 + 0x410)) {
    do {
      if (*(short *)(iVar1 + 0x186) <= *(short *)(iVar1 + 0x18a)) {
        *(undefined2 *)(iVar1 + 0x18a) = 0;
      }
      sVar2 = *(short *)(iVar1 + 0x18a);
      if (*(char *)(param_2 + 0x2e) == '\a') {
        iVar3 = (int)sVar2 / 0xc;
        uVar5 = (int)sVar2 % 0xc;
      }
      else {
        uVar5 = (uint)sVar2;
        iVar3 = (int)(uVar5 + ((int)uVar5 >> 0x1f & 0x1fU)) >> 5;
        uVar5 = uVar5 & 0x8000001f;
        if ((int)uVar5 < 0) {
          uVar5 = (uVar5 - 1 | 0xffffffe0) + 1;
        }
      }
      pfVar6 = (float *)((uVar5 + 1) * 0x20 + *(int *)(iVar1 + 0x100 + iVar3 * 4));
      *(short *)(iVar1 + 0x18a) = sVar2 + 1;
      param_1 = param_1 + 1;
      pfVar8 = pfVar7;
      pfVar9 = pfVar6;
      for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar9 = *pfVar8;
        pfVar8 = pfVar8 + 1;
        pfVar9 = pfVar9 + 1;
      }
      pfVar6[3] = (float)param_1 * *(float *)(param_2 + 0x414) + pfVar6[3];
    } while (param_1 < *(char *)(param_2 + 0x410));
  }
  if (*(int *)(param_2 + 0x2a8) == 0) {
    FUN_00600260(param_2);
  }
  return pfVar7;
}

