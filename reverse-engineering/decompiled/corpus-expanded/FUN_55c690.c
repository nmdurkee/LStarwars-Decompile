/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c690; label: FUN_0055c690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055c690(void)

{
  int iVar1;
  
  if ((DAT_0093b2a4 == 0) && (DAT_00856c08 == 0)) {
    iVar1 = FUN_0058a900(0);
    if ((iVar1 == 0) && (DAT_0093b324 == 0)) {
      return 1;
    }
  }
  return 0;
}

