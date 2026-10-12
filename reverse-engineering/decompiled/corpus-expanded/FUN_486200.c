/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x486200; label: FUN_00486200
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00486200(void)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  code *pcVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  undefined2 in_FPUControlWord;
  float10 extraout_ST0;
  float10 fVar16;
  float local_114;
  float local_110;
  float local_10c [2];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_114;
  _DAT_0087a1d0 = -1.0;
  _memset(&DAT_0087a330,0,0x2d0);
  if (DAT_0093b338 != 0) {
    if ((DAT_0093b338 == 1) && (_DAT_00950780 == 0.0)) {
      local_114 = -0.75 - _DAT_00800994 * 0.5;
      local_10c[0] = *(float *)(DAT_00926c20 + DAT_00880888 * 4);
      local_10c[1] = (float)*(undefined4 *)(DAT_00926c20 + DAT_00880ba0 * 4);
      iVar12 = 0;
      do {
        bVar6 = DAT_00921dae;
        fVar16 = (float10)0;
        if (iVar12 == DAT_0087a778) {
          bVar3 = DAT_008009a2;
          bVar4 = DAT_008009a1;
          bVar5 = DAT_00921dae;
          if (DAT_009213e4 != 0) {
            bVar3 = DAT_008009a0;
            bVar4 = DAT_00921dad;
            bVar5 = DAT_0080099f;
          }
          uVar14 = (uint)bVar5;
          uVar13 = (uint)bVar4;
          uVar9 = (uint)bVar3;
          if (fVar16 < (float10)_DAT_00921d70) {
            local_110 = (float)(uint)DAT_008009a1;
            uVar13 = FUN_006e6b90();
            local_110 = (float)(uint)bVar6;
            uVar14 = FUN_006e6b90();
            local_110 = (float)(uint)DAT_008009a2;
            uVar9 = FUN_006e6b90();
            fVar16 = extraout_ST0;
          }
        }
        else {
          uVar13 = (uint)DAT_00921da9;
          uVar14 = (uint)DAT_0080099a;
          uVar9 = (uint)DAT_0080099b;
        }
        FUN_00511500(local_10c[iVar12],(float)fVar16,local_114,0x3f800000,_DAT_0080098c,
                     _DAT_0080098c,_DAT_0080098c,0,uVar13,uVar14,uVar9);
        local_114 = _DAT_00800994 + local_114;
        iVar12 = iVar12 + 1;
      } while (iVar12 < 2);
      __security_check_cookie(local_4 ^ (uint)&local_114);
      return;
    }
    goto LAB_00486927;
  }
  if (0.0 < _DAT_00950780) goto LAB_00486927;
  if (DAT_0087a6dc == '\0') {
    local_114 = _DAT_007fa4b4 - _DAT_0092505c;
    if (local_114 < 0.0) {
      local_114 = 0.0;
    }
    FUN_0054bbc0(local_114,0,0,0,local_104);
    fVar16 = (float10)FUN_005b7d30(_DAT_0092505c,0x3f000000,0x3f800000,0x3f800000,0x3f800000,
                                   0x3f800000,0,0xff,0xbf,0);
    local_10c[0] = (float)(&DAT_029899a0)
                          [(uint)(int)ROUND((fVar16 + fVar16) * (float10)65536.0) >> 1 & 0x7fff] *
                   0.01;
    fVar16 = (float10)FUN_005b7d30(_DAT_0092505c,0x3edd2f1b,local_10c[0]);
    local_114 = (float)CONCAT22(local_114._2_2_,in_FPUControlWord);
    local_10c[0] = (float)(&DAT_029899a0)
                          [(uint)(int)ROUND((fVar16 / (float10)0.4320000112056732) *
                                            (float10)65536.0) >> 1 & 0x7fff] * 0.01;
    FUN_00511500(local_104,local_10c[0]);
    __security_check_cookie(local_4 ^ (uint)&local_114);
    return;
  }
  if (DAT_0087a638 != (code *)0x0) {
    (*DAT_0087a638)(&DAT_0087a628);
  }
  if ((((DAT_0087a32c != -1) && (DAT_0087a1e0 != -1)) && (DAT_0087a74c[5] == DAT_0087a32c)) &&
     (DAT_0087a6e0 == DAT_0087a1e0)) {
    if (DAT_0087a32c == 4) {
      fVar2 = 5.5;
      fVar1 = (float)DAT_0087a74c[6];
      if (!NAN(fVar1) && 5.5 < fVar1 != (fVar1 == 5.5)) goto LAB_00486483;
    }
    else {
      fVar2 = (float)DAT_0087a74c[7];
    }
    local_110 = fVar2;
    fVar16 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
    uVar13 = (int)ROUND(fVar16 * (float10)0.25 * (float10)65536.0) & 0xffff;
    fVar2 = (float)(&DAT_029899a0)[(int)(uVar13 * 2) >> 1 & 0x7fff];
    local_114 = (float)CONCAT22(local_114._2_2_,in_FPUControlWord);
    local_10c[0] = (float)((float10)local_110 * (float10)0.25);
    local_110 = (float)((float10)0.75 * (float10)local_110);
    if (((float)DAT_0087a74c[6] < local_10c[0]) || (local_110 <= (float)DAT_0087a74c[6])) {
      iVar12 = FUN_006e6b90();
      local_114 = (float)(&DAT_029899a0)[iVar12 >> 1 & 0x7fff];
    }
    else {
      local_114 = 1.0;
    }
    local_10c[0] = _DAT_007fa4d8 * local_114;
    FUN_00552d10(_DAT_007fa4d0,_DAT_007fa4d4,0x3f800000,local_10c[0],local_10c[0],local_10c[0],
                 (int)ROUND(fVar2 * 1820.0) & 0xffff,uVar13,0,
                 *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd30,2);
    if (DAT_0080235c != 0) {
      fVar2 = local_114 * 128.0;
      local_114 = (float)CONCAT22(local_114._2_2_,in_FPUControlWord);
      local_10c[0] = _DAT_007fa4d4 - 0.15;
      FUN_0050c780(&DAT_0075993c,_DAT_007fa4d0,local_10c[0],0x3f800000,0x3f000000,0x3f000000,
                   0x3f000000,0,0xff,0,0xff,(int)ROUND(fVar2) & 0xff);
    }
  }
