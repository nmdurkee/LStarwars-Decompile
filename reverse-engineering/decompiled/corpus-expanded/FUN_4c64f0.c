/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c64f0; label: FUN_004c64f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c64f0(void)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  bool bVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  undefined *puVar8;
  char *pcVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  float10 extraout_ST0;
  char *pcVar13;
  float fVar14;
  undefined4 uVar15;
  float local_110;
  undefined4 *local_10c;
  float local_108;
  char local_104 [128];
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_110;
  bVar11 = false;
  bVar4 = false;
  if (DAT_008801ac == 0) {
    local_10c = (undefined4 *)&DAT_008800bc;
    puVar8 = DAT_0088047c;
LAB_004c6522:
    if (puVar8 == (undefined *)0x0) goto LAB_004c6bd4;
  }
  else {
    if (DAT_008801ac == 1) {
      local_10c = (undefined4 *)&DAT_0087bdec;
      puVar8 = DAT_00880478;
      goto LAB_004c6522;
    }
    if (DAT_008801ac == 2) {
      local_10c = (undefined4 *)&DAT_0087bf00;
      puVar8 = DAT_00880480;
      goto LAB_004c6522;
    }
    if (DAT_008801ac == 4) {
      local_10c = (undefined4 *)&DAT_0087ff98;
      puVar8 = DAT_00880488;
      goto LAB_004c6522;
    }
    if (DAT_008801ac != 5) goto LAB_004c6bd4;
    puVar8 = &DAT_0087c578;
    local_10c = &DAT_0087bed4;
  }
  cVar1 = puVar8[local_10c[3] * 0x74 + 0x62];
  pcVar9 = puVar8 + local_10c[3] * 0x74;
  if (cVar1 == '\x01') {
    if (pcVar9[99] == '\x01') {
      bVar4 = true;
      goto LAB_004c6a80;
    }
    if ((uint)*(ushort *)(pcVar9 + 0x60) == (int)DAT_007f17d4) {
      bVar12 = DAT_0086e4e5 != '\0';
    }
    else {
      iVar6 = FUN_00594870((uint)*(ushort *)(pcVar9 + 0x60));
      bVar12 = iVar6 != 0;
    }
    if (bVar12) goto LAB_004c65d9;
    local_110 = _DAT_0087c570 * 0.7;
    uVar7 = FUN_006e6b90();
    local_108 = (_DAT_007f92ec + _DAT_007f92e4) * 0.5;
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008806e8 * 4),0,local_108,0x3f800000,local_110,
                 local_110,local_110,0,0xff,0,0,0x3fd9999a,1,0,0,uVar7);
  }
  else {
    if (cVar1 == '\0') {
      bVar4 = false;
      if (pcVar9[99] != '\x01') {
        bVar11 = *(int *)(pcVar9 + 100) != 0;
        goto LAB_004c6a82;
      }
    }
    else if (cVar1 == '\x02') {
      uVar10 = (uint)*(ushort *)(pcVar9 + 0x60);
      sVar5 = DAT_008806a0;
      if ((short *)(&PTR_DAT_007f3d9c)[uVar10 * 8] != (short *)0x0) {
        sVar5 = *(short *)(&PTR_DAT_007f3d9c)[uVar10 * 8];
      }
      FUN_004f1f10(local_84,*(undefined4 *)(DAT_00926c20 + sVar5 * 4));
      pcVar9 = local_84;
      if (puVar8[local_10c[3] * 0x74 + 99] != '\x01') {
        if (((7 < uVar10) && ((&DAT_007f3da3)[uVar10 * 0x20] != -1)) &&
           ((&DAT_0086e0fa)[(char)(&DAT_007f3da3)[uVar10 * 0x20] * 0xc] == '\0')) {
          _sprintf(local_104,"%s %i",*(undefined4 *)(DAT_00926c20 + DAT_0088072c * 4),uVar10 - 7);
          local_110 = _DAT_0087c570 * 0.6;
          uVar7 = FUN_006e6b90();
          FUN_0050d910(local_104,0,_DAT_007f92e4,0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,
                       0xff,0xff,0x3fd9999a,1,0,0,uVar7);
LAB_004c6a10:
          uVar7 = FUN_006e6b90();
          pcVar13 = *(char **)(DAT_00926c20 + DAT_008806e8 * 4);
          uVar15 = 0;
          fVar14 = local_110;
          goto LAB_004c6a76;
        }
LAB_004c65d9:
        bVar4 = true;
        bVar11 = true;
        goto LAB_004c6a82;
      }
      bVar4 = true;
    }
    else {
      if (cVar1 == '\x04') {
        uVar2 = *(ushort *)(pcVar9 + 0x60);
        _sprintf(local_104,"%s %i",*(undefined4 *)(DAT_00926c20 + DAT_00880758 * 4),uVar2 + 1);
        pcVar9 = local_104;
        if (puVar8[local_10c[3] * 0x74 + 99] == '\x01') {
          bVar4 = true;
          goto LAB_004c6a80;
        }
        local_108 = (float)((uint)uVar2 * 0xe10);
        if ((float)(int)local_108 <= _DAT_0086e4e8) goto LAB_004c65d9;
        uVar7 = FUN_006e6b90();
        FUN_0050d910(local_104,0,_DAT_007f92e4,0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,
                     0xff,0xff,0x3fd9999a,1,0,0,uVar7);
        local_110 = _DAT_0087c570 * 0.6;
        uVar7 = FUN_006e6b90();
        pcVar13 = *(char **)(DAT_00926c20 + DAT_008806e8 * 4);
        uVar15 = 0;
        fVar14 = local_110;
      }
      else {
        if (cVar1 != '\x05') goto LAB_004c6a82;
        uVar3 = *(undefined2 *)(pcVar9 + 0x60);
        iVar6 = FUN_0057e720(uVar3);
        FUN_0057e850(uVar3,local_104,local_84,iVar6);
        uVar7 = FUN_006e6b90();
        FUN_0050d910(local_104,0,_DAT_007f92e4,0x3f800000,0x3f19999a,0x3f19999a,0x3f19999a,0,0xff,
                     0xff,0xff,0x3fd9999a,1,0,0,uVar7);
        if ((iVar6 == 0) || (DAT_0088049c == 0)) {
          local_110 = _DAT_0087c570 * 0.6;
          goto LAB_004c6a10;
        }
        uVar7 = FUN_006e6b90();
        fVar14 = 0.6;
        uVar15 = 0xbf;
        pcVar13 = local_84;
      }
LAB_004c6a76:
      FUN_0050d910(pcVar13,0,_DAT_007f92ec,0x3f800000,fVar14,fVar14,fVar14,0,0xff,uVar15,0,
                   0x3fd9999a,1,0,0,uVar7);
      bVar4 = false;
    }
LAB_004c6a80:
    bVar11 = false;
  }
