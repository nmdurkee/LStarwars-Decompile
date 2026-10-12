/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x483c70; label: FUN_00483c70
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00483c70(int param_1)

{
  float *pfVar1;
  float fVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  uint extraout_EDX;
  int iVar9;
  undefined4 uVar10;
  undefined *puVar11;
  undefined4 uVar12;
  bool bVar13;
  float10 fVar14;
  int local_c;
  
  if (DAT_0087a628 == 0) {
    return;
  }
  iVar7 = 0;
  if (*(int *)(DAT_0087a600 + 0xc) != -1) {
    iVar4 = 0;
    iVar9 = DAT_0087a600;
    do {
      iVar4 = iVar4 + iVar9;
      if (iVar4 != 0) {
        *(undefined4 *)(iVar4 + 0x14) = 0xffffffff;
        *(undefined4 *)(iVar4 + 0x18) = 0;
        *(undefined1 *)(iVar4 + 0x12) = 0;
        *(undefined4 *)(iVar4 + 0x1c) = 0x3f800000;
        iVar9 = DAT_0087a600;
      }
      iVar7 = iVar7 + 1;
      iVar4 = iVar7 * 0x20;
    } while (*(int *)(iVar4 + 0xc + iVar9) != -1);
  }
  FUN_00483c10(&DAT_0087a628);
  DAT_0087a6d8 = DAT_0087a6d8 & 0xfffffffe;
  _DAT_0087a188 = _DAT_007fc310;
  DAT_0087a18c = 0;
  DAT_0087a1a0 = 0;
  FUN_0054a7f0(&DAT_0087a64c);
  FUN_0054a7f0(&DAT_0087a660);
  _DAT_0087b93c = 0x3f800000;
  DAT_0087a1d4 = 0;
  if (DAT_00951b50 == 0) {
    iVar9 = 0;
    puVar6 = &DAT_0087a6c4;
    iVar7 = 0;
    do {
      iVar4 = *(int *)((int)&DAT_0093d7f0 + iVar7);
      if (iVar4 == 0) {
        *puVar6 = 0xffff;
      }
      else {
        *puVar6 = *(undefined2 *)(iVar4 + 0x1064);
        (&DAT_0087a6cc)[iVar9] = (byte)(*(uint *)(iVar4 + 0x1fc) >> 7) & 1;
        if (*(undefined4 **)(iVar4 + 0x7fc) == (undefined4 *)0x0) {
          *(undefined4 *)((int)&DAT_0087a6ac + iVar7) = 0;
          DAT_0087a6dc = DAT_0087a6dc + '\x01';
        }
        else {
          *(undefined4 *)((int)&DAT_0087a6ac + iVar7) = **(undefined4 **)(iVar4 + 0x7fc);
          DAT_0087a6dc = DAT_0087a6dc + '\x01';
        }
      }
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + 1;
      iVar7 = iVar7 + 4;
    } while ((int)puVar6 < 0x87a6c8);
  }
  if (DAT_0087a6dc != '\x02') {
    DAT_0087a6dc = 0;
    return;
  }
  uVar5 = DAT_0087a6d8 ^ (DAT_0093b2a8 << 10 ^ DAT_0087a6d8) & 0x400;
  uVar5 = uVar5 ^ (DAT_0093b2a4 << 6 ^ uVar5) & 0x40;
  DAT_0087a6d8 = (uVar5 ^ (DAT_0087b720 << 0xb ^ uVar5) & 0x800) & 0xffffefff;
  DAT_0087a6df = 0;
  DAT_0087a648 = FUN_0058a900(0);
  if (DAT_0087a648 == 0) {
    DAT_0087a6cf = '\0';
  }
  else {
    DAT_0087a6cf = FUN_0058a930(0);
  }
  DAT_0087a6e4 = (undefined1)DAT_0086e4e0;
  DAT_0087a6ce = (char)DAT_00856c08;
  DAT_0087b720 = 0;
  local_c = (int)*(char *)(param_1 + 0x120);
  DAT_0087a6d8 = DAT_0087a6d8 & 0xfffffc77;
  DAT_0087a740 = -1;
  DAT_0087a6e8 = 0xff;
  DAT_0087a644 = &DAT_0086e4dc;
  DAT_0087a6e5 = DAT_0086e4e2;
  DAT_0087a6e6 = DAT_0086e4e2;
  DAT_0087a6e3 = 0;
  DAT_0087a6e7 = 0;
  DAT_0087a6c8 = (short)*(char *)(param_1 + 0x120);
  if (local_c == -1) {
    DAT_0087a63c = 0;
    DAT_0087a640 = 0;
    local_c = -1;
    iVar7 = -1;
    DAT_0087a742 = -1;
  }
  else {
    DAT_0087a63c = local_c * 0x9c + DAT_00951354;
    DAT_0087a6ca = *(char *)(DAT_0087a63c + 0x86);
    iVar7 = (int)DAT_0087a6ca;
    if (iVar7 != -1) {
      DAT_0087a640 = DAT_00956290 + *(char *)(DAT_0087a63c + 0x86) * 0x1c;
    }
    DAT_0087a742 = *(char *)(DAT_0087a63c + 0x87);
    if ((*(byte *)(DAT_0087a63c + 0x7a) & 1) != 0) {
      DAT_0087a6d8 = DAT_0087a6d8 | 0x80;
    }
    if ((*(byte *)(DAT_0087a63c + 0x7a) & 4) != 0) {
      DAT_0087a6d8 = DAT_0087a6d8 | 0x100;
    }
    if ((*(ushort *)(DAT_0087a63c + 0x7a) & 0x100) != 0) {
      DAT_0087a6d8 = DAT_0087a6d8 | 0x200;
    }
  }
  iVar9 = (*DAT_0087a62c)(param_1,&DAT_0087a628);
  uVar8 = DAT_0093b298;
  uVar5 = DAT_0087a6b0;
  if (iVar9 != 0) {
    return;
  }
  if ((DAT_0087a6d8 & 0x400) != 0) {
    if (DAT_00951b80 != DAT_00951b98) {
      if (*(int *)(PTR_DAT_00802c54 + 0x110) != 0) {
        if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b98) goto LAB_00483fa8;
        if (*(int *)(PTR_DAT_00802c54 + 0x110) != 0) goto LAB_004841d0;
      }
      if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_00951b98) goto LAB_004841d0;
    }
