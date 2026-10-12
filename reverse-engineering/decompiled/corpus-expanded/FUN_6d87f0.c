/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d87f0; label: FUN_006d87f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d87f0(int param_1,int param_2,char *param_3,int param_4,int param_5,int param_6,
                 int param_7,char *param_8)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  bool bVar9;
  undefined4 uVar10;
  int local_2c;
  int local_28;
  uint local_24;
  int local_20;
  char *local_1c;
  undefined1 uStack_18;
  char local_14 [16];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2c;
  local_28 = 0;
  local_20 = 0;
  if (0xff < param_2) {
    if (DAT_029755d8 != (code *)0x0) {
      (*DAT_029755d8)(param_2,param_3);
      __security_check_cookie(local_4 ^ (uint)&local_2c);
      return;
    }
    FUN_004f1f10(param_3,&DAT_007759c8);
    __security_check_cookie(local_4 ^ (uint)&local_2c);
    return;
  }
  local_2c = DAT_0297516c;
  if (param_7 != 0) {
    local_2c = DAT_02975138;
  }
  local_24 = (uint)(param_1 < 4);
  if (((param_8 != (char *)0x0) && (cVar6 = *param_8, cVar6 != '\0')) && (param_8[1] != '\0')) {
    local_28 = (int)cVar6;
    local_20 = (int)param_8[1];
    if (local_28 != 0) {
      *param_3 = cVar6;
      param_3 = param_3 + 1;
    }
  }
  pcVar3 = DAT_029755d8;
  if (param_4 == 0) {
    iVar5 = param_1 * 0x5f + param_2;
    cVar6 = *(char *)(in_ECX + 0x4ea2 + iVar5 * 4);
    sVar2 = *(short *)(in_ECX + 0x4ea4 + iVar5 * 4);
  }
  else {
    iVar5 = param_5 * 0x20 + param_2;
    cVar6 = *(char *)(in_ECX + 0x6358 + iVar5 * 4);
    sVar2 = *(short *)(in_ECX + 0x635a + iVar5 * 4);
  }
  uVar8 = (uint)sVar2;
  if ((((*(char *)(in_ECX + 0x67e0) != '\0') && (*(int *)(in_ECX + 0x6354) == 0)) &&
      ((param_1 - 10U < 4 || (param_1 < 0)))) && ((&DAT_00824fa0)[param_2] != 0)) {
    cVar6 = '\a';
    uVar8 = (uint)(byte)(&DAT_00824fa0)[param_2];
  }
  cVar7 = '\x02';
  switch(cVar6) {
  case '\x01':
    *param_3 = '\0';
    if (local_24 != 0) {
      if (((DAT_029755d8 != (code *)0x0) && (param_6 != 0)) &&
         ((*DAT_029755d8)(uVar8,local_14), local_14[0] != '\0')) {
        if (local_28 != 0) {
          param_3 = param_3 + -1;
        }
        FUN_004f1f10(param_3,local_14);
        __security_check_cookie(local_4 ^ (uint)&local_2c);
        return;
      }
      if ((int)uVar8 < 0xb) {
        uVar10 = *(undefined4 *)(local_2c + (char)(&DAT_00825f10)[uVar8] * 4);
        break;
      }
    }
    if (3 < uVar8 - 0x80) {
      _sprintf(param_3,"%s %d",*(undefined4 *)(local_2c + 0x10),uVar8 + 1);
      goto LAB_006d8cbb;
    }
    uVar10 = *(undefined4 *)(local_2c + -0x200 + uVar8 * 4);
    break;
  case '\x02':
    goto switchD_006d8942_caseD_2;
  case '\x03':
    cVar7 = '\x01';
switchD_006d8942_caseD_2:
    if ((int)uVar8 < 0) goto LAB_006d8cbb;
    cVar1 = *(char *)(in_ECX + 0x67f0 + param_2 * 6);
    local_1c = (char *)(in_ECX + 0x67f0 + param_2 * 6);
    if ((cVar1 == '\x03') && (cVar6 == '\x02')) {
      cVar7 = '\x03';
    }
    if ((local_24 == 0) || (7 < (int)uVar8)) {
      if ((int)uVar8 < 6) {
        if (cVar1 == cVar7) {
          _sprintf(param_3,"%s %s",*(undefined4 *)(local_2c + 0x20 + uVar8 * 4),
                   *(undefined4 *)(local_2c + 0x18));
        }
        else {
          _sprintf(param_3,"%s %s",*(undefined4 *)(local_2c + 0x20 + uVar8 * 4),
                   *(undefined4 *)(local_2c + 0x14));
        }
      }
      else {
        iVar5 = FUN_004f5240();
        if (*local_1c == cVar7) {
          if (iVar5 == 0xb) {
            _sprintf(param_3,*(char **)(local_2c + 0x1c),*(undefined4 *)(local_2c + 0x18),uVar8);
          }
          else {
            _sprintf(param_3,*(char **)(local_2c + 0x1c),uVar8,*(undefined4 *)(local_2c + 0x18));
          }
        }
        else if (iVar5 == 0xb) {
          _sprintf(param_3,*(char **)(local_2c + 0x1c),*(undefined4 *)(local_2c + 0x14),uVar8);
        }
        else {
          _sprintf(param_3,*(char **)(local_2c + 0x1c),uVar8,*(undefined4 *)(local_2c + 0x14));
        }
      }
      goto LAB_006d8cbb;
    }
    iVar5 = uVar8 * 2;
    local_1c = (char *)0x0;
    uStack_18 = 0;
    if (cVar1 == cVar7) {
      iVar5 = iVar5 + 1;
    }
    bVar9 = DAT_029755d8 != (code *)0x0;
    *param_3 = '\0';
    if (bVar9) {
      if ((iVar5 == 0xd) || (iVar5 == 0xe)) {
        uVar10 = 0xb;
LAB_006d8a88:
        (*pcVar3)(uVar10,&local_1c);
      }
      else if ((iVar5 == 0xf) || (iVar5 == 0xc)) {
        uVar10 = 10;
        goto LAB_006d8a88;
      }
      if ((char)local_1c != '\0') {
        if (local_28 != 0) {
          param_3 = param_3 + -1;
        }
        FUN_004f1f10(param_3,&local_1c);
        __security_check_cookie(local_4 ^ (uint)&local_2c);
        return;
      }
    }
    uVar10 = *(undefined4 *)(local_2c + *(char *)(iVar5 + 0x825f00) * 4);
    break;
  case '\x04':
    if (2 < uVar8) {
      _sprintf(param_3,*(char **)(local_2c + 0xb8),uVar8 + 1);
      goto LAB_006d8cbb;
    }
    uVar10 = *(undefined4 *)(local_2c + 0xac + uVar8 * 4);
    break;
  case '\x05':
    if (2 < uVar8) goto LAB_006d8cbb;
    cVar6 = *(char *)(in_ECX + 0x67f0 + param_2 * 6);
    if ((cVar6 == '\x02') || (cVar6 == '\x03')) {
      uVar10 = *(undefined4 *)(local_2c + 0xa0 + uVar8 * 4);
    }
    else {
      uVar10 = *(undefined4 *)(local_2c + 0x94 + uVar8 * 4);
    }
    break;
  case '\x06':
    if (2 < uVar8) goto LAB_006d8cbb;
    cVar6 = *(char *)(in_ECX + 0x67f0 + param_2 * 6);
    if ((cVar6 == '\x02') || (cVar6 == '\x03')) {
      uVar10 = *(undefined4 *)(local_2c + 0x94 + uVar8 * 4);
    }
    else {
      uVar10 = *(undefined4 *)(local_2c + 0xa0 + uVar8 * 4);
    }
    break;
  case '\a':
  case '\b':
  case '\t':
    if ((int)uVar8 < 1) goto LAB_006d8cbb;
    uVar10 = *(undefined4 *)(PTR_PTR_00824f98 + uVar8 * 4);
    break;
  default:
    uVar10 = *(undefined4 *)(local_2c + 0xbc);
    break;
  case '\f':
    if (*(char *)(in_ECX + 0x67f0 + param_2 * 6) == '\x01') {
      uVar10 = *(undefined4 *)(local_2c + 0x94);
    }
    else {
      uVar10 = *(undefined4 *)(local_2c + 0xa0);
    }
    break;
  case '\r':
    if (*(char *)(in_ECX + 0x67f0 + param_2 * 6) == '\x01') {
      uVar10 = *(undefined4 *)(local_2c + 0x98);
    }
    else {
      uVar10 = *(undefined4 *)(local_2c + 0xa4);
    }
  }
  FUN_004f1f10(param_3,uVar10);
LAB_006d8cbb:
  iVar5 = local_20;
  if (local_20 != 0) {
    iVar4 = FUN_004f1ff0(param_3);
    param_3[iVar4] = (char)iVar5;
    param_3[iVar4 + 1] = '\0';
  }
  __security_check_cookie(local_4 ^ (uint)&local_2c);
  return;
}

