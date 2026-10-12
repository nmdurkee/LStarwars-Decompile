/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44b290; label: FUN_0044b290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044b290(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint local_4;
  
  iVar3 = 0;
  local_4 = 0xffffffff;
  if (param_6 != 0) {
    if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
      iVar3 = **(int **)(param_3 + 0xd0);
    }
    iVar4 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character=");
        if (iVar1 == 0) {
          FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar4 * 4));
          local_4 = FUN_006e6b90();
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *piVar2;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if (iVar3 != 0) {
      if (local_4 == 0xffffffff) {
        local_4 = (uint)*(byte *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0xf5);
      }
      *(undefined1 *)(iVar3 + 0xe38) = (undefined1)local_4;
    }
  }
  return 1;
}

