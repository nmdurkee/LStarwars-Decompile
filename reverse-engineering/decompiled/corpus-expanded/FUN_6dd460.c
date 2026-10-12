/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dd460; label: FUN_006dd460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dd460(char *param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  FILE *_File;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined2 *puVar9;
  undefined4 *puVar10;
  undefined4 local_10c;
  undefined1 local_108 [3];
  undefined4 uStack_105;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_10c;
  _local_108 = param_1;
  local_10c = param_4;
  if (param_3 == 1) {
    uVar2 = 0x1c;
    if (DAT_00827620 != 0) {
      uVar2 = 5;
    }
    iVar3 = SHGetFolderPathA(0,uVar2,0,0,&DAT_02975d70);
    pcVar6 = (char *)((int)&uStack_105 + 1);
    pcVar4 = (char *)((iVar3 < 0) - 1 & 0x2975d70);
    do {
      cVar1 = *pcVar4;
      *pcVar6 = cVar1;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    puVar9 = (undefined2 *)(local_108 + 3);
    do {
      pcVar6 = (char *)((int)puVar9 + 1);
      puVar9 = (undefined2 *)((int)puVar9 + 1);
    } while (*pcVar6 != '\0');
    *puVar9 = 0x5c;
    pcVar6 = PTR_s_TTales_00827618;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    puVar10 = (undefined4 *)(local_108 + 3);
    do {
      pcVar4 = (char *)((int)puVar10 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    } while (*pcVar4 != '\0');
    puVar7 = (undefined4 *)PTR_s_TTales_00827618;
    for (uVar5 = (uint)((int)pcVar6 - (int)PTR_s_TTales_00827618) >> 2; uVar5 != 0;
        uVar5 = uVar5 - 1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar5 = (int)pcVar6 - (int)PTR_s_TTales_00827618 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    puVar9 = (undefined2 *)(local_108 + 3);
    do {
      pcVar6 = (char *)((int)puVar9 + 1);
      puVar9 = (undefined2 *)((int)puVar9 + 1);
    } while (*pcVar6 != '\0');
    *puVar9 = 0x5c;
    pcVar6 = PTR_s_GameTitle_0082761c;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    puVar10 = (undefined4 *)(local_108 + 3);
    do {
      pcVar4 = (char *)((int)puVar10 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    } while (*pcVar4 != '\0');
    puVar7 = (undefined4 *)PTR_s_GameTitle_0082761c;
    for (uVar5 = (uint)((int)pcVar6 - (int)PTR_s_GameTitle_0082761c) >> 2; uVar5 != 0;
        uVar5 = uVar5 - 1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    for (uVar5 = (int)pcVar6 - (int)PTR_s_GameTitle_0082761c & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    puVar9 = (undefined2 *)(local_108 + 3);
    do {
      pcVar6 = (char *)((int)puVar9 + 1);
      puVar9 = (undefined2 *)((int)puVar9 + 1);
    } while (*pcVar6 != '\0');
    *puVar9 = 0x5c;
    pcVar6 = param_2;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    pcVar4 = local_108 + 3;
    do {
      pcVar8 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar8 != '\0');
    pcVar8 = param_2;
    for (uVar5 = (uint)((int)pcVar6 - (int)param_2) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar5 = (int)pcVar6 - (int)param_2 & 3; param_1 = _local_108, uVar5 != 0; uVar5 = uVar5 - 1
        ) {
      *pcVar4 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar4 = pcVar4 + 1;
    }
  }
  else {
    iVar3 = 1 - (int)param_2;
    do {
      cVar1 = *param_2;
      param_2[(int)&uStack_105 + iVar3] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
  }
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  pcVar6 = local_108 + 3;
  do {
    pcVar4 = pcVar6 + 1;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar4 != '\0');
  pcVar4 = _local_108;
  for (uVar5 = (uint)((int)param_1 - (int)_local_108) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar5 = (int)param_1 - (int)_local_108 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar6 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  }
  _File = _fopen((char *)((int)&uStack_105 + 1),"rb");
  if (_File != (FILE *)0x0) {
    FUN_006e89b3(local_10c,param_5,1,_File);
    _fclose(_File);
    __security_check_cookie(local_4 ^ (uint)&local_10c);
    return;
  }
  __security_check_cookie(local_4 ^ (uint)&local_10c);
  return;
}

