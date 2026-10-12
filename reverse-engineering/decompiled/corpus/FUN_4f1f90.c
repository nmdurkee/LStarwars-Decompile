/* Ghidra analysis pseudocode, not original source.
 * ev_116b86ff2e9f158600429d02afe1772ae33b5a9670778d11324883284a10b71b
 * Entry: 0x4f1f90; label: FUN_004f1f90
 */

char * FUN_004f1f90(char *param_1,char param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return (char *)0x0;
    }
    if (cVar1 == param_2) break;
    cVar1 = param_1[1];
    param_1 = param_1 + 1;
  }
  return param_1;
}

