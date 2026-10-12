/* Ghidra analysis pseudocode, not original source.
 * ev_c6c5de14d13fb7351cb00798d8d33f42525c6eb06c0958f12186e2f5ad93dde9
 * Entry: 0x4f8c60; label: FUN_004f8c60
 */

void FUN_004f8c60(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_2;
  if (cVar1 == '\0') {
    *param_1 = *param_2;
    return;
  }
  do {
    if (((byte)(cVar1 + 0xbfU) < 0x1a) || ((byte)(cVar1 + 0x40U) < 0x20)) {
      cVar1 = cVar1 + ' ';
    }
    param_2 = param_2 + 1;
    *param_1 = cVar1;
    cVar1 = *param_2;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  *param_1 = '\0';
  return;
}

