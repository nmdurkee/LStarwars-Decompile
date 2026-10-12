/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f2080; label: FUN_005f2080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f2080(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (param_1 - in_ECX) / 0x830;
  pbVar1 = (byte *)((iVar2 >> 3) + 0x4180 + in_ECX);
  *pbVar1 = *pbVar1 & ~('\x01' << ((byte)iVar2 & 7));
  *(int *)(in_ECX + 0x4184) = iVar2;
  return;
}

