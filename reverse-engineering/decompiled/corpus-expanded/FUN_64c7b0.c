/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64c7b0; label: FUN_0064c7b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064c7b0(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  char *pcVar5;
  undefined1 *puVar6;
  undefined4 local_708;
  char local_704 [256];
  char local_604 [256];
  char local_504 [256];
  char local_404 [256];
  char local_304 [256];
  char local_204 [256];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_708;
  if (DAT_0291f664 != (void *)0x0) {
    _memset(DAT_0291f664,0,DAT_0081020c * 0x220);
  }
  DAT_008102d8 = 0;
  _memset(&DAT_02913a58,0,0xbc00);
  puVar6 = &DAT_02913af8;
  do {
    iVar2 = 0;
    puVar4 = (undefined2 *)(puVar6 + -0x10);
    do {
      *puVar4 = 0xffff;
      puVar6[iVar2] = 0xff;
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar2 < 8);
    puVar6 = puVar6 + 0x178;
  } while ((int)puVar6 < 0x291f6f8);
  DAT_02920a94 = 0;
  _memset(&DAT_0291f7a8,0,0x10e0);
  puVar3 = &DAT_0291f7b4;
  do {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 0x1b;
  } while ((int)puVar3 < 0x2920894);
  DAT_0291f688 = 0xffffffff;
  DAT_0291f68c = 0xffffffff;
  DAT_0291f690 = 0xffffffff;
  DAT_0291f694 = 0xffffffff;
  _DAT_0291f698 = 0xffffffff;
  _DAT_0291f69c = 0xffffffff;
  _DAT_0291f6a0 = 0xffffffff;
  _DAT_0291f6a4 = 0xffffffff;
  _DAT_0291f6a8 = 0xffffffff;
  _DAT_0291f6ac = 0xffffffff;
  _DAT_0291f6b0 = 0xffffffff;
  _DAT_0291f6b4 = 0xffffffff;
  _DAT_0291f6b8 = 0xffffffff;
  _DAT_0291f6bc = 0xffffffff;
  _DAT_0291f6c0 = 0xffffffff;
  _DAT_0291f6c4 = 0xffffffff;
  _DAT_0291f6c8 = 0xffffffff;
  _DAT_0291f6cc = 0xffffffff;
  _DAT_0291f6d0 = 0xffffffff;
  _DAT_0291f6d4 = 0xffffffff;
  _DAT_0291f6d8 = 0xffffffff;
  _DAT_0291f6dc = 0xffffffff;
  _DAT_0291f6e0 = 0xffffffff;
  _DAT_0291f6e4 = 0xffffffff;
  _DAT_0291f6e8 = 0xffffffff;
  _DAT_0291f6ec = 0xffffffff;
  _DAT_0291f6f0 = 0xffffffff;
  _DAT_0291f6f4 = 0xffffffff;
  _DAT_0291f6f8 = 0xffffffff;
  _DAT_0291f6fc = 0xffffffff;
  _DAT_0291f700 = 0xffffffff;
  _DAT_0291f704 = 0xffffffff;
  DAT_02920a98 = 0;
  _DAT_0292089c = 0;
  _DAT_02913a2c = 0;
  DAT_029208a0 = 0;
  DAT_02913a30 = 0;
  DAT_029208a4 = 0;
  DAT_02913a34 = 0;
  _DAT_029208a8 = 0;
  _DAT_02913a38 = 0;
  _DAT_029208ac = 0;
  _DAT_02913a3c = 0;
  _DAT_029208b0 = 0;
  _DAT_02913a40 = 0;
  _DAT_029208b4 = 0;
  _DAT_02913a44 = 0;
  _DAT_029208b8 = 0;
  _DAT_02913a48 = 0;
  DAT_029208d0 = 0;
  DAT_029208d4 = 0;
  DAT_029208d8 = 0;
  DAT_029208dc = 0;
  _DAT_029208e0 = 0;
  _DAT_029208e4 = 0;
  _DAT_029208e8 = 0;
  _DAT_029208ec = 0;
  _DAT_029208f0 = 0;
  _DAT_029208f4 = 0;
  _DAT_029208f8 = 0;
  _DAT_029208fc = 0;
  _DAT_02920900 = 0;
  _DAT_02920904 = 0;
  _DAT_02920908 = 0;
  _DAT_0292090c = 0;
  _DAT_02920910 = 0;
  _DAT_02920914 = 0;
  _DAT_02920918 = 0;
  _DAT_0292091c = 0;
  _DAT_02920920 = 0;
  _DAT_02920924 = 0;
  _DAT_02920928 = 0;
  _DAT_0292092c = 0;
  _DAT_02920930 = 0;
  _DAT_02920934 = 0;
  _DAT_02920938 = 0;
  _DAT_0292093c = 0;
  _DAT_02920940 = 0;
  _DAT_02920944 = 0;
  _DAT_02920948 = 0;
  _DAT_0292094c = 0;
  DAT_0291f780 = 0;
  if (DAT_02962218 == '\0') {
    _sprintf(local_204,".");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962218)[iVar2];
      local_204[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962318 == '\0') {
    _sprintf(local_604,"part");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962318)[iVar2];
      local_604[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962418 == '\0') {
    _sprintf(local_404,(char *)&PTR_DAT_0076cbb4);
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962418)[iVar2];
      local_404[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962518 == '\0') {
    _sprintf(local_104,".");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962518)[iVar2];
      local_104[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962618 == '\0') {
    _sprintf(local_304,"part");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962618)[iVar2];
      local_304[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962718 == '\0') {
    _sprintf(local_504,(char *)&PTR_DAT_0076cbb4);
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962718)[iVar2];
      local_504[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  _sprintf(local_704,"%s\\%s.%s",local_204,local_604,local_404);
  iVar2 = thunk_FUN_004fa610(local_704);
  if (iVar2 != 0) {
    local_708 = DAT_02962918;
    FUN_0064c300(local_704,0,&local_708,1);
  }
  _sprintf(local_704,"%s\\%s.%s",local_104,local_304,local_504);
  iVar2 = thunk_FUN_004fa610(local_704);
  if (iVar2 != 0) {
    local_708 = DAT_02962114;
    cVar1 = FUN_0064c300(local_704,1,&local_708,1);
    pcVar5 = &DAT_0291f7da;
    do {
      if ((*(int *)(pcVar5 + -0x26) != -1) && (*pcVar5 == cVar1)) {
        pcVar5[0xe] = -0x66;
        pcVar5[0xf] = '?';
        pcVar5[0x10] = '\x1c';
        pcVar5[0x11] = 'F';
      }
      pcVar5 = pcVar5 + 0x6c;
    } while ((int)pcVar5 < 0x29208ba);
    *(undefined4 *)(&DAT_02913a2c + cVar1 * 4) = 1;
  }
  FUN_00644d00("Loaded OK",1);
  __security_check_cookie(local_4 ^ (uint)&local_708);
  return;
}

