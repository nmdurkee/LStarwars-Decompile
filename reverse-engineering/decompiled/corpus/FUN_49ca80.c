/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49ca80; label: FUN_0049ca80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0049ca80(int param_1,float param_2,float param_3,int param_4,int param_5,int param_6)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  float10 fVar15;
  float local_18 [2];
  float local_10;
  float local_c [2];
  float local_4;
  
  iVar7 = param_1;
  iVar6 = DAT_0087b900;
  fVar4 = param_2 * param_2;
  DAT_0087b900 = 0;
  if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) {
    uVar9 = *(undefined2 *)(param_1 + 0x5a);
  }
  else {
    uVar9 = FUN_0054b3d0(param_1,*(int *)(param_1 + 0xca4));
  }
  FUN_005b3620(local_c,&DAT_0080250c,uVar9);
  param_2 = 1e+08;
  iVar13 = 0;
  DAT_0087b898 = 0;
  param_1 = 0;
  iVar14 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if ((((DAT_007fc054 != 0) && ((*(byte *)(iVar7 + 0x1fc) & 0x80) == 0)) &&
          (piVar3 = *(int **)(iVar7 + 0x3ac), piVar3 != (int *)0x0)) && (*piVar3 != 0)) {
        iVar14 = *piVar3;
        iVar13 = DAT_0093d500;
      }
      uVar12 = DAT_0087b898;
      iVar8 = param_1;
      fVar1 = param_2;
      if (((iVar14 != iVar7) && ((*(uint *)(iVar14 + 0x1fc) & 1) != 0)) &&
         (((*(uint *)(iVar14 + 0x1fc) & 0x1000) != 0 &&
          ((*(char *)(iVar14 + 0x28b) == '\0' &&
           (*(float *)(iVar14 + 0x17c) <= *(float *)(iVar7 + 0x188))))))) {
        if (param_6 == 1) {
          if (*(char *)(iVar14 + 0x280) == -1) goto LAB_0049cbaa;
        }
        else if ((param_6 != 2) || (*(char *)(iVar14 + 0x280) != -1)) {
LAB_0049cbaa:
          cVar2 = *(char *)(iVar14 + 0x7b5);
          if (((((cVar2 != '\x17') ||
                ((*(char *)(iVar14 + 0x107f) != '\0' &&
                 ((*(byte *)(*(int *)(*(int *)(iVar14 + 0x54) + 0x24) + 0x90) & 0x40) == 0)))) &&
               ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8) & 0x8000) == 0)) &&
              ((((((cVar2 != ';' && (cVar2 != '9')) && (cVar2 != '<')) &&
                 ((cVar2 != '\0' ||
                  ((*(char *)(iVar14 + 0x7b8) != '\x04' && (*(char *)(iVar14 + 0x7b8) != '\x03')))))
                 ) && (cVar2 != '\x0e')) &&
               (((cVar2 != '\r' && (cVar2 != 'G')) &&
                ((cVar2 != '5' &&
                 ((cVar2 != 'F' &&
                  ((*(uint *)(*(int *)(*(int *)(iVar14 + 0x54) + 0x24) + 0x90) & 0x8000) == 0)))))))
               ))) && (((*(int *)(iVar7 + 0xcd0) == 0 || (iVar14 != *(int *)(iVar7 + 0xcd0))) &&
                       ((((uVar11 = *(uint *)(iVar7 + 0x1f8), (uVar11 & 0x10000) != 0 ||
                          ((*(uint *)(iVar14 + 0x1f8) & 0x10000) != 0)) ||
                         ((*(byte *)(iVar7 + 0x1fc) & 0x80) != 0)) ||
                        (((*(uint *)(iVar14 + 0x1f8) ^ uVar11) & 5) != 0)))))) {
            if (param_5 == 0) {
LAB_0049cdee:
              if (((param_4 != 0) &&
                  (((iVar6 != 0 || (*(int *)(iVar7 + 0x3ac) == 0)) || (param_5 != 0)))) ||
                 (uVar12 = DAT_0087b898, (*(byte *)(iVar14 + 0x1f8) & 1) != 0)) {
                fVar15 = (float10)FUN_005b3c50(iVar14 + 0x5c,iVar7 + 0x5c,local_18);
                fVar1 = (float)fVar15;
                if (fVar1 < fVar4) {
                  if (((param_5 == 1) && (*(char *)(iVar7 + 0x7b2) != '\0')) ||
                     (0.0 <= local_18[0] * local_c[0] + local_10 * local_4)) {
                    uVar12 = 0;
                  }
                  else {
                    uVar12 = 1;
                    if ((param_5 != 1) ||
                       (*(int *)(*(int *)(*(int *)(iVar7 + 0x50) + 0xc) + 0x250) == 0))
                    goto LAB_0049cece;
                  }
                  if (((param_3 <= 0.0) ||
                      (fVar5 = *(float *)(iVar14 + 0x1dc) + *(float *)(iVar7 + 0x1dc) + param_3,
                      fVar5 = fVar5 * fVar5, fVar5 < fVar1 == (fVar5 == fVar1))) &&
                     (iVar8 = iVar14, fVar1 < param_2)) goto LAB_0049ced0;
                }
LAB_0049cece:
                uVar12 = DAT_0087b898;
                iVar8 = param_1;
                fVar1 = param_2;
              }
            }
            else if ((((cVar2 != '_') && (cVar2 != '`')) &&
                     ((cVar2 != 'Z' ||
                      ((*(char *)(iVar14 + 0x7b3) != '\0' &&
                       ((*(byte *)(iVar7 + 0x1fc) & 0x80) != 0)))))) &&
                    ((cVar2 != '\x17' || (*(char *)(iVar14 + 0x107e) != '\0')))) {
              if (*(char *)(iVar7 + 0x280) == -1) goto LAB_0049cdc5;
              if (((*(byte *)(iVar7 + 0x1fc) & 0x80) != 0) || (*(char *)(iVar14 + 0x280) == -1)) {
                if (*(char *)(iVar14 + 0x280) == -1) {
                  if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_00951b94) {
                    uVar11 = *(uint *)(iVar14 + 0x1f8) & 0x10005;
joined_r0x0049cdbf:
                    uVar12 = DAT_0087b898;
                    if (uVar11 == 0) goto LAB_0049ced0;
                  }
LAB_0049cdc5:
                  uVar12 = DAT_0087b898;
                  if (((*(uint *)(*(int *)(iVar14 + 0x54) + 4) & 0x2000) == 0) &&
                     (((*(byte *)(*(int *)(*(int *)(iVar14 + 0x54) + 0x24) + 0x90) & 0x40) == 0 ||
                      ((*(byte *)(iVar14 + 0x1fc) & 0x80) != 0)))) goto LAB_0049cdee;
                }
                else if ((((*(uint *)(iVar14 + 0x1f8) ^ uVar11) & 1) != 0) ||
                        ((*(int *)(iVar7 + 0x3ac) == 0 && (*(int *)(iVar14 + 0x3ac) == 0)))) {
                  if ((DAT_00804dcc != 0) ||
                     ((((*(uint *)(iVar7 + 0xef4) & 0x800) != 0 ||
                       ((*(uint *)(iVar14 + 0xef4) & 0x800) == 0)) ||
                      (*(short *)(iVar7 + 0x1064) == DAT_007f1884)))) goto LAB_0049cdc5;
                  iVar10 = FUN_0058af60(iVar7,iVar14);
                  uVar12 = DAT_0087b898;
                  if (iVar10 != -1) {
                    uVar11 = FUN_0058af20(iVar10,1);
                    goto joined_r0x0049cdbf;
                  }
                }
              }
            }
          }
        }
      }
LAB_0049ced0:
      param_2 = fVar1;
      param_1 = iVar8;
      DAT_0087b898 = uVar12;
      iVar13 = iVar13 + 1;
      iVar14 = iVar14 + 0x10d8;
    } while (iVar13 < DAT_0093d500);
  }
  _DAT_0087b89c = param_2;
  return param_1;
}

