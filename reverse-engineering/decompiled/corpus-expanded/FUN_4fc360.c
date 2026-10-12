/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fc360; label: FUN_004fc360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short FUN_004fc360(undefined4 param_1)

{
  byte bVar1;
  short sVar2;
  
  bVar1 = FUN_004fc2d0(param_1);
  sVar2 = FUN_004fc2d0(param_1);
  return sVar2 * 0x100 + (ushort)bVar1;
}

