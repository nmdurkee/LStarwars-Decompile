/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54c0c0; label: FUN_0054c0c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c0c0(float param_1,int param_2,float param_3,float param_4)

{
  short sVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined2 in_FPUControlWord;
  float10 fVar11;
  float fVar12;
  float fVar13;
  float local_8ac;
  float local_8a8;
  float local_8a4;
  longlong local_8a0;
  int local_898;
  float local_894;
  int local_890;
  char *local_88c;
  int local_888;
  undefined1 local_884 [64];
  char local_844 [64];
  undefined1 local_804 [2048];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_8ac;
  uVar8 = 0;
  local_8ac = param_4;
  if (((DAT_00926c44 != (undefined4 *)0x0) && (DAT_00921e9c != 0)) &&
     ((FUN_005d0ee0(0x3f99999a,0x3f99999a), param_2 != 0 || (_DAT_00921eb8 < 60.0)))) {
    if (*(char *)((int)DAT_00926c44 + 0xd) == -1) {
      iVar10 = 0;
      iVar9 = -1;
      local_898 = -1;
      iVar7 = -1;
    }
    else {
      iVar10 = *(char *)((int)DAT_00926c44 + 0xd) * 0x9c + DAT_00951354;
      local_898 = (int)*(short *)(iVar10 + 0x94);
      iVar9 = (int)*(char *)(iVar10 + 0x86);
      iVar7 = (int)*(char *)(iVar10 + 0x87);
    }
    local_894 = 0.0;
    local_890 = 0;
    local_88c = (char *)0x0;
    local_888 = 0;
    if (local_8ac == 0.0) {
      iVar3 = FUN_0058a900(0);
      if (iVar3 == 0) {
        if (DAT_0093b324 == 0) {
          if (iVar9 == -1) {
            if ((iVar10 != 0) && (*(short *)(iVar10 + 0x78) != -1)) {
              local_888 = *(int *)(DAT_00926c20 + *(short *)(iVar10 + 0x78) * 4);
            }
          }
          else {
            sVar1 = *(short *)(DAT_00956290 + iVar9 * 0x1c);
            if (sVar1 != -1) {
              local_894 = *(float *)(DAT_00926c20 + sVar1 * 4);
            }
            sVar1 = *(short *)(DAT_00956290 + iVar9 * 0x1c + 2);
            if (sVar1 != -1) {
              local_890 = *(int *)(DAT_00926c20 + sVar1 * 4);
            }
            if (iVar7 != -1) {
              if ((*(ushort *)(iVar10 + 0x7a) & 4) == 0) {
                if ((short *)*DAT_00926c44 != (short *)0x0) {
                  _sprintf(local_844,"%s %i",
                           *(undefined4 *)(DAT_00926c20 + *(short *)*DAT_00926c44 * 4),iVar7 + 1);
                  local_88c = local_844;
                }
              }
              else if ((*(ushort *)(iVar10 + 0x7a) & 1) == 0) {
                if ((short *)DAT_00926c44[2] != (short *)0x0) {
                  local_88c = *(char **)(DAT_00926c20 + *(short *)DAT_00926c44[2] * 4);
                }
              }
              else if ((short *)DAT_00926c44[1] != (short *)0x0) {
                local_88c = *(char **)(DAT_00926c20 + *(short *)DAT_00926c44[1] * 4);
              }
              if (*(short *)(iVar10 + 0x78) != -1) {
                local_888 = *(int *)(DAT_00926c20 + *(short *)(iVar10 + 0x78) * 4);
              }
            }
          }
        }
        else {
          if ((iVar10 != 0) && (*(short *)(iVar10 + 0x78) != -1)) {
            local_888 = *(int *)(DAT_00926c20 + *(short *)(iVar10 + 0x78) * 4);
          }
          local_898 = DAT_007fa1c4;
          uVar8 = DAT_007fa1c8;
        }
      }
      else {
        iVar7 = (int)*(short *)(iVar3 + 4);
        if ((iVar7 != -1) && (*(int *)(DAT_00926c20 + iVar7 * 4) != 0)) {
          local_888 = *(int *)(DAT_00926c20 + iVar7 * 4);
        }
        local_898 = (int)*(short *)(iVar3 + 6);
        uVar8 = 3;
      }
    }
    else {
      local_894 = local_8ac;
      local_898 = -1;
    }
    _DAT_00921eb8 = _DAT_00921eb8 + param_1;
    if (60.0 <= _DAT_00921eb8) {
      if (param_2 == 0) goto LAB_0054c8e3;
      _DAT_00921eb8 = 0.0;
    }
    uVar4 = FUN_005d6170();
    FUN_005b5430(local_884,&DAT_00926bd8,uVar4);
    FUN_005d0fb0(DAT_00921e9c);
    FUN_005d1030(DAT_00921e9c,local_884);
    FUN_005d0880(4);
    FUN_005d0940(4);
    fVar6 = DAT_00926c50;
    local_8a0 = CONCAT44(local_8a0._4_4_,0x43000000);
    uVar5 = DAT_00802394;
    if ((param_2 == 0) && (55.0 < _DAT_00921eb8 != (_DAT_00921eb8 == 55.0))) {
      local_8a4 = (float)DAT_00802394;
      local_8a0 = CONCAT44(local_8a0._4_4_,(1.0 - (_DAT_00921eb8 - 55.0) / 5.0) * 128.0);
      uVar5 = FUN_006e6b90();
      local_8a4 = fVar6;
      fVar6 = (float)FUN_006e6b90();
    }
    local_8a8 = (float)CONCAT22(local_8a8._2_2_,in_FPUControlWord);
    local_8a0 = (longlong)ROUND((float)local_8a0 * param_3);
    uVar5 = (((int)(float)local_8a0 << 8 | (uint)fVar6 & 0xff) << 8 | uVar5 & 0xff) << 8 |
            (uint)DAT_00802390;
    FUN_005d1060(DAT_00921e9c,uVar5);
    fVar6 = local_894;
    local_8a8 = _DAT_00921eb8 * 0.4 - 4.5;
    local_8a0 = CONCAT44(local_8a0._4_4_,_DAT_008015ac * _DAT_00802374);
    local_8a4 = _DAT_008015b0 * _DAT_00802378;
    if (local_894 != 0.0) {
      if ((local_8ac == 0.0) || (iVar7 = FUN_004f20f0(local_8ac,&DAT_00755ba8), iVar7 != 0)) {
        fVar12 = (float)local_8a0;
        fVar13 = local_8a4;
      }
      else {
        local_8ac = (float)local_8a0 + (float)local_8a0;
        fVar12 = local_8ac;
        fVar13 = local_8a4 * 3.0;
      }
      FUN_005d0fe0(DAT_00921e9c,fVar12,fVar13);
      FUN_0050c100(fVar6,local_804);
      fVar11 = (float10)FUN_005d0c50(DAT_00921e9c,local_804,local_8a8,0);
      local_8ac = (float)(-fVar11 * (float10)0.5);
      FUN_005eabb0(DAT_00921e9c,local_8ac);
      FUN_005f34e0(DAT_00921e9c,local_804);
      fVar11 = (float10)FUN_005d0e80(DAT_00921e9c);
      local_8a8 = (float)(fVar11 * (float10)1.5 + (float10)local_8a8);
    }
    iVar7 = local_890;
    if (local_890 != 0) {
      local_8ac = local_8a4 + local_8a4;
      FUN_005d0fe0(DAT_00921e9c,(float)local_8a0,local_8ac);
      FUN_0050c100(iVar7,local_804);
      fVar11 = (float10)FUN_005d0c50(DAT_00921e9c,local_804,local_8a8,0);
      local_8ac = (float)(-fVar11 * (float10)0.5);
      FUN_005eabb0(DAT_00921e9c,local_8ac);
      FUN_005f34e0(DAT_00921e9c,local_804);
      fVar11 = (float10)FUN_005d0e80(DAT_00921e9c);
      local_8a8 = (float)(fVar11 * (float10)1.5 + (float10)local_8a8);
    }
    pcVar2 = local_88c;
    if (local_88c != (char *)0x0) {
      FUN_005d0fe0(DAT_00921e9c,(float)local_8a0,local_8a4);
      FUN_0050c100(pcVar2,local_804);
      fVar11 = (float10)FUN_005d0c50(DAT_00921e9c,local_804,local_8a8,0);
      local_8ac = (float)(-fVar11 * (float10)0.5);
      FUN_005eabb0(DAT_00921e9c,local_8ac);
      FUN_005f34e0(DAT_00921e9c,local_804);
      fVar11 = (float10)FUN_005d0e80(DAT_00921e9c);
      local_8a8 = (float)(fVar11 * (float10)1.5 + (float10)local_8a8);
    }
    iVar7 = local_888;
    if (local_888 != 0) {
      local_8ac = local_8a4 + local_8a4;
      FUN_005d0fe0(DAT_00921e9c,(float)local_8a0,local_8ac);
      FUN_0050c100(iVar7,local_804);
      fVar11 = (float10)FUN_005d0c50(DAT_00921e9c,local_804,local_8a8,0);
      local_8ac = (float)(-fVar11 * (float10)0.5);
      FUN_005eabb0(DAT_00921e9c,local_8ac);
      FUN_005f34e0(DAT_00921e9c,local_804);
      fVar11 = (float10)FUN_005d0e80(DAT_00921e9c);
      local_8a8 = (float)(fVar11 * (float10)1.5 + (float10)local_8a8);
    }
    if (local_898 != -1) {
      FUN_005d0fe0(DAT_00921e9c,(float)local_8a0,local_8a4);
      if (uVar8 == 0) {
        if (iVar10 == 0) {
          uVar8 = (uint)*(byte *)(DAT_00926c44 + 3);
        }
        else {
          uVar8 = (uint)*(byte *)(iVar10 + 0x96);
        }
      }
      iVar7 = 0;
      if (0 < (int)uVar8) {
        iVar9 = local_898 * 4;
        do {
          if ((*(int *)(iVar9 + DAT_00926c20) == 0) || (**(char **)(iVar9 + DAT_00926c20) == '\0'))
          break;
          FUN_0050c100(*(char **)(iVar9 + DAT_00926c20),local_804);
          local_8ac = -_DAT_0080237c * 0.5;
          fVar11 = (float10)FUN_005f69c0(DAT_00921e9c,local_804,local_8ac,local_8a8,0,
                                         (float)local_8a0,local_8a4,_DAT_0080237c,_DAT_00802380,
                                         uVar5,local_884);
          local_8a8 = (float)(fVar11 + (float10)local_8a8);
          fVar11 = (float10)FUN_005d0e80(DAT_00921e9c);
          iVar7 = iVar7 + 1;
          iVar9 = iVar9 + 4;
          local_8a8 = (float)(fVar11 + (float10)local_8a8);
        } while (iVar7 < (int)uVar8);
      }
    }
    FUN_005d08c0();
  }
LAB_0054c8e3:
  __security_check_cookie(local_4 ^ (uint)&local_8ac);
  return;
}