LAB_004c6a82:
  if (_DAT_0087bd78 <= 0.0) {
switchD_004c6b55_caseD_5:
    goto LAB_004c6bd4;
  }
  if (bVar4) {
    if (bVar11) {
      local_108 = _DAT_007f92e4;
      local_110 = 0.6;
    }
    else {
      local_108 = (_DAT_007f92ec + _DAT_007f92e4) * 0.5;
      local_110 = 0.8;
    }
    uVar7 = FUN_006e6b90();
    FUN_0050d910(pcVar9,(float)extraout_ST0,local_108,0x3f800000,local_110,local_110,local_110,0,
                 0xff,0xff,0xff,0x3fd9999a,1,0,0,uVar7);
  }
  if (!bVar11) goto switchD_004c6b55_caseD_5;
  switch(puVar8[local_10c[3] * 0x74 + 0x62]) {
  case 0:
    iVar6 = DAT_008800c8;
    goto LAB_004c6b95;
  case 1:
    uVar7 = *(undefined4 *)(puVar8 + DAT_0087bdf8 * 0x74 + 100);
    break;
  case 2:
    uVar7 = *(undefined4 *)(puVar8 + DAT_0087bf0c * 0x74 + 100);
    break;
  default:
    iVar6 = DAT_0087bdf8;
LAB_004c6b95:
    uVar7 = *(undefined4 *)(puVar8 + iVar6 * 0x74 + 100);
    break;
  case 4:
    uVar7 = *(undefined4 *)(puVar8 + DAT_0087ffa4 * 0x74 + 100);
    break;
  case 5:
    goto switchD_004c6b55_caseD_5;
  }
  FUN_004b80e0(uVar7,_DAT_007f92ec,0x3f99999a,0,_DAT_0087bd78,0xff,0xbf,0);
LAB_004c6bd4:
  __security_check_cookie(local_4 ^ (uint)&local_110);
  return;
}

