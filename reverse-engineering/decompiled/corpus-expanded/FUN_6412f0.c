/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x6412f0; label: FUN_006412f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006412f0(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
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
    iVar3 = 0;
    do {
      cVar1 = (&DAT_02962518)[iVar3];
      local_304[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962618 == '\0') {
    _sprintf(local_404,"burnout");
  }
  else {
    iVar3 = 0;
    do {
      cVar1 = (&DAT_02962618)[iVar3];
      local_404[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962718 == '\0') {
    _sprintf(local_204,(char *)&PTR_DAT_0076ba28);
  }
  else {
    iVar3 = 0;
    do {
      cVar1 = (&DAT_02962718)[iVar3];
      local_204[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
    } while (cVar1 != '\0');
  }
  _sprintf(local_104,"%s\\%s.%s",local_304,local_404,local_204);
  iVar3 = DAT_0291396c;
  if (DAT_0291396c != 0) {
    puVar2 = (undefined4 *)(DAT_0291396c + 0xd0);
    iVar4 = 0x20;
    do {
      *puVar2 = 0;
      puVar2 = puVar2 + 9;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    *(undefined4 *)(iVar3 + 0x550) = 0;
    *(undefined4 *)(iVar3 + 0x554) = 0xffffffff;
  }
  iVar3 = thunk_FUN_004fa610(local_104);
  if (iVar3 != 0) {
    FUN_00641020(local_104,DAT_0291396c);
  }
  FUN_00628d80(param_1,"Loaded OK",1);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}

