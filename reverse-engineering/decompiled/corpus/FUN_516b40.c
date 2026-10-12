/* Ghidra analysis pseudocode, not original source.
 * ev_84e2b506f29363daa42df6f934b4c92b1585b3e8a57a6b6866ee0e5470757f5b
 * Entry: 0x516b40; label: FUN_00516b40
 */

undefined4
FUN_00516b40(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 1;
  if (param_6 != 0) {
    iVar2 = 0;
    if ((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) {
      iVar2 = *(int *)(param_3 + 0xd0);
    }
    iVar4 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(param_4[iVar4],"character");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8b10("FALSE",*param_4);
          if (iVar1 == 0) {
            iVar3 = 0;
          }
        }
        else if (DAT_00923904 != (code *)0x0) {
          iVar2 = (*DAT_00923904)(param_1,iVar1 + 10);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if (iVar2 != 0) {
      *(uint *)(iVar2 + 0x1fc) =
           *(uint *)(iVar2 + 0x1fc) ^ (iVar3 << 0x11 ^ *(uint *)(iVar2 + 0x1fc)) & 0x20000;
      return 1;
    }
  }
  return 1;
}

