/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5eb0; label: FUN_004f5eb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f5eb0(char *param_1)

{
  char cVar1;
  int iVar2;
  char local_c [8];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_c;
  builtin_strncpy(local_c,"LZ2K",5);
  iVar2 = 0;
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if (cVar1 != local_c[iVar2]) {
      __security_check_cookie(local_4 ^ (uint)local_c);
      return;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  __security_check_cookie(local_4 ^ (uint)local_c);
  return;
}

