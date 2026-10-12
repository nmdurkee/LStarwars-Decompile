/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x445710; label: FUN_00445710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00445710(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) {
    FUN_00426de0(*(int *)(param_3 + 0xd0) + 0x5c,0);
  }
  return 1;
}

