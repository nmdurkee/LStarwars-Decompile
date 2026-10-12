/* Ghidra pseudocode, not original source.
 * ev_0c11dca3c01e2e078e91e20b90f08271c2558dc41f56def09ad2bffabccf1687
 * Entry: 0x60ce70; label: FUN_0060ce70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060ce70(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_0060ccb0(param_1,(int)pcVar2 - (int)(param_1 + 1));
  return;
}

