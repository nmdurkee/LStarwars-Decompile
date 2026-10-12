/* Ghidra analysis pseudocode, not original source.
 * ev_f70dbfb4dc55c21d9a8b2990429bfe298595e1ea041c5f65e2960caacde39e05
 * Entry: 0x4499b0; label: FUN_004499b0
 */

undefined4
FUN_004499b0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_6 != 0) && (param_3 != 0)) &&
      (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (((*piVar1 != 0 && (iVar2 = *piVar1, iVar2 != 0)) && (iVar4 = 0, 0 < param_5)))) {
    do {
      iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"Reset");
      if (iVar3 == 0) {
        *(undefined1 *)(iVar2 + 0x378) = 0;
      }
      else {
        FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar4 * 4));
        iVar3 = FUN_006e6b90();
        if (iVar3 - 1U < 0x10) {
          *(char *)(iVar2 + 0x378) = (char)iVar3;
          (&DAT_00876847)[iVar3] = (&DAT_00876847)[iVar3] + '\x01';
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_5);
  }
  return 1;
}

