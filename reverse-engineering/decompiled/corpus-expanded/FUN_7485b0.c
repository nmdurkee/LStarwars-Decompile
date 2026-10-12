/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x7485b0; label: FUN_007485b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_007485b0(char *param_1,int param_2)

{
  int *in_ECX;
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)(*in_ECX + param_2);
  pcVar2 = param_1;
  while( true ) {
    if (in_ECX[1] <= param_2) {
      return (char *)0xffffffff;
    }
    if (*pcVar2 == '\0') break;
    if (*pcVar1 == *pcVar2) {
      pcVar2 = pcVar2 + 1;
    }
    else if (pcVar2 != param_1) {
      pcVar2 = param_1;
    }
    param_2 = param_2 + 1;
    pcVar1 = pcVar1 + 1;
  }
  return param_1 + (param_2 - (int)pcVar2);
}

