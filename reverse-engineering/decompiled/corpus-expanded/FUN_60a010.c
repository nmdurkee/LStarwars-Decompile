/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x60a010; label: FUN_0060a010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060a010(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (param_1 - in_ECX) / 0x30;
  pbVar1 = (byte *)((iVar2 >> 3) + 0x300 + in_ECX);
  *pbVar1 = *pbVar1 & ~('\x01' << ((byte)iVar2 & 7));
  *(int *)(in_ECX + 0x304) = iVar2;
  return;
}

