/* Ghidra pseudocode, not original source.
 * ev_36c567c8b03fa9be6305a90618e5976b2395159d59c428aaf9f1abc99d465ca0
 * Entry: 0x65ae30; label: FUN_0065ae30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065ae30(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
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
    _sprintf(local_404,"anims");
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
    _sprintf(local_204,"anm");
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
  iVar2 = FUN_00659af0(local_104);
  if (iVar2 == 0) {
    pcVar3 = "File Save Error";
  }
  else {
    pcVar3 = "Saved OK";
  }
  FUN_00628d80(param_1,pcVar3,iVar2 != 0);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

