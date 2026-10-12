/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ee440; label: FUN_005ee440
 */

void FUN_005ee440(undefined4 param_1,int param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  float *in_EAX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  float10 fVar9;
  float fStack_80;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30 [12];
  
  if (DAT_0097398c != 0) {
    local_60 = *param_3 * DAT_00966378;
    local_5c = DAT_0097313c * param_3[1];
    local_58 = 0x3f800000;
    FUN_005b3200(&local_60,&local_60,&DAT_009736e8);
    local_54 = *param_3 * DAT_00966378;
    local_50 = in_EAX[1] * DAT_0097313c;
    local_4c = 0x3f800000;
    FUN_005b3200(&local_54,&local_54,&DAT_009736e8);
    local_48 = *in_EAX * DAT_00966378;
    local_44 = in_EAX[1] * DAT_0097313c;
    local_40 = 0x3f800000;
    FUN_005b3200(&local_48,&local_48,&DAT_009736e8);
    local_3c = *in_EAX * DAT_00966378;
    local_38 = DAT_0097313c * param_3[1];
    local_34 = 0x3f800000;
    FUN_005b3200(&local_3c,&local_3c,&DAT_009736e8);
    iVar6 = 0;
    do {
      FUN_005b9290(param_1,&DAT_00971894,(int)&local_60 + iVar6,(int)local_30 + iVar6);
      iVar6 = iVar6 + 0xc;
    } while (iVar6 < 0x30);
    if (DAT_0097394c == 1) {
      FUN_00603cc0(&DAT_00973760);
    }
    FUN_005ee110(param_3);
    uVar3 = 0;
    puVar7 = local_30 + 1;
    do {
      uVar3 = uVar3 + 1;
      uVar4 = uVar3 & 0x80000003;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
      }
      FUN_005dc050(puVar7[-1],*puVar7,puVar7[1],local_30[uVar4 * 3],local_30[uVar4 * 3 + 1],
                   local_30[uVar4 * 3 + 2],0xff0000ff);
      puVar7 = puVar7 + 3;
    } while ((int)uVar3 < 4);
    iVar6 = 0;
    do {
      iVar1 = (int)&local_60 + iVar6;
      FUN_005b3b30(iVar1,iVar1);
      fStack_80 = 3.4028235e+38;
      if (*(char *)(param_2 + 0xe) != '\0') {
        iVar8 = 0;
        iVar5 = 0;
        do {
          fVar9 = (float10)FUN_005b9290(*(int *)(param_2 + 4) + iVar8,(int)local_30 + iVar6,iVar1,
                                        &uStack_6c);
          fVar2 = (float)fVar9;
          if ((0.0 < fVar2) && (fVar2 < fStack_80)) {
            uStack_78 = uStack_6c;
            uStack_74 = uStack_68;
            uStack_70 = uStack_64;
            fStack_80 = fVar2;
          }
          iVar5 = iVar5 + 1;
          iVar8 = iVar8 + 0x10;
        } while (iVar5 < (int)(uint)*(byte *)(param_2 + 0xe));
      }
      FUN_005dc050(uStack_78,uStack_74,uStack_70,*(undefined4 *)((int)local_30 + iVar6),
                   *(undefined4 *)((int)local_30 + iVar6 + 4),
                   *(undefined4 *)((int)local_30 + iVar6 + 8),0xff0000ff);
      iVar6 = iVar6 + 0xc;
    } while (iVar6 < 0x30);
    if (DAT_0097394c == 1) {
      FUN_00603cc0(&DAT_00971b00);
    }
  }
  return;
}

