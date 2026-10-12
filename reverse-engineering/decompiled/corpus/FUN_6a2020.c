/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x6a2020; label: FUN_006a2020
 */

undefined4 FUN_006a2020(int param_1,int *param_2)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  float *pfVar5;
  int *piVar6;
  void *_Dst;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  float10 fVar14;
  
  iVar10 = *(int *)(param_1 + 4);
  piVar3 = *(int **)(iVar10 + 0x1c);
  puVar4 = *(undefined4 **)(param_1 + 0x68);
  pfVar5 = (float *)puVar4[0xf];
  piVar6 = (int *)param_2[0x1a];
  iVar7 = *(int *)(param_1 + 0x30) - piVar3[*(int *)(param_1 + 0x28)] / 2;
  if (*(int *)(param_1 + 0x1c) == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x20) == -1) {
    return 0;
  }
  iVar8 = FUN_006b1240(param_1);
  if (iVar8 == -1) {
    if (*(int *)(param_1 + 0x20) == 0) {
      return 0;
    }
  }
  else if (*piVar3 != piVar3[1]) {
    *(int *)(param_1 + 0x2c) = iVar8;
    goto LAB_006a20a1;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
LAB_006a20a1:
  iVar8 = piVar3[*(int *)(param_1 + 0x2c)];
  iVar11 = ((int)(piVar3[*(int *)(param_1 + 0x28)] + (piVar3[*(int *)(param_1 + 0x28)] >> 0x1f & 3U)
                 ) >> 2) + ((int)(iVar8 + (iVar8 >> 0x1f & 3U)) >> 2) + *(int *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x14) < iVar8 / 2 + iVar11) {
    return 0;
  }
  FUN_006a15c0(param_2);
  param_2[6] = *(int *)(param_1 + 0x24);
  param_2[7] = *(int *)(param_1 + 0x28);
  param_2[8] = *(int *)(param_1 + 0x2c);
  if (*(int *)(param_1 + 0x28) == 0) {
    iVar8 = FUN_006b1460(param_1);
    piVar6[2] = (uint)(iVar8 == 0);
  }
  else if ((*(int *)(param_1 + 0x24) == 0) || (*(int *)(param_1 + 0x2c) == 0)) {
    piVar6[2] = 0;
  }
  else {
    piVar6[2] = 1;
  }
  param_2[0x10] = param_1;
  param_2[0xe] = *(int *)(param_1 + 0x40);
  param_2[0xf] = *(int *)(param_1 + 0x44);
  puVar1 = (uint *)(param_1 + 0x40);
  uVar13 = *puVar1;
  *puVar1 = *puVar1 + 1;
  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + (uint)(0xfffffffe < uVar13);
  param_2[0xc] = *(int *)(param_1 + 0x38);
  param_2[0xd] = *(int *)(param_1 + 0x3c);
  param_2[9] = piVar3[*(int *)(param_1 + 0x28)];
  if (*pfVar5 < (float)piVar6[1]) {
    *pfVar5 = (float)piVar6[1];
  }
  fVar14 = (float10)FUN_006a6f20(*pfVar5,param_1);
  *pfVar5 = (float)fVar14;
  piVar6[1] = (int)(float)fVar14;
  iVar8 = FUN_006a1550(param_2,*(int *)(iVar10 + 4) * 4);
  *param_2 = iVar8;
  iVar8 = FUN_006a1550(param_2,*(int *)(iVar10 + 4) * 4);
  iVar12 = 0;
  *piVar6 = iVar8;
  if (0 < *(int *)(iVar10 + 4)) {
    do {
      uVar9 = FUN_006a1550(param_2,(param_2[9] + iVar7) * 4);
      *(undefined4 *)(*piVar6 + iVar12 * 4) = uVar9;
      _memcpy(*(void **)(*piVar6 + iVar12 * 4),*(void **)(*(int *)(param_1 + 8) + iVar12 * 4),
              (param_2[9] + iVar7) * 4);
      *(int *)(*param_2 + iVar12 * 4) = *(int *)(*piVar6 + iVar12 * 4) + iVar7 * 4;
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(iVar10 + 4));
  }
  if ((*(int *)(param_1 + 0x20) != 0) && (*(int *)(param_1 + 0x20) <= *(int *)(param_1 + 0x30))) {
    *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
    param_2[0xb] = 1;
    return 1;
  }
  iVar7 = piVar3[1] / 2;
  uVar13 = iVar11 - iVar7;
  if (0 < (int)uVar13) {
    FUN_006b1520(*puVar4,uVar13);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - uVar13;
    iVar8 = 0;
    if (0 < *(int *)(iVar10 + 4)) {
      do {
        _Dst = *(void **)(*(int *)(param_1 + 8) + iVar8 * 4);
        _memmove(_Dst,(void *)((int)_Dst + uVar13 * 4),*(int *)(param_1 + 0x14) * 4);
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(iVar10 + 4));
    }
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2c);
    *(int *)(param_1 + 0x30) = iVar7;
    if (*(int *)(param_1 + 0x20) != 0) {
      iVar10 = *(int *)(param_1 + 0x20) - uVar13;
      *(int *)(param_1 + 0x20) = iVar10;
      if (iVar10 < 1) {
        *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
      }
      if (*(int *)(param_1 + 0x20) <= iVar7) {
        uVar13 = (*(int *)(param_1 + 0x20) - iVar7) + uVar13;
        puVar1 = (uint *)(param_1 + 0x38);
        uVar2 = *puVar1;
        *puVar1 = *puVar1 + uVar13;
        *(int *)(param_1 + 0x3c) =
             *(int *)(param_1 + 0x3c) + ((int)uVar13 >> 0x1f) + (uint)CARRY4(uVar2,uVar13);
        return 1;
      }
    }
    puVar1 = (uint *)(param_1 + 0x38);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar13;
    *(int *)(param_1 + 0x3c) =
         *(int *)(param_1 + 0x3c) + ((int)uVar13 >> 0x1f) + (uint)CARRY4(uVar2,uVar13);
  }
  return 1;
}

