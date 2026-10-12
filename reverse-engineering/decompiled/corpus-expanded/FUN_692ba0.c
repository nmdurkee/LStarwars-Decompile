/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x692ba0; label: FUN_00692ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00692ba0(void)

{
  char cVar1;
  int iVar2;
  char local_744;
  undefined1 local_743 [63];
  char local_704 [256];
  char local_604 [256];
  char local_504 [256];
  char local_404 [256];
  char local_304 [256];
  char local_204 [256];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_744;
  local_744 = '\0';
  _memset(local_743,0,0x3f);
  iVar2 = 0;
  do {
    if ((&DAT_02924b10)[iVar2] != 0) {
      FUN_0068ea00(iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  if (DAT_02962818 != '\0') {
    FUN_004f6900(&local_744);
    FUN_004f6930(&DAT_02962818);
  }
  if (DAT_02962218 == '\0') {
    _sprintf(local_604,".");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962218)[iVar2];
      local_604[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962318 == '\0') {
    _sprintf(local_204,"particle");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962318)[iVar2];
      local_204[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962418 == '\0') {
    _sprintf(local_504,"ptl");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962418)[iVar2];
      local_504[iVar2] = cVar1;
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
    _sprintf(local_304,"particle");
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
    _sprintf(local_404,"ptl");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962718)[iVar2];
      local_404[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  _sprintf(local_704,"%s\\%s.%s",local_604,local_204,local_504);
  iVar2 = thunk_FUN_004fa610(local_704);
  if (iVar2 != 0) {
    FUN_0068df20(local_704,0,0);
  }
  _sprintf(local_704,"%s\\char.%s",local_604,local_504);
  iVar2 = thunk_FUN_004fa610(local_704);
  if (iVar2 != 0) {
    FUN_0068df20(local_704,5,0);
  }
  _sprintf(local_704,"%s\\%s.%s",local_104,local_304,local_404);
  iVar2 = thunk_FUN_004fa610(local_704);
  if (0 < iVar2) {
    FUN_0068df20(local_704,1,DAT_02962114);
  }
  FUN_0068e4f0();
  FUN_00663aa0("Loaded OK",1);
  if (local_744 != '\0') {
    FUN_004f6930(&local_744);
  }
  __security_check_cookie(local_4 ^ (uint)&local_744);
  return;
}

