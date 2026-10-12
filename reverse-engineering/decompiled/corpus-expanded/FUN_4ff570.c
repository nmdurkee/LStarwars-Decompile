/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ff570; label: FUN_004ff570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ff570(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  HANDLE pvVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined4 *puVar8;
  char local_cc [200];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_cc;
  if (DAT_00921248 == 0x10) {
    __security_check_cookie(local_4 ^ (uint)local_cc);
    return;
  }
  iVar6 = 0;
  do {
    if ((&DAT_00921250)[iVar6] == 0) break;
    if ((&DAT_00921254)[iVar6] == 0) {
      iVar6 = iVar6 + 1;
      break;
    }
    if ((&DAT_00921258)[iVar6] == 0) {
      iVar6 = iVar6 + 2;
      break;
    }
    if ((&DAT_0092125c)[iVar6] == 0) {
      iVar6 = iVar6 + 3;
      break;
    }
    iVar6 = iVar6 + 4;
  } while (iVar6 < 0x10);
  if (iVar6 == 0x10) {
    __security_check_cookie(local_4 ^ (uint)local_cc);
    return;
  }
  iVar2 = -(int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)(local_cc + iVar2)] = cVar1;
    param_1 = param_1 + 1;
    pcVar3 = local_cc;
  } while (cVar1 != '\0');
  do {
    pcVar4 = pcVar3;
    pcVar3 = pcVar4 + 1;
  } while (*pcVar4 != '\0');
  if (pcVar4[-1] != '\\') {
    puVar7 = (undefined2 *)&stack0xffffff33;
    do {
      pcVar3 = (char *)((int)puVar7 + 1);
      puVar7 = (undefined2 *)((int)puVar7 + 1);
    } while (*pcVar3 != '\0');
    *puVar7 = 0x5c;
  }
  puVar8 = (undefined4 *)&stack0xffffff33;
  do {
    pcVar3 = (char *)((int)puVar8 + 1);
    puVar8 = (undefined4 *)((int)puVar8 + 1);
  } while (*pcVar3 != '\0');
  pcVar3 = local_cc;
  *puVar8 = 0x2a2e2a;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar4 = (char *)FUN_004eef40(pcVar3 + (4 - (int)(local_cc + 1)),
                                "d:\\projects\\legosagapc\\nu2api.saga\\nucore\\pc\\nufile_pc.c",
                                0x21a);
  puVar8 = &DAT_00921250 + iVar6;
  *puVar8 = pcVar4;
  pcVar3 = local_cc;
  do {
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  DAT_00921248 = DAT_00921248 + 1;
  pvVar5 = FindFirstFileA((LPCSTR)*puVar8,(LPWIN32_FIND_DATAA)(&DAT_0091f1b8 + iVar6 * 0x140));
  *(HANDLE *)(&DAT_0091ef40 + iVar6 * 4) = pvVar5;
  if (pvVar5 != (HANDLE)0xffffffff) {
    __security_check_cookie(local_4 ^ (uint)local_cc);
    return;
  }
  FUN_004ef280(*puVar8,"d:\\projects\\legosagapc\\nu2api.saga\\nucore\\pc\\nufile_pc.c",0x222);
  DAT_00921248 = DAT_00921248 + -1;
  (&DAT_0092124c)[iVar6] = 0;
  __security_check_cookie(local_4 ^ (uint)local_cc);
  return;
}

