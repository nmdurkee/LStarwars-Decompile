/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a6f40; label: FUN_005a6f40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a6f40(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    *(uint *)(iVar1 + 200) =
         *(uint *)(iVar1 + 200) ^
         ((uint)(param_2 != 0) << 0x18 ^ *(uint *)(iVar1 + 200)) & 0x1000000;
    if (param_2 != 0) {
      iVar2 = *(int *)(PTR_DAT_00802c54 + 0x46c0);
      iVar3 = 0;
      if (0 < iVar2) {
        iVar4 = *(int *)(PTR_DAT_00802c54 + 0x46bc);
        do {
          if (iVar1 == iVar4) break;
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0xd4;
        } while (iVar3 < iVar2);
      }
      if (iVar3 < iVar2) {
        FUN_005a4450(PTR_DAT_00802c54,iVar1,iVar3);
      }
      *(uint *)(iVar1 + 200) = *(uint *)(iVar1 + 200) | 0x40000;
    }
  }
  return;
}

