/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f20c0; label: FUN_005f20c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005f20c0(void)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  
  iVar2 = *(int *)(in_ECX + 0x4184);
  for (iVar3 = iVar2; iVar3 < 8; iVar3 = iVar3 + 1) {
    if ((*(char *)((iVar3 >> 3) + 0x4180 + in_ECX) >> ((byte)iVar3 & 7) & 1U) == 0)
    goto LAB_005f2124;
  }
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if ((*(char *)((iVar3 >> 3) + 0x4180 + in_ECX) >> ((byte)iVar3 & 7) & 1U) == 0) {
LAB_005f2124:
        pbVar1 = (byte *)((iVar3 >> 3) + 0x4180 + in_ECX);
        *pbVar1 = *pbVar1 | '\x01' << ((byte)iVar3 & 7);
        uVar4 = iVar3 + 1U & 0x80000007;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
        }
        *(uint *)(in_ECX + 0x4184) = uVar4;
        return iVar3 * 0x830 + in_ECX;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return 0;
}

