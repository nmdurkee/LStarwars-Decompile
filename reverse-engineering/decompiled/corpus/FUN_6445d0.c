/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x6445d0; label: FUN_006445d0
 */

void FUN_006445d0(int param_1)

{
  char cVar1;
  code *pcVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int local_20;
  char *local_1c;
  int local_18;
  char local_14 [12];
  undefined1 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_20;
  iVar6 = 0;
  local_18 = param_1;
  local_20 = 0;
  if ((DAT_02920a94 < 0x80) && (DAT_00810194 != -1)) {
    pcVar3 = &DAT_02913a58;
    do {
      if (*pcVar3 == '\0') {
        iVar7 = DAT_00810194 * 0x178;
        local_1c = &DAT_02913a58 + iVar6 * 0x178;
        pcVar3 = &DAT_02913a58 + iVar7;
        pcVar4 = pcVar3;
        pcVar8 = local_1c;
        for (iVar5 = 0x5e; iVar5 != 0; iVar5 = iVar5 + -1) {
          *(undefined4 *)pcVar8 = *(undefined4 *)pcVar4;
          pcVar4 = pcVar4 + 4;
          pcVar8 = pcVar8 + 4;
        }
        pcVar4 = pcVar3;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        if ((uint)((int)pcVar4 - (int)(&DAT_02913a59 + iVar7)) < 0xd) {
          _sprintf(local_1c,"%s%03d",pcVar3,iVar6);
        }
        else {
          _sprintf(local_14,"%s",pcVar3);
          local_8 = 0;
          _sprintf(local_1c,"%s%03d",local_14,iVar6);
        }
        DAT_02920a94 = DAT_02920a94 + 1;
        DAT_00810194 = iVar6;
        break;
      }
      pcVar3 = pcVar3 + 0x178;
      iVar6 = iVar6 + 1;
    } while ((int)pcVar3 < 0x291f658);
  }
  iVar6 = local_18;
  if (*(int *)(local_18 + 0x40) != 0) {
    local_20 = *(int *)(local_18 + 0x40);
    FUN_006279f0(local_18);
  }
  pcVar2 = *(code **)(iVar6 + 0x30);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(iVar6,local_20);
  }
  __security_check_cookie(local_4 ^ (uint)&local_20);
  return;
}

