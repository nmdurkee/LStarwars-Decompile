/* Ghidra pseudocode, not original source.
 * ev_df1722bf86f416057db1e0e925a798d75462d70944199476382a8f5b3ee202ce
 * Entry: 0x621c80; label: FUN_00621c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00621c80(undefined1 *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 == &DAT_02900c88) {
    return 0;
  }
  pcVar2 = param_1 + -2;
  cVar1 = *pcVar2;
  while( true ) {
    if (cVar1 == '\0') {
      return iVar3 + 1;
    }
    if (pcVar2 == &DAT_02900c88) break;
    pcVar2 = pcVar2 + -1;
    iVar3 = iVar3 + 1;
    cVar1 = *pcVar2;
  }
  return iVar3 + 2;
}

