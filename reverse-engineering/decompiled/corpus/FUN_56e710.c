/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56e710; label: FUN_0056e710
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056e710(uint *param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  uint uVar4;
  float fVar5;
  bool bVar6;
  char cVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  float10 fVar14;
  float local_198;
  int local_188;
  float local_184;
  float local_180;
  float local_17c;
  float local_178;
  float local_174;
  float local_170;
  float local_16c;
  float local_168;
  float local_164;
  float local_160;
  undefined1 local_15c [12];
  uint local_150;
  uint local_14c;
  uint local_148;
  undefined4 local_138;
  uint local_134;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  undefined4 local_48;
  undefined1 local_38;
  undefined1 local_37;
  
  fVar1 = (float)param_1[7];
  bVar6 = false;
  fVar2 = (float)param_1[8];
  uVar12 = *(ushort *)((int)param_1 + 0x2a);
  fVar5 = (fVar1 / fVar2) * (float)param_1[6];
  if ((param_1[9] & 0x10) != 0) {
    iVar10 = 5;
    do {
      uVar8 = FUN_0062c350(0x42200000,_DAT_00925018);
      local_168 = (float)param_1[3] + fVar5 * (float)(&DAT_029899a0)[uVar12 >> 1];
      local_164 = (float)param_1[4] + (fVar1 / fVar2) * 0.1;
      local_160 = fVar5 * (float)(&DAT_029899a0)[(int)(uVar12 + 0x4000) >> 1 & 0x7fff] +
                  (float)param_1[5];
      FUN_0062c680(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),(int)(short)param_1[0xb],&local_168,
                   uVar8,0,0);
      uVar12 = uVar12 + 0x3333;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  local_180 = (float)param_1[3] - fVar5;
  local_178 = (float)param_1[5] - fVar5;
  local_174 = fVar5 + (float)param_1[3];
  local_16c = fVar5 + (float)param_1[5];
  local_17c = (float)param_1[4] - fVar5;
  local_170 = fVar5 + (float)param_1[4];
  if (((param_1[9] & 0x100) == 0) && (local_188 = 0, uVar13 = DAT_0093d504, 0 < DAT_0093d500)) {
    do {
      if ((((((*(uint *)(uVar13 + 0x1fc) & 1) != 0) &&
            (((((*(uint *)(uVar13 + 0x1fc) & 0x1000) != 0 && (*(char *)(uVar13 + 0x28b) == '\0')) &&
              ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(uVar13 + 0x7b5) * 0x10 + 8) & 0x8000) == 0))
             && (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(uVar13 + 0x7b5) * 0x10 + 8) & 0x20008000)
                  == 0 && ((*(uint *)(*(int *)(*(int *)(uVar13 + 0x54) + 0x24) + 0x90) & 0x8000) ==
                           0)))))) &&
           ((uVar9 = param_1[9], -1 < (char)uVar9 ||
            ((*(byte *)(*(int *)(uVar13 + 0x54) + 4) & 0x10) == 0)))) &&
          (((((uVar9 & 0x4000) == 0 || (*(char *)(uVar13 + 0x280) == -1)) &&
            (((uVar9 & 8) != 0 ||
             (((*(uint *)(uVar13 + 0x1e8) & *param_1) == 0 &&
               (*(uint *)(uVar13 + 0x1ec) & param_1[1]) == 0 && (param_1[2] != uVar13)))))) &&
           (*(float *)(uVar13 + 0x178) <= local_174)))) &&
         ((((local_180 <= *(float *)(uVar13 + 0x184) && (*(float *)(uVar13 + 0x17c) <= local_170))
           && (local_17c <= *(float *)(uVar13 + 0x188))) &&
          ((*(float *)(uVar13 + 0x180) <= local_16c && (local_178 <= *(float *)(uVar13 + 0x18c))))))
         ) {
        iVar10 = FUN_0054fce0((float *)(uVar13 + 0x80),*(undefined4 *)(uVar13 + 0x1dc),
                              *(undefined4 *)(uVar13 + 0x1e0),param_1 + 3,fVar5,fVar5);
        if (iVar10 != 0) {
          if ((param_1[9] & 8) != 0) {
            local_184 = *(float *)(uVar13 + 0x80) - (float)param_1[3];
            local_198 = *(float *)(uVar13 + 0x88) - (float)param_1[5];
            if ((local_184 == 0.0) && (local_198 == 0.0)) {
              iVar10 = FUN_0054fa60();
              local_184 = (float)iVar10 * 1.5259022e-05 - 0.5;
              iVar10 = FUN_0054fa60();
              local_198 = (float)iVar10 * 1.5259022e-05 - 0.5;
            }
            fVar14 = (float10)FUN_005c0240(local_184 * local_184 + local_198 * local_198);
            fVar1 = _DAT_00803334;
            *(float *)(uVar13 + 0x200) = _DAT_00803334 * (float)((float10)1 / fVar14) * local_184;
            *(float *)(uVar13 + 0x208) = fVar1 * local_198 * (float)((float10)1 / fVar14);
          }
          if (((((!bVar6) && ((param_1[9] & 1) != 0)) &&
               ((*(uint *)(uVar13 + 0x1e8) & *param_1) == 0 &&
                (*(uint *)(uVar13 + 0x1ec) & param_1[1]) == 0)) &&
              (((uVar13 != param_1[2] && (*(float *)(uVar13 + 0x1000) <= 0.0)) &&
               ((*(uint *)(uVar13 + 0xef0) & 0x400000) == 0)))) &&
             (((*(char *)(uVar13 + 0x280) == -1 || (*(float *)(uVar13 + 0x1018) <= 0.0)) ||
              ((param_1[9] & 0x2000) != 0)))) {
            if ((param_1[2] != 0) &&
               ((iVar10 = FUN_00475850(0), iVar10 != 0 || ((param_1[9] & 0x10010) == 0)))) {
              if (*(char *)(uVar13 + 0x280) == -1) {
                if (*(char *)(param_1[2] + 0x280) == -1) {
LAB_0056eb8b:
                  if (((*(uint *)(param_1[2] + 0x1f8) ^ *(uint *)(uVar13 + 0x1f8)) & 1) == 0)
                  goto LAB_0056ed30;
                }
              }
              else if ((*(char *)(param_1[2] + 0x280) != -1) && (*(float *)(uVar13 + 0xd30) != 1.0))
              goto LAB_0056eb8b;
            }
            *param_1 = *param_1 | *(uint *)(uVar13 + 0x1e8);
            param_1[1] = param_1[1] | *(uint *)(uVar13 + 0x1ec);
            if (((*(float *)(uVar13 + 0xd30) < 0.99) ||
                (FUN_00433be0(param_1[2],uVar13,*(undefined1 *)(uVar13 + 0xe38),0),
                (param_1[9] & 0x20) != 0)) && (iVar10 = FUN_0058b7f0(uVar13), iVar10 == 0)) {
              if (((*(byte *)(uVar13 + 0x1fc) & 0x80) == 0) ||
                 (iVar10 = FUN_0055f1d0(uVar13), iVar10 == 0)) {
                if (((param_1[9] & 0x800) == 0) || ((*(uint *)(uVar13 + 0xeec) & 0x8000000) != 0)) {
                  if ((((param_1[9] & 0x20) == 0) || ((*(uint *)(uVar13 + 0xeec) & 0x8000000) != 0))
                     || (*(char *)(uVar13 + 0x107f) < '\x01')) {
                    uVar9 = (uint)*(byte *)((int)param_1 + 0x32);
                  }
                  else {
                    uVar9 = 0xffffffff;
                  }
                }
                else {
                  uVar9 = 0xffffffff;
                }
              }
              else {
                uVar9 = 0;
              }
              uVar4 = param_1[2];
              uVar11 = uVar4;
              if (((uVar4 == 0) && (uVar11 = DAT_0093d7f0, *(char *)((int)param_1 + 0x33) != '\0'))
                 && (uVar11 = uVar4, *(char *)((int)param_1 + 0x33) == '\x01')) {
                uVar11 = DAT_0093d7f4;
              }
              uVar12 = *(ushort *)((int)param_1 + 0x2e) | 0x200;
              if ((param_1[9] & 0x200) != 0) {
                uVar12 = *(ushort *)((int)param_1 + 0x2e) | 0x4200;
              }
              iVar10 = FUN_00438230(uVar11,uVar13,uVar9,uVar12,0,1);
              if (iVar10 == 2) {
                if (uVar11 != 0) {
                  FUN_0054a850(**(undefined4 **)(uVar11 + 0xca4),0x3f000000,0);
                }
                *(short *)(param_1 + 0xc) = (short)param_1[0xc] + 1;
                if ((((param_1[9] & 0x200) != 0) &&
                    ((cVar7 = *(char *)((int)param_1 + 0x33), cVar7 == '\0' || (cVar7 == '\x01'))))
                   && (DAT_0093b324 != 0)) {
                  cVar3 = *(char *)(uVar13 + 0x280);
                  if ((cVar3 == '\0') || (cVar3 == '\x01')) {
                    FUN_00475fb0(cVar3 == '\0',0);
                  }
                  else if (cVar3 == -1) {
                    FUN_00476010((int)cVar7);
                    FUN_0056e6b0();
                    bVar6 = true;
                    goto LAB_0056ed30;
                  }
                }
              }
              FUN_0056e6b0();
            }
            bVar6 = true;
          }
        }
      }
