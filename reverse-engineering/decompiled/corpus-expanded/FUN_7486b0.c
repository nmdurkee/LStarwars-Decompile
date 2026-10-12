/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x7486b0; label: FUN_007486b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007486b0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00748530(param_1,(int)pcVar2 - (int)(param_1 + 1));
  return;
}

