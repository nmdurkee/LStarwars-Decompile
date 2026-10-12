/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bc910; label: FUN_006bc910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bc910(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_006e6b90();
  **(undefined4 **)(param_2 + 0xc) = uVar1;
  return;
}

