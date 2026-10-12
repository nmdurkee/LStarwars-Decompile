/* Ghidra pseudocode, not original source.
 * ev_ea16e91579c763516a5ec9191881acc35a0dcfc8106f35e62baf3c19fc401ba6
 * Entry: 0x448ed0; label: FUN_00448ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00448ed0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((((param_3 != 0) && (piVar3 = *(int **)(param_3 + 0xd0), piVar3 != (int *)0x0)) &&
      (*piVar3 != 0)) && (iVar1 = *piVar3, param_6 != 0)) {
    piVar3 = *(int **)(iVar1 + 0x3ac);
    if (piVar3 != (int *)0x0) {
      iVar5 = *piVar3;
    }
    iVar4 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"victim=");
        if (iVar2 != 0) {
          if ((DAT_00923904 == (code *)0x0) ||
             (piVar3 = (int *)(*DAT_00923904)(param_1,iVar2 + 7), piVar3 == (int *)0x0)) {
            iVar5 = 0;
          }
          else {
            iVar5 = *piVar3;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if (iVar5 != 0) {
      FUN_0049c540(iVar1,iVar5);
    }
  }
  return 1;
}

