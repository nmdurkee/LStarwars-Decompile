/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x490d10; label: FUN_00490d10
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490d10(undefined4 param_1,int param_2)

{
  ushort *puVar1;
  uint uVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  float10 fVar8;
  double local_8;
  
  local_8 = (double)CONCAT44(local_8._4_4_,0x4e6e6b28);
  if (*(char *)(param_2 + 0x7b5) != 'J') {
    if (*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + 0x174) == 0) {
      return;
    }
    if (*(char *)(param_2 + 0x281) == '\0') {
      return;
    }
    iVar5 = FUN_005620f0(param_2);
    if ((iVar5 == 0) && (iVar5 = FUN_00578790(param_2,0x4a), iVar5 == 0)) {
      return;
    }
    iVar5 = FUN_00490160(param_1,param_2 + 0x19c,param_2,&local_8);
    iVar6 = FUN_00578790(param_2,0x4a);
    if (iVar6 != 0) {
      fVar3 = *(float *)(param_2 + 0x77c) - _DAT_00925018;
      *(float *)(param_2 + 0x77c) = fVar3;
      if (fVar3 < 0.0 != (fVar3 == 0.0)) {
        *(undefined1 *)(param_2 + 0x7b5) = 0xff;
        *(undefined4 *)(param_2 + 0x7a0) = 0;
      }
    }
    if (((iVar5 != 0) &&
        (fVar3 = (*(float *)(param_2 + 0x1dc) + 0.25) * *(float *)(iVar5 + 0x84),
        local_8._0_4_ < fVar3 * fVar3)) &&
       (((*(uint *)(*(int *)(param_2 + 0xca4) + 8) & DAT_00802280) != 0 ||
        (iVar6 = FUN_00578790(param_2,0x4a), iVar6 != 0)))) {
      *(undefined4 *)(param_2 + 0x77c) = 0;
      *(undefined4 *)(param_2 + 0x778) = 0;
      *(undefined1 *)(param_2 + 0x7b5) = 0x4a;
      *(int *)(param_2 + 0x798) = iVar5;
      *(undefined2 *)(param_2 + 0x7aa) = 0x5d;
      fVar8 = (float10)FUN_0062e040((int)*(short *)(param_2 + 0x1064),0x5d,0,0,1);
      *(float *)(param_2 + 0x784) = (float)fVar8;
      if ((float)fVar8 <= 0.0) {
        *(undefined4 *)(param_2 + 0x784) = 0x3f800000;
      }
      *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) & 0xffffffbf;
      *(undefined2 *)(param_2 + 0x5a) = *(undefined2 *)(*(int *)(param_2 + 0x798) + 0x88);
      puVar1 = (ushort *)(*(int *)(param_2 + 0x798) + 0x94);
      *puVar1 = *puVar1 | 1;
      *(undefined4 *)(*(int *)(param_2 + 0x798) + 0x78) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x798) + 0x7c) = 0;
      return;
    }
    return;
  }
  fVar3 = _DAT_00925018 + *(float *)(param_2 + 0x778);
  *(float *)(param_2 + 0x778) = fVar3;
  if (1.0 < fVar3) {
    *(undefined4 *)(param_2 + 0x778) = 0x3f800000;
  }
  fVar3 = _DAT_00925018 + *(float *)(param_2 + 0x77c);
  *(float *)(param_2 + 0x77c) = fVar3;
  if (*(float *)(param_2 + 0x784) < fVar3 == (*(float *)(param_2 + 0x784) == fVar3)) {
    if ((*(byte *)(param_2 + 0x7bc) & 0x40) != 0) {
      return;
    }
    if (*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + *(short *)(param_2 + 0x7aa) * 4) != 0) {
      pfVar4 = (float *)FUN_0062f150(param_2 + 8,(int)*(short *)(param_2 + 0x7aa),1,0);
      if (pfVar4 == (float *)0x0) {
        return;
      }
      local_8 = (double)*pfVar4;
      fVar8 = (float10)FUN_0062f1f0(*(undefined4 *)(param_2 + 0x50),(int)*(short *)(param_2 + 0x7aa)
                                    ,0);
      if (fVar8 < (float10)local_8 == (fVar8 == (float10)local_8)) {
        return;
      }
      goto LAB_00490e14;
    }
    bVar7 = 0.25 <= fVar3;
  }
  else {
    bVar7 = (*(byte *)(param_2 + 0x7bc) & 0x40) == 0;
    *(undefined1 *)(param_2 + 0x7b5) = 0xff;
  }
  if (!bVar7) {
    return;
  }
LAB_00490e14:
  uVar2 = *(uint *)(*(int *)(param_2 + 0x54) + 4);
  if ((uVar2 & 4) == 0) {
    if ((uVar2 & 0x200) == 0) {
      puVar1 = (ushort *)(*(int *)(param_2 + 0x798) + 0x94);
      *puVar1 = *puVar1 | 4;
    }
  }
  else {
    puVar1 = (ushort *)(*(int *)(param_2 + 0x798) + 0x94);
    *puVar1 = *puVar1 | 8;
  }
  puVar1 = (ushort *)(*(int *)(param_2 + 0x798) + 0x94);
  *puVar1 = *puVar1 | 0x800;
  *(uint *)(param_2 + 0x7bc) = *(uint *)(param_2 + 0x7bc) | 0x40;
  return;
}

