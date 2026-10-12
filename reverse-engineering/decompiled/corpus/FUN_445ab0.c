/* Ghidra analysis pseudocode, not original source.
 * ev_f48dedfde503d95163bfd3eb2ed6449a9a2f0083b079fa518a64f4b7b72b2f93
 * Entry: 0x445ab0; label: FUN_00445ab0
 */

undefined4
FUN_00445ab0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_6 != 0) {
    iVar2 = 0;
    if ((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) {
      iVar2 = *(int *)(param_3 + 0xd0);
    }
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"character");
        if (iVar1 == 0) {
          FUN_004f8b10("FALSE",*(undefined4 *)(param_4 + iVar3 * 4));
        }
        else if (DAT_00923904 != (code *)0x0) {
          iVar2 = (*DAT_00923904)(param_1,iVar1 + 10);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x1cc) = *(undefined4 *)(iVar2 + 0x5c);
      *(undefined4 *)(iVar2 + 0x1b4) = *(undefined4 *)(iVar2 + 0x5c);
      *(undefined4 *)(iVar2 + 0x1d0) = *(undefined4 *)(iVar2 + 0x60);
      *(undefined4 *)(iVar2 + 0x1b8) = *(undefined4 *)(iVar2 + 0x60);
      *(undefined4 *)(iVar2 + 0x1d4) = *(undefined4 *)(iVar2 + 100);
      *(undefined4 *)(iVar2 + 0x1bc) = *(undefined4 *)(iVar2 + 100);
    }
  }
  return 1;
}

