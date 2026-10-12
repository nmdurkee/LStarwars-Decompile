/* Ghidra pseudocode, not original source.
 * ev_4aa7baba24777c7cef62b6758f8d176321ddee5c4eaac4ea92e033f295beb802
 * Entry: 0x44fb90; label: FUN_0044fb90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044fb90(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = 1;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) {
      iVar5 = *piVar2;
    }
    iVar4 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"FALSE");
          if (iVar1 == 0) {
            iVar3 = 0;
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
          iVar5 = 0;
        }
        else {
          iVar5 = *piVar2;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if (iVar5 != 0) {
      *(uint *)(iVar5 + 0xef0) =
           *(uint *)(iVar5 + 0xef0) ^ (iVar3 << 0x18 ^ *(uint *)(iVar5 + 0xef0)) & 0x1000000;
      return 1;
    }
  }
  return 1;
}

