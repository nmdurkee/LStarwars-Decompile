/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d4fe0; label: FUN_006d4fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d4fe0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int in_ECX;
  byte *pbVar2;
  
  iVar1 = 0;
  pbVar2 = (byte *)(in_ECX + 0x4ea2 + param_1 * 0x17c);
  while ((*pbVar2 != param_2 ||
         (*(short *)(in_ECX + 0x4ea4 + (param_1 * 0x5f + iVar1) * 4) != param_3))) {
    iVar1 = iVar1 + 1;
    pbVar2 = pbVar2 + 4;
    if (0x1f < iVar1) {
      return 0;
    }
  }
  return 1;
}

