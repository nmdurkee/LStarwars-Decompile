/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550690; label: FUN_00550690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00550690(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  FUN_005b7ea0(param_3,local_30);
  FUN_005b7ea0(param_2,local_20);
  FUN_005b87a0(local_10,local_20,local_30,param_4);
  FUN_005b8040(local_10,param_1);
  return;
}

