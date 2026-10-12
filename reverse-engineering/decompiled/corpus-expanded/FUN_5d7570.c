/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d7570; label: FUN_005d7570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined2 * FUN_005d7570(void)

{
  int in_EAX;
  undefined2 *puVar1;
  int in_ECX;
  
  if ((in_EAX == 0) || (puVar1 = *(undefined2 **)(in_EAX + in_ECX * 4), puVar1 == (undefined2 *)0x0)
     ) {
    puVar1 = &DAT_007596f8;
  }
  return puVar1;
}

