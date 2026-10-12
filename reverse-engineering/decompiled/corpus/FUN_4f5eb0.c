/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f5eb0; label: FUN_004f5eb0
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

