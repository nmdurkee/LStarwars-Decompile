/* Ghidra pseudocode, not original source.
 * ev_a2a60ac3c7fd5e2c8ec7dea46f9f8f7cd19ec865371f09d136a7de11792ab0da
 * Entry: 0x6c3120; label: FUN_006c3120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c3120(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  puVar1 = (undefined4 *)*in_ECX;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if ((puVar1[3] == param_2) && (puVar1[4] == param_3)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}

