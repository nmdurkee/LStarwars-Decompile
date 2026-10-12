/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748600; label: FUN_00748600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00748600(int param_1,char *param_2)

{
  char *pcVar1;
  int *in_ECX;
  
  pcVar1 = (char *)(*in_ECX + param_1);
  for (; (param_1 < in_ECX[1] && (*param_2 != '\0')); param_2 = param_2 + 1) {
    if (*pcVar1 != *param_2) {
      return (uint)pcVar1 & 0xffffff00;
    }
    param_1 = param_1 + 1;
    pcVar1 = pcVar1 + 1;
  }
  return CONCAT31((int3)((uint)pcVar1 >> 8),1);
}

