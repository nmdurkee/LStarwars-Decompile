/* Ghidra analysis pseudocode, not original source.
 * ev_528f0eafdf60551b868e0e925a842777892bdaf44669a30da4d03ef81027d70b
 * Entry: 0x6dd9e0; label: FUN_006dd9e0
 */

void FUN_006dd9e0(char *param_1,char *param_2,int param_3,char *param_4)

{
  char cVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  FILE *pFVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *unaff_ESI;
  undefined4 *puVar10;
  char *pcVar11;
  undefined2 *puVar12;
  undefined4 *puVar13;
  
  if (param_3 == 1) {
    uVar3 = 0x1c;
    if (DAT_00827620 != 0) {
      uVar3 = 5;
    }
    iVar4 = SHGetFolderPathA(0,uVar3,0,0,&DAT_02975d70);
    pcVar9 = (char *)&DAT_02975f78;
    pcVar6 = (char *)((iVar4 < 0) - 1 & 0x2975d70);
    do {
      cVar1 = *pcVar6;
      *pcVar9 = cVar1;
      puVar2 = PTR_s_TTales_00827618;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    puVar12 = (undefined2 *)0x2975f77;
    do {
      pcVar6 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined2 *)((int)puVar12 + 1);
    } while (*pcVar6 != '\0');
    *puVar12 = 0x5c;
    pcVar6 = puVar2;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    puVar13 = (undefined4 *)0x2975f77;
    do {
      pcVar9 = (char *)((int)puVar13 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    } while (*pcVar9 != '\0');
    puVar10 = (undefined4 *)puVar2;
    for (uVar7 = (uint)((int)pcVar6 - (int)puVar2) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar13 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar13 = puVar13 + 1;
    }
    for (uVar7 = (int)pcVar6 - (int)puVar2 & 3; puVar2 = PTR_s_GameTitle_0082761c, uVar7 != 0;
        uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar13 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    puVar12 = (undefined2 *)0x2975f77;
    do {
      pcVar6 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined2 *)((int)puVar12 + 1);
    } while (*pcVar6 != '\0');
    *puVar12 = 0x5c;
    pcVar6 = puVar2;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    puVar13 = (undefined4 *)0x2975f77;
    do {
      pcVar9 = (char *)((int)puVar13 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    } while (*pcVar9 != '\0');
    puVar10 = (undefined4 *)puVar2;
    for (uVar7 = (uint)((int)pcVar6 - (int)puVar2) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar13 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar13 = puVar13 + 1;
    }
    for (uVar7 = (int)pcVar6 - (int)puVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar13 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    puVar12 = (undefined2 *)0x2975f77;
    do {
      pcVar6 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined2 *)((int)puVar12 + 1);
    } while (*pcVar6 != '\0');
    *puVar12 = 0x5c;
    pcVar6 = param_2;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    pcVar9 = (char *)0x2975f77;
    do {
      pcVar11 = pcVar9 + 1;
      pcVar9 = pcVar9 + 1;
    } while (*pcVar11 != '\0');
    pcVar11 = param_2;
    for (uVar7 = (uint)((int)pcVar6 - (int)param_2) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar11;
      pcVar11 = pcVar11 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar7 = (int)pcVar6 - (int)param_2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar9 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  else {
    iVar4 = (int)&DAT_02975f78 - (int)param_2;
    do {
      cVar1 = *param_2;
      param_2[iVar4] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
  }
  iVar4 = 0;
  do {
    pcVar6 = (char *)((int)&DAT_02975f78 + iVar4);
    (&DAT_02975e78)[iVar4] = *pcVar6;
    iVar4 = iVar4 + 1;
    pcVar9 = param_1;
  } while (*pcVar6 != '\0');
  do {
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  uVar7 = (int)pcVar9 - (int)param_1;
  pcVar6 = (char *)0x2975e77;
  do {
    pcVar9 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar9 != '\0');
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)param_1;
    param_1 = param_1 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *pcVar6 = *param_1;
    param_1 = param_1 + 1;
    pcVar6 = pcVar6 + 1;
  }
  pFVar5 = _fopen(&DAT_02975e78,param_4);
  if (pFVar5 == (FILE *)0x0) {
    uVar3 = 0x1c;
    if (DAT_00827620 != 0) {
      uVar3 = 5;
    }
    iVar4 = SHGetFolderPathA(0,uVar3,0,0,&DAT_02975d70);
    pcVar9 = (char *)&DAT_02975f78;
    pcVar6 = (char *)((iVar4 < 0) - 1 & 0x2975d70);
    do {
      cVar1 = *pcVar6;
      *pcVar9 = cVar1;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    puVar12 = (undefined2 *)0x2975f77;
    do {
      pcVar6 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined2 *)((int)puVar12 + 1);
    } while (*pcVar6 != '\0');
    *puVar12 = 0x5c;
    pcVar6 = PTR_s_TTales_00827618;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    uVar7 = (int)pcVar6 - (int)PTR_s_TTales_00827618;
    puVar13 = (undefined4 *)0x2975f77;
    do {
      pcVar6 = (char *)((int)puVar13 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    } while (*pcVar6 != '\0');
    puVar10 = (undefined4 *)PTR_s_TTales_00827618;
    for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar13 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar13 = puVar13 + 1;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar13 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    CreateDirectoryA((LPCSTR)&DAT_02975f78,(LPSECURITY_ATTRIBUTES)0x0);
    puVar2 = PTR_s_GameTitle_0082761c;
    puVar12 = (undefined2 *)0x2975f77;
    do {
      pcVar6 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined2 *)((int)puVar12 + 1);
    } while (*pcVar6 != '\0');
    *puVar12 = 0x5c;
    pcVar6 = puVar2;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    puVar13 = (undefined4 *)0x2975f77;
    do {
      pcVar9 = (char *)((int)puVar13 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    } while (*pcVar9 != '\0');
    puVar10 = (undefined4 *)puVar2;
    for (uVar7 = (uint)((int)pcVar6 - (int)puVar2) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar13 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar13 = puVar13 + 1;
    }
    for (uVar7 = (int)pcVar6 - (int)puVar2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar13 = *(undefined1 *)puVar10;
      puVar10 = (undefined4 *)((int)puVar10 + 1);
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    }
    CreateDirectoryA((LPCSTR)&DAT_02975f78,(LPSECURITY_ATTRIBUTES)0x0);
    puVar12 = (undefined2 *)0x2975f77;
    do {
      pcVar6 = (char *)((int)puVar12 + 1);
      puVar12 = (undefined2 *)((int)puVar12 + 1);
    } while (*pcVar6 != '\0');
    *puVar12 = 0x5c;
    pcVar6 = unaff_ESI;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    pcVar9 = (char *)0x2975f77;
    do {
      pcVar11 = pcVar9 + 1;
      pcVar9 = pcVar9 + 1;
    } while (*pcVar11 != '\0');
    pcVar11 = unaff_ESI;
    for (uVar7 = (uint)((int)pcVar6 - (int)unaff_ESI) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar11;
      pcVar11 = pcVar11 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar7 = (int)pcVar6 - (int)unaff_ESI & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar9 = *pcVar11;
      pcVar11 = pcVar11 + 1;
      pcVar9 = pcVar9 + 1;
    }
    CreateDirectoryA((LPCSTR)&DAT_02975f78,(LPSECURITY_ATTRIBUTES)0x0);
    _fopen(&DAT_02975e78,param_4);
  }
  return;
}

