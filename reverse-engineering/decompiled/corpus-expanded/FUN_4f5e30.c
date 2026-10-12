/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5e30; label: FUN_004f5e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f5e30(char *param_1)

{
  int iVar1;
  char *pcVar2;
  char local_c [8];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_c;
  builtin_strncpy(local_c,"LZ2K",5);
  iVar1 = 0;
  do {
    pcVar2 = param_1;
    if (*pcVar2 != local_c[iVar1]) {
      __security_check_cookie(local_4 ^ (uint)local_c);
      return;
    }
    iVar1 = iVar1 + 1;
    param_1 = pcVar2 + 1;
  } while (iVar1 < 4);
  __security_check_cookie(local_4 ^ (uint)local_c,pcVar2[2]);
  return;
}

