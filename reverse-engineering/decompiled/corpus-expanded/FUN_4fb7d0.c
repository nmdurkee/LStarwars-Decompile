/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fb7d0; label: FUN_004fb7d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004fb7d0(undefined4 param_1)

{
  uint3 in_ECX;
  undefined4 uStack_4;
  
  uStack_4 = (uint)in_ECX;
  FUN_004fb550(param_1,(int)&uStack_4 + 3,1);
  return uStack_4 >> 0x18;
}

