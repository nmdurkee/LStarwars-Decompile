/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f77d0; label: FUN_004f77d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f77d0(char *param_1)

{
  char cVar1;
  char cVar2;
  int in_EAX;
  char *in_ECX;
  
  cVar1 = *in_ECX;
  while( true ) {
    if (cVar1 == '\0') {
      return 1;
    }
    param_1 = param_1 + -1;
    if (in_EAX == 0) break;
    cVar2 = *param_1;
    if (((byte)(cVar2 + 0xbfU) < 0x1a) || ((byte)(cVar2 + 0x40U) < 0x20)) {
      cVar2 = cVar2 + ' ';
    }
    if (cVar1 != cVar2) {
      return 0;
    }
    cVar1 = in_ECX[1];
    in_ECX = in_ECX + 1;
    in_EAX = in_EAX + -1;
  }
  return 0;
}

