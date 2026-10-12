/* Ghidra pseudocode, not original source.
 * ev_f229a78d5de0bf17b480d7e9a60f462b055d08f1d682cbbe42c93314af3c723e
 * Entry: 0x5b21f0; label: FUN_005b21f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005b21f0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (param_4 < 1) {
    return 0;
  }
  if ((DAT_0095e41c != 0) && (iVar2 = 0, iVar4 = DAT_0095e41c, 0 < DAT_0095e420)) {
    do {
      iVar1 = FUN_004f8b80(param_2,*(undefined4 *)(iVar4 + 4),0xffffffff);
      if (iVar1 == 0) {
        *(int *)(param_3 + iVar3 * 4) = iVar4;
        iVar3 = iVar3 + 1;
        if (param_4 <= iVar3) {
          return iVar3;
        }
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0xc;
    } while (iVar2 < DAT_0095e420);
  }
  if (param_1 != 0) {
    iVar4 = *(int *)(param_1 + 0x34);
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x30)) {
      do {
        iVar1 = FUN_004f8b80(param_2,*(undefined4 *)(iVar4 + 4),0xffffffff);
        if (iVar1 == 0) {
          *(int *)(param_3 + iVar3 * 4) = iVar4;
          iVar3 = iVar3 + 1;
          if (param_4 <= iVar3) {
            return iVar3;
          }
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar2 < *(int *)(param_1 + 0x30));
    }
  }
  return iVar3;
}

