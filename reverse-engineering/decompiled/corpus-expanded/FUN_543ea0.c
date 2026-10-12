/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x543ea0; label: FUN_00543ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00543ea0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  if ((DAT_00802014 != -1) && (DAT_00802014 < 6)) {
    FUN_00543d40(DAT_00802014,param_1,param_2,param_3);
    return 1;
  }
  return 0;
}

