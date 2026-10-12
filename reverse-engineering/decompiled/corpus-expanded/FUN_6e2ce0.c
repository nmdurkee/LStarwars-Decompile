/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e2ce0; label: FUN_006e2ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2ce0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_006e1b70(param_1,param_2,param_3);
  if (*(uint *)(in_ECX + 0x618) <= uVar1) {
    uVar1 = *(uint *)(in_ECX + 0x620);
  }
  *(uint *)(in_ECX + 0x660) = uVar1;
  return;
}

