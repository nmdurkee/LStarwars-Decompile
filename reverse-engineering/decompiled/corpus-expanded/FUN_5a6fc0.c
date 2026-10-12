/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a6fc0; label: FUN_005a6fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a6fc0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  *(uint *)(iVar1 + 200) =
       *(uint *)(iVar1 + 200) ^ ((uint)(param_2 != 0) << 0x12 ^ *(uint *)(iVar1 + 200)) & 0x40000;
  FUN_005cfc00(iVar1 + 0x24,param_2);
  iVar3 = 0;
  if (*(char *)(iVar1 + 0xd1) != '\0') {
    iVar2 = iVar1 + 0x5c;
    do {
      FUN_005cfc00(iVar2,*(uint *)(iVar1 + 200) >> 0x12 & 1);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (iVar3 < (int)(uint)*(byte *)(iVar1 + 0xd1));
  }
  return;
}

