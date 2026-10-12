/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55d8c0; label: FUN_0055d8c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055d8c0(int param_1)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  
  *(uint *)(param_1 + 0xef4) = *(uint *)(param_1 + 0xef4) & 0xffbfffff;
  if ((*(char *)(param_1 + 0x28b) != '\0') ||
     (((DAT_00802828 != -1 && (*(char *)(param_1 + 0x7b5) == DAT_00802828)) ||
      ((*(byte *)(param_1 + 0x1fc) & 4) != 0)))) goto LAB_0055dcba;
  *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x1c4) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x1c8) = *(undefined4 *)(param_1 + 100);
  if (((*(int *)(param_1 + 0xcd0) == 0) || (DAT_00802858 == -1)) ||
     (iVar6 = *(int *)(param_1 + 0xcd0), *(char *)(param_1 + 0x7b5) != DAT_00802858)) {
    iVar6 = param_1;
  }
  if ((((*(char *)(iVar6 + 0x285) == -1) ||
       ((*(uint *)(&DAT_008034cc + *(char *)(iVar6 + 0x285) * 0xc) & 0xc041) == 0)) &&
      ((cVar1 = *(char *)(iVar6 + 0x283), cVar1 == -1 ||
       ((((&DAT_0080364c)[cVar1 * 0xc] & 1) == 0 && (cVar1 != '\t')))))) ||
     ((bVar5 = true, DAT_00951288 != 0 &&
      ((DAT_00951154 != 0 && (0.0 < *(float *)(*(int *)(*(int *)(iVar6 + 0x54) + 0x24) + 0x28)))))))
  {
    bVar5 = false;
  }
  if ((*(uint *)(param_1 + 0xef4) & 4) == 0) {
    iVar6 = (int)*(char *)(param_1 + 0x7b5);
    if ((*(uint *)(PTR_PTR_007fb0e4 + iVar6 * 0x10 + 0xc) & 8) == 0) {
      if ((*(char *)(param_1 + 0x281) == '\0') &&
         (((*(char *)(param_1 + 0x7b5) == -1 ||
           (((iVar6 != DAT_00802858 && (iVar6 != DAT_0080289c)) && (iVar6 != DAT_0080285c)))) &&
          (DAT_00951288 == 0)))) {
        uVar3 = *(uint *)(*(int *)(param_1 + 0x54) + 4);
        if ((((uVar3 & 0x2000) == 0) ||
            (*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28) <= 0.0)) &&
           (((uVar3 & 0x8000) == 0 || (*(char *)(param_1 + 0xe32) != '\x01')))) goto LAB_0055dc2a;
      }
      if (((*(float *)(param_1 + 0x21c) != 2e+06) &&
          (((((sVar2 = *(short *)(param_1 + 0x106c), sVar2 == -1 || (sVar2 == DAT_00803bb0)) ||
             (sVar2 == DAT_00803bb4)) &&
            (((sVar2 = *(short *)(param_1 + 0x27e), sVar2 == -1 || (sVar2 == DAT_00803bb0)) ||
             (sVar2 == DAT_00803bb4)))) ||
           ((DAT_0093d50c != (code *)0x0 && (iVar6 = (*DAT_0093d50c)(param_1), iVar6 != 0)))))) &&
         ((*(float *)(param_1 + 0x21c) - 0.1 < *(float *)(param_1 + 0x1a0) && (!bVar5)))) {
        *(undefined4 *)(param_1 + 0xd9c) = 0;
        *(uint *)(param_1 + 0xef4) = *(uint *)(param_1 + 0xef4) | 0x400000;
        *(undefined4 *)(param_1 + 0x1b4) = *(undefined4 *)(param_1 + 0x5c);
        *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0x60);
        *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 100);
        if (((*(byte *)(param_1 + 0x42e) & 1) != 0) &&
           ((*(int **)(param_1 + 0x424))[1] == 0 && **(int **)(param_1 + 0x424) == 0)) {
          if (((*(int *)(param_1 + 0xcd4) != 0) &&
              ((DAT_0080285c == -1 || (*(char *)(param_1 + 0x7b5) != DAT_0080285c)))) &&
             ((DAT_00802858 == -1 || (*(char *)(param_1 + 0x7b5) != DAT_00802858)))) {
            *(undefined4 *)(param_1 + 0xcd4) = 0;
          }
          *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 0x2000;
          *(undefined4 *)(param_1 + 0x1cc) = *(undefined4 *)(param_1 + 0x5c);
          *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(param_1 + 0x60);
          *(undefined4 *)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 100);
        }
        if ((((*(char *)(param_1 + 0x280) == '\0') || (*(char *)(param_1 + 0x280) == '\x01')) &&
            (*(float *)(param_1 + 0xda8) <= 0.0)) &&
           ((*(float *)(PTR_DAT_008021b4 + 0x1c0) < *(float *)(PTR_DAT_008021b4 + 0x1bc) !=
             (*(float *)(PTR_DAT_008021b4 + 0x1c0) == *(float *)(PTR_DAT_008021b4 + 0x1bc)) &&
            (*(char *)(param_1 + 0x671) != -1)))) {
          if (((*(int *)(param_1 + 0xcd4) != 0) &&
              ((DAT_0080285c == -1 || (*(char *)(param_1 + 0x7b5) != DAT_0080285c)))) &&
             ((DAT_00802858 == -1 || (*(char *)(param_1 + 0x7b5) != DAT_00802858)))) {
            *(undefined4 *)(param_1 + 0xcd4) = 0;
          }
          *(undefined4 *)(param_1 + 0xc74) = *(undefined4 *)(param_1 + 0x5c);
          *(undefined4 *)(param_1 + 0xc78) = *(undefined4 *)(param_1 + 0x60);
          *(undefined4 *)(param_1 + 0xc7c) = *(undefined4 *)(param_1 + 100);
        }
        goto LAB_0055dcba;
      }
    }
  }
