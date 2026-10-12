/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x6626b0; label: FUN_006626b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006626b0(undefined4 param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if ((DAT_00810ad8 != -1) && (*(int *)(DAT_0296209c + DAT_00810ad8 * 4) != 0)) {
    pcVar3 = *(char **)(DAT_0296209c + DAT_00810ad8 * 4);
    pcVar2 = (char *)(param_2 + 0x4c);
    do {
      cVar1 = *pcVar2;
      *pcVar3 = cVar1;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
  }
  return;
}

