/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afd50; label: FUN_005afd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005afd50(int *param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(*param_1 + 0x23);
  if ((((bVar1 & 2) != 0) && ((bVar1 & 1) != 0)) && ((bVar1 & 4) != 0)) {
    return 1;
  }
  return 0;
}

