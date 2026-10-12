/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x4a0900; label: FUN_004a0900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a0900(undefined4 param_1)

{
  char cVar1;
  short sVar2;
  int in_EAX;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte local_a;
  byte local_8 [4];
  int local_4;
  
  local_4 = 0;
  if ((((*(char *)(*(int *)(*(int *)(in_EAX + 0x54) + 0x24) + 0x116) == '\x03') ||
       (*(short *)(in_EAX + 0x1064) == DAT_007f1968)) ||
      (*(short *)(in_EAX + 0x1064) == DAT_007f1a08)) &&
     ((*(char *)(in_EAX + 0x7b5) == '\0' && (*(char *)(in_EAX + 0x7b8) == '\x03')))) {
LAB_004a09a6:
    *(byte *)(in_EAX + 0xe34) = *(byte *)(in_EAX + 0xe34) | 2;
  }
  else {
    if (((*(short *)(in_EAX + 0x1064) == DAT_007f1968) &&
        ((*(char *)(in_EAX + 0x7b5) == '\x18' || (*(char *)(in_EAX + 0x7b5) == '\f')))) &&
       (*(short *)(in_EAX + 0x7aa) == 0x1a)) {
      local_4 = 1;
      goto LAB_004a09a6;
    }
    if (((*(short *)(in_EAX + 0x1064) == DAT_007f187c) &&
        ((*(char *)(in_EAX + 0x7b5) == '\x18' || (*(char *)(in_EAX + 0x7b5) == '\f')))) &&
       ((*(short *)(in_EAX + 0x7aa) == 0x1a || (*(short *)(in_EAX + 0x7aa) == 0x1b))))
    goto LAB_004a09a6;
  }
  local_8[1] = *(byte *)(in_EAX + 0xe34);
  local_8[0] = local_8[1];
  local_a = local_8[1] & 2;
  sVar2 = *(short *)(in_EAX + 0x1064);
  bVar3 = *(byte *)(in_EAX + 0xe34) & 4;
  if (sVar2 != DAT_007f1968) {
    if (sVar2 == DAT_007f1880) {
      FUN_0049fa50(0,param_1);
      *(byte *)(in_EAX + 0xe34) = local_a | 1;
      FUN_0049fa50(1,param_1);
      return;
    }
    if (sVar2 != DAT_007f187c) {
      FUN_0049fa50(0,param_1);
      return;
    }
    if (*(char *)(in_EAX + 0x7b5) == '\x05') {
      if (bVar3 != 0) {
        if (*(char *)(in_EAX + 0x7b2) == '\x02') {
          local_8[0] = local_8[1] & 0xfb;
          local_8[1] = local_8[1] | 4;
        }
        else {
          local_8[0] = local_8[1] | 4;
          local_8[1] = local_8[1] & 0xfb;
        }
      }
    }
    else if ((*(char *)(in_EAX + 0x7b5) == '\0') && (*(char *)(in_EAX + 0x7b8) == '\x04')) {
      local_8[0] = local_8[1] | 2;
      local_8[1] = local_8[1] | 2;
    }
    iVar4 = 0;
    do {
      *(byte *)(in_EAX + 0xe34) = local_8[iVar4];
      FUN_0049fa50(iVar4,param_1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    return;
  }
  iVar4 = -1;
  iVar5 = -1;
  if (bVar3 == 0) goto switchD_004a0a17_default;
  cVar1 = *(char *)(in_EAX + 0x7b5);
  if (cVar1 == '\r') {
switchD_004a0a17_caseD_31:
    iVar5 = 0;
    iVar4 = 2;
    iVar6 = 0;
    goto LAB_004a0a48;
  }
  if (cVar1 == '\x10') {
switchD_004a0a17_caseD_36:
    iVar4 = 3;
    goto switchD_004a0a17_caseD_38;
  }
  if (cVar1 != '\x05') goto switchD_004a0a17_default;
  switch(*(undefined2 *)(in_EAX + 0x7aa)) {
  case 0x2e:
    iVar5 = 0;
    iVar6 = 0;
    break;
  case 0x2f:
  case 0x30:
    iVar5 = 3;
    iVar6 = 0;
    break;
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
    goto switchD_004a0a17_caseD_31;
  case 0x35:
    iVar5 = 0;
    iVar4 = 1;
    iVar6 = 0;
    break;
  case 0x36:
  case 0x37:
    goto switchD_004a0a17_caseD_36;
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
switchD_004a0a17_caseD_38:
    iVar5 = 2;
  default:
switchD_004a0a17_default:
    iVar6 = 0;
  }
LAB_004a0a48:
  do {
    if ((local_4 != 0) && (iVar6 == 2)) {
      local_a = 0;
    }
    *(byte *)(in_EAX + 0xe34) = local_a | 1;
    if ((bVar3 != 0) && ((iVar6 == iVar5 || (iVar6 == iVar4)))) {
      *(byte *)(in_EAX + 0xe34) = local_a | 1 | bVar3;
    }
    if (*(char *)(in_EAX + 0x7b5) == '\x10') {
      if ((iVar6 == 2) || (iVar6 == 3)) {
        *(byte *)(in_EAX + 0xe34) = *(byte *)(in_EAX + 0xe34) | 2;
      }
      else {
        *(byte *)(in_EAX + 0xe34) = *(byte *)(in_EAX + 0xe34) & 0xfd;
      }
    }
    FUN_0049fa50(iVar6,param_1);
    iVar6 = iVar6 + 1;
  } while (iVar6 < 4);
  return;
}

