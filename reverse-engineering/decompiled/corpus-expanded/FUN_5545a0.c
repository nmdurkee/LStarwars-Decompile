/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x5545a0; label: FUN_005545a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005545a0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar5 = 0;
    if (*(char *)(*(int *)(param_1 + 0x128) + 0xf2) != '\0') {
      iVar3 = 0;
      do {
        iVar4 = *(int *)(param_1 + 0x46e0) + iVar3;
        if ((iVar4 != 0) && ((*(byte *)(iVar4 + 0xac) & 1) != 0)) {
          uVar1 = FUN_005cfa50(iVar4 + 0x50,param_2);
          iVar2 = FUN_004f20f0(uVar1);
          if (iVar2 == 0) {
            return iVar4;
          }
        }
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 + 0x304;
      } while (iVar5 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2));
    }
    return 0;
  }
  return 0;
}

