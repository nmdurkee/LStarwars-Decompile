/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x60a010; label: FUN_0060a010
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

