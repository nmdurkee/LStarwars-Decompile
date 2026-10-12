/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x669dd0; label: FUN_00669dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00669dd0(void)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  char local_844;
  undefined1 local_843 [63];
  char local_804 [256];
  char local_704 [256];
  char local_604 [256];
  char local_504 [256];
  char local_404 [256];
  char local_304 [256];
  char local_204 [256];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_844;
  bVar2 = true;
  iVar6 = 1;
  local_844 = '\0';
  _memset(local_843,0,0x3f);
  if (DAT_02962818 != '\0') {
    FUN_004f6900(&local_844);
    FUN_004f6930(&DAT_02962818);
  }
  if (DAT_02962218 == '\0') {
    _sprintf(local_604,".");
  }
  else {
    iVar4 = 0;
    do {
      cVar1 = (&DAT_02962218)[iVar4];
      local_604[iVar4] = cVar1;
      iVar4 = iVar4 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962318 == '\0') {
    _sprintf(local_204,"particle");
  }
  else {
    iVar4 = 0;
    do {
      cVar1 = (&DAT_02962318)[iVar4];
      local_204[iVar4] = cVar1;
      iVar4 = iVar4 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962418 == '\0') {
    _sprintf(local_504,"ptl");
  }
  else {
    iVar4 = 0;
    do {
      cVar1 = (&DAT_02962418)[iVar4];
      local_504[iVar4] = cVar1;
      iVar4 = iVar4 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962518 == '\0') {
    _sprintf(local_104,".");
  }
  else {
    iVar4 = 0;
    do {
      cVar1 = (&DAT_02962518)[iVar4];
      local_104[iVar4] = cVar1;
      iVar4 = iVar4 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962618 == '\0') {
    _sprintf(local_304,"particle");
  }
  else {
    iVar4 = 0;
    do {
      cVar1 = (&DAT_02962618)[iVar4];
      local_304[iVar4] = cVar1;
      iVar4 = iVar4 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962718 == '\0') {
    _sprintf(local_404,"ptl");
  }
  else {
    iVar4 = 0;
    do {
      cVar1 = (&DAT_02962718)[iVar4];
      local_404[iVar4] = cVar1;
      iVar4 = iVar4 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_0292118b == '\0') {
    iVar4 = DAT_02962a90;
    if (DAT_02962a90 == 0) {
      _sprintf(local_804,"%s\\%s.%s",local_604,local_204,local_504);
      pcVar7 = local_504;
      pcVar5 = local_204;
      pcVar3 = local_604;
LAB_0066a078:
      _sprintf(local_704,"%s\\%s.%s.bak",pcVar3,pcVar5,pcVar7);
    }
    else {
LAB_00669fba:
      FUN_004f1f10(local_804,iVar4);
      FUN_004f1f10(local_704,local_804);
      FUN_004f1e80(local_704,&DAT_0076e074);
    }
  }
  else {
    if (DAT_0292118b == '\x01') {
      iVar4 = DAT_02962a94;
      if (DAT_02962a94 == 0) {
        _sprintf(local_804,"%s\\%s.%s",local_104,local_304,local_404);
        pcVar7 = local_404;
        pcVar5 = local_304;
        pcVar3 = local_104;
        goto LAB_0066a078;
      }
      goto LAB_00669fba;
    }
    if (DAT_0292118b == '\x05') {
      iVar4 = DAT_02962aa4;
      if (DAT_02962aa4 != 0) goto LAB_00669fba;
      _sprintf(local_804,"%s\\char.%s",local_604,local_504);
      _sprintf(local_704,"%s\\char.%s.bak",local_604,local_504);
    }
    else {
      bVar2 = false;
    }
  }
  if ((DAT_02962a28 == 0) && (DAT_02962950 == 0)) {
    if (bVar2) {
      iVar6 = FUN_00621a60(local_804,local_704);
      goto LAB_0066a118;
    }
  }
  else {
LAB_0066a118:
    if ((bVar2) && (iVar4 = FUN_006691f0(local_804,DAT_0292118b), iVar4 != 0)) {
      uVar8 = 1;
      if (iVar6 == 0) {
        pcVar7 = "Saved OK - Backup Failed";
      }
      else {
        pcVar7 = "Saved OK";
      }
      goto LAB_0066a150;
    }
  }
  uVar8 = 0;
  pcVar7 = "File Save Error";
LAB_0066a150:
  FUN_00663aa0(pcVar7,uVar8);
  if (local_844 != '\0') {
    FUN_004f6930(&local_844);
  }
  __security_check_cookie(local_4 ^ (uint)&local_844);
  return;
}

