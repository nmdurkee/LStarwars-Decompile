/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60d070; label: FUN_0060d070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060d070(char *param_1)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_0060ccb0(param_1,(int)pcVar2 - (int)(param_1 + 1));
  return;
}