LAB_00483fa8:
    _DAT_0087a684 = *(undefined4 *)(&DAT_0086e454 + iVar7 * 0xc);
    uVar5 = *(uint *)(&DAT_0086e458 + iVar7 * 0xc);
    iVar9 = iVar7 * 0xc;
    uVar3 = 0;
    _DAT_0087a6d0 = _DAT_0092506c;
    DAT_0087a6d4 = DAT_0093b298;
    _DAT_0087a694 = uVar5;
    if (iVar7 == -1) {
      DAT_0087a698 = 0;
      _DAT_0087a688 = 0.0;
    }
    else {
      if (*(float *)(&DAT_0086e454 + iVar9) <= _DAT_0092506c) {
        _DAT_0087a688 = 0.0;
      }
      else {
        _DAT_0087a688 = _DAT_0092506c;
        *(float *)(&DAT_0086e454 + iVar9) = _DAT_0092506c;
      }
      if (uVar5 < uVar8) {
        DAT_0087a698 = uVar8;
        *(uint *)(&DAT_0086e458 + iVar9) = uVar8;
      }
      else {
        DAT_0087a698 = 0;
      }
      uVar10 = DAT_0093b2dc;
      if ((&DAT_0086e45c)[iVar9] == '\0') {
        (&DAT_0086e45c)[iVar9] = 1;
        FUN_0055c820(uVar10);
        if (DAT_0093b31c != 0) {
          uVar3 = FUN_00483a90(&DAT_0087a628,DAT_0088071c);
        }
      }
    }
    DAT_0087a6a4 = *DAT_0087a644;
    if (_DAT_0087a688 != 0.0) {
      iVar9 = FUN_006e6b90();
      uVar5 = iVar9 * 100;
      iVar9 = (int)uVar5 >> 0x1f;
      if ((-1 < (int)uVar5) && (uVar5 < 100)) {
        uVar5 = 100;
        iVar9 = 0;
      }
      FUN_005533f0(&DAT_0087a6a4,uVar5,iVar9,0);
    }
    _DAT_0087a6a8 = DAT_0087a6a4;
    FUN_005533f0(&DAT_0087a6a8,DAT_0087a6d4,0,0);
    (&DAT_0087a6f0)[DAT_0087a6df] = 0xe;
    (&DAT_0087a718)[DAT_0087a6df] = uVar3;
    DAT_0087a6df = DAT_0087a6df + 1;
    (&DAT_0087a6f0)[DAT_0087a6df] = 0xf;
    (&DAT_0087a718)[DAT_0087a6df] = 0;
    DAT_0087a6df = DAT_0087a6df + 1;
    (&DAT_0087a6f0)[DAT_0087a6df] = 0x10;
    (&DAT_0087a718)[DAT_0087a6df] = 0;
    DAT_0087a6df = DAT_0087a6df + 1;
    if (DAT_0087a6e5 < DAT_0086e4e2) {
      FUN_00483ac0(&DAT_0087a628,0x13,0);
    }
    if ((DAT_00951b50 == 0) &&
       (((_DAT_0087a688 != 0.0 || (DAT_0087a698 != 0)) || (DAT_0087a6d4 != 0)))) {
      FUN_00483ac0(&DAT_0087a628,0xb,0);
    }
    DAT_008059f4 = (int)*(char *)(DAT_0087a63c + 0x86);
