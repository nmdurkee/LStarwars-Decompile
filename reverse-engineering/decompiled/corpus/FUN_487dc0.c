/* Ghidra analysis pseudocode, not original source.
 * ev_6a5348c5de1b6aa473bf814c408ae5ab94878b8c78b78ea0d14786caa34bcd70
 * Entry: 0x487dc0; label: FUN_00487dc0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00487dc0(int param_1)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  float fVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float10 extraout_ST0;
  float10 fVar9;
  
  fVar9 = (float10)0;
  if (((DAT_0093b324 != 0) || (bVar1 = *(byte *)(param_1 + 0x7c5), (bVar1 & 1) != 0)) ||
     (*(char *)(param_1 + 0x7b5) == 'Q')) {
    bVar1 = *(byte *)(param_1 + 0x7c5);
    if (((bVar1 & 1) != 0) || (*(char *)(param_1 + 0x7b5) == 'Q')) {
      *(float *)(param_1 + 0xd60) = (float)fVar9;
    }
    *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xffe7ffff;
    *(float *)(param_1 + 0xee4) = (float)fVar9;
    *(float *)(param_1 + 0xee8) = (float)fVar9;
    if (DAT_0093b324 == 0) {
      return;
    }
  }
  if (*(char *)(param_1 + 0x280) == -1) {
    return;
  }
  if ((bVar1 & 4) == 0) {
    *(undefined1 *)(param_1 + 0x7c4) = 0xff;
    if ((-1 < (char)*(uint *)(param_1 + 0x1fc)) || (*(char *)(param_1 + 0x28b) != '\0'))
    goto LAB_004882aa;
    cVar2 = *(char *)(param_1 + 0x7b5);
    uVar3 = *(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 8);
    if (((uVar3 & 0x800) != 0) ||
       (((*(uint *)(param_1 + 0x1fc) & 0x100) != 0 || (fVar9 < (float10)*(float *)(param_1 + 0x7c0))
        ))) goto LAB_004882aa;
    if (DAT_00951288 != 0) {
      if ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802284) != 0) {
        *(undefined4 *)(param_1 + 0xd60) = 0x40000000;
      }
      goto LAB_004882aa;
    }
    if ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802284) == 0) goto LAB_004882aa;
    if (DAT_00951c5c == 0) {
      if (DAT_0093b324 == 0) {
        if (DAT_007fa564 == 3) {
          if (((((cVar2 == -1) || (cVar2 == '\x17')) || ((uVar3 & 4) != 0)) ||
              ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 0xc) & 0x10) != 0)) &&
             (iVar6 = FUN_00487020(param_1), iVar6 != 0)) {
            iVar7 = FUN_00594250((int)*(short *)(iVar6 + 0x1064),0,0);
            if (iVar7 != -1) {
              fVar9 = (float10)0;
              goto LAB_0048805b;
            }
            FUN_00547930(0x32,param_1 + 0x80,0,0);
            FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f000000,0);
            iVar7 = iVar6 + 0x2c8;
            iVar8 = FUN_0052c790(iVar7,"MapRunAway");
            if (iVar8 != 0) {
              FUN_0052cc90(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar6,iVar7,iVar7,
                           _DAT_00925018);
            }
          }
        }
        else {
          if (DAT_007fa564 == 1) {
            if (((cVar2 == -1) || (cVar2 == '\x17')) ||
               (((uVar3 & 4) != 0 ||
                ((*(uint *)(PTR_PTR_007fb0e4 + cVar2 * 0x10 + 0xc) & 0x10) != 0)))) {
              iVar6 = FUN_00487020(param_1);
              if ((iVar6 != 0) && (*(char *)(iVar6 + 0x280) != -1)) {
                *(char *)(param_1 + 0x7c4) = *(char *)(iVar6 + 0x280);
              }
              fVar9 = (float10)0;
            }
          }
          else {
            uVar5 = FUN_00486f60(param_1);
            *(undefined1 *)(param_1 + 0x7c4) = uVar5;
            fVar9 = extraout_ST0;
          }
          if (-1 < *(char *)(param_1 + 0x7c4)) {
            iVar6 = (&DAT_0093d7f0)[*(char *)(param_1 + 0x7c4)];
LAB_0048805b:
            if (iVar6 != 0) {
              if ((*(byte *)(iVar6 + 0xef4) & 2) != 0) {
                FUN_004874f0(iVar6,param_1);
                goto LAB_004882aa;
              }
              if (((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) &&
                 ((*(byte *)(iVar6 + 0x1fc) & 0x80) != 0)) {
                if ((((float10)_DAT_0087a7d0 <= fVar9) || (DAT_0087a7c8 != param_1)) ||
                   (DAT_0087a7cc != iVar6)) {
                  _DAT_0087a7d0 = 0.5;
                  DAT_0087a7cc = param_1;
                  DAT_0087a7c8 = iVar6;
                }
                else {
                  DAT_0087a7d4 = 1;
                }
                goto LAB_004882aa;
              }
              iVar7 = FUN_004876a0(param_1,iVar6,0,0,1);
              if (iVar7 == 2) {
                *(undefined4 *)(param_1 + 0x7c0) = 0x3f800000;
                *(int *)(param_1 + 0x7c8) = iVar6;
                *(byte *)(param_1 + 0x7c5) = *(byte *)(param_1 + 0x7c5) & 0xf7 | 4;
                goto LAB_004882aa;
              }
              goto LAB_004881c6;
            }
          }
        }
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xd60) = 0x40000000;
      *(undefined4 *)(param_1 + 0xda4) = _DAT_00802be8;
    }
    if (*(int *)(param_1 + 0xcd0) == 0) {
      *(undefined4 *)(param_1 + 0xd60) = 0x40000000;
    }
  }
  else {
    fVar4 = *(float *)(param_1 + 0x7c0) - _DAT_00925018;
    *(float *)(param_1 + 0x7c0) = fVar4;
    if ((fVar9 < (float10)fVar4) && (iVar6 = *(int *)(param_1 + 0x7c8), iVar6 != 0)) {
      if (((*(uint *)(iVar6 + 0x1fc) & 0x1000) == 0) || ((*(uint *)(iVar6 + 0x1fc) & 1) == 0)) {
        *(byte *)(param_1 + 0x7c5) = *(byte *)(param_1 + 0x7c5) & 0xfb;
        *(undefined4 *)(param_1 + 0x7c8) = 0;
        goto LAB_004882aa;
      }
      if ((*(byte *)(param_1 + 0xef4) & 2) == 0) {
        iVar7 = FUN_004876a0(param_1,iVar6,bVar1 >> 3 & 1,0,1);
      }
      else {
        iVar7 = FUN_004873d0(param_1,iVar6);
      }
      if (iVar7 != 0) {
LAB_004881c6:
        if (iVar7 == 1) {
          *(byte *)(param_1 + 0x7c5) = *(byte *)(param_1 + 0x7c5) & 0xfb;
          FUN_00547930(0x21,param_1 + 0x80,0,0);
          if (*(char *)(iVar6 + 0x288) == '\0') {
            FUN_0054a2f0(PTR_DAT_008021b4);
          }
          else {
            FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
          }
          if (DAT_0093d7f4 == 0) {
            iVar7 = -1;
          }
          else {
            iVar7 = (int)*(short *)(DAT_0093d7f4 + 0x1064);
          }
          if (DAT_0093d7f0 == 0) {
            iVar8 = -1;
          }
          else {
            iVar8 = (int)*(short *)(DAT_0093d7f0 + 0x1064);
          }
          FUN_0055e1b0(0,iVar8,iVar7);
          if ((DAT_007fa564 == 1) || (DAT_007fa564 == 3)) {
            FUN_0059fe30(param_1,iVar6);
          }
          if (((*(char *)(param_1 + 0x280) == '\0') || (*(char *)(param_1 + 0x280) == '\x01')) &&
             ((*(char *)(iVar6 + 0x280) == '\0' || (*(char *)(iVar6 + 0x280) == '\x01')))) {
            FUN_00548fb0(&DAT_00925044,0);
          }
        }
        goto LAB_004882aa;
      }
    }
    *(byte *)(param_1 + 0x7c5) = *(byte *)(param_1 + 0x7c5) & 0xfb;
  }
LAB_004882aa:
  if (DAT_0087a7d8 == (code *)0x0) {
    return;
  }
  (*DAT_0087a7d8)(param_1);
  return;
}

