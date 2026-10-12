/* Ghidra analysis pseudocode, not original source.
 * ev_df5ebe5055aa55c8d4ffbc3d42601afd4ff508e5ed8fd93234c5a96c9c8b7e66
 * Entry: 0x4f6900; label: FUN_004f6900
 */

void FUN_004f6900(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = PTR_DAT_00800478 + 0xac;
  if (pcVar2 != (char *)0x0) {
    cVar1 = *pcVar2;
    while (cVar1 != '\0') {
      pcVar2 = pcVar2 + 1;
      *param_1 = cVar1;
      param_1 = param_1 + 1;
      cVar1 = *pcVar2;
    }
  }
  *param_1 = '\0';
  return;
}

