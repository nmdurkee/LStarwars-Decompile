/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x583af0; label: FUN_00583af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00583af0(int param_1,int param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  bool bVar9;
  undefined2 in_FPUControlWord;
  float10 fVar10;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  float fStack_160;
  uint local_15c;
  float *pfStack_158;
  undefined4 *local_154;
  undefined *local_150;
  undefined1 *puStack_14c;
  float *pfStack_148;
  int local_144;
  int local_140;
  float fStack_13c;
  float fStack_138;
  undefined4 uStack_134;
  float local_130;
  int local_12c;
  float local_128;
  undefined4 local_124;
  undefined4 local_120;
  float local_11c [3];
  undefined1 auStack_110 [12];
  uint auStack_104 [8];
  uint uStack_e4;
  uint uStack_e0;
  undefined1 auStack_d8 [12];
  uint uStack_cc;
  uint uStack_c8;
  undefined1 auStack_c0 [12];
  undefined1 auStack_b4 [64];
  undefined4 auStack_74 [24];
  short asStack_14 [8];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&fStack_16c;
  local_140 = 0;
  local_12c = 0;
  if ((param_2 < 0) || (*(int *)(PTR_PTR_008040bc + 4) <= param_2)) {
    if ((PTR_DAT_00802c54 == (undefined *)0x0) ||
       ((iVar6 = *(int *)(PTR_PTR_008040bc + 4), param_2 < iVar6 || (iVar6 + 8 <= param_2)))) {
      local_150 = (undefined *)0x0;
    }
    else {
      local_150 = PTR_DAT_00802c54 + (param_2 - iVar6) * 0xa4 + 0x4b14;
    }
  }
  else {
    local_150 = (undefined *)(param_2 * 0xa4 + *(int *)PTR_PTR_008040bc);
  }
  local_130 = *(float *)(local_150 + 0x10);
  uVar2 = *(uint *)(local_150 + 0x60);
  local_154 = *(undefined4 **)(local_150 + 0x14);
  local_144 = 0;
  local_15c = uVar2;
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    local_15c = uVar2 | 0x20;
    if (*(char *)(param_1 + 0x280) == '\0') {
      local_15c = uVar2 | 0x21;
    }
    else if (*(char *)(param_1 + 0x280) == '\x01') {
      local_15c = uVar2 | 0x22;
    }
  }
  if ((*(byte *)(param_1 + 0xef0) & 8) != 0) {
    local_15c = local_15c | 0x40;
  }
  local_124 = *(undefined4 *)(param_1 + 0xc84);
  local_128 = *(float *)(param_1 + 0xc80);
  local_120 = *(undefined4 *)(param_1 + 0xc88);
  (**(code **)(PTR_PTR_008040bc + 0x10))(param_1,local_11c);
  uVar2 = (**(code **)(PTR_PTR_008040bc + 0x14))(param_1,auStack_c0);
  fStack_16c = (float)(uVar2 & 0xffff);
  if ((*(char *)(param_1 + 0x7b5) != -1) && (sVar1 = *(short *)(param_1 + 0x7aa), sVar1 != -1)) {
    if (sVar1 == DAT_00804c20) {
      fStack_16c = (float)((int)fStack_16c + 0x4000);
    }
    else if (sVar1 == DAT_00804c24) {
      fStack_16c = (float)((int)fStack_16c + 0xc000);
    }
    else if (sVar1 == DAT_00804c28) {
      fStack_16c = (float)((int)fStack_16c + 0x8000);
    }
  }
  if ((*(uint *)(param_1 + 0xe20) & 0x800) == 0) {
    fStack_164 = 0.0;
  }
  else if (((((*(uint *)(param_1 + 0xeec) & 0x8000) == 0) && (*(int *)(param_1 + 0xea0) == 0)) &&
           (*(char *)(param_1 + 0x280) != -1)) &&
          (((*(float *)(param_1 + 0xc8c) != 0.0 || (*(float *)(param_1 + 0xc90) != 0.0)) ||
           (*(float *)(param_1 + 0xc94) != 0.0)))) {
    fStack_164 = (float)local_154 * local_130;
    FUN_005b3800(&fStack_13c,&local_128,local_11c);
    FUN_005b3b30(&fStack_13c,&fStack_13c);
    FUN_005b3830(&fStack_13c,&fStack_13c,fStack_164);
    FUN_005b37d0(&local_128,local_11c,&fStack_13c);
  }
  else {
    fVar10 = (float10)FUN_005becc0(local_11c,&local_128,0);
    fStack_164 = (float)fVar10;
  }
  uVar2 = *(uint *)(param_1 + 0xeec);
  pfStack_158 = (float *)0x0;
  pfStack_148 = (float *)0x0;
  puStack_14c = (undefined1 *)0x0;
  fVar5 = fStack_164;
  if ((uVar2 & 0x8000) == 0) {
    iVar6 = *(int *)(param_1 + 0xea0);
    if (iVar6 != 0) {
      pfVar7 = (float *)(iVar6 + 0x80);
      puStack_14c = (undefined1 *)(iVar6 + 0x68);
      pfStack_148 = pfVar7;
      if (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) == 0) &&
         ((*(byte *)(param_1 + 0x1f8) & 1) != 0)) {
        fStack_13c = *pfVar7;
        fStack_138 = *(float *)(iVar6 + 0x84);
        uStack_134 = *(undefined4 *)(iVar6 + 0x88);
        fVar10 = (float10)FUN_005809a0(iVar6);
        local_154 = auStack_74;
        fStack_138 = (float)(fVar10 + (float10)fStack_138);
        iVar6 = 0;
        fVar5 = fStack_164;
        pfStack_158 = &fStack_13c;
      }
      else {
        local_154 = auStack_74;
        iVar6 = 0;
        pfStack_158 = pfVar7;
      }
      goto LAB_00583e99;
    }
    if ((*(uint *)(param_1 + 0xe20) & 0x800) != 0) {
      pfStack_148 = &local_128;
    }
  }
  else {
    pfVar7 = (float *)(param_1 + 0xe4c);
    pfStack_148 = pfVar7;
    if (((uVar2 & 0x10000) == 0) && ((uVar2 & 0x20000) != 0)) {
      pfStack_158 = pfVar7;
      FUN_005b3800(auStack_110,pfVar7,param_1 + 0xe58);
      local_154 = (undefined4 *)(1.0 / _DAT_00925018);
      FUN_005b3830(auStack_110,auStack_110,local_154);
      puStack_14c = auStack_110;
      local_154 = auStack_74;
      iVar6 = 0;
      fVar5 = fStack_164;
      goto LAB_00583e99;
    }
  }
  local_154 = auStack_74;
  iVar6 = 0;
  pfVar7 = pfStack_148;
  pfStack_158 = pfStack_148;
