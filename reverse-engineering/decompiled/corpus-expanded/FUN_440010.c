/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440010; label: FUN_00440010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00440010(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_EAX;
  
  *in_EAX = param_1;
  in_EAX[1] = param_2;
  in_EAX[2] = param_3;
  in_EAX[3] = param_4;
  return;
}

