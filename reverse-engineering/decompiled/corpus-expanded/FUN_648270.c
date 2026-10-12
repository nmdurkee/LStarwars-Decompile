/* Ghidra pseudocode, not original source.
 * ev_4cb705c119a92d6224ed1b3e942cece0f3f9eff485159b2837ae2ccadb058a2e
 * Entry: 0x648270; label: FUN_00648270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00648270(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  char local_804 [256];
  char local_704 [256];
  char local_604 [256];
  char local_504 [256];
  char local_404 [256];
  char local_304 [256];
  char local_204 [256];
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_804;
  iVar4 = 1;
  iVar5 = 1;
  if (DAT_02962218 == '\0') {
    _sprintf(local_704,".");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962218)[iVar2];
      local_704[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962318 == '\0') {
    _sprintf(local_204,"part");
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
    _sprintf(local_504,"part");
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962618)[iVar2];
      local_504[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  if (DAT_02962718 == '\0') {
    _sprintf(local_604,(char *)&PTR_DAT_0076cbb4);
  }
  else {
    iVar2 = 0;
    do {
      cVar1 = (&DAT_02962718)[iVar2];
      local_604[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
  }
  _sprintf(local_804,"%s\\%s.%s",local_704,local_204,local_404);
  _sprintf(local_104,"%s\\%s.%s.bak",local_704,local_204,local_404);
  if (DAT_02962950 == 0) {
    iVar4 = FUN_00621a60(local_804,local_104);
  }
  iVar2 = FUN_00647ca0(local_804,0);
  _sprintf(local_804,"%s\\%s.%s",local_304,local_504,local_604);
  _sprintf(local_104,"%s\\%s.%s.bak",local_304,local_504,local_604);
  if (DAT_02962950 == 0) {
    iVar5 = FUN_00621a60(local_804,local_104);
  }
  iVar3 = FUN_00647ca0(local_804,1);
  if (iVar2 == 0) {
    uVar7 = 0;
    if (iVar3 == 0) {
      pcVar6 = "Both Saves Failed";
    }
    else {
      pcVar6 = "General Save Failed";
    }
    goto LAB_00648572;
  }
  if (iVar4 == 0) {
LAB_00648534:
    if (iVar3 != 0) {
      uVar7 = 0;
      if (iVar4 == 0) {
        if (iVar5 == 0) {
          pcVar6 = "Saved OK - Both Backups Failed";
        }
        else {
          pcVar6 = "Saved OK - General Backup Failed";
        }
      }
      else {
        pcVar6 = "Saved OK - Level Backup Failed";
      }
      goto LAB_00648572;
    }
  }
  else if (iVar3 != 0) {
    if (iVar5 != 0) {
      uVar7 = 1;
      pcVar6 = "Saved OK";
      goto LAB_00648572;
    }
    goto LAB_00648534;
  }
  uVar7 = 0;
  pcVar6 = "Level Save Failed";
LAB_00648572:
  FUN_00644d00(pcVar6,uVar7);
  __security_check_cookie(local_4 ^ (uint)local_804);
  return;
}

