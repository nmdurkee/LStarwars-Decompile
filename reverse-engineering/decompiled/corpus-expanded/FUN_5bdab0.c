/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bdab0; label: FUN_005bdab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005bdab0(undefined4 param_1,int param_2)

{
  undefined4 local_4;
  
  local_4 = 2;
  if (param_2 != 0) {
    FUN_004f03d0(param_2,&local_4,4);
    FUN_004f03d0(param_2,param_1,0x5c);
    return 1;
  }
  return 0;
}

