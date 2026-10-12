/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748640; label: FUN_00748640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748640(int param_1,char *param_2)

{
  char *pcVar1;
  int *in_ECX;
  
  pcVar1 = (char *)(*in_ECX + param_1);
  if (param_1 < in_ECX[1]) {
    do {
      if (*param_2 == '\0') {
        return;
      }
      *pcVar1 = *param_2;
      param_1 = param_1 + 1;
      pcVar1 = pcVar1 + 1;
      param_2 = param_2 + 1;
    } while (param_1 < in_ECX[1]);
  }
  return;
}

