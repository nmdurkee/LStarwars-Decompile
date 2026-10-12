/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x60a0b0; label: FUN_0060a0b0
 */

int FUN_0060a0b0(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  iVar2 = *(int *)(in_ECX + 0x304);
  for (iVar3 = iVar2; iVar3 < 0x10; iVar3 = iVar3 + 1) {
    if ((*(char *)((iVar3 >> 3) + 0x300 + in_ECX) >> ((byte)iVar3 & 7) & 1U) == 0)
    goto LAB_0060a114;
  }
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if ((*(char *)((iVar3 >> 3) + 0x300 + in_ECX) >> ((byte)iVar3 & 7) & 1U) == 0) {
LAB_0060a114:
        pbVar1 = (byte *)((iVar3 >> 3) + 0x300 + in_ECX);
        *pbVar1 = *pbVar1 | '\x01' << ((byte)iVar3 & 7);
        uVar4 = iVar3 + 1U & 0x8000000f;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffff0) + 1;
        }
        *(uint *)(in_ECX + 0x304) = uVar4;
        return iVar3 * 0x30 + in_ECX;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return 0;
}

