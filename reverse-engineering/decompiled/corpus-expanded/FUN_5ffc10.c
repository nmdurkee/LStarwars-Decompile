/* Ghidra pseudocode, not original source.
 * ev_84daf39e48317c5610d39db166d0a8d3fb26fedafe51c8456603b097e41224df
 * Entry: 0x5ffc10; label: FUN_005ffc10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ffc10(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0280d3cc;
  do {
    FUN_006e5b70(puVar1);
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined4 *)&DAT_0280d3dc);
  return;
}

