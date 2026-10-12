/* Ghidra pseudocode, not original source.
 * ev_4aa7baba24777c7cef62b6758f8d176321ddee5c4eaac4ea92e033f295beb802
 * Entry: 0x44f100; label: FUN_0044f100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044f100(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_6 != 0) {
    if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
      iVar4 = **(int **)(param_3 + 0xd0);
    }
    if ((param_5 != 0) && (iVar3 = 0, 0 < param_5)) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"character=");
        if (iVar1 != 0) {
          if ((DAT_00923904 == (code *)0x0) ||
             (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
            iVar4 = 0;
          }
          else {
            iVar4 = *piVar2;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    if (iVar4 != 0) {
      FUN_0055e4a0(iVar4,1);
      FUN_0055e4e0(iVar4 + 0x6c4);
    }
  }
  return 1;
}

