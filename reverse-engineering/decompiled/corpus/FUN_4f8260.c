/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f8260; label: FUN_004f8260
 */

void FUN_004f8260(int param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_44;
  FUN_004f7fb0(param_1);
  pcVar4 = local_44;
  if (*(char *)(param_1 + 0x578) == '\0') {
    pcVar1 = *(char **)(param_1 + 0x510);
    if ((pcVar1 != (char *)0x0) && (cVar2 = *pcVar1, cVar2 != '\0')) {
      do {
        *pcVar4 = cVar2;
        cVar2 = pcVar4[(int)(pcVar1 + (1 - (int)local_44))];
        pcVar4 = pcVar4 + 1;
      } while (cVar2 != '\0');
    }
    *pcVar4 = '\0';
  }
  else {
    FUN_004f2dc0(pcVar4,*(undefined4 *)(param_1 + 0x510));
  }
  if ((param_2 != (int *)0x0) && (local_44[0] != '\0')) {
    iVar3 = FUN_004f29a0(local_44);
    *param_2 = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x520) = DAT_0088ab4c;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_44);
  return;
}

