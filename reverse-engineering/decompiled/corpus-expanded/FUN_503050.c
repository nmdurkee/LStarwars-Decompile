/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x503050; label: FUN_00503050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00503050(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,uint *param_4,
                 uint *param_5,float *param_6,float *param_7,float *param_8,undefined4 *param_9)

{
  float fVar1;
  int *piVar2;
  float *pfVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  float10 fVar9;
  undefined8 local_4c;
  float local_44;
  uint local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [24];
  
  piVar2 = (int *)param_1[0x11];
  if (piVar2 == (int *)0x0) {
    *param_4 = *(byte *)(param_1 + 0x17) & 1;
    if (param_5 != (uint *)0x0) {
      *param_5 = (uint)*(byte *)((int)param_1 + 0x5d);
    }
    puVar7 = param_1;
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *param_3 = *puVar7;
      puVar7 = puVar7 + 1;
      param_3 = param_3 + 1;
    }
    if (param_6 != (float *)0x0) {
      *param_6 = (float)param_1[0x16];
    }
    if (param_7 != (float *)0x0) {
      *param_7 = (float)*(byte *)((int)param_1 + 0x61);
      return;
    }
  }
  else {
    if ((0x414e4933 < *piVar2) && (*piVar2 < 0x414e4936)) {
      FUN_00502e10(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
      return;
    }
    FUN_005c9c40(piVar2,param_2,local_18);
    iVar8 = param_1[0x11];
    local_40 = (uint)**(char **)(iVar8 + 0x14);
    pfVar3 = *(float **)(iVar8 + 0xc);
    pcVar4 = *(char **)(iVar8 + 0x10);
    if (*(short *)(iVar8 + 6) < 7) {
      *param_4 = *(byte *)(param_1 + 0x17) & 1;
    }
    else {
      if (pcVar4[6] != '\0') {
        FUN_005c9520(pfVar3 + 6,local_18,(int)pcVar4[6]);
      }
      uVar5 = FUN_006e6b90();
      *param_4 = uVar5;
    }
    if (param_5 == (uint *)0x0) {
      if (param_8 != (float *)0x0) {
        *param_8 = 0.0;
      }
    }
    else {
      if (*(short *)(param_1[0x11] + 6) < 8) {
        *param_5 = (uint)*(byte *)((int)param_1 + 0x5d);
      }
      else {
        if (pcVar4[7] == '\0') {
          fVar9 = (float10)pfVar3[7];
        }
        else {
          fVar9 = (float10)FUN_005c9520(pfVar3 + 7,local_18,(int)pcVar4[7]);
        }
        if (0.0 <= (float)fVar9) {
          local_4c = (longlong)ROUND((float)fVar9);
          *param_5 = (uint)local_4c;
        }
        else {
          *param_5 = 0xff;
        }
      }
      if (param_8 != (float *)0x0) {
        if ((*param_5 == 0) || (*param_5 == 0xff)) {
          fVar1 = 0.0;
        }
        else if (*(short *)(param_1[0x11] + 6) < 0xb) {
          local_4c = CONCAT44(local_4c._4_4_,(int)*(char *)((int)param_1 + 99));
          fVar1 = (float)(int)*(char *)((int)param_1 + 99);
        }
        else {
          if (pcVar4[10] == '\0') {
            fVar9 = (float10)pfVar3[10];
          }
          else {
            fVar9 = (float10)FUN_005c9520(pfVar3 + 10,local_18,(int)pcVar4[10]);
          }
          fVar1 = (float)fVar9;
        }
        *param_8 = fVar1;
      }
    }
    if (*param_4 != 0) {
      if (param_9 != (undefined4 *)0x0) {
        if (*(short *)(param_1[0x11] + 6) < 0xc) {
          *param_9 = 0xffffffff;
        }
        else if (pcVar4[0xb] == '\0') {
          uVar6 = FUN_006e6b90();
          *param_9 = uVar6;
        }
        else {
          FUN_005c9520(pfVar3 + 0xb,local_18,(int)pcVar4[0xb]);
          uVar6 = FUN_006e6b90();
          *param_9 = uVar6;
        }
      }
      if ((local_40 & 1) == 0) {
        FUN_005b44e0(param_3);
      }
      else {
        if (pcVar4[3] == '\0') {
          fVar9 = (float10)pfVar3[3];
        }
        else {
          fVar9 = (float10)FUN_005c9520(pfVar3 + 3,local_18,(int)pcVar4[3]);
        }
        local_4c = CONCAT44(local_4c._4_4_,(float)fVar9);
        if (pcVar4[4] == '\0') {
          fVar9 = (float10)pfVar3[4];
        }
        else {
          fVar9 = (float10)FUN_005c9520(pfVar3 + 4,local_18,(int)pcVar4[4]);
        }
        local_4c = CONCAT44((float)fVar9,(uint)local_4c);
        if (pcVar4[5] == '\0') {
          fVar9 = (float10)pfVar3[5];
        }
        else {
          fVar9 = (float10)FUN_005c9520(pfVar3 + 5,local_18,(int)pcVar4[5]);
        }
        local_44 = (float)fVar9;
        local_30 = FUN_006e6b90();
        local_2c = FUN_006e6b90();
        local_28 = FUN_006e6b90();
        FUN_005b5300(param_3,&local_30);
      }
      if (*pcVar4 == '\0') {
        fVar9 = (float10)*pfVar3;
      }
      else {
        fVar9 = (float10)FUN_005c9520(pfVar3,local_18,(int)*pcVar4);
      }
      local_3c = (float)fVar9;
      if (pcVar4[1] == '\0') {
        fVar9 = (float10)pfVar3[1];
      }
      else {
        fVar9 = (float10)FUN_005c9520(pfVar3 + 1,local_18,(int)pcVar4[1]);
      }
      local_38 = (float)fVar9;
      if (pcVar4[2] == '\0') {
        fVar9 = (float10)pfVar3[2];
      }
      else {
        fVar9 = (float10)FUN_005c9520(pfVar3 + 2,local_18,(int)pcVar4[2]);
      }
      local_34 = (float)fVar9;
      FUN_005b4900(param_3,&local_3c);
      param_3[2] = -(float)param_3[2];
      param_3[6] = -(float)param_3[6];
      param_3[8] = -(float)param_3[8];
      param_3[9] = -(float)param_3[9];
      param_3[0xb] = -(float)param_3[0xb];
      param_3[0xe] = -(float)param_3[0xe];
      puVar7 = (undefined4 *)FUN_005b4b90(&local_4c,param_1);
      local_24 = *puVar7;
      local_20 = puVar7[1];
      local_1c = puVar7[2];
      FUN_005b4c30(param_3,&local_24);
      if (param_6 != (float *)0x0) {
        if (*(short *)(param_1[0x11] + 6) < 10) {
          fVar1 = (float)param_1[0x16];
        }
        else if (pcVar4[9] == '\0') {
          fVar1 = pfVar3[9];
        }
        else {
          fVar9 = (float10)FUN_005c9520(pfVar3 + 9,local_18,(int)pcVar4[9]);
          fVar1 = (float)fVar9;
        }
        *param_6 = fVar1;
      }
      if (param_7 != (float *)0x0) {
        if (*(short *)(param_1[0x11] + 6) < 9) {
          *param_7 = (float)*(byte *)((int)param_1 + 0x61);
          return;
        }
        if (pcVar4[8] == '\0') {
          *param_7 = pfVar3[8];
          return;
        }
        fVar9 = (float10)FUN_005c9520(pfVar3 + 8,local_18,(int)pcVar4[8]);
        *param_7 = (float)fVar9;
      }
    }
  }
  return;
}