LAB_00486483:
  iVar12 = 0;
  piVar11 = DAT_0087a74c;
  if (*(int *)(DAT_0087a600 + 0xc) != -1) {
    iVar7 = 0;
    do {
      piVar8 = (int *)(iVar7 + DAT_0087a600);
      pcVar10 = (code *)*piVar8;
      if (pcVar10 != (code *)0x0) {
        bVar15 = piVar8 == piVar11;
        if (bVar15) {
          pcVar10 = (code *)*piVar11;
          piVar8 = piVar11;
        }
        (*pcVar10)(piVar8,&DAT_0087a628,bVar15);
        piVar11 = DAT_0087a74c;
      }
      iVar12 = iVar12 + 1;
      iVar7 = iVar12 * 0x20;
    } while (*(int *)(iVar7 + 0xc + DAT_0087a600) != -1);
  }
  iVar12 = piVar11[3];
  if (iVar12 == 0xb) goto LAB_00486927;
  if (iVar12 == 0xc) {
LAB_0048676e:
    local_114 = 0.0;
  }
  else if (iVar12 == 10) {
    if (1.0 <= (float)piVar11[6]) goto LAB_0048676e;
    local_114 = 1.0 - (float)piVar11[6];
  }
  else {
    local_114 = 1.0;
    if ((iVar12 == 0x13) && (local_114 = 1.0, piVar11[5] != 0)) {
      if (1.0 <= (float)piVar11[6]) {
        local_10c[0] = (float)piVar11[7] - 1.0;
        if (local_10c[0] < (float)piVar11[6] == (local_10c[0] == (float)piVar11[6]))
        goto LAB_0048676e;
        local_114 = ((float)piVar11[6] - local_10c[0]) / ((float)piVar11[7] - local_10c[0]);
      }
      else {
        local_114 = 1.0 - (float)piVar11[6];
      }
    }
  }
  if (DAT_0087a1e4 != 0) {
    local_110 = _DAT_0087a1d0;
    if (_DAT_0087a1d0 < 0.0) {
      local_110 = local_114;
    }
    FUN_00485030(&DAT_0087a628,_DAT_0087a188,local_110);
    __security_check_cookie(local_4 ^ (uint)&local_114);
    return;
  }
LAB_00486927:
  __security_check_cookie(local_4 ^ (uint)&local_114);
  return;
}

