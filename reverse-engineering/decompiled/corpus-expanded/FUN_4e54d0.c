/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e54d0; label: FUN_004e54d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e54d0(int param_1)

{
  FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aaf0,"door_push",1);
  DAT_0087a9e0 = FUN_0051adf0(*(int *)(param_1 + 0x2ae8),
                              *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) + 8),
                              "droid_rescue_a","droid_rescue_b",&DAT_0087a950);
  return;
}