LAB_00583e99:
  do {
    if (param_3 == 1) {
      bVar9 = iVar6 == 1;
LAB_00583eb0:
      if (!bVar9) goto LAB_00583eb6;
    }
    else {
      if (param_3 == 2) {
        bVar9 = iVar6 == 0;
        goto LAB_00583eb0;
      }
LAB_00583eb6:
      if ((iVar6 != -1) &&
         ((*(int *)(PTR_PTR_008040bc + 0x1c) == 0 ||
          (iVar3 = (**(code **)(PTR_PTR_008040bc + 0x1c))(param_1,iVar6), fVar5 = fStack_164,
          iVar3 != 0)))) {
        if (iVar6 == 4) {
          if (local_12c != 0) break;
          pfVar8 = local_11c;
LAB_00583f61:
          if ((local_15c & 0x600000) == 0) {
            if (pfStack_158 == (float *)0x0) {
              if (*(char *)(param_1 + 0x107a) == '\x04') {
                FUN_0054ff40(auStack_c0,0,0);
                auStack_104[5] = (uint)DAT_0092b0c4;
                auStack_104[6] = (uint)DAT_0093b0c8;
                FUN_005c0820(auStack_b4,auStack_104 + 5);
              }
              else {
                FUN_0057f700();
              }
            }
            else {
              if ((puStack_14c == (undefined1 *)0x0) ||
                 ((*(uint *)(param_1 + 0xeec) & 0x20000) == 0)) {
                FUN_005b3800(auStack_d8,pfStack_158,pfVar8);
              }
              else {
                FUN_00550250(pfVar8,pfVar7,puStack_14c,local_130,auStack_d8,0);
              }
              FUN_0054ff40(auStack_d8,0,0);
              uStack_cc = (uint)DAT_0092b0c4;
              uStack_c8 = (uint)DAT_0093b0c8;
              FUN_005c0820(auStack_b4,&uStack_cc);
            }
          }
          else {
            if ((((int)local_15c < 0) && ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0)) &&
               (*(int *)(param_1 + 0xea0) != 0)) {
              fVar10 = (float10)FUN_005bed80(*(int *)(param_1 + 0xea0) + 0x80,param_1 + 0x80,0);
              fStack_168 = (float)fVar10;
              if (2.0 < fStack_168) {
                fStack_168 = 2.0;
              }
              if ((local_15c & 0x200000) == 0) {
                fVar5 = -20.0;
              }
              else {
                fVar5 = -10.0;
              }
              fVar5 = fVar5 * fStack_168;
              fStack_168 = (float)CONCAT22(fStack_168._2_2_,in_FPUControlWord);
              fStack_160 = (float)(int)ROUND((fVar5 * 0.5 * 65536.0) / 360.0);
              fVar5 = fStack_160;
            }
            else {
              fVar5 = (float)((-(uint)((local_15c & 0x200000) != 0) & 0x71c) + 0xf1c8);
            }
            if (pfStack_158 != (float *)0x0) {
              fStack_160 = *pfStack_158 - *pfVar8;
              uVar2 = FUN_005be2d0(fStack_160,pfStack_158[2] - pfVar8[2]);
              fStack_16c = (float)(uVar2 & 0xffff);
            }
            uStack_e0 = (uint)fStack_16c & 0xffff;
            uStack_e4 = (uint)fVar5 & 0xffff;
            FUN_005c0820(auStack_b4,&uStack_e4);
            pfVar7 = pfStack_148;
          }
          DAT_009543e8 = 1;
          iVar3 = FUN_00582e70(param_1,pfVar8,auStack_b4,param_2,0);
          if (iVar3 != 0) {
            auStack_104[local_140] = (uint)*(byte *)(iVar3 + 0x103);
            local_140 = local_140 + 1;
          }
          if ((DAT_00951cbc != -1) && (local_144 < 8)) {
            asStack_14[local_144] = (short)DAT_00951cbc;
            *local_154 = DAT_00951cd8;
            local_154[1] = DAT_00951cdc;
            local_144 = local_144 + 1;
            local_154[2] = DAT_00951ce0;
            local_154 = local_154 + 3;
          }
          fVar5 = fStack_164;
          if ((*(uint *)(local_150 + 0x60) & 0x20000000) != 0) {
            *(undefined4 *)(param_1 + 0xd54) = _DAT_00804014;
          }
        }
        else if (*(char *)(param_1 + 0x288) != '\0') {
          iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
          iVar4 = (int)*(char *)(iVar3 + 0xfc + iVar6);
          if ((iVar4 == -1) || (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar4 * 4) == 0)) {
            iVar4 = (int)*(char *)(iVar3 + iVar6 + 0xf8);
          }
          if ((iVar4 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar4 * 4) != 0)) {
            pfVar8 = (float *)(iVar4 * 0x40 + 0x834 + param_1);
            local_12c = 1;
            if (pfVar8 != (float *)0x0) goto LAB_00583f61;
          }
        }
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  iVar6 = local_144;
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x40000;
  if (0 < local_144) {
    if (local_144 < 2) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_0054fa60();
      iVar3 = iVar3 / ((int)(0xffff / (longlong)iVar6) + 1);
    }
    FUN_005478a0((int)asStack_14[iVar3],auStack_74 + iVar3 * 3,0,0);
    fVar5 = fStack_164;
  }
  if (((*(uint *)(param_1 + 0xe20) & 0x800) != 0) && (1 < local_140)) {
    iVar6 = 0;
    if (3 < local_140) {
      do {
        uVar2 = auStack_104[iVar6];
        if ((fVar5 == 0.0) ||
           ((float)(&DAT_00951db4)[uVar2 * 0x4e] * (float)(&DAT_00951db8)[uVar2 * 0x4e] == 0.0)) {
          fStack_168 = 0.0;
        }
        else {
          fStack_168 = fVar5 / ((float)(&DAT_00951db4)[uVar2 * 0x4e] *
                               (float)(&DAT_00951db8)[uVar2 * 0x4e]);
        }
        if (*(float *)(local_150 + 0x14) * fStack_168 < (float)(&DAT_00951db8)[uVar2 * 0x4e]) {
          (&DAT_00951db8)[uVar2 * 0x4e] = *(float *)(local_150 + 0x14) * fStack_168;
        }
        uVar2 = auStack_104[iVar6 + 1];
        if ((fVar5 == 0.0) ||
           ((float)(&DAT_00951db4)[uVar2 * 0x4e] * (float)(&DAT_00951db8)[uVar2 * 0x4e] == 0.0)) {
          fStack_168 = 0.0;
        }
        else {
          fStack_168 = fVar5 / ((float)(&DAT_00951db4)[uVar2 * 0x4e] *
                               (float)(&DAT_00951db8)[uVar2 * 0x4e]);
        }
        if (*(float *)(local_150 + 0x14) * fStack_168 < (float)(&DAT_00951db8)[uVar2 * 0x4e]) {
          (&DAT_00951db8)[uVar2 * 0x4e] = *(float *)(local_150 + 0x14) * fStack_168;
        }
        uVar2 = auStack_104[iVar6 + 2];
        if ((fVar5 == 0.0) ||
           ((float)(&DAT_00951db4)[uVar2 * 0x4e] * (float)(&DAT_00951db8)[uVar2 * 0x4e] == 0.0)) {
          fStack_168 = 0.0;
        }
        else {
          fStack_168 = fVar5 / ((float)(&DAT_00951db4)[uVar2 * 0x4e] *
                               (float)(&DAT_00951db8)[uVar2 * 0x4e]);
        }
        if (*(float *)(local_150 + 0x14) * fStack_168 < (float)(&DAT_00951db8)[uVar2 * 0x4e]) {
          (&DAT_00951db8)[uVar2 * 0x4e] = *(float *)(local_150 + 0x14) * fStack_168;
        }
        uVar2 = auStack_104[iVar6 + 3];
        if ((fVar5 == 0.0) ||
           ((float)(&DAT_00951db4)[uVar2 * 0x4e] * (float)(&DAT_00951db8)[uVar2 * 0x4e] == 0.0)) {
          fStack_168 = 0.0;
        }
        else {
          fStack_168 = fVar5 / ((float)(&DAT_00951db4)[uVar2 * 0x4e] *
                               (float)(&DAT_00951db8)[uVar2 * 0x4e]);
        }
        fStack_16c = *(float *)(local_150 + 0x14) * fStack_168;
        if (fStack_16c < (float)(&DAT_00951db8)[uVar2 * 0x4e]) {
          (&DAT_00951db8)[uVar2 * 0x4e] = fStack_16c;
        }
        iVar6 = iVar6 + 4;
      } while (iVar6 < local_140 + -3);
    }
    for (; iVar6 < local_140; iVar6 = iVar6 + 1) {
      uVar2 = auStack_104[iVar6];
      if ((fVar5 == 0.0) ||
         ((float)(&DAT_00951db4)[uVar2 * 0x4e] * (float)(&DAT_00951db8)[uVar2 * 0x4e] == 0.0)) {
        fStack_168 = 0.0;
      }
      else {
        fStack_168 = fVar5 / ((float)(&DAT_00951db4)[uVar2 * 0x4e] *
                             (float)(&DAT_00951db8)[uVar2 * 0x4e]);
      }
      fStack_16c = *(float *)(local_150 + 0x14) * fStack_168;
      if (fStack_16c < (float)(&DAT_00951db8)[uVar2 * 0x4e]) {
        (&DAT_00951db8)[uVar2 * 0x4e] = fStack_16c;
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)&fStack_16c);
  return;
}

