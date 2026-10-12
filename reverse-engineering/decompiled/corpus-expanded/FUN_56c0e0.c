/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56c0e0; label: FUN_0056c0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056c0e0(int param_1)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  byte bVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  float10 fVar12;
  float local_c [2];
  float local_4;
  
  if (DAT_00802830 == -1) {
    return;
  }
  iVar11 = (int)*(char *)(param_1 + 0x7b5);
  if (iVar11 != DAT_00802830) {
    if (((*(char *)(param_1 + 0x7b5) != -1) && ((DAT_00802840 == -1 || (iVar11 != DAT_00802840))))
       && (((DAT_00802838 == -1 || (iVar11 != DAT_00802838)) ||
           ((fVar1 = *(float *)(param_1 + 0x77c), NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0) &&
            ((*(float *)(param_1 + 0x77c) < 0.1 || (0.0 < *(float *)(param_1 + 0x6c))))))))) {
      if (DAT_00802818 == -1) {
        return;
      }
      if (iVar11 != DAT_00802818) {
        return;
      }
      if (*(int *)(param_1 + 0x798) != 0) {
        return;
      }
    }
    if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) {
      return;
    }
    if (*(char *)(param_1 + 0x1078) == '\0') {
      return;
    }
    if (DAT_029959a0 <= ABS(*(float *)(param_1 + 0x6b8))) {
      return;
    }
    iVar11 = FUN_0056bfb0(param_1,(int)*(char *)(param_1 + 0x6c0));
    if (iVar11 == 0) {
      return;
    }
    cVar2 = *(char *)(param_1 + 0x6c0);
    uVar9 = *(undefined4 *)(param_1 + 0x6b4);
    uVar3 = *(undefined4 *)(param_1 + 0x6bc);
    uVar4 = *(undefined4 *)(param_1 + 0x6b8);
    FUN_005b3620(local_c,&DAT_0080250c,*(undefined2 *)(param_1 + 0x5a));
    fVar1 = *(float *)(param_1 + 0x6a8) - *(float *)(param_1 + 0x5c);
    fVar5 = *(float *)(param_1 + 0x6b0) - *(float *)(param_1 + 100);
    if (0.0 < fVar5 * local_4 + fVar1 * local_c[0]) {
      uVar7 = FUN_005be2d0(fVar1,fVar5);
      *(undefined2 *)(param_1 + 0x5a) = uVar7;
      *(undefined4 *)(param_1 + 0x6c) = 0;
      *(char *)(param_1 + 0x7b5) = (char)DAT_00802830;
      *(undefined4 *)(param_1 + 0x784) = 0x3e800000;
      *(char *)(param_1 + 0x7b6) = cVar2;
      if (cVar2 == '\x05') {
        FUN_0056bff0(param_1);
        FUN_0056c0a0(param_1,param_1 + 0x760);
      }
      else {
        *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c44;
      }
      *(undefined4 *)(param_1 + 0x754) = *(undefined4 *)(param_1 + 0x6a8);
      *(undefined4 *)(param_1 + 0x758) = *(undefined4 *)(param_1 + 0x6ac);
      *(undefined4 *)(param_1 + 0x748) = uVar9;
      *(undefined4 *)(param_1 + 0x74c) = uVar4;
      *(undefined4 *)(param_1 + 0x750) = uVar3;
      *(undefined4 *)(param_1 + 0x75c) = *(undefined4 *)(param_1 + 0x6b0);
      FUN_0054ff40((undefined4 *)(param_1 + 0x748),param_1 + 0x7a4,0);
      *(undefined4 *)(param_1 + 0x70) = 0;
      *(undefined4 *)(param_1 + 0x68) = 0;
      return;
    }
    return;
  }
  if (((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802278) != 0) &&
     (*(char *)(param_1 + 0x7b6) != '\x05')) {
    FUN_00561ba0(param_1,0);
    *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x1000;
    *(float *)(param_1 + 0x68) =
         -(float)(&DAT_029899a0)[*(ushort *)(param_1 + 0x5a) >> 1] *
         *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
    *(float *)(param_1 + 0x70) =
         -(float)(&DAT_029899a0)[(int)(*(ushort *)(param_1 + 0x5a) + 0x4000) >> 1 & 0x7fff] *
         *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c);
    return;
  }
  uVar7 = FUN_0054b3d0(param_1,*(int *)(param_1 + 0xca4));
  bVar6 = *(byte *)(param_1 + 0x281) & 2;
  if (((bVar6 == 0) || (*(char *)(param_1 + 0x285) != *(char *)(param_1 + 0x7b6))) &&
     ((bVar6 == 0 ||
      (((*(char *)(param_1 + 0x285) == *(char *)(param_1 + 0x7b6) ||
        (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0)) ||
       (fVar12 = (float10)FUN_00550180(uVar7,*(undefined2 *)(param_1 + 0x5a)), (float10)0 <= fVar12)
       ))))) {
    if ((*(char *)(param_1 + 0x1078) != '\0') &&
       (*(char *)(param_1 + 0x6c0) == *(char *)(param_1 + 0x7b6))) {
      *(undefined4 *)(param_1 + 0x784) = 0x3e800000;
      uVar8 = FUN_005be2d0(*(float *)(param_1 + 0x6a8) - *(float *)(param_1 + 0x5c),
                           *(float *)(param_1 + 0x6b0) - *(float *)(param_1 + 100));
      *(undefined4 *)(param_1 + 0x748) = *(undefined4 *)(param_1 + 0x6b4);
      *(undefined2 *)(param_1 + 0x5a) = uVar8;
      *(undefined4 *)(param_1 + 0x74c) = *(undefined4 *)(param_1 + 0x6b8);
      *(undefined4 *)(param_1 + 0x750) = *(undefined4 *)(param_1 + 0x6bc);
      *(undefined4 *)(param_1 + 0x754) = *(undefined4 *)(param_1 + 0x6a8);
      *(undefined4 *)(param_1 + 0x758) = *(undefined4 *)(param_1 + 0x6ac);
      *(undefined4 *)(param_1 + 0x75c) = *(undefined4 *)(param_1 + 0x6b0);
      FUN_0054ff40(param_1 + 0x748,param_1 + 0x7a4,0);
      goto LAB_0056c2d4;
    }
    fVar1 = *(float *)(param_1 + 0x784) - _DAT_00925018;
    *(float *)(param_1 + 0x784) = fVar1;
    if (fVar1 < 0.0 == (fVar1 == 0.0)) goto LAB_0056c2d4;
  }
  *(undefined1 *)(param_1 + 0x7b5) = 0xff;
LAB_0056c2d4:
  if (*(char *)(param_1 + 0x7b5) == DAT_00802830) {
    if (*(char *)(param_1 + 0x7b6) == '\x05') {
      FUN_0056bff0(param_1);
      FUN_0056c0a0(param_1,param_1 + 0x760);
      *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x2000;
      if (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) {
        uVar7 = FUN_00550040(*(undefined2 *)(param_1 + 0x5a),uVar7);
        uVar7 = FUN_00550070(*(undefined2 *)(param_1 + 0xe1c),uVar7,0x41100000);
        *(undefined2 *)(param_1 + 0xe1c) = uVar7;
        return;
      }
    }
    else {
      if (*(float *)(*(int *)(param_1 + 0xca4) + 0x28) <= 0.0) {
        *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c44;
        return;
      }
      uVar9 = FUN_0054b3d0(param_1,*(int *)(param_1 + 0xca4));
      uVar10 = FUN_00550040(*(undefined2 *)(param_1 + 0x5a),uVar9);
      if ((int)((uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f)) < 0x4001) {
        *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c48;
      }
      else {
        *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c4c;
      }
      if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0)
      {
        *(undefined2 *)(param_1 + 0x7aa) = DAT_00804c44;
        return;
      }
    }
  }
  return;
}

