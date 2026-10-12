/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dd8c0; label: FUN_006dd8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dd8c0(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  DWORD DVar5;
  char *pcVar6;
  uint uVar7;
  LPCSTR pCVar8;
  CHAR *pCVar9;
  LPCSTR lpFileName;
  
  uVar2 = 0x1c;
  if (DAT_00827620 != 0) {
    uVar2 = 5;
  }
  lpFileName = (LPCSTR)0x0;
  iVar3 = SHGetFolderPathA(0,uVar2,0,0,&DAT_02975d70);
  pcVar6 = (char *)((iVar3 < 0) - 1 & 0x2975d70);
  pCVar8 = lpFileName;
  do {
    cVar1 = *pcVar6;
    *pCVar8 = cVar1;
    pcVar6 = pcVar6 + 1;
    pCVar8 = pCVar8 + 1;
  } while (cVar1 != '\0');
  pCVar8 = lpFileName + -1;
  do {
    pcVar6 = pCVar8 + 1;
    pCVar8 = pCVar8 + 1;
  } while (*pcVar6 != '\0');
  pCVar8[0] = '\\';
  pCVar8[1] = '\0';
  pcVar6 = PTR_s_TTales_00827618;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar4 = (int)pcVar6 - (int)PTR_s_TTales_00827618;
  pCVar8 = lpFileName + -1;
  do {
    pcVar6 = pCVar8 + 1;
    pCVar8 = pCVar8 + 1;
  } while (*pcVar6 != '\0');
  pCVar9 = PTR_s_TTales_00827618;
  for (uVar7 = uVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pCVar8 = *(undefined4 *)pCVar9;
    pCVar9 = pCVar9 + 4;
    pCVar8 = pCVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pCVar8 = *pCVar9;
    pCVar9 = pCVar9 + 1;
    pCVar8 = pCVar8 + 1;
  }
  pCVar8 = lpFileName + -1;
  do {
    pcVar6 = pCVar8 + 1;
    pCVar8 = pCVar8 + 1;
  } while (*pcVar6 != '\0');
  pCVar8[0] = '\\';
  pCVar8[1] = '\0';
  pcVar6 = PTR_s_GameTitle_0082761c;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar4 = (int)pcVar6 - (int)PTR_s_GameTitle_0082761c;
  pCVar8 = lpFileName + -1;
  do {
    pcVar6 = pCVar8 + 1;
    pCVar8 = pCVar8 + 1;
  } while (*pcVar6 != '\0');
  pCVar9 = PTR_s_GameTitle_0082761c;
  for (uVar7 = uVar4 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pCVar8 = *(undefined4 *)pCVar9;
    pCVar9 = pCVar9 + 4;
    pCVar8 = pCVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pCVar8 = *pCVar9;
    pCVar9 = pCVar9 + 1;
    pCVar8 = pCVar8 + 1;
  }
  DVar5 = GetFileAttributesA(lpFileName);
  pCVar8 = lpFileName + -1;
  do {
    pcVar6 = pCVar8 + 1;
    pCVar8 = pCVar8 + 1;
  } while (*pcVar6 != '\0');
  pCVar8[0] = '\\';
  pCVar8[1] = '\0';
  if (DVar5 == 0xffffffff) {
    SHCreateDirectoryExA((HWND)0x0,lpFileName,(SECURITY_ATTRIBUTES *)0x0);
  }
  return;
}

