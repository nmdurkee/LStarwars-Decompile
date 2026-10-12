/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x6906c0; label: FUN_006906c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006906c0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  char local_404 [256];
  char local_304 [256];
  char local_204 [256];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  if (DAT_02962518 == '\0') {
    _sprintf(local_304,".");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962518)[iVar2];
      local_304[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962618 == '\0') {
    _sprintf(local_404,"bridge");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962618)[iVar2];
      local_404[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962718 == '\0') {
    _sprintf(local_204,"bri");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962718)[iVar2];
      local_204[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  _sprintf(local_104,"%s\\%s.%s",local_304,local_404,local_204);
  FUN_0065d470();
  iVar2 = thunk_FUN_004fa610(local_104);
  if (iVar2 != 0) {
    FUN_006893e0(local_104,DAT_02962114);
  }
  iVar2 = 0;
  do {
    if ((&DAT_029211c8)[iVar2] != 0) {
      FUN_00689670(iVar2);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  FUN_0065d540(0x3f800000);
  FUN_00628d80(param_1,"Loaded OK",1);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

