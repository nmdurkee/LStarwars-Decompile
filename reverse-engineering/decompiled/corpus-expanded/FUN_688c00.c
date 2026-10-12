/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x688c00; label: FUN_00688c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00688c00(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char local_404 [256];
  char local_304 [256];
  char local_204 [256];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_404;
  iVar3 = -1;
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
  FUN_0065a510();
  iVar2 = thunk_FUN_004fa610(local_104);
  if (iVar2 != 0) {
    iVar3 = FUN_00687850(local_104,DAT_02962114);
  }
  FUN_0065a640();
  if (iVar3 < 0) {
    pcVar4 = "File Load Error";
  }
  else {
    pcVar4 = "Loaded OK";
  }
  FUN_00628d80(param_1,pcVar4,iVar3 >= 0);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

