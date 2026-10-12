/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x543160; label: FUN_00543160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00543160(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7,float *param_8,float *param_9,
            float *param_10,float *param_11,float *param_12,float *param_13,float *param_14)

{
  float fVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  float10 fVar10;
  float local_d4 [2];
  int local_cc;
  undefined4 local_c8 [14];
  undefined1 local_90 [12];
  undefined1 local_84 [12];
  undefined1 local_78 [4];
  undefined1 local_74 [4];
  undefined1 local_70 [4];
  undefined1 local_6c [4];
  undefined1 local_68 [4];
  undefined4 local_64 [14];
  undefined1 local_2c [12];
  undefined1 local_20 [12];
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  FUN_00541bc0(param_1,param_4,(int)*(char *)((int)param_7 + 1),(int)*(short *)((int)param_7 + 2),
               param_7);
  if (1 < DAT_029838e4) {
    local_cc = (int)DAT_02983939;
    iVar7 = (int)DAT_02983901;
    iVar6 = *param_1;
    puVar5 = param_7;
    puVar2 = local_64;
    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
    puVar5 = param_7;
    puVar2 = local_c8;
    for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
    iVar4 = iVar7 * 0x13c + iVar6;
    iVar6 = local_cc * 0x13c + iVar6;
    iVar9 = 0;
    if (0 < *(int *)(iVar4 + 0x110)) {
      pcVar8 = (char *)(iVar4 + 0x101);
      do {
        if ((uint)(byte)pcVar8[-1] == (int)DAT_02983939) {
          if (*pcVar8 == '\0') {
            fVar10 = (float10)FUN_00540670(param_4,&DAT_02983900,0,param_1);
          }
          else if (*pcVar8 == '\x01') {
            fVar10 = (float10)FUN_005407d0(param_4,&DAT_02983900,0,param_1);
          }
          else {
            fVar10 = (float10)0;
          }
          local_d4[0] = (float)fVar10;
        }
        iVar9 = iVar9 + 1;
        pcVar8 = pcVar8 + 2;
      } while (iVar9 < *(int *)(iVar4 + 0x110));
    }
    iVar4 = 0;
    if (0 < *(int *)(iVar6 + 0x110)) {
      pcVar8 = (char *)(iVar6 + 0x101);
      do {
        if ((uint)(byte)pcVar8[-1] == (int)DAT_02983901) {
          if (*pcVar8 == '\0') {
            fVar10 = (float10)FUN_00540670(param_4,&DAT_02983938,0,param_1);
          }
          else if (*pcVar8 == '\x01') {
            fVar10 = (float10)FUN_005407d0(param_4,&DAT_02983938,0,param_1);
          }
          else {
            fVar10 = (float10)0;
          }
          local_d4[1] = (float)fVar10;
        }
        iVar4 = iVar4 + 1;
        pcVar8 = pcVar8 + 2;
      } while (iVar4 < *(int *)(iVar6 + 0x110));
    }
    if ((iVar9 != 0) && (iVar4 != 0)) {
      FUN_00540b10(param_1,iVar7);
      FUN_00541e60(param_1,param_2,param_3,param_4,param_5,param_6,local_c8,local_90,local_84,
                   local_78,local_74,local_70,local_6c,local_68);
      FUN_00540c40(param_1);
      FUN_00540b10(param_1,local_cc);
      FUN_00541e60(param_1,param_2,param_3,param_4,param_5,param_6,local_64,local_2c,local_20,
                   local_14,local_10,local_c,local_8,local_4);
      FUN_00540c40(param_1);
      fVar1 = local_d4[DAT_00801e3c != iVar7] / (local_d4[1] + local_d4[0]);
      if (0.5 <= fVar1) {
        fVar1 = (1.0 - fVar1) * (1.0 - fVar1);
        fVar1 = 1.0 - (fVar1 + fVar1);
      }
      else {
        fVar1 = fVar1 * fVar1 + fVar1 * fVar1;
      }
      if ((DAT_00801e3c != iVar7) == 0) {
        puVar2 = local_64;
        puVar5 = local_c8;
      }
      else {
        puVar2 = local_c8;
        puVar5 = local_64;
      }
      *param_8 = (float)puVar2[0xe] + fVar1 * ((float)puVar5[0xe] - (float)puVar2[0xe]);
      param_8[1] = ((float)puVar5[0xf] - (float)puVar2[0xf]) * fVar1 + (float)puVar2[0xf];
      param_8[2] = ((float)puVar5[0x10] - (float)puVar2[0x10]) * fVar1 + (float)puVar2[0x10];
      *param_9 = ((float)puVar5[0x11] - (float)puVar2[0x11]) * fVar1 + (float)puVar2[0x11];
      param_9[1] = ((float)puVar5[0x12] - (float)puVar2[0x12]) * fVar1 + (float)puVar2[0x12];
      param_9[2] = ((float)puVar5[0x13] - (float)puVar2[0x13]) * fVar1 + (float)puVar2[0x13];
      *param_10 = ((float)puVar5[0x14] - (float)puVar2[0x14]) * fVar1 + (float)puVar2[0x14];
      *param_11 = ((float)puVar5[0x15] - (float)puVar2[0x15]) * fVar1 + (float)puVar2[0x15];
      *param_12 = ((float)puVar5[0x16] - (float)puVar2[0x16]) * fVar1 + (float)puVar2[0x16];
      *param_13 = ((float)puVar5[0x17] - (float)puVar2[0x17]) * fVar1 + (float)puVar2[0x17];
      if (param_14 == (float *)0x0) {
        return 1;
      }
      *param_14 = ((float)puVar5[0x18] - (float)puVar2[0x18]) * fVar1 + (float)puVar2[0x18];
      return 1;
    }
  }
  if (DAT_029838e4 < 1) {
    DAT_00801e3c = -1;
  }
  else {
    DAT_00801e3c = (int)DAT_02983901;
  }
  uVar3 = FUN_00541e60(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11,param_12,param_13,param_14);
  return uVar3;
}