LAB_0056ed30:
      local_188 = local_188 + 1;
      uVar13 = uVar13 + 0x10d8;
    } while (local_188 < DAT_0093d500);
    if (bVar6) goto LAB_0056edcb;
  }
  uVar13 = param_1[9];
  if ((uVar13 & 2) != 0) {
    if ((uVar13 & 0x10) == 0) {
      if ((uVar13 & 0x100) == 0) {
        if ((uVar13 & 0x200) == 0) {
          cVar7 = (-((uVar13 & 0x8000) != 0) & 7U) + 2;
        }
        else {
          cVar7 = '\b';
        }
      }
      else {
        cVar7 = '\a';
      }
    }
    else {
      cVar7 = '\x03';
    }
    iVar10 = FUN_00569c70(param_1[2],param_1 + 3,1,fVar5,&local_180,&local_174,0,cVar7,0);
    if (iVar10 != 0) {
      FUN_0056e6b0();
      return;
    }
  }
LAB_0056edcb:
  if (((param_1[9] & 0x100) == 0) && ((param_1[9] & 4) != 0)) {
    local_150 = param_1[3];
    local_134 = param_1[2];
    local_14c = param_1[4];
    local_148 = param_1[5];
    local_38 = 0;
    local_48 = 0x200;
    local_37 = 1;
    local_b0 = local_150;
    local_ac = local_14c;
    local_a8 = local_148;
    local_138 = FUN_005806a0(1,PTR_DAT_00802c54);
    iVar10 = FUN_00580a10(&local_138,local_15c,&local_180,&local_174,fVar5,0);
    if (iVar10 != 0) {
      FUN_0056e6b0();
    }
  }
  return;
}

