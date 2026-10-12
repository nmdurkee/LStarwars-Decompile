/* Ghidra analysis pseudocode, not original source.
 * ev_6d5e80728f20a9db75e52af560e5ebae31a03548301b37a6feef2e83d352f64f
 * Entry: 0x5e6420; label: FUN_005e6420
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e6420(void)

{
  float fVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int in_ECX;
  float *pfVar9;
  float10 fVar10;
  int local_a8;
  float local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  float local_80 [31];
  
  uVar2 = *(undefined4 *)(DAT_0080bbb4 + DAT_0080bbb0 * 0x28);
  piVar3 = *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28);
  piVar7 = *(int **)(DAT_0080bbcc + DAT_0080bbc8 * 0x28);
  if (*(char *)((int)piVar3 + 9) == '\0') {
    FUN_005f8ba0(piVar3[1],(char)piVar3[2]);
    *(undefined1 *)((int)piVar3 + 9) = 1;
  }
  if (*(char *)((int)piVar7 + 9) == '\0') {
    FUN_005f8ba0(piVar7[1],(char)piVar7[2]);
    *(undefined1 *)((int)piVar7 + 9) = 1;
  }
  iVar4 = *piVar3;
  iVar5 = *piVar7;
  iVar6 = FUN_005f8a80(uVar2,0,0,0);
  FUN_005c2760();
  local_90 = *(float *)(in_ECX + 0x98) / *(float *)(in_ECX + 0x94);
  local_a8 = 0;
  pfVar9 = local_80 + 2;
  do {
    fVar10 = (float10)FUN_005be630(((float)local_a8 + 1.0) / 7.0,*(undefined4 *)(in_ECX + 0x9c));
    local_a8 = local_a8 + 1;
    fVar1 = (float)((float10)local_90 * (fVar10 - (float10)0.5));
    pfVar9[-2] = fVar1;
    pfVar9[-1] = fVar1;
    *pfVar9 = 0.0;
    pfVar9[1] = 0.0;
    pfVar9 = pfVar9 + 4;
  } while (local_a8 < 7);
  local_8c = _DAT_0080c078;
  local_88 = 0;
  local_84 = 0;
  FUN_006e52e0(0x8a,&local_90,1);
  FUN_006e52e0(0x8b,local_80,7);
  FUN_005f7d00(iVar4,2,2,2);
  FUN_005f7ed0(iVar4,2,2);
  if ((iVar4 != 0) &&
     ((piVar7 = (int *)FUN_005f8460(iVar4), DAT_0097f9b8 != *piVar7 || (DAT_0097f9bc != piVar7[1])))
     ) {
    uVar8 = FUN_005f8460(iVar4);
    FUN_005fa540(0,uVar8);
  }
  FUN_005f8550(iVar4,0);
  FUN_005f7d00(iVar5,2,2,0);
  FUN_005f7ed0(iVar5,2,2);
  if ((iVar5 != 0) &&
     ((piVar7 = (int *)FUN_005f8460(iVar5), DAT_0097f9c8 != *piVar7 || (DAT_0097f9cc != piVar7[1])))
     ) {
    uVar8 = FUN_005f8460(iVar5);
    FUN_005fa540(2,uVar8);
  }
  FUN_005f8550(iVar5,2);
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  FUN_005f8bf0(uVar2);
  FUN_005fb550();
  *piVar3 = iVar6;
  piVar3[1] = 4;
  *(undefined1 *)(piVar3 + 2) = 1;
  *(undefined1 *)((int)piVar3 + 9) = 0;
  *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28) = piVar3;
  return;
}

