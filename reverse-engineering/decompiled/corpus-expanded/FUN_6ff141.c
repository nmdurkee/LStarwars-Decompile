/* Ghidra pseudocode, not original source.
 * ev_8ae20aee9003ac5b707eda996059b97c5ee653d1eec48e1211714341787544ca
 * Entry: 0x6ff141; label: FUN_006ff141
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006ff141(short *param_1)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = param_1;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  return ((int)psVar2 - (int)param_1 >> 1) + -1;
}

