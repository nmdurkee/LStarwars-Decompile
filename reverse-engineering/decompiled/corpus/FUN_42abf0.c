/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x42abf0; label: FUN_0042abf0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042abf0(void)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  char cVar6;
  ushort *puVar7;
  int iVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  uVar5 = DAT_008668d8;
  uVar4 = DAT_008668d4;
  uVar3 = _DAT_008668d0;
  uVar2 = _DAT_008668cc;
  _DAT_0087656c = _DAT_008668cc;
  _DAT_00876570 = _DAT_008668d0;
  _DAT_00876574 = DAT_008668d4;
  DAT_00876578 = DAT_008668d8;
  _memset(&DAT_008668c8,0,0x7e4c);
  _DAT_00856c10 = 0x3f000000;
  _DAT_00856c14 = 0;
  DAT_00856c0c = 0;
  DAT_008668c8._1_1_ = 5;
  _DAT_008668cc = uVar2;
  _DAT_008668d0 = uVar3;
  DAT_008668d4 = uVar4;
  DAT_008668d8 = uVar5;
  if (DAT_00956290 == 0) {
    DAT_0086e0f4 = 1;
  }
  else {
    (&DAT_0086e0f4)[*(short *)(DAT_00956290 + 4) * 0xc] = 1;
  }
  if (DAT_0087b030 != 0) {
    (&DAT_0086e0f4)[(uint)*(byte *)(DAT_0087b030 + 0x7c) * 0xc] = 1;
  }
  if (DAT_0087b034 != 0) {
    (&DAT_0086e0f4)[(uint)*(byte *)(DAT_0087b034 + 0x7c) * 0xc] = 1;
  }
  if (DAT_0087b038 != 0) {
    (&DAT_0086e0f4)[(uint)*(byte *)(DAT_0087b038 + 0x7c) * 0xc] = 1;
  }
  if (DAT_0087b03c != 0) {
    (&DAT_0086e0f4)[(uint)*(byte *)(DAT_0087b03c + 0x7c) * 0xc] = 1;
  }
  if (DAT_0087b040 != 0) {
    (&DAT_0086e0f4)[(uint)*(byte *)(DAT_0087b040 + 0x7c) * 0xc] = 1;
  }
  if (DAT_0087b044 != 0) {
    (&DAT_0086e0f4)[(uint)*(byte *)(DAT_0087b044 + 0x7c) * 0xc] = 1;
  }
  FUN_0056e2e0(0);
  _DAT_0086e4cc = _DAT_0086e4cc | 0x1000;
  FUN_0056e130(0x2c,1,1);
  FUN_00576670();
  _DAT_00876d9c = _DAT_00876d9c & 0xfffffff8;
  FUN_004017c0();
  iVar12 = DAT_00951360;
  iVar8 = DAT_00951354;
  iVar11 = 0;
  DAT_0087a7c4 = 0;
  _DAT_0087a7c0 = 0;
  if (3 < DAT_00951360) {
    iVar10 = (DAT_00951360 - 4U >> 2) + 1;
    iVar11 = iVar10 * 4;
    puVar7 = (ushort *)(DAT_00951354 + 0x120);
    pfVar9 = (float *)&DAT_0086e108;
    do {
      iVar10 = iVar10 + -1;
      pfVar9[-3] = (float)puVar7[-0x4e];
      *pfVar9 = (float)*puVar7;
      pfVar9[3] = (float)puVar7[0x4e];
      pfVar9[6] = (float)puVar7[0x9c];
      puVar7 = puVar7 + 0x138;
      pfVar9 = pfVar9 + 0xc;
    } while (iVar10 != 0);
  }
  if (iVar11 < iVar12) {
    puVar7 = (ushort *)(iVar11 * 0x9c + 0x84 + iVar8);
    iVar12 = iVar12 - iVar11;
    pfVar9 = (float *)(&DAT_0086e0fc + iVar11 * 3);
    do {
      uVar1 = *puVar7;
      puVar7 = puVar7 + 0x4e;
      iVar12 = iVar12 + -1;
      *pfVar9 = (float)uVar1;
      pfVar9 = pfVar9 + 3;
    } while (iVar12 != 0);
  }
  _DAT_0086e454 = 0x45610000;
  _DAT_0086e458 = 100000;
  _DAT_0086e460 = 0x45610000;
  _DAT_0086e464 = 100000;
  _DAT_0086e46c = 0x45610000;
  _DAT_0086e470 = 100000;
  _DAT_0086e47c = 100000;
  _DAT_0086e478 = 0x45610000;
  _DAT_0086e488 = 100000;
  _DAT_0086e484 = 0x45610000;
  _DAT_0086e494 = 100000;
  _DAT_0086e490 = 0x45610000;
  FUN_00593810(DAT_00856980,&DAT_0086e4ec);
  if (DAT_00926c20 != 0) {
    if (*(int *)(DAT_00926c20 + 0x330) != 0) {
      FUN_004f1f10(&DAT_0086e500,*(undefined4 *)(DAT_00926c20 + 0x330));
    }
    if (*(int *)(DAT_00926c20 + 0x334) != 0) {
      FUN_004f1f10(&DAT_0086e538,*(undefined4 *)(DAT_00926c20 + 0x334));
    }
    FUN_00423900(0xffffffff);
  }
  if ((short)_DAT_007f1808 != -1) {
    (&DAT_0086e5c0)[(short)_DAT_007f1808] = (&DAT_0086e5c0)[(short)_DAT_007f1808] | 3;
  }
  if (DAT_007f180a != -1) {
    (&DAT_0086e5c0)[DAT_007f180a] = (&DAT_0086e5c0)[DAT_007f180a] | 3;
  }
  iVar11 = DAT_0093b274;
  if (DAT_007f18e4 != -1) {
    iVar8 = (int)DAT_007f18e4;
    (&DAT_0086e5c0)[iVar8] = (&DAT_0086e5c0)[iVar8] | 3;
    if (iVar11 != 0) {
      *(undefined4 *)(iVar8 * 0x4c + iVar11) = 0xcc;
      iVar11 = DAT_0093b274;
    }
  }
  if (DAT_007f18e8 != -1) {
    iVar8 = (int)DAT_007f18e8;
    (&DAT_0086e5c0)[iVar8] = (&DAT_0086e5c0)[iVar8] | 3;
    if (iVar11 != 0) {
      *(undefined4 *)(iVar8 * 0x4c + iVar11) = 0xcd;
    }
  }
  DAT_0086e520 = 1;
  DAT_0086e558 = 1;
  if (DAT_007fcfc6 == '\0') {
    cVar6 = '\0';
  }
  else {
    DAT_0086e4c4 = DAT_0086e4c4 | 1;
    cVar6 = DAT_007fcfc6;
  }
  if (DAT_007fcfde != cVar6) {
    DAT_0086e4c4 = DAT_0086e4c4 | 2;
    cVar6 = DAT_007fcfde;
  }
  if (DAT_007fcff6 != cVar6) {
    DAT_0086e4c4 = DAT_0086e4c4 | 4;
    cVar6 = DAT_007fcff6;
  }
  if (DAT_007fd00e != cVar6) {
    DAT_0086e4c4 = DAT_0086e4c4 | 8;
    cVar6 = DAT_007fd00e;
  }
  if (DAT_007fd026 != cVar6) {
    DAT_0086e4c4 = DAT_0086e4c4 | 0x10;
    cVar6 = DAT_007fd026;
  }
  if (DAT_007fd03e != cVar6) {
    DAT_0086e4c4 = DAT_0086e4c4 | 0x20;
    cVar6 = DAT_007fd03e;
  }
  if (DAT_007fd056 != cVar6) {
    DAT_0086e4c4 = DAT_0086e4c4 | 0x40;
    cVar6 = DAT_007fd056;
  }
  if (DAT_007fd06e != cVar6) {
    DAT_0086e4c4 = DAT_0086e4c4 | 0x80;
    cVar6 = DAT_007fd06e;
  }
  if (DAT_007fd086 != cVar6) {
    DAT_0086e4c4 = DAT_0086e4c4 | 0x100;
    cVar6 = DAT_007fd086;
  }
  if (DAT_007fd09e != cVar6) {
    DAT_0086e4c4 = DAT_0086e4c4 | 0x200;
  }
  return;
}

