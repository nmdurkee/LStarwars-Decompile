/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f81a0; label: FUN_004f81a0
 */

void FUN_004f81a0(int param_1,float *param_2)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  float10 fVar4;
  float local_48;
  char local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_48;
  FUN_004f7fb0(param_1);
  pcVar3 = local_44;
  if (*(char *)(param_1 + 0x578) == '\0') {
    pcVar1 = *(char **)(param_1 + 0x510);
    if ((pcVar1 != (char *)0x0) && (cVar2 = *pcVar1, cVar2 != '\0')) {
      do {
        *pcVar3 = cVar2;
        cVar2 = pcVar3[(int)(pcVar1 + (1 - (int)local_44))];
        pcVar3 = pcVar3 + 1;
      } while (cVar2 != '\0');
    }
    *pcVar3 = '\0';
  }
  else {
    FUN_004f2dc0(pcVar3,*(undefined4 *)(param_1 + 0x510));
  }
  if ((param_2 != (float *)0x0) && (local_44[0] != '\0')) {
    fVar4 = (float10)FUN_004f28e0(local_44);
    local_48 = (float)fVar4;
    *param_2 = local_48;
    if (local_48 == 0.0) {
      *(undefined4 *)(param_1 + 0x520) = DAT_0088ab4c;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_48);
  return;
}

