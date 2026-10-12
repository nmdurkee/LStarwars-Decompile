/* Ghidra pseudocode, not original source.
 * ev_65bfb004178f96b2f9e297a0d063366919d30641ec00bce2a5b47a652ae06e9d
 * Entry: 0x5e7070; label: FUN_005e7070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Type propagation algorithm not settling */

void FUN_005e7070(void)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  int iVar8;
  float10 fVar9;
  float local_42c;
  undefined4 local_424;
  undefined4 local_420;
  int local_41c;
  int local_418;
  undefined4 local_414;
  float local_410 [260];
  
  uVar7 = *(undefined4 *)(DAT_0080bbb4 + DAT_0080bbb0 * 0x28);
  piVar2 = *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28);
  local_420 = uVar7;
  if (*(char *)((int)piVar2 + 9) == '\0') {
    FUN_005f8ba0(piVar2[1],(char)piVar2[2]);
    *(undefined1 *)((int)piVar2 + 9) = 1;
  }
  iVar8 = *piVar2;
  local_418 = iVar8;
  local_41c = FUN_005f8a80(uVar7,0,0,0);
  iVar3 = *(int *)(in_ECX + 0x18);
  if (0x100 < iVar3) {
    iVar3 = FUN_005c12e0();
  }
  local_42c = 0.0;
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      iVar3 = iVar5 + 1;
      fVar9 = (float10)FUN_005be630((float)iVar3 / (float)*(int *)(in_ECX + 0x18),
                                    *(undefined4 *)(in_ECX + 0x20));
      local_410[iVar5 + 4] = (float)fVar9;
      local_42c = (float)fVar9 + local_42c;
      iVar8 = local_418;
      iVar5 = iVar3;
    } while (iVar3 < *(int *)(in_ECX + 0x18));
  }
  iVar3 = *(int *)(in_ECX + 0x18);
  if (0 < iVar3) {
    iVar5 = 0;
    do {
      iVar4 = iVar5 + 1;
      local_410[iVar5 + 4] = local_410[iVar5 + 4] * (1.0 / local_42c);
      iVar5 = iVar4;
    } while (iVar4 < iVar3);
  }
  if (0 < iVar3) {
    fVar1 = 0.0;
    iVar5 = 0;
    do {
      fVar1 = fVar1 + local_410[iVar5 + 4];
      iVar4 = iVar5 + 1;
      local_410[iVar5 + 4] = local_410[iVar5 + 4] / fVar1;
      iVar5 = iVar4;
    } while (iVar4 < iVar3);
  }
  *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  if (*(int *)(in_ECX + 0x24) == iVar3) {
    *(undefined4 *)(in_ECX + 0x24) = 0;
  }
  piVar6 = *(int **)(in_ECX + 0xc);
  if (piVar6 == (int *)0x0) {
    FUN_006e5700(0);
    FUN_006e5290(0);
    DAT_02854c18 = 0;
    DAT_02854c1c = 0;
  }
  else {
    if (DAT_02854c18 != *piVar6) {
      FUN_006e5700(*piVar6);
      DAT_02854c18 = *piVar6;
    }
    if (DAT_02854c1c != piVar6[1]) {
      FUN_006e5290(piVar6[1]);
      DAT_02854c1c = piVar6[1];
    }
  }
  local_410[1] = 0.0;
  local_410[2] = 0.0;
  local_410[3] = 0.0;
  local_410[0] = local_410[*(int *)(in_ECX + 0x24) + 4];
  FUN_006e52e0(0x8a,local_410,1);
  FUN_005f7d00(iVar8,1,1,0);
  FUN_005f7ed0(iVar8,2,2);
  if ((iVar8 != 0) &&
     ((piVar6 = (int *)FUN_005f8460(iVar8), DAT_0097f9b8 != *piVar6 || (DAT_0097f9bc != piVar6[1])))
     ) {
    uVar7 = FUN_005f8460(iVar8);
    FUN_005fa540(0,uVar7);
  }
  FUN_005f8550(iVar8,0);
  FUN_005f7d00(*(undefined4 *)(in_ECX + 0x14),1,1,0);
  FUN_005f7ed0(*(undefined4 *)(in_ECX + 0x14),2,2);
  iVar3 = *(int *)(in_ECX + 0x14);
  if ((iVar3 != 0) &&
     ((piVar6 = (int *)FUN_005f8460(iVar3), DAT_0097f9c0 != *piVar6 || (DAT_0097f9c4 != piVar6[1])))
     ) {
    uVar7 = FUN_005f8460(iVar3);
    FUN_005fa540(1,uVar7);
  }
  FUN_005f8550(iVar3,1);
  FUN_005f7c60(*(undefined4 *)(in_ECX + 0x14),0,&local_424,&local_414);
  FUN_005f8bf0(*(undefined4 *)(in_ECX + 0x10));
  FUN_005fa2f0(0,0,local_424,local_414);
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  FUN_005fb550();
  FUN_005f8ba0(0,1);
  piVar6 = *(int **)(in_ECX + 0xc);
  if (piVar6 == (int *)0x0) {
    FUN_006e5700(0);
    FUN_006e5290(0);
    DAT_02854c18 = 0;
    DAT_02854c1c = 0;
  }
  else {
    if (DAT_02854c18 != *piVar6) {
      FUN_006e5700(*piVar6);
      DAT_02854c18 = *piVar6;
    }
    if (DAT_02854c1c != piVar6[1]) {
      FUN_006e5290(piVar6[1]);
      DAT_02854c1c = piVar6[1];
    }
  }
  FUN_006e52e0(0x8a,local_410,1);
  FUN_005f7d00(iVar8,1,1,0);
  FUN_005f7ed0(iVar8,2,2);
  iVar8 = *(int *)(in_ECX + 0x14);
  if ((iVar8 != 0) &&
     ((piVar6 = (int *)FUN_005f8460(iVar8), DAT_0097f9b8 != *piVar6 || (DAT_0097f9bc != piVar6[1])))
     ) {
    uVar7 = FUN_005f8460(iVar8);
    FUN_005fa540(0,uVar7);
  }
  FUN_005f8550(iVar8,0);
  FUN_005f7d00(*(undefined4 *)(in_ECX + 0x14),1,1,0);
  FUN_005f7ed0(*(undefined4 *)(in_ECX + 0x14),2,2);
  iVar8 = *(int *)(in_ECX + 0x14);
  if ((iVar8 != 0) &&
     ((piVar6 = (int *)FUN_005f8460(iVar8), DAT_0097f9c0 != *piVar6 || (DAT_0097f9c4 != piVar6[1])))
     ) {
    uVar7 = FUN_005f8460(iVar8);
    FUN_005fa540(1,uVar7);
  }
  FUN_005f8550(iVar8,1);
  FUN_005f8bf0(local_420);
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  FUN_005fb550();
  *piVar2 = local_41c;
  piVar2[1] = 4;
  *(undefined1 *)(piVar2 + 2) = 1;
  *(undefined1 *)((int)piVar2 + 9) = 0;
  *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28) = piVar2;
  return;
}