LAB_004841d0:
    (&DAT_0087a6f0)[DAT_0087a6df] = 10;
    (&DAT_0087a718)[DAT_0087a6df] = 0;
    DAT_0087a6df = DAT_0087a6df + 1;
    (&DAT_0087a6f0)[DAT_0087a6df] = 0xff;
    DAT_0087a6e0 = 0xff;
    _DAT_0087a750 = FUN_00483690((int)DAT_0087a6f0);
    FUN_004838f0(&DAT_0087a628);
    if ((iVar7 != -1) &&
       ((int)DAT_0087a742 < (int)(uint)*(byte *)(DAT_00956290 + 0x19 + iVar7 * 0x1c))) {
      DAT_0087a740 = *(short *)(DAT_00956290 + 6 + ((int)DAT_0087a742 + iVar7 * 0xe) * 2);
      if ((DAT_0087a740 != -1) && ((*(byte *)(DAT_0087a740 * 0x9c + 0x7a + DAT_00951354) & 2) != 0))
      {
        DAT_008059f4 = iVar7;
        return;
      }
    }
    return;
  }
  if (((DAT_0087a6d8 & 0x100) != 0) && (local_c != -1)) {
    _DAT_0087a68c = _DAT_00925008;
    _DAT_0087a684 = (&DAT_0086e0fc)[local_c * 3];
    uVar5 = DAT_0087a6d8 ^ (DAT_007f3b14 << 5 ^ DAT_0087a6d8) & 0x20;
    uVar10 = 0;
    DAT_0087a6d8 = uVar5;
    if (((float)(&DAT_0086e0fc)[local_c * 3] <= 0.0) ||
       (_DAT_00925008 < (float)(&DAT_0086e0fc)[local_c * 3])) {
      if ((*(ushort *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x84) != 0) &&
         (fVar2 = (float)*(ushort *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x84),
         fVar2 < (float)(&DAT_0086e0fc)[local_c * 3] !=
         (fVar2 == (float)(&DAT_0086e0fc)[local_c * 3]))) {
        FUN_0055c820(DAT_0093b2e4);
        uVar10 = FUN_00483a90(&DAT_0087a628,DAT_008806fc);
      }
      uVar5 = DAT_0087a6d8;
      _DAT_0087a688 = _DAT_0087a68c;
      (&DAT_0086e0fc)[local_c * 3] = _DAT_0087a68c;
    }
    uVar12 = DAT_0093b2e0;
    if ((uVar5 & 0x200) == 0) {
      FUN_00483ac0(&DAT_0087a628,0x14,0);
    }
    else {
      if ((&DAT_0086e0f5)[DAT_0087a6c8 * 0xc] == '\0') {
        (&DAT_0086e0f5)[DAT_0087a6c8 * 0xc] = 1;
        FUN_0055c820(uVar12);
        DAT_0087a6e3 = 1;
        if (DAT_0093b318 != 0) {
          uVar10 = FUN_00483a90(&DAT_0087a628,DAT_00880708);
        }
      }
      FUN_00483ac0(&DAT_0087a628,0x16,uVar10);
      uVar10 = 0;
    }
    FUN_00483ac0(&DAT_0087a628,0x15,uVar10);
    if (DAT_0087a6e5 < DAT_0086e4e2) {
      FUN_00483ac0(&DAT_0087a628,0x13,0);
    }
    FUN_00483ac0(&DAT_0087a628,9,0);
    FUN_00483ac0(&DAT_0087a628,10,0);
    if (DAT_00951b50 == 0) {
      FUN_00483ac0(&DAT_0087a628,0xb,0);
    }
    FUN_00483ac0(&DAT_0087a628,0xc,0);
    (&DAT_0087a6f0)[DAT_0087a6df] = 0xff;
    DAT_0087a6e0 = 0xff;
    _DAT_0087a750 = FUN_00483690((int)DAT_0087a6f0);
    FUN_004838f0(&DAT_0087a628);
    DAT_0087a1e4 = 1;
    return;
  }
  if (DAT_0087a6cf == '\0') {
    if (DAT_0087a6ce != '\0') {
      _DAT_0087a68c = (float)_DAT_0085ea64;
      _DAT_0087a69c = *DAT_0087a644;
      bVar13 = false;
      _DAT_0087a6a0 = _DAT_0087a69c;
      if (DAT_0087a6ce == '\x02') {
        bVar13 = (&DAT_0086e0fb)[DAT_0087a6c8 * 0xc] == '\0';
        if (bVar13) {
          FUN_0055c820(DAT_0093b2ec);
          (&DAT_0086e0fb)[DAT_0087a6c8 * 0xc] = 1;
        }
        iVar7 = FUN_006e6b90();
        uVar5 = iVar7 * 500;
        iVar7 = (int)uVar5 >> 0x1f;
        if ((-1 < (int)uVar5) && (uVar5 < 500)) {
          uVar5 = 500;
          iVar7 = 0;
        }
        FUN_005533f0(&DAT_0087a6a0,uVar5,iVar7,0);
      }
      FUN_00483ac0(&DAT_0087a628,0x17,0);
      if ((DAT_0087a6ce == '\x02') && (bVar13)) {
        FUN_00483ac0(&DAT_0087a628,0x19,0);
      }
      FUN_00483ac0(&DAT_0087a628,9,0);
      FUN_00483ac0(&DAT_0087a628,10,0);
      if (DAT_00951b50 == 0) {
        FUN_00483ac0(&DAT_0087a628,0xb,0);
      }
      FUN_00483ac0(&DAT_0087a628,0xc,0);
      (&DAT_0087a6f0)[DAT_0087a6df] = 0xff;
      DAT_0087a6e0 = 0xff;
      _DAT_0087a750 = FUN_00483690((int)DAT_0087a6f0);
      FUN_004838f0(&DAT_0087a628);
      DAT_0087a1e4 = 1;
      DAT_007fc378 = 0xc3;
      DAT_007fc374 = 0xc3;
      return;
    }
    if (local_c != -1) {
      if (DAT_0087b980 != 0) {
        DAT_0087a6d8 = DAT_0087a6d8 | 4;
      }
      DAT_0087a6de = -((*(byte *)(DAT_0087a63c + 0x7a) & 0x10) != 0) & 10;
      DAT_0087a6dd = (&DAT_0086e0f9)[local_c * 0xc] + (char)DAT_00951234;
      if (DAT_0087a6de < (byte)((&DAT_0086e0f9)[local_c * 0xc] + (char)DAT_00951234)) {
        DAT_0087a6dd = DAT_0087a6de;
      }
      uVar8 = DAT_0087a6d8 >> 6 & 1;
      _DAT_0087a67c = (float)*(int *)(DAT_0087a63c + 0x8c + uVar8 * 4);
      if (*(int *)(DAT_0087a63c + 0x8c + uVar8 * 4) < 0) {
        _DAT_0087a67c = _DAT_0087a67c + 4.2949673e+09;
      }
    }
    _DAT_0087a674 = _DAT_0092507c;
    if ((CARRY4(DAT_0087a6ac,DAT_0087a6b0)) || (3999999999 < DAT_0087a6ac + DAT_0087a6b0)) {
      _DAT_0087a678 = 4e+09;
    }
    else {
      _DAT_0087a678 = (float)(int)(DAT_0087a6ac + DAT_0087a6b0);
      if ((int)(DAT_0087a6ac + DAT_0087a6b0) < 0) {
        _DAT_0087a678 = _DAT_0087a678 + 4.2949673e+09;
      }
    }
    DAT_0087a6e3 = '\0';
    if ((DAT_0087a6d8 & 4) == 0) {
      fVar14 = (float10)FUN_00482c10(_DAT_0087a678 * 100.0,_DAT_0087a67c);
      _DAT_0087a680 = (float)fVar14;
      _DAT_0087a6b4 = extraout_EDX;
      if (99.0 < _DAT_0087a680) {
        _DAT_0087a680 = 99.0;
        _DAT_0087a6b4 = extraout_EDX;
      }
    }
    else {
      _DAT_0087a680 = 100.0;
      _DAT_0087a6b4 = DAT_0087a6ac;
    }
    _DAT_0087a6b8 = uVar5;
    if ((((local_c != -1) && ((DAT_0087a6d8 & 0x40) == 0)) && (DAT_0087a640 != 0)) &&
       ((iVar7 = (int)DAT_0087a742, iVar7 < (int)(uint)*(byte *)(DAT_0087a640 + 0x19) &&
        (DAT_0087a740 = *(short *)(DAT_0087a640 + 6 + iVar7 * 2),
        iVar7 < (int)(*(byte *)(DAT_0087a640 + 0x19) - 1))))) {
      DAT_0087a6d8 = DAT_0087a6d8 | 8;
    }
    DAT_0087a1e4 = 0;
    if ((local_c != -1) && (iVar7 = 0, 0 < DAT_00951234)) {
      puVar11 = &DAT_00955fd0;
      do {
        if ((byte)(&DAT_0086e0f9)[local_c * 0xc] < 10) {
          (&DAT_0086e0f9)[local_c * 0xc] = (&DAT_0086e0f9)[local_c * 0xc] + 1;
        }
        iVar9 = *(short *)(puVar11 + 8) * 0x54;
        if ((byte)(&DAT_00866929)[iVar9] < 10) {
          FUN_004f1f10(&DAT_008668d9 + (uint)(byte)(&DAT_00866929)[iVar9] * 8 + iVar9,puVar11);
          (&DAT_00866929)[iVar9] = (&DAT_00866929)[iVar9] + '\x01';
        }
        iVar7 = iVar7 + 1;
        puVar11 = puVar11 + 0xc;
      } while (iVar7 < DAT_00951234);
    }
    uVar10 = DAT_0093b2e8;
    iVar7 = 0;
    uVar12 = 0;
    if ((((local_c != -1) && ((DAT_0087a6d8 & 0x40) == 0)) &&
        ((&DAT_0086e0f5)[local_c * 0xc] == '\0')) && ((*(byte *)(DAT_0087a63c + 0x7a) & 0x26) == 0))
    {
      DAT_0087a6e3 = '\x01';
      (&DAT_0086e0f5)[local_c * 0xc] = 1;
      FUN_0055c820(uVar10);
      if (((DAT_0087a6d8 & 0x100) == 0) && ((*(ushort *)(DAT_0087a63c + 0x7a) & 0x800) == 0)) {
        uVar12 = FUN_00483a90(&DAT_0087a628,DAT_00880708);
      }
      if ((DAT_0087a640 != 0) && (iVar9 = FUN_0059b700(DAT_0087a640,0), iVar9 != 0)) {
        iVar7 = (int)*(char *)(DAT_0087a63c + 0x86);
      }
      iVar4 = DAT_00956290;
      iVar9 = DAT_0087a640;
      if ((DAT_007f39e4 != 0) && (DAT_0087a63c == DAT_0087af50)) {
        (&DAT_0086e0f4)[*(short *)(DAT_00956290 + 0x20) * 0xc] = 1;
        (&DAT_0086e0f4)[*(short *)(iVar4 + 0x3c) * 0xc] = 1;
        (&DAT_0086e0f4)[*(short *)(iVar4 + 0x58) * 0xc] = 1;
        (&DAT_0086e0f4)[*(short *)(iVar4 + 0x74) * 0xc] = 1;
        (&DAT_0086e0f4)[*(short *)(iVar4 + 0x90) * 0xc] = 1;
      }
      if ((DAT_0087a6d8 & 8) == 0) {
        if (iVar9 != 0) {
          iVar9 = FUN_0059b6a0(iVar9,5,4);
          DAT_008059fc = FUN_0059b6a0(DAT_0087a640,5,5);
          if (iVar9 != -1) {
            (&DAT_0086e0f4)[iVar9 * 0xc] = 1;
          }
          if (DAT_008059fc != -1) {
            (&DAT_0086e0f4)[DAT_008059fc * 0xc] = 1;
          }
        }
      }
      else {
        (&DAT_0086e0f4)[DAT_0087a740 * 0xc] = 1;
      }
    }
    if (DAT_0087a6e3 != '\0') {
      FUN_00483ac0(&DAT_0087a628,0xd,uVar12);
    }
    if (iVar7 != 0) {
      FUN_00483ac0(&DAT_0087a628,iVar7 + 0x1d,0);
    }
    if (((DAT_0087af44 != 0) && (DAT_0087a6e3 != '\0')) && (DAT_0087a63c == DAT_0087af44)) {
      FUN_00483ac0(&DAT_0087a628,8,0);
    }
    if (((DAT_0087a63c != 0) && (*(char *)(DAT_0087a63c + 0x7e) != -1)) &&
       (((&DAT_0086e0fa)[local_c * 0xc] == '\0' && (DAT_0095122c != 0)))) {
      FUN_0055c820(DAT_0093b2f8);
      (&DAT_0086e0fa)[local_c * 0xc] = 1;
      FUN_00483ac0(&DAT_0087a628,0x12,0);
    }
    if ((DAT_0087a6e3 != '\0') && (iVar7 = FUN_00483af0(&DAT_0087a628), 0 < iVar7)) {
      if (DAT_007f39e4 == 0) {
        if ((*(byte *)(DAT_0087a628 + 3) & 1) == 0) {
          FUN_00483ac0(&DAT_0087a628,6,0);
          uVar10 = 7;
          goto LAB_00484cd7;
        }
        FUN_00483ac0(&DAT_0087a628,5,0);
      }
      else {
        FUN_00483ac0(&DAT_0087a628,0x23,0);
        uVar10 = 0x24;
LAB_00484cd7:
        FUN_00483ac0(&DAT_0087a628,uVar10,0);
      }
      FUN_0055e1b0(1,(int)DAT_0087a6c4,(int)DAT_0087a6c6);
    }
    uVar10 = DAT_0093b2f4;
    if ((local_c != -1) && ((*(ushort *)(DAT_0087a63c + 0x7a) & 0x136) == 0x10)) {
      if (DAT_0093b314 == 0) {
        iVar7 = local_c * 0xc;
        if (((&DAT_0086e0f6)[iVar7] == '\0') && ((&DAT_0086e0f7)[iVar7] == '\0')) {
          if ((DAT_0087a6d8 & 4) != 0) {
            (&DAT_0086e0f7)[iVar7] = 1;
            (&DAT_0086e0f6)[iVar7] = 1;
            FUN_0055c820(uVar10);
            goto LAB_00484d6c;
          }
          if (_DAT_0087a678 <= 0.0) goto LAB_00484e32;
          if ((DAT_0087a6d8 & 0x800) == 0) goto LAB_00484e01;
        }
      }
      else {
        uVar5 = DAT_0087a6d8 >> 6 & 1;
        if ((&DAT_0086e0f6)[local_c * 0xc + uVar5] == '\0') {
          if ((DAT_0087a6d8 & 4) == 0) {
            if (_DAT_0087a678 <= 0.0) goto LAB_00484e32;
LAB_00484e01:
            FUN_00483ac0(&DAT_0087a628,2,0);
          }
          else {
            (&DAT_0086e0f6)[local_c * 0xc + uVar5] = 1;
            FUN_0055c820(uVar10);
LAB_00484d6c:
            uVar10 = FUN_00483a90(&DAT_0087a628,DAT_008807f8);
            FUN_00483ac0(&DAT_0087a628,1,uVar10);
          }
        }
      }
    }
    if (0.0 < _DAT_0087a678) {
      FUN_00483ac0(&DAT_0087a628,3,0);
    }
LAB_00484e32:
    uVar10 = DAT_0093b2f0;
    if ((((DAT_0087a6de != 0) && ((*(byte *)(DAT_0087a63c + 0x7a) & 0x36) == 0x10)) &&
        (local_c = local_c * 0xc, (&DAT_0086e0f8)[local_c] == '\0')) && (0 < DAT_00951234)) {
      DAT_0087a6bc = DAT_00951234;
      uVar12 = 0;
      if (DAT_0087a6de <= (byte)(&DAT_0086e0f9)[local_c]) {
        DAT_0087a6d8 = DAT_0087a6d8 | 0x10;
        (&DAT_0086e0f8)[local_c] = 1;
        FUN_0055c820(uVar10);
        uVar12 = FUN_00483a90(&DAT_0087a628,DAT_008808b0);
      }
      if ((DAT_0087b720 == 0) || (DAT_0087a6bc != 0)) {
        FUN_00483ac0(&DAT_0087a628,4,uVar12);
      }
      if (((DAT_0087a6d8 & 0x10) != 0) && (iVar7 = FUN_0059a190(&DAT_0086e0f4), iVar7 != 0)) {
        FUN_00594a90((int)DAT_007f195c);
        FUN_00483ac0(&DAT_0087a628,0x11,0);
      }
    }
    if (DAT_0087a6e5 < DAT_0086e4e2) {
      FUN_00483ac0(&DAT_0087a628,0x13,0);
    }
    if ((DAT_0087a6d8 & 0x800) == 0) {
      FUN_00483ac0(&DAT_0087a628,9,0);
    }
    (&DAT_0087a6f0)[DAT_0087a6df] = 10;
    (&DAT_0087a718)[DAT_0087a6df] = 0;
    DAT_0087a6df = DAT_0087a6df + 1;
    if (DAT_00951b50 == 0) {
      FUN_00483ac0(&DAT_0087a628,0xb,0);
    }
    (&DAT_0087a6f0)[DAT_0087a6df] = 0xc;
    (&DAT_0087a718)[DAT_0087a6df] = 0;
    DAT_0087a6df = DAT_0087a6df + 1;
    (&DAT_0087a6f0)[DAT_0087a6df] = 0xff;
    DAT_0087a6e0 = 0xff;
    _DAT_0087a750 = FUN_00483690((int)DAT_0087a6f0);
    FUN_004838f0(&DAT_0087a628);
    _DAT_0087a1a4 = DAT_0086e4c4;
    DAT_0086e4c4 = DAT_0087aa8c;
    return;
  }
  DAT_0087a6e3 = 0;
  _DAT_0087a69c = *DAT_0087a644;
  _DAT_0087a68c = *(float *)(DAT_009553d4 + 8);
  uVar10 = 0;
  _DAT_0087a6a0 = _DAT_0087a69c;
  if (DAT_0087a6cf != '\x02') goto LAB_004845b4;
  if (DAT_009553d8 == 0) {
LAB_0048450d:
    FUN_0055c820(DAT_0093b2fc);
    uVar10 = FUN_00483a90(&DAT_0087a628,DAT_008806c4);
  }
  else {
    iVar7 = (int)*(char *)(*(int *)(DAT_009553d4 + 4) + 0x12);
    if (*(char *)(iVar7 + 0x50 + DAT_009553d8) == '\0') {
      *(undefined1 *)(iVar7 + 0x50 + DAT_009553d8) = 1;
      goto LAB_0048450d;
    }
  }
  iVar7 = FUN_006e6b90();
  uVar5 = iVar7 * 0x96;
  iVar7 = (int)uVar5 >> 0x1f;
  if ((-1 < (int)uVar5) && (uVar5 < 0x96)) {
    uVar5 = 0x96;
    iVar7 = 0;
  }
  FUN_005533f0(&DAT_0087a6a0,uVar5,iVar7,0);
  if ((DAT_009553d8 != 0) &&
     ((iVar7 = (int)*(char *)(*(int *)(DAT_009553d4 + 4) + 0x12),
      pfVar1 = (float *)(DAT_009553d8 + iVar7 * 4), *(float *)(DAT_009553d8 + iVar7 * 4) == 0.0 ||
      (_DAT_0087a68c < *pfVar1)))) {
    *pfVar1 = _DAT_0087a68c;
  }
