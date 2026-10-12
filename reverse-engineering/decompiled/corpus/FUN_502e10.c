/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x502e10; label: FUN_00502e10
 */

void FUN_00502e10(int param_1,undefined4 param_2,int param_3,uint *param_4,uint *param_5,
                 undefined4 *param_6,float *param_7,float *param_8,undefined4 *param_9)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 fVar7;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  iVar2 = *(int *)(param_1 + 0x44);
  iVar3 = FUN_005ce7e0(iVar2,0,param_2,0);
  fVar7 = (float10)0;
  bVar1 = **(byte **)(iVar2 + 0x34);
  if (*(ushort *)(iVar2 + 0xc) < 7) {
    *param_4 = *(byte *)(param_1 + 0x5c) & 1;
  }
  else if (fVar7 <= (float10)*(float *)(iVar3 + 0x18)) {
    uVar4 = FUN_006e6b90();
    *param_4 = uVar4;
    fVar7 = extraout_ST0_00;
  }
  else {
    uVar4 = FUN_006e6b90();
    *param_4 = uVar4;
    fVar7 = extraout_ST0;
  }
  if (param_5 == (uint *)0x0) {
    if (param_8 != (float *)0x0) {
      *param_8 = (float)fVar7;
    }
  }
  else {
    if (*(ushort *)(iVar2 + 0xc) < 8) {
      *param_5 = (uint)*(byte *)(param_1 + 0x5d);
    }
    else if (fVar7 <= (float10)*(float *)(iVar3 + 0x1c)) {
      uVar4 = FUN_006e6b90();
      *param_5 = uVar4;
      fVar7 = extraout_ST0_02;
    }
    else {
      uVar4 = FUN_006e6b90();
      *param_5 = uVar4;
      fVar7 = extraout_ST0_01;
    }
    if (param_8 != (float *)0x0) {
      if ((*param_5 != 0) && (*param_5 != 0xff)) {
        if (10 < *(ushort *)(iVar2 + 0xc)) {
          *param_8 = *(float *)(iVar3 + 0x28);
          goto LAB_00502f0b;
        }
        fVar7 = (float10)(int)*(char *)(param_1 + 99);
      }
      *param_8 = (float)fVar7;
    }
  }
LAB_00502f0b:
  if (*param_4 != 0) {
    if (param_9 != (undefined4 *)0x0) {
      if (*(ushort *)(iVar2 + 0xc) < 0xc) {
        *param_9 = 0xffffffff;
      }
      else {
        uVar5 = FUN_00502dc0(iVar2,iVar3,0xb);
        *param_9 = uVar5;
      }
    }
    if ((bVar1 & 1) == 0) {
      FUN_005b44e0(param_3);
    }
    else {
      local_24 = FUN_006e6b90();
      local_20 = FUN_006e6b90();
      local_1c = FUN_006e6b90();
      FUN_005b5300(param_3,&local_24);
    }
    FUN_005b4900(param_3,iVar3);
    *(float *)(param_3 + 8) = -*(float *)(param_3 + 8);
    *(float *)(param_3 + 0x18) = -*(float *)(param_3 + 0x18);
    *(float *)(param_3 + 0x20) = -*(float *)(param_3 + 0x20);
    *(float *)(param_3 + 0x24) = -*(float *)(param_3 + 0x24);
    *(float *)(param_3 + 0x2c) = -*(float *)(param_3 + 0x2c);
    *(float *)(param_3 + 0x38) = -*(float *)(param_3 + 0x38);
    puVar6 = (undefined4 *)FUN_005b4b90(local_c,param_1);
    local_18 = *puVar6;
    local_14 = puVar6[1];
    local_10 = puVar6[2];
    FUN_005b4c30(param_3,&local_18);
    if (param_6 != (undefined4 *)0x0) {
      if (*(ushort *)(iVar2 + 0xc) < 10) {
        uVar5 = *(undefined4 *)(param_1 + 0x58);
      }
      else {
        uVar5 = *(undefined4 *)(iVar3 + 0x24);
      }
      *param_6 = uVar5;
    }
    if (param_7 != (float *)0x0) {
      if (8 < *(ushort *)(iVar2 + 0xc)) {
        *param_7 = *(float *)(iVar3 + 0x20);
        return;
      }
      *param_7 = (float)*(byte *)(param_1 + 0x61);
    }
  }
  return;
}

