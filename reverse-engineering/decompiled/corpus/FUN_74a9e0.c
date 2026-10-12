/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x74a9e0; label: FUN_0074a9e0
 */

undefined1 FUN_0074a9e0(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined4 *in_ECX;
  char *pcVar3;
  
  pcVar3 = (char *)*in_ECX;
  cVar1 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return 1;
    }
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    param_1 = param_1 + 1;
    if (cVar1 != cVar2) break;
    cVar1 = *param_1;
  }
  return 0;
}

