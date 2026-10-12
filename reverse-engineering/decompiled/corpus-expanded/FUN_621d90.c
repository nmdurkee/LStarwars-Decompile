/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x621d90; label: FUN_00621d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00621d90(int param_1)

{
  float fVar1;
  float fVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  char *pcVar8;
  float10 fVar9;
  undefined4 uVar10;
  float fStack_180;
  float local_17c;
  float fStack_178;
  float local_174;
  float local_170;
  float fStack_16c;
  double dStack_168;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  double dStack_14c;
  undefined1 auStack_144 [64];
  undefined1 auStack_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&fStack_180;
  if (DAT_02912f4d != '\0') {
    local_170 = _DAT_0080fad8;
    local_17c = _DAT_0080fadc;
    local_160 = _DAT_0080fad4;
    local_154 = _DAT_0080fad4;
    FUN_005d0880(2);
    FUN_005d0a40(1);
    FUN_005d0fb0(DAT_009738b8);
    FUN_005eaad0(DAT_009738b8,0x3f800000,0x3f800000);
    fVar9 = (float10)FUN_005d0e80(DAT_009738b8);
    local_15c = (float)fVar9;
    fVar9 = (float10)FUN_005d0eb0(DAT_009738b8);
    local_150 = (float)fVar9;
    if (0xe < DAT_02913058) {
      local_154 = local_160 + 8.0;
    }
    if (param_1 == 0) {
      local_174 = local_15c * 16.0 * 0.0625 + 4.0;
    }
    else {
      local_174 = local_15c * 17.0 * 0.0625 + 6.0;
    }
    local_158 = local_154 + 4.0;
    FUN_005db7e0(local_170,local_17c,0,local_158,local_174,0xff808080,0);
    local_170 = local_170 + 2.0;
    local_17c = local_17c + 1.0;
    _DAT_02910c8c = local_158;
    _DAT_029110b0 = local_174;
    local_158 = (local_170 + 4.0) * 16.0;
    if (param_1 != 0) {
      local_174 = local_15c * 0.0625;
      FUN_005db7e0(local_170,local_17c,0,local_154,local_174,0xff404040,0);
      fStack_178 = local_170 + local_160;
      FUN_005dc050(local_170,local_17c,0,fStack_178,local_17c,0,0xff808080);
      FUN_005d0fb0(DAT_009738b8);
      FUN_005d1060(DAT_009738b8,0x80808080);
      fStack_178 = local_17c * 16.0 + local_150;
      FUN_005eabb0(DAT_009738b8,local_158,fStack_178,0);
      FUN_005f3510(DAT_009738b8,s_Title_0080f888);
      local_17c = local_174 + 2.0 + local_17c;
    }
    fStack_180 = local_154 - 8.0;
    puVar6 = &DAT_02912f50;
    fStack_178 = local_15c * 0.0625;
    fStack_16c = local_17c * 16.0 + local_150;
    local_174 = fStack_178;
    FUN_005db7e0(local_170,local_17c,0,local_154,fStack_178,0x20202020,0);
    if (DAT_02912f4c == '\0') {
      fVar9 = (float10)FUN_005d0d60(DAT_009738b8,&DAT_02912f50);
      fVar1 = (float)(fVar9 * (float10)0.0625);
      dStack_168 = (double)CONCAT44(dStack_168._4_4_,fVar1);
      if (fStack_180 < fVar1) {
        dStack_168 = (double)CONCAT44(dStack_168._4_4_,fStack_180 / fVar1);
        if (fStack_180 / fVar1 < 0.5) {
          puVar3 = (undefined1 *)FUN_004f1f90(&DAT_02912f50,0x5c);
          if (puVar3 != (undefined1 *)0x0) {
            puVar4 = (undefined1 *)FUN_004f1f90(puVar3 + 1,0x5c);
            if (puVar4 != (undefined1 *)0x0) {
              puVar3 = puVar4;
            }
            *puVar3 = 0;
            FUN_004f1f10(auStack_104,&DAT_02912f50);
            *puVar3 = 0x5c;
            FUN_004f1e80(auStack_104,"\\....");
            iVar7 = FUN_004f1ff0(puVar3);
            if ((iVar7 == 0) || (puVar3[iVar7 + -1] != '\\')) {
              puVar4 = (undefined1 *)FUN_004f1fc0(puVar3,0x5c);
            }
            else {
              puVar3[iVar7 + -1] = 0;
              puVar4 = (undefined1 *)FUN_004f1fc0(puVar3,0x5c);
              puVar3[iVar7 + -1] = 0x5c;
            }
            if (puVar3 < puVar4) {
              FUN_004f1e80(auStack_104,puVar4);
              puVar6 = auStack_104;
            }
          }
          fVar9 = (float10)FUN_005d0d60(DAT_009738b8,puVar6);
          fVar1 = (float)(fVar9 * (float10)0.0625);
          dStack_168 = (double)CONCAT44(dStack_168._4_4_,fVar1);
        }
        if (fStack_180 < fVar1) {
          fStack_180 = fStack_180 / fVar1;
          FUN_005eaad0(DAT_009738b8,fStack_180,0x3f800000);
        }
      }
    }
    else {
      FUN_004f1f10(auStack_104,"Volumes:-");
      puVar6 = auStack_104;
    }
    FUN_005d0fb0(DAT_009738b8);
    FUN_005eabb0(DAT_009738b8,local_158,fStack_16c,0);
    FUN_005d1060(DAT_009738b8,0x80408080);
    FUN_005f3510(DAT_009738b8,puVar6);
    FUN_005eaad0(DAT_009738b8,0x3f800000,0x3f800000);
    local_17c = local_174 + 2.0 + local_17c;
    dStack_14c = (double)(local_15c * 14.0);
    local_174 = local_15c * 14.0 * 0.0625;
    FUN_005db7e0(local_170,local_17c,0,local_160,local_174,0x20202020,0);
    if (0xe < DAT_02913058) {
      fStack_180 = local_160 + local_170;
      FUN_005db7e0(fStack_180,local_17c,0,0x41000000,local_174,0xff646464,0);
      fVar1 = (local_174 / (float)DAT_02913058) * 14.0;
      if (fVar1 < 5.0) {
        dStack_168._0_4_ = 5.0;
        fVar1 = dStack_168._0_4_;
      }
      fVar2 = ((local_174 - fVar1) * (float)DAT_02913054) / (float)(DAT_02913058 + -0xe) + local_17c
      ;
      dStack_168 = (double)CONCAT44(dStack_168._4_4_,fVar2);
      FUN_005db7e0(fStack_180,fVar2,0,0x41000000,fVar1,0xffc8c8c8,0);
    }
    fStack_16c = fStack_16c + 32.0;
    iVar7 = 0;
    pcVar8 = PTR_DAT_0080facc;
    do {
      if (PTR_DAT_0080fac8 <= pcVar8) break;
      fStack_16c = fStack_16c + local_15c;
      if (pcVar8 == PTR_DAT_0080fad0) {
        fStack_180 = (fStack_16c - local_150) * 0.0625;
        FUN_005db7e0(local_170,fStack_180,0,local_160,fStack_178,0xff202060,0);
      }
      FUN_005d0fb0(DAT_009738b8);
      FUN_005eabb0(DAT_009738b8,local_158,fStack_16c,0);
      if (*pcVar8 == 'V') {
        uVar10 = 0x80204080;
      }
      else if (*pcVar8 == 'D') {
        uVar10 = 0x80804020;
      }
      else {
        uVar10 = 0x80408080;
      }
      FUN_005d1060(DAT_009738b8,uVar10);
      FUN_005eaad0(DAT_009738b8,0x3f800000,0x3f800000);
      FUN_005f3510(DAT_009738b8,pcVar8 + 7);
      if (pcVar8[6] != '#') {
        FUN_005eaad0(DAT_009738b8,0x3f4ccccd,0x3f800000);
        FUN_004f2740(auStack_144," %.2d:%.2d:%.2d",(byte)pcVar8[3] - 0x41,(byte)pcVar8[2] - 0x41,
                     (byte)pcVar8[1] - 0x41);
        fVar9 = (float10)FUN_005d0d60(DAT_009738b8,auStack_144);
        fStack_180 = (float)fVar9;
        FUN_005d1060(DAT_009738b8,0x80208080);
        fStack_180 = (local_160 + local_170) * 16.0 - fStack_180;
        dStack_168 = (double)fStack_180;
        FUN_005eabb0(DAT_009738b8,fStack_180,fStack_16c,0);
        FUN_005f3510(DAT_009738b8,auStack_144);
        FUN_004f2740(auStack_144," %.2d/%.2d/%d",(byte)pcVar8[4] - 0x41,(byte)pcVar8[5] - 0x41,
                     (byte)pcVar8[6] + 0x77b);
        fVar9 = (float10)FUN_005d0d60(DAT_009738b8,auStack_144);
        fStack_180 = (float)fVar9;
        FUN_005d1060(DAT_009738b8,0x80808020);
        fStack_180 = (float)dStack_168 - fStack_180;
        FUN_005eabb0(DAT_009738b8,fStack_180,fStack_16c,0);
        FUN_005f3510(DAT_009738b8,auStack_144);
      }
      iVar5 = FUN_004f1ff0(pcVar8 + 7);
      iVar7 = iVar7 + 1;
      pcVar8 = pcVar8 + iVar5 + 8;
    } while (iVar7 < 0xe);
    fStack_178 = local_17c * 16.0 + local_150;
    fStack_16c = fStack_178 + (float)dStack_14c;
    FUN_005d0fb0(DAT_009738b8);
    FUN_005eaad0(DAT_009738b8,0x3f800000,0x3f800000);
    FUN_005d1060(DAT_009738b8,0x80808080);
    fStack_178 = local_170 * 16.0;
    FUN_005eabb0(DAT_009738b8,fStack_178,fStack_16c,0);
    FUN_005f3510(DAT_009738b8,s___nup_____hgp_0080f8c8);
    FUN_005d1060(DAT_009738b8,0x80000040);
    fVar9 = (float10)FUN_005d0d60(DAT_009738b8,*(undefined4 *)(DAT_0080faf0 * 4 + 0x80fae0));
    fStack_178 = (local_154 + local_170) * 16.0 - (float)fVar9;
    FUN_005eabb0(DAT_009738b8,fStack_178,fStack_16c,0);
    FUN_005f3510(DAT_009738b8,*(undefined4 *)(DAT_0080faf0 * 4 + 0x80fae0));
    FUN_005d0a70();
    FUN_005d08c0();
  }
  __security_check_cookie(local_4 ^ (uint)&fStack_180);
  return;
}

