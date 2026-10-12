/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x421430; label: FUN_00421430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00421430(void)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  code *pcVar4;
  int in_ECX;
  int iVar5;
  char *pcVar6;
  int local_10;
  int local_c;
  int *local_4;
  
  iVar5 = 0;
  do {
    iVar3 = FUN_006d6920(1,*(undefined4 *)(in_ECX + 0x3c + *(int *)(in_ECX + 0x38) * 4),iVar5);
    if (iVar3 != 0) break;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  local_c = 0;
  if (0 < *(int *)(in_ECX + 0x1c)) {
    piVar1 = (int *)(in_ECX + 0xa4);
    do {
      local_4 = piVar1;
      pcVar6 = (char *)local_4[2];
      local_10 = 0;
      if (0 < *local_4) {
        do {
          pcVar6[3] = pcVar6[3] & 0x1f;
          if (*pcVar6 == '\x04') {
            if ((*(int *)(in_ECX + 0x3c + *(int *)(in_ECX + 0x38) * 4) < 0) &&
               ((pcVar6[2] == '(' || (pcVar6[2] == '+')))) {
              pcVar6[3] = pcVar6[3] | 0x80;
            }
            if ((pcVar6[2] == '(') && (iVar3 == 0)) {
              pcVar6[3] = pcVar6[3] | 0x80;
            }
            if ((pcVar6[2] == '+') &&
               (iVar5 = FUN_006d67a0(*(undefined4 *)(in_ECX + 0x3c + *(int *)(in_ECX + 0x38) * 4)),
               iVar5 == 0)) {
              pcVar6[3] = pcVar6[3] | 0x80;
            }
          }
          if (((*(char *)(in_ECX + 8) != '\0') && (*pcVar6 == '\x04')) && (pcVar6[2] != '\0')) {
            pcVar6[3] = pcVar6[3] | 0xe0;
          }
          if (*pcVar6 == '\x02') {
            iVar5 = FUN_006d67e0(*(undefined4 *)(in_ECX + 0x3c));
            if (iVar5 == 0) {
              pcVar6[3] = pcVar6[3] | 0x20;
            }
            iVar5 = FUN_006d67e0(*(undefined4 *)(in_ECX + 0x40));
            if (iVar5 == 0) {
              pcVar6[3] = pcVar6[3] | 0x40;
            }
          }
          if (*pcVar6 == '\0') {
            pcVar6[3] = pcVar6[3] ^ ((*(int *)(in_ECX + 0x3c) < 0) << 5 ^ pcVar6[3]) & 0x20U;
            bVar2 = ((*(int *)(in_ECX + 0x40) < 0) << 6 ^ pcVar6[3]) & 0x40U ^ pcVar6[3];
            pcVar6[3] = bVar2;
            pcVar6[3] = (*(int *)(in_ECX + 0x3c + *(int *)(in_ECX + 0x38) * 4) < 0) << 7 |
                        bVar2 & 0x7f;
            if ((bVar2 & 7) == 1) {
              pcVar6[2] = '\a';
            }
            if ((pcVar6[3] & 7U) == 2) {
              pcVar6[2] = '\b';
            }
            if ((pcVar6[3] & 7U) == 3) {
              pcVar6[2] = '\t';
            }
            if ((pcVar6[3] & 7U) == 4) {
              pcVar6[2] = '\n';
            }
            if (((pcVar6[3] & 7U) == 1) || ((pcVar6[3] & 7U) == 2)) {
              iVar5 = FUN_006d67c0(*(undefined4 *)(in_ECX + 0x3c));
              if (iVar5 != 0) {
                pcVar6[3] = pcVar6[3] | 0x20;
              }
              iVar5 = FUN_006d67c0(*(undefined4 *)(in_ECX + 0x40));
              if (iVar5 != 0) {
                pcVar6[3] = pcVar6[3] | 0x40;
              }
            }
            iVar5 = FUN_006d67c0(*(undefined4 *)(in_ECX + 0x3c + *(int *)(in_ECX + 0x38) * 4));
            if (iVar5 != 0) {
              if ((pcVar6[3] & 7U) == 3) {
                pcVar6[2] = ')';
              }
              if ((pcVar6[3] & 7U) == 4) {
                pcVar6[2] = '*';
              }
            }
            pcVar4 = (code *)FUN_006d6da0();
            if (pcVar4 != (code *)0x0) {
              iVar5 = (*pcVar4)(*(undefined4 *)(in_ECX + 0x3c),pcVar6[1]);
              if (iVar5 == 0) {
                pcVar6[3] = pcVar6[3] | 0x20;
              }
              iVar5 = (*pcVar4)(*(undefined4 *)(in_ECX + 0x40),pcVar6[1]);
              if (iVar5 == 0) {
                pcVar6[3] = pcVar6[3] | 0x40;
              }
            }
            if ((pcVar6[3] & 8U) != 0) {
              iVar5 = FUN_006d67a0(*(undefined4 *)(in_ECX + 0x3c));
              if (iVar5 != 0) {
                pcVar6[3] = pcVar6[3] | 0x20;
              }
              iVar5 = FUN_006d67a0(*(undefined4 *)(in_ECX + 0x40));
              if (iVar5 != 0) {
                pcVar6[3] = pcVar6[3] | 0x40;
              }
            }
          }
          if (*pcVar6 == '\x02') {
            iVar5 = *(int *)(in_ECX + 0x38);
            if (iVar5 == 0) {
              if ((pcVar6[3] & 0x20U) != 0) {
                iVar5 = 1;
              }
            }
            else if ((pcVar6[3] & 0x40U) != 0) {
              iVar5 = iVar5 + -1;
            }
            pcVar6[2] = '\"';
            iVar5 = FUN_006d67a0(*(undefined4 *)(in_ECX + 0x3c + iVar5 * 4));
            if (iVar5 != 0) {
              pcVar6[2] = '#';
            }
          }
          bVar2 = pcVar6[3];
          if ((((bVar2 & 0x20) != 0) && (*(int *)(in_ECX + 0x38) == 0)) ||
             (((bVar2 & 0x40) != 0 && (*(int *)(in_ECX + 0x38) != 0)))) {
            pcVar6[3] = bVar2 | 0x80;
          }
          local_10 = local_10 + 1;
          pcVar6 = pcVar6 + 8;
        } while (local_10 < *local_4);
      }
      local_c = local_c + 1;
      piVar1 = local_4 + 3;
    } while (local_c < *(int *)(in_ECX + 0x1c));
  }
  FUN_00420690(local_4);
  return;
}

