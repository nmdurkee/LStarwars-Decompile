/* Ghidra pseudocode, not original source.
 * ev_e04dcb01310c2b6a71419ceaaf6429f586bcd28525a19be66005014cd18274f1
 * Entry: 0x74b1e0; label: FUN_0074b1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0074b1e0(int *param_1,int *param_2)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  if (*param_2 < param_1[1]) {
    iVar3 = 0;
    pcVar1 = (char *)(*param_1 + *param_2);
    for (pcVar2 = pcVar1;
        (pcVar2 < (char *)(*param_1 + param_1[1]) && (iVar3 = iVar3 + 1, *pcVar2 != '\n'));
        pcVar2 = pcVar2 + 1) {
    }
    FUN_00748530(pcVar1,iVar3);
    *param_2 = *param_2 + iVar3;
    return 1;
  }
  return 0;
}

