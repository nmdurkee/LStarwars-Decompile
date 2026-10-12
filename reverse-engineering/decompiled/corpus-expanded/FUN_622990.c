/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x622990; label: FUN_00622990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00622990(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  char *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  FUN_004f1f10(local_104,param_1);
  FUN_004f8de0(local_104);
  iVar6 = 0;
  if (0 < DAT_029130a4) {
    puVar7 = &DAT_029120b8;
    do {
      iVar2 = FUN_004f20a0(local_104,puVar7);
      if (iVar2 != 0) {
        __security_check_cookie(local_4 ^ (uint)local_104);
        return;
      }
      iVar6 = iVar6 + 1;
      puVar7 = puVar7 + 0xc;
    } while (iVar6 < DAT_029130a4);
  }
  iVar6 = 0;
  if (DAT_029130a0 < 1) {
LAB_00622a95:
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  }
LAB_00622a03:
  pcVar3 = local_104;
LAB_00622a07:
  pcVar5 = (char *)0x0;
  iVar2 = 0;
  do {
    iVar1 = iVar2 + iVar6 * 8;
    if ((&DAT_02912b48)[iVar1 * 0xc] == '\0') {
      cVar4 = *pcVar3;
      iVar2 = 0;
      if (cVar4 == '\0') goto LAB_00622aaf;
      goto LAB_00622a67;
    }
    pcVar3 = (char *)FUN_004f20a0(pcVar3,&DAT_02912b48 + iVar1 * 0xc);
    if (pcVar3 == (char *)0x0) break;
    if (iVar2 == 0) {
      pcVar5 = pcVar3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  goto LAB_00622a82;
  while (cVar4 = *pcVar3, cVar4 != '\0') {
LAB_00622a67:
    pcVar3 = pcVar3 + 1;
    if ((cVar4 == '.') && (iVar2 = iVar2 + 1, 1 < iVar2)) goto LAB_00622a82;
  }
  if (iVar2 < 2) {
LAB_00622aaf:
    __security_check_cookie(local_4 ^ (uint)local_104);
    return;
  }
LAB_00622a82:
  pcVar3 = pcVar5;
  if (pcVar5 == (char *)0x0) goto code_r0x00622a86;
  goto LAB_00622a07;
code_r0x00622a86:
  iVar6 = iVar6 + 1;
  if (DAT_029130a0 <= iVar6) goto LAB_00622a95;
  goto LAB_00622a03;
}

