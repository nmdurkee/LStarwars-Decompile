/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d2690; label: FUN_005d2690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d2690(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  FUN_004f7fb0(param_1);
  iVar2 = DAT_00971580;
  *(undefined1 *)(*(int *)(param_1 + 0x510) + 0x20) = 0;
  pcVar3 = *(char **)(param_1 + 0x510);
  pcVar4 = (char *)(iVar2 + 8);
  do {
    cVar1 = *pcVar3;
    *pcVar4 = cVar1;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  return;
}

