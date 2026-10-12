/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55d2b0; label: FUN_0055d2b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055d2b0(int param_1)

{
  float *pfVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  
  *(uint *)(param_1 + 0x1f8) = *(uint *)(param_1 + 0x1f8) | 0x100;
  if (*(char *)(param_1 + 0x1079) == '\0') {
LAB_0055d438:
    *(uint *)(param_1 + 0x1f8) = *(uint *)(param_1 + 0x1f8) ^ 0x100;
    *(float *)(param_1 + 0x80) =
         *(float *)(param_1 + 0x74) * _DAT_00925018 + *(float *)(param_1 + 0x5c);
    *(float *)(param_1 + 0x84) =
         *(float *)(param_1 + 0x78) * _DAT_00925018 + *(float *)(param_1 + 0x60) +
         (*(float *)(param_1 + 0xff4) + *(float *)(param_1 + 0xff0)) * *(float *)(param_1 + 0xa8) *
         0.5;
    fVar3 = *(float *)(param_1 + 0x7c) * _DAT_00925018 + *(float *)(param_1 + 100);
  }
  else {
    iVar5 = (int)*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x10f);
    if (((iVar5 == -1) || (*(int *)(param_1 + 0x50) == 0)) ||
       (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar5 * 4) == 0)) {
      if (((*(char *)(param_1 + 0x1079) != '\0') && (*(float *)(param_1 + 0xd30) == 1.0)) &&
         ((cVar2 = *(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x10d), cVar2 != -1 &&
          ((*(int *)(*(int *)(param_1 + 0x50) + 0x14 + cVar2 * 4) != 0 &&
           (*(char *)(param_1 + 0x28c) != '\0')))))) {
        iVar6 = cVar2 * 0x40;
        iVar5 = iVar6 + 0x834 + param_1;
        *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(iVar6 + 0x834 + param_1);
        *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(iVar5 + 4);
        *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(iVar5 + 8);
        goto LAB_0055d496;
      }
      goto LAB_0055d438;
    }
    pfVar1 = (float *)(param_1 + 0x80);
    if ((*(byte *)(param_1 + 0xe24) & 8) == 0) {
      *pfVar1 = 0.0;
      *(float *)(param_1 + 0x84) = -*(float *)(param_1 + 0xff0);
      *(undefined4 *)(param_1 + 0x88) = 0;
      FUN_005b3200(pfVar1,pfVar1,param_1 + 0xb8);
      FUN_005b37d0(pfVar1,pfVar1,param_1 + 0x5c);
    }
    else {
      iVar5 = iVar5 * 0x40 + param_1;
      *pfVar1 = *(float *)(param_1 + 0x74) * _DAT_00925018 + *(float *)(iVar5 + 0x834);
      *(float *)(param_1 + 0x84) =
           *(float *)(param_1 + 0x78) * _DAT_00925018 + *(float *)(iVar5 + 0x838) +
           (*(float *)(param_1 + 0xff4) + *(float *)(param_1 + 0xff0)) * *(float *)(param_1 + 0xa8)
           * 0.5;
      *(float *)(param_1 + 0x88) =
           *(float *)(param_1 + 0x7c) * _DAT_00925018 + *(float *)(iVar5 + 0x83c);
    }
    *pfVar1 = *(float *)(param_1 + 0x74) * _DAT_00925018 + *pfVar1;
    *(float *)(param_1 + 0x84) =
         *(float *)(param_1 + 0x78) * _DAT_00925018 + *(float *)(param_1 + 0x84);
    fVar3 = *(float *)(param_1 + 0x7c) * _DAT_00925018 + *(float *)(param_1 + 0x88);
  }
  *(float *)(param_1 + 0x88) = fVar3;
LAB_0055d496:
  *(float *)(param_1 + 0x178) = *(float *)(param_1 + 0x80) - *(float *)(param_1 + 0x1dc);
  *(float *)(param_1 + 0x184) = *(float *)(param_1 + 0x1dc) + *(float *)(param_1 + 0x80);
  *(float *)(param_1 + 0x180) = *(float *)(param_1 + 0x88) - *(float *)(param_1 + 0x1dc);
  *(float *)(param_1 + 0x18c) = *(float *)(param_1 + 0x1dc) + *(float *)(param_1 + 0x88);
  fVar3 = *(float *)(param_1 + 0x84) - *(float *)(param_1 + 0x1e0);
  *(float *)(param_1 + 0x17c) = fVar3;
  fVar4 = *(float *)(param_1 + 0x1e0) + *(float *)(param_1 + 0x84);
  *(float *)(param_1 + 0x188) = fVar4;
  *(float *)(param_1 + 400) =
       *(float *)(param_1 + 0x74) * _DAT_00925018 + *(float *)(param_1 + 0x5c);
  *(float *)(param_1 + 0x194) = fVar4;
  *(float *)(param_1 + 0x198) =
       *(float *)(param_1 + 0x7c) * _DAT_00925018 + *(float *)(param_1 + 100);
  *(float *)(param_1 + 0x19c) =
       *(float *)(param_1 + 0x74) * _DAT_00925018 + *(float *)(param_1 + 0x5c);
  *(float *)(param_1 + 0x1a0) = fVar3;
  *(float *)(param_1 + 0x1a4) =
       *(float *)(param_1 + 0x7c) * _DAT_00925018 + *(float *)(param_1 + 100);
  *(float *)(param_1 + 0x1a8) =
       *(float *)(param_1 + 0x74) * _DAT_00925018 + *(float *)(param_1 + 0x5c);
  *(float *)(param_1 + 0x1ac) = *(float *)(param_1 + 0x78) * _DAT_00925018 + fVar3;
  *(float *)(param_1 + 0x1b0) =
       *(float *)(param_1 + 0x7c) * _DAT_00925018 + *(float *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x414) = *(undefined4 *)(param_1 + 0x1a8);
  *(undefined4 *)(param_1 + 0x418) = *(undefined4 *)(param_1 + 0x1ac);
  *(undefined4 *)(param_1 + 0x41c) = *(undefined4 *)(param_1 + 0x1b0);
  if (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x80000) != 0) &&
     ((*(uint *)(param_1 + 0x7bc) & 0x800) != 0)) {
    *(float *)(param_1 + 0x418) = (fVar4 - fVar3) + *(float *)(param_1 + 0x418);
    return;
  }
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x100000) != 0) {
    *(undefined4 *)(param_1 + 0x414) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x418) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x41c) = *(undefined4 *)(param_1 + 100);
    return;
  }
  fVar3 = *(float *)(param_1 + 0x418) - *(float *)(param_1 + 0xd7c);
  *(float *)(param_1 + 0x418) = fVar3;
  if ((fVar3 < *(float *)(param_1 + 0x21c)) &&
     (*(float *)(param_1 + 0x21c) < *(float *)(param_1 + 0xb4) + *(float *)(param_1 + 0x1ac))) {
    *(undefined4 *)(param_1 + 0x418) = *(undefined4 *)(param_1 + 0x21c);
  }
  return;
}

