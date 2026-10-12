/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f2080; label: FUN_005f2080
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

