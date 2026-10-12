/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f20f0; label: FUN_004f20f0
 */

undefined4 FUN_004f20f0(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_2 != (char *)0x0) {
    while( true ) {
      cVar1 = *param_1;
      cVar2 = *param_2;
      if (cVar2 < cVar1) break;
      if (cVar1 < cVar2) {
        return 0xffffffff;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      if ((cVar1 == '\0') || (cVar2 == '\0')) {
        return 0;
      }
    }
  }
  return 1;
}

