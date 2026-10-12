/* Ghidra pseudocode, not original source.
 * ev_9f880a640db7021abf6bd9453b6c2d9d41a7c75291a178dd1542c0e98d960678
 * Entry: 0x6b9110; label: FUN_006b9110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9110(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_004f6d10(param_1);
  *(undefined4 *)(&DAT_02973a1c + DAT_02973a40 * 4) = uVar1;
  DAT_02973a40 = DAT_02973a40 + 1;
  FUN_004f04b0(param_1,param_2);
  FUN_004f04b0(param_1,0);
  FUN_004f04b0(param_1,0);
  FUN_004f04b0(param_1,0);
  return;
}