LAB_0055dc2a:
  fVar4 = 0.0;
  if ((((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) && (*(char *)(param_1 + 0x283) != -1)) &&
     (((&DAT_0080364c)[*(char *)(param_1 + 0x283) * 0xc] & 1) != 0)) {
    iVar6 = FUN_0058b840(param_1);
    fVar4 = 0.0;
    if (iVar6 == 0) {
      if (*(float *)(param_1 + 0xd9c) <= 0.0) {
        *(undefined4 *)(param_1 + 0xdb4) = *(undefined4 *)(param_1 + 0x60);
      }
      fVar4 = *(float *)(param_1 + 0xd9c) + _DAT_00925018;
    }
  }
  *(float *)(param_1 + 0xd9c) = fVar4;
  if ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x40000) != 0) {
    *(undefined4 *)(param_1 + 0x1b4) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 100);
  }
LAB_0055dcba:
  if ((((*(uint *)(param_1 + 0xef4) & 0x1000000) == 0) && (-1 < (char)*(uint *)(param_1 + 0x1fc)))
     && (((DAT_0080289c == -1 || (*(char *)(param_1 + 0x7b5) != DAT_0080289c)) &&
         ((*(uint *)(param_1 + 0x1fc) & 0x2000) != 0)))) {
    if (((((*(byte *)(param_1 + 0x42e) & 1) != 0) && (*(int *)(param_1 + 0xcd4) != 0)) &&
        ((DAT_0080285c == -1 || (*(char *)(param_1 + 0x7b5) != DAT_0080285c)))) &&
       ((DAT_00802858 == -1 || (*(char *)(param_1 + 0x7b5) != DAT_00802858)))) {
      *(undefined4 *)(param_1 + 0xcd4) = 0;
    }
    *(undefined4 *)(param_1 + 0x1b4) = *(undefined4 *)(param_1 + 0x1cc);
    *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(param_1 + 0x1d0);
    *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_1 + 0x1d4);
  }
  *(uint *)(param_1 + 0xef4) = *(uint *)(param_1 + 0xef4) & 0xfffffffb;
  return;
}

