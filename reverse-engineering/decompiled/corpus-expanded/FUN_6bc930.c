/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bc930; label: FUN_006bc930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bc930(undefined4 param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(param_2 + 0xc);
  pcVar2 = (char *)(param_2 + 0x4c);
  do {
    cVar1 = *pcVar2;
    *pcVar3 = cVar1;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return;
}