LAB_004845b4:
  FUN_00483ac0(&DAT_0087a628,0x1a,uVar10);
  if (DAT_0087a6e5 < DAT_0086e4e2) {
    FUN_00483ac0(&DAT_0087a628,0x13,0);
  }
  (&DAT_0087a6f0)[DAT_0087a6df] = 9;
  (&DAT_0087a718)[DAT_0087a6df] = 0;
  DAT_0087a6df = DAT_0087a6df + 1;
  (&DAT_0087a6f0)[DAT_0087a6df] = 10;
  (&DAT_0087a718)[DAT_0087a6df] = 0;
  DAT_0087a6df = DAT_0087a6df + 1;
  if (DAT_00951b50 == 0) {
    FUN_00483ac0(&DAT_0087a628,0xb,0);
  }
  (&DAT_0087a6f0)[DAT_0087a6df] = 0xc;
  (&DAT_0087a718)[DAT_0087a6df] = 0;
  DAT_0087a6df = DAT_0087a6df + 1;
  (&DAT_0087a6f0)[DAT_0087a6df] = 0xff;
  DAT_0087a6e0 = 0xff;
  _DAT_0087a750 = FUN_00483690((int)DAT_0087a6f0);
  FUN_004838f0(&DAT_0087a628);
  DAT_0087a1e4 = 1;
  DAT_007fc378 = 0xc3;
  DAT_007fc374 = 0xc3;
  return;
}

