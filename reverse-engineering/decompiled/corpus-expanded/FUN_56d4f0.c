/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d4f0; label: FUN_0056d4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056d4f0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  float *pfVar4;
  uint uVar5;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x4690) != 0)) &&
     (iVar3 = 0, 0 < *(int *)(param_1 + 0x4694))) {
    pfVar4 = (float *)(*(int *)(param_1 + 0x4690) + 0x14);
    do {
      bVar2 = *(byte *)(pfVar4 + 8) | 3;
      *(byte *)(pfVar4 + 8) = bVar2;
      pfVar4[5] = pfVar4[2] + *pfVar4;
      pfVar4[6] = pfVar4[3] * pfVar4[3];
      if ((param_3 != 0) && (iVar3 < 0x20)) {
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        uVar5 = 1 << ((byte)iVar3 & 0x1f);
        bVar2 = (((*(uint *)(param_3 + iVar1 * 4) & uVar5) != 0) * '\x02' ^ bVar2) & 2 ^ bVar2;
        *(byte *)(pfVar4 + 8) = bVar2;
        *(byte *)(pfVar4 + 8) =
             ((*(uint *)(param_3 + 4 + iVar1 * 4) & uVar5) != 0 ^ bVar2) & 1 ^ bVar2;
      }
      iVar3 = iVar3 + 1;
      pfVar4 = pfVar4 + 0x10;
    } while (iVar3 < *(int *)(param_1 + 0x4694));
  }
  return;
}

