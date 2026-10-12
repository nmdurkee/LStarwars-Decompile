/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f6c60; label: FUN_005f6c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f6c60(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int in_ECX;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 *puVar16;
  int *local_bc;
  int local_b8;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  float fStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80 [16];
  undefined4 local_40 [16];
  
  D3DPERF_BeginEvent(0xffffffff,L"Deferred shading");
  iVar12 = *(int *)(DAT_0080bbb4 + DAT_0080bbb0 * 0x28);
  piVar1 = *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28);
  piVar8 = *(int **)(DAT_0080bbc4 + DAT_0080bbc0 * 0x28);
  piVar2 = *(int **)(DAT_0080bbd4 + DAT_0080bbd0 * 0x28);
  iVar11 = *(int *)(DAT_0080bbdc + DAT_0080bbd8 * 0x28);
  if (*(char *)((int)piVar1 + 9) == '\0') {
    FUN_005f8ba0(piVar1[1],(char)piVar1[2]);
    *(undefined1 *)((int)piVar1 + 9) = 1;
  }
  if (*(char *)((int)piVar8 + 9) == '\0') {
    FUN_005f8ba0(piVar8[1],(char)piVar8[2]);
    *(undefined1 *)((int)piVar8 + 9) = 1;
  }
  if (*(char *)((int)piVar2 + 9) == '\0') {
    FUN_005f8ba0(piVar2[1],(char)piVar2[2]);
    *(undefined1 *)((int)piVar2 + 9) = 1;
  }
  if (*(char *)(iVar11 + 9) == '\0') {
    FUN_005f8ba0(*(undefined4 *)(iVar11 + 4),*(undefined1 *)(iVar11 + 8));
    *(undefined1 *)(iVar11 + 9) = 1;
  }
  iVar3 = *piVar1;
  iVar4 = *piVar8;
  iVar5 = *piVar2;
  iVar7 = FUN_005f8a80(iVar12,0,0,0);
  iVar11 = *(int *)(in_ECX + 0xc);
  bVar6 = true;
  local_b8 = 0;
  if (0 < *(int *)(in_ECX + 0x54)) {
    local_bc = (int *)(in_ECX + 0x58);
    do {
      iVar15 = *local_bc;
      if (*(int *)(iVar15 + 0x808) != 0) {
        puVar14 = &DAT_00986eb8;
        puVar16 = local_40;
        for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar16 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar16 = puVar16 + 1;
        }
        puVar14 = &DAT_0280d820;
        puVar16 = local_80;
        for (iVar13 = 0x10; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar16 = *puVar14;
          puVar14 = puVar14 + 1;
          puVar16 = puVar16 + 1;
        }
        FUN_006e5340(0x16,1);
        FUN_006e5340(0xf,1);
        FUN_006e5340(0x1b,1);
        FUN_006e5340(7,1);
        FUN_006e5340(0x17,4);
        D3DPERF_BeginEvent(0xffffffff,L"Shadow render");
        iVar13 = 0;
        if (0 < *(int *)(iVar15 + 0x710)) {
          puVar14 = (undefined4 *)(in_ECX + 0x2dc);
          do {
            FUN_00605b60(*puVar14,0,puVar14[-0xa9],0);
            FUN_00605b60(*puVar14,4,*(undefined4 *)(in_ECX + 0x30),0);
            FUN_005f8bf0(*puVar14);
            FUN_005f7c60(*(undefined4 *)(in_ECX + 0x30),0,&local_94,&local_98);
            FUN_005fa2f0(0,0,local_94,local_98);
            FUN_005f8cb0(0x300,0xffffffff);
            FUN_005f6ab0(iVar13,*puVar14);
            FUN_005f8bb0(1);
            iVar13 = iVar13 + 1;
            puVar14 = puVar14 + 1;
          } while (iVar13 < *(int *)(iVar15 + 0x710));
        }
        D3DPERF_EndEvent();
        FUN_005fa330(local_40,local_80);
        iVar13 = FUN_005f8a80(*(undefined4 *)(in_ECX + 0x2f4),0,0,0);
        if (iVar13 == 0) {
          FUN_00605b60(*(undefined4 *)(in_ECX + 0x2f4),0,*(undefined4 *)(in_ECX + 0x28),0);
        }
        FUN_005f8bf0(*(undefined4 *)(in_ECX + 0x2f4));
        if (bVar6) {
          FUN_005f8cb0(0x100,0xff0000ff);
          FUN_006e5340(0x16,1);
          FUN_006e5340(0xf,0);
          FUN_006e5340(0x1b,0);
          FUN_006e5340(7,0);
          FUN_006e5340(0xa8,0xf);
        }
        if (*(int *)(iVar15 + 0x804) == 0) {
          piVar8 = *(int **)(in_ECX + 0x10);
        }
        else if (*(int *)(iVar15 + 0x804) == 1) {
          piVar8 = *(int **)(in_ECX + 0x10);
        }
        else {
          piVar8 = *(int **)(in_ECX + 0x14);
        }
        if (!bVar6) {
          DAT_02854c18 = 0;
          DAT_02854c1c = 0;
        }
        if (piVar8 == (int *)0x0) {
          FUN_006e5700(0);
          FUN_006e5290(0);
          DAT_02854c18 = 0;
          DAT_02854c1c = 0;
        }
        else {
          if (DAT_02854c18 != *piVar8) {
            FUN_006e5700(*piVar8);
            DAT_02854c18 = *piVar8;
          }
          if (DAT_02854c1c != piVar8[1]) {
            FUN_006e5290(piVar8[1]);
            DAT_02854c1c = piVar8[1];
          }
        }
        FUN_005c70a0(piVar8);
        FUN_005f7d00(iVar5,2,2,0);
        if ((iVar5 != 0) &&
           ((piVar8 = (int *)FUN_005f8460(iVar5), DAT_0097f9b8 != *piVar8 ||
            (DAT_0097f9bc != piVar8[1])))) {
          uVar9 = FUN_005f8460(iVar5);
          FUN_005fa540(0,uVar9);
        }
        FUN_005f8550(iVar5,0);
        iVar15 = *(int *)(in_ECX + 0x38);
        if ((iVar15 != 0) &&
           ((piVar8 = (int *)FUN_005f8460(iVar15), DAT_0097f9c0 != *piVar8 ||
            (DAT_0097f9c4 != piVar8[1])))) {
          uVar9 = FUN_005f8460(iVar15);
          FUN_005fa540(1,uVar9);
        }
        FUN_005f8550(iVar15,1);
        iVar15 = *(int *)(in_ECX + 0x3c);
        if ((iVar15 != 0) &&
           ((piVar8 = (int *)FUN_005f8460(iVar15), DAT_0097f9d8 != *piVar8 ||
            (DAT_0097f9dc != piVar8[1])))) {
          uVar9 = FUN_005f8460(iVar15);
          FUN_005fa540(4,uVar9);
        }
        FUN_005f8550(iVar15,4);
        if (iVar4 != 0) {
          FUN_005f7d00(iVar4,1,1,0);
          piVar8 = (int *)FUN_005f8460(iVar4);
          if ((DAT_0097f9c8 != *piVar8) || (DAT_0097f9cc != piVar8[1])) {
            uVar9 = FUN_005f8460(iVar4);
            FUN_005fa540(2,uVar9);
          }
          FUN_005f8550(iVar4,2);
        }
        FUN_006e5340(0x16,1);
        FUN_006e5340(0xf,0);
        FUN_006e5340(0x1b,0);
        FUN_006e5340(7,0);
        FUN_006e5340(0xa8,0xf);
        FUN_005fb550();
        FUN_005f8ba0(0,0);
        iVar15 = 0;
        do {
          FUN_005f8550(0,iVar15);
          iVar15 = iVar15 + 1;
        } while (iVar15 != 6);
        bVar6 = false;
      }
      local_bc = local_bc + 1;
      local_b8 = local_b8 + 1;
    } while (local_b8 < *(int *)(in_ECX + 0x54));
  }
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  FUN_0060a830(*(undefined4 *)(in_ECX + 0x28),0,*(undefined4 *)(in_ECX + 0x28),1,1,
               *(int *)(in_ECX + 0xc) + -1,1,0x3f800000,DAT_00973814);
  FUN_005f8bf0(iVar12);
  uVar9 = FUN_005f8ae0(iVar12);
  uVar10 = FUN_005f8b10(iVar12);
  FUN_005fa2f0(0,0,uVar9,uVar10);
  FUN_005f8a60(1);
  FUN_005c2760();
  uStack_90 = *(undefined4 *)(in_ECX + 0x48);
  uStack_88 = *(undefined4 *)(in_ECX + 0x4c);
  uStack_84 = *(undefined4 *)(in_ECX + 0x50);
  fStack_8c = (float)iVar11 - 1.0;
  FUN_006e52e0(0xa0,&uStack_90,1);
  iVar11 = FUN_005f8a60(1);
  if ((iVar12 == iVar11) && (DAT_02976c7c != 0)) {
    FUN_005f7d00(iVar3,2,2,0);
    if ((iVar3 != 0) &&
       ((piVar8 = (int *)FUN_005f8460(iVar3), DAT_0097f9d8 != *piVar8 || (DAT_0097f9dc != piVar8[1])
        ))) {
      uVar9 = FUN_005f8460(iVar3);
      FUN_005fa540(4,uVar9);
    }
    FUN_005f8550(iVar3,4);
    FUN_006e5340(0x1b,0);
    FUN_006e5340(0xf,0);
  }
  else {
    FUN_006e5340(0x1b,1);
    FUN_006e5340(0xf,0);
    FUN_006e5340(0x13,5);
    FUN_006e5340(0x14,6);
    FUN_005f8550(0,4);
  }
  FUN_006e5340(0xbe,0);
  FUN_006e5340(0xbf,0);
  FUN_006e5340(0xc0,0);
  FUN_005f7d00(*(undefined4 *)(in_ECX + 0x28),2,2,2);
  iVar12 = FUN_006e6b90();
  FUN_005f7cc0(*(undefined4 *)(in_ECX + 0x28),0,iVar12 + 1);
  iVar12 = *(int *)(in_ECX + 0x28);
  if ((iVar12 != 0) &&
     ((piVar8 = (int *)FUN_005f8460(iVar12), DAT_0097f9e0 != *piVar8 || (DAT_0097f9e4 != piVar8[1]))
     )) {
    uVar9 = FUN_005f8460(iVar12);
    FUN_005fa540(5,uVar9);
  }
  FUN_005f8550(iVar12,5);
  FUN_005fb550();
  *piVar1 = iVar7;
  piVar1[1] = 0;
  *(undefined1 *)(piVar1 + 2) = 1;
  *(undefined1 *)((int)piVar1 + 9) = 0;
  *(int **)(DAT_0080bbbc + DAT_0080bbb8 * 0x28) = piVar1;
  FUN_006e5340(0xbe,0xffffffff);
  FUN_006e5340(0xbf,0xffffffff);
  FUN_006e5340(0xc0,0xffffffff);
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  D3DPERF_EndEvent();
  return;
}

