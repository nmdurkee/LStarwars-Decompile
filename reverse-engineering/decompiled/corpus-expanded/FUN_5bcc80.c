/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bcc80; label: FUN_005bcc80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bcc80(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (-1 < param_2 + param_3) {
    do {
      if (iVar1 < param_3) {
        *(undefined4 *)(param_1 + iVar1 * 4) = 0;
      }
      else {
        if (param_2 < iVar1) {
          iVar2 = (param_2 - param_3) + 2;
        }
        else {
          iVar2 = (1 - param_3) + iVar1;
        }
        *(int *)(param_1 + iVar1 * 4) = iVar2;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= param_2 + param_3);
  }
  return;
}

