/* Ghidra pseudocode, not original source.
 * ev_4aa7baba24777c7cef62b6758f8d176321ddee5c4eaac4ea92e033f295beb802
 * Entry: 0x44ee70; label: FUN_0044ee70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044ee70(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (iVar2 = *piVar1, param_6 != 0)) {
    *(uint *)(iVar2 + 0x1044) = *(uint *)(iVar2 + 0x1044) | 4;
    iVar4 = 0;
    if (0 < param_5) {
      do {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757ebc);
        if (iVar3 == 0) {
          *(uint *)(iVar2 + 0x1044) = *(uint *)(iVar2 + 0x1044) | 4;
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"FALSE");
          if (iVar3 == 0) {
            *(uint *)(iVar2 + 0x1044) = *(uint *)(iVar2 + 0x1044) & 0xfffffffb;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
  }
  return 1;
}

