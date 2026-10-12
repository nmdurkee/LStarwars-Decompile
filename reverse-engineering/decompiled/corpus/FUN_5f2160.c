/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f2160; label: FUN_005f2160
 */

int FUN_005f2160(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  iVar2 = *(int *)(in_ECX + 0x204);
  for (iVar3 = iVar2; iVar3 < 8; iVar3 = iVar3 + 1) {
    if ((*(char *)((iVar3 >> 3) + 0x200 + in_ECX) >> ((byte)iVar3 & 7) & 1U) == 0)
    goto LAB_005f21c4;
  }
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if ((*(char *)((iVar3 >> 3) + 0x200 + in_ECX) >> ((byte)iVar3 & 7) & 1U) == 0) {
LAB_005f21c4:
        pbVar1 = (byte *)((iVar3 >> 3) + 0x200 + in_ECX);
        *pbVar1 = *pbVar1 | '\x01' << ((byte)iVar3 & 7);
        uVar4 = iVar3 + 1U & 0x80000007;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
        }
        *(uint *)(in_ECX + 0x204) = uVar4;
        return iVar3 * 0x40 + in_ECX;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return 0;
}

