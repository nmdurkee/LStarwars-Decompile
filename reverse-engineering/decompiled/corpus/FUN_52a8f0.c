/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52a8f0; label: FUN_0052a8f0
 */

void FUN_0052a8f0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float local_6c;
  undefined4 uStack_68;
  float fStack_64;
  undefined4 uStack_60;
  int iStack_50;
  undefined4 uStack_44;
  float fStack_40;
  undefined4 uStack_3c;
  int iStack_2c;
  undefined1 local_20 [12];
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_6c;
  if (DAT_009238a0 == (code *)0x0) goto LAB_0052ae07;
  uVar2 = FUN_004f12f0();
  iVar8 = (param_1 + 10) * 0x10;
  FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + -0x28,0x10,"Creature Editor  (%d placed)",uVar2);
  FUN_005d1060(DAT_009738b8,0x80000000);
  FUN_005d0fe0(DAT_009738b8,param_3,param_4);
  if (*(int *)(DAT_009238e4 + 0x371b0) == 0) {
    if (*(int *)(DAT_009238e4 + 0x371ac) != 0) {
      iVar4 = *(int *)(DAT_009238e4 + 0x371ac);
      goto LAB_0052a9b0;
    }
  }
  else {
    iVar4 = *(int *)(DAT_009238e4 + 0x371b0);
LAB_0052a9b0:
    if (iVar4 != 0) {
      fVar9 = (float10)FUN_005bed80(iVar4 + 0x28,DAT_009238e4 + 0x28,local_20);
      local_6c = (float)fVar9;
      FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + 0x78,0x10,"\"%s\", xzrng=%.2f",iVar4 + 8,
                   (double)local_6c);
      if (*(char *)(iVar4 + 0x5a) == '\0') {
        _sprintf(local_14,"Set=NONE");
      }
      else {
        _sprintf(local_14,"Set=%d");
      }
      pcVar3 = (char *)(iVar4 + 0x18);
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (pcVar3 == (char *)(iVar4 + 0x19)) {
        FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + 0xf0,0x10,"Script = NONE, %s",local_14);
      }
      else {
        FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + 0xf0,0x10,"Script = \"%s\", %s",
                     (char *)(iVar4 + 0x18));
      }
      if (*(int *)(iVar4 + 0x80) != 0) {
        FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + 0x168,0x10,"Area = \"%s\"",
                     *(int *)(iVar4 + 0x80) + 8);
      }
      if (*(int *)(iVar4 + 0x84) != 0) {
        FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + 0x1e0,0x10,"Locator = \"%s\"",
                     *(int *)(iVar4 + 0x84) + 8);
      }
    }
  }
  FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + 600,0x10,"SQR - Options");
  iVar4 = param_2 * 8 + 0x2d0;
  if (*(int *)(DAT_009238e4 + 0x371ac) == 0) {
    FUN_005f35e0(DAT_009738b8,iVar8,iVar4,0x10,"X - Create creature");
    if (*(int *)(DAT_009238e4 + 0x371b0) != 0) {
      FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + 0x348,0x10,"TRI - Deselect selected");
    }
    pcVar3 = "LLEFT/LRight - Rotate";
    iVar7 = param_2 * 8 + 0x3c0;
LAB_0052abc6:
    FUN_005f35e0(DAT_009738b8,iVar8,iVar7,CONCAT44(pcVar3,0x10));
  }
  else {
    if (*(int *)(DAT_009238e4 + 0x371b0) != *(int *)(DAT_009238e4 + 0x371ac)) {
      pcVar3 = "X - Select creature";
      iVar7 = iVar4;
      goto LAB_0052abc6;
    }
    FUN_005f35e0(DAT_009738b8,iVar8,iVar4,0x10,"X - Move selected");
    FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + 0x348,0x10,"TRI - Delete selected");
    FUN_005f35e0(DAT_009738b8,iVar8,param_2 * 8 + 0x3c0,0x10,"LLEFT/LRight - Rotate");
  }
  if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) && (*(int *)(DAT_009238e4 + 0x3cbe4) != 0)) {
    FUN_005f35e0(DAT_009738b8,iVar8,iVar4,0x10,"O - Set locator.");
  }
  iVar8 = FUN_004f1440();
  while (iVar8 != 0) {
    if (*(int *)(DAT_009238e4 + 0x371b0) == iVar8) {
      iVar4 = (-(uint)(*(int *)(DAT_009238e4 + 0x371b0) != *(int *)(DAT_009238e4 + 0x371ac)) &
              0x81000000) - 0xffff01;
    }
    else {
      iVar4 = (*(int *)(DAT_009238e4 + 0x371ac) != iVar8) - 1;
    }
    iVar7 = 0;
    if (*(char *)(iVar8 + 0x5b) != '\0') {
      do {
        uVar5 = __allshl();
        if (((uVar5 & *(uint *)(iVar8 + 0x54)) != 0) && (iVar6 = FUN_00528af0(), iVar6 != 0)) {
          FUN_0052a630(iVar8,iVar7,local_20,0);
          (*DAT_009238a0)(local_20,*(undefined2 *)(iVar8 + 0x34),(int)*(short *)(iVar8 + 0x58),iVar4
                          ,iVar8);
          iVar6 = *(int *)(iVar8 + 0x84);
          if (iVar6 != 0) {
            uStack_68 = *(undefined4 *)(iVar8 + 0x28);
            fStack_64 = *(float *)(iVar8 + 0x2c);
            uStack_60 = *(undefined4 *)(iVar8 + 0x30);
            uStack_44 = *(undefined4 *)(iVar6 + 0x18);
            fStack_40 = *(float *)(iVar6 + 0x1c);
            uStack_3c = *(undefined4 *)(iVar6 + 0x20);
            iStack_50 = iVar4;
            iStack_2c = iVar4;
            FUN_00512b00(&uStack_68,0);
          }
          iVar6 = *(int *)(iVar8 + 0x88);
          if (iVar6 != 0) {
            uStack_68 = *(undefined4 *)(iVar8 + 0x28);
            uStack_44 = *(undefined4 *)(iVar6 + 0x18);
            fStack_64 = *(float *)(iVar8 + 0x2c) + 0.1;
            uStack_60 = *(undefined4 *)(iVar8 + 0x30);
            fStack_40 = *(float *)(iVar6 + 0x1c) + 0.1;
            uStack_3c = *(undefined4 *)(iVar6 + 0x20);
            iStack_50 = iVar4 + 0x8000;
            iStack_2c = iStack_50;
            FUN_00512b00(&uStack_68,0);
          }
        }
        iVar7 = iVar7 + 1;
        iVar4 = 0;
      } while (iVar7 < (int)(uint)*(byte *)(iVar8 + 0x5b));
    }
    iVar8 = FUN_004f1460(DAT_009238e4 + 0x371a4);
  }
  if ((((*(int *)(DAT_009238e4 + 0x371ac) == 0) && (*(int *)(DAT_009238e4 + 0x48) != 0)) &&
      (*(float *)(DAT_009238e4 + 0x43824) < 0.5)) && (-1 < DAT_00921f34)) {
    (*DAT_009238a0)();
  }
  FUN_00524190();
  FUN_00521800();
  FUN_005226b0();
  FUN_00528010();
LAB_0052ae07:
  __security_check_cookie(local_4 ^ (uint)&local_6c);
  return;
}

