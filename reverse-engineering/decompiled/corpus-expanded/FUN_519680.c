/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x519680; label: FUN_00519680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00519680(int param_1,undefined4 param_2)

{
  undefined1 local_40 [64];
  
  FUN_005b4500(local_40,param_1);
  FUN_005b5060(local_40,*(undefined4 *)(param_1 + 0x38));
  FUN_005191f0(local_40,param_2);
  return;
}

