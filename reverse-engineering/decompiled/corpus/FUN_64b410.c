/* Ghidra analysis pseudocode, not original source.
 * ev_b688fd0177351e281ce3a654852fc29d1d3855db670688278c9fb06d06ddbb68
 * Entry: 0x64b410; label: FUN_0064b410
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064b410(int param_1,float param_2)

{
  char *pcVar1;
  char cVar2;
  float fVar3;
  short *psVar4;
  char *pcVar5;
  int *piVar6;
  int iVar7;
  int extraout_EDX;
  int iVar8;
  char *pcVar9;
  char *local_20;
  char *local_1c;
  int local_18;
  char local_14 [12];
  undefined1 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_20;
  if ((param_1 < 1) || (0x80 < param_1)) {
    __security_check_cookie(local_4 ^ (uint)&local_20);
    return;
  }
  if ((&DAT_02913ae8)[param_1 * 0xbc] != -1) {
    if ((float)(&DAT_02913bc8)[param_1 * 0x5e] != 1.0) {
      param_1 = (&DAT_02913bcc)[param_1 * 0x5e];
      if ((&DAT_02913ae8)[param_1 * 0xbc] == -1) goto LAB_0064b489;
    }
    iVar8 = 0;
    if (param_2 == 1.0) {
      iVar8 = param_1;
    }
    if (param_2 < 0.01) {
      param_2 = 0.01;
    }
    if (iVar8 == 0) {
      fVar3 = param_2 / (float)(&DAT_02913bc8)[param_1 * 0x5e];
      if (fVar3 < 1.0 == (fVar3 == 1.0)) {
        local_20 = (char *)(fVar3 - 1.0);
      }
      else {
        local_20 = (char *)(1.0 - fVar3);
      }
      piVar6 = &DAT_02913bcc;
      iVar8 = 2;
      local_1c = local_20;
      local_18 = param_1;
      do {
        if (((short)piVar6[-0x39] != -1) && (*piVar6 == param_1)) {
          fVar3 = param_2 / (float)piVar6[-1];
          if (fVar3 < 1.0 == (fVar3 == 1.0)) {
            local_20 = (char *)(fVar3 - 1.0);
          }
          else {
            local_20 = (char *)(1.0 - fVar3);
          }
          if ((float)local_20 < (float)local_1c) {
            local_18 = iVar8 + -2;
            local_1c = local_20;
          }
        }
        if (((short)piVar6[0x25] != -1) && (piVar6[0x5e] == param_1)) {
          fVar3 = param_2 / (float)piVar6[0x5d];
          if (fVar3 < 1.0 == (fVar3 == 1.0)) {
            local_20 = (char *)(fVar3 - 1.0);
          }
          else {
            local_20 = (char *)(1.0 - fVar3);
          }
          if ((float)local_20 < (float)local_1c) {
            local_18 = iVar8 + -1;
            local_1c = local_20;
          }
        }
        if (((short)piVar6[0x83] != -1) && (piVar6[0xbc] == param_1)) {
          fVar3 = param_2 / (float)piVar6[0xbb];
          if (fVar3 < 1.0 == (fVar3 == 1.0)) {
            local_20 = (char *)(fVar3 - 1.0);
          }
          else {
            local_20 = (char *)(1.0 - fVar3);
          }
          if ((float)local_20 < (float)local_1c) {
            local_1c = local_20;
            local_18 = iVar8;
          }
        }
        if (((short)piVar6[0xe1] != -1) && (piVar6[0x11a] == param_1)) {
          fVar3 = param_2 / (float)piVar6[0x119];
          if (fVar3 < 1.0 == (fVar3 == 1.0)) {
            local_20 = (char *)(fVar3 - 1.0);
          }
          else {
            local_20 = (char *)(1.0 - fVar3);
          }
          if ((float)local_20 < (float)local_1c) {
            local_18 = iVar8 + 1;
            local_1c = local_20;
          }
        }
        iVar7 = iVar8 + 2;
        piVar6 = piVar6 + 0x178;
        iVar8 = iVar8 + 4;
      } while (iVar7 < 0x80);
      if ((local_18 == 0) || (1.1 <= (float)local_1c)) {
        iVar8 = 0;
        psVar4 = &DAT_02913ae8;
        while (*psVar4 != -1) {
          psVar4 = psVar4 + 0xbc;
          iVar8 = iVar8 + 1;
          if (0x291f6e7 < (int)psVar4) {
            __security_check_cookie(local_4 ^ (uint)&local_20);
            return;
          }
        }
        pcVar1 = &DAT_02913a58 + param_1 * 0x178;
        local_1c = &DAT_02913a58 + iVar8 * 0x178;
        pcVar5 = pcVar1;
        pcVar9 = local_1c;
        for (iVar7 = 0x5e; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)pcVar9 = *(undefined4 *)pcVar5;
          pcVar5 = pcVar5 + 4;
          pcVar9 = pcVar9 + 4;
        }
        FUN_00645050(iVar8,param_2);
        *(undefined4 *)((int)&DAT_02913bc4 + extraout_EDX) = _DAT_02920a90;
        *(float *)((int)&DAT_02913bc8 + extraout_EDX) = param_2;
        *(int *)((int)&DAT_02913bcc + extraout_EDX) = param_1;
        pcVar5 = pcVar1;
        do {
          cVar2 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        if ((uint)((int)pcVar5 - (int)(&DAT_02913a59 + param_1 * 0x178)) < 0xd) {
          _sprintf(local_1c,"%s%03d",pcVar1,iVar8);
        }
        else {
          _sprintf(local_14,"%s",pcVar1);
          local_8 = 0;
          _sprintf(local_1c,"%s%03d",local_14,iVar8);
        }
        DAT_02920a94 = DAT_02920a94 + 1;
        if (iVar8 == 0) {
          __security_check_cookie(local_4 ^ (uint)&local_20);
          return;
        }
      }
    }
    __security_check_cookie(local_4 ^ (uint)&local_20);
    return;
  }
LAB_0064b489:
  __security_check_cookie(local_4 ^ (uint)&local_20);
  return;
}

