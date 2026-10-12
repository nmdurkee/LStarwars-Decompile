/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x5319f0; label: FUN_005319f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005319f0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint unaff_EBP;
  int iVar3;
  float10 fVar4;
  uint uVar6;
  longlong lVar5;
  int local_8c;
  float local_88;
  undefined4 local_84;
  undefined4 local_80;
  int local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined4 local_3c;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_18;
  undefined1 local_c [12];
  
  iVar3 = (param_1 + 10) * 0x10;
  if (*(int *)(DAT_009238e4 + 0x41208) == 0) {
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + -0x28,0x10,"Locator Editor: Set=\"NONE\"");
  }
  else {
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + -0x28,0x10,"Locator Editor: Set=\"%s\"",
                 *(int *)(DAT_009238e4 + 0x41208) + 8);
  }
  FUN_005d1060(DAT_009738b8,0x80000000);
  FUN_005d0fe0(DAT_009738b8,param_3,param_4);
  if (*(int *)(DAT_009238e4 + 0x3cbe0) == 0) {
    if (*(int *)(DAT_009238e4 + 0x3cbe4) != 0) {
      iVar2 = *(int *)(DAT_009238e4 + 0x3cbe4);
      goto LAB_00531abe;
    }
  }
  else {
    iVar2 = *(int *)(DAT_009238e4 + 0x3cbe0);
LAB_00531abe:
    if (iVar2 != 0) {
      fVar4 = (float10)FUN_005bed80(iVar2 + 0x18,DAT_009238e4 + 0x28,local_c);
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x78,0x10,"\"%s\", xzrng=%.2f",iVar2 + 8,
                   (double)(float)fVar4);
    }
  }
  FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0xf0,0x10,"SQR - Options");
  if (*(int *)(DAT_009238e4 + 0x3cbe4) == 0) {
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x168,0x10,"X - Create locator");
  }
  else {
    if (*(int *)(DAT_009238e4 + 0x3cbe0) == *(int *)(DAT_009238e4 + 0x3cbe4)) {
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x168,0x10,"X - Move selected");
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"TRI - Delete selected");
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 600,0x10,"LLEFT - Rotate left");
      FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x2d0,0x10,"LRIGHT - Rotate right");
      goto LAB_00531c25;
    }
    FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x168,0x10,"X - Select locator");
  }
  FUN_005f35e0(DAT_009738b8,iVar3,param_2 * 8 + 0x1e0,0x10,"SELECT - Select nearest");
LAB_00531c25:
  if (((*(int *)(DAT_009238e4 + 0x3cbe4) == 0) && (*(int *)(DAT_009238e4 + 0x48) != 0)) &&
     (_DAT_00921f54 < 0.5)) {
    FUN_00522500(DAT_009238e4 + 0x28,_DAT_00801cc4,DAT_00921f30,0);
  }
  FUN_00521800();
  FUN_005226b0();
  FUN_00524190();
  FUN_00528010();
  if (((byte)DAT_00921f50 & 8) != 0) {
    FUN_0052a760();
  }
  if (*(int *)(DAT_009238e4 + 0x41208) != 0) {
    local_3c = 0x32323232;
    local_18 = 0x32323232;
    if (*(int *)(*(int *)(DAT_009238e4 + 0x41208) + 0x18) == 0) {
      lVar5 = (ulonglong)unaff_EBP << 0x20;
      local_7c = 0;
      local_8c = 0x18;
      local_58 = local_80;
      local_5c = local_84;
      local_60 = local_88;
    }
    else {
      iVar3 = *(int *)(*(int *)(DAT_009238e4 + 0x41208) + 0x18);
      lVar5 = (ulonglong)unaff_EBP << 0x20;
      local_7c = 0;
      local_8c = 0x18;
      local_58 = *(undefined4 *)(iVar3 + 0x20);
      local_5c = *(undefined4 *)(iVar3 + 0x1c);
      local_60 = *(float *)(iVar3 + 0x18);
    }
    do {
      piVar1 = (int *)(*(int *)(DAT_009238e4 + 0x41208) + local_8c);
      if (*piVar1 == 0) {
        return;
      }
      iVar3 = *piVar1;
      local_88 = *(float *)(iVar3 + 0x18);
      local_84 = *(undefined4 *)(iVar3 + 0x1c);
      local_80 = *(undefined4 *)(iVar3 + 0x20);
      if (local_7c != 0) {
        uVar6 = (uint)((ulonglong)lVar5 >> 0x20);
        local_54 = local_88;
        local_50 = (float)local_84;
        local_4c = (float)local_80;
        local_30 = local_60;
        local_2c = local_5c;
        local_28 = local_58;
        FUN_00512b00(&local_54,0,0,uVar6);
        FUN_005b3800(&local_78,&local_60,&local_88);
        FUN_005b3b30(&local_78,&local_78);
        FUN_005b3830(&local_78,&local_78,0x3d4ccccd);
        FUN_005b37d0(&local_6c,&local_88,&local_60);
        FUN_005b3830(&local_6c,&local_6c,0x3f000000);
        local_54 = local_6c - local_78 * 0.5;
        local_50 = local_68 - local_74 * 0.5;
        local_4c = local_64 - local_70 * 0.5;
        FUN_005b3620(&local_30,&local_78,0xe39);
        FUN_005b37d0(&local_30,&local_30,&local_54);
        FUN_00512b00(&local_54,0,0);
        FUN_005b3620(&local_30,&local_78,0xfffff1c7);
        FUN_005b37d0(&local_30,&local_30,&local_54);
        lVar5 = (ulonglong)uVar6 << 0x20;
        FUN_00512b00(&local_54,0);
      }
      local_7c = local_7c + 1;
      local_8c = local_8c + 4;
      local_58 = local_80;
      local_5c = local_84;
      local_60 = local_88;
    } while (local_8c < 0x118);
  }
  return;
}

