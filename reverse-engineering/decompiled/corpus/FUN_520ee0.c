/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x520ee0; label: FUN_00520ee0
 */

void FUN_00520ee0(void)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  
  iVar2 = 0;
  for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x383c0); iVar1 != 0;
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar1)) {
    iVar2 = iVar2 + 1;
  }
  FUN_00621520(iVar2);
  for (iVar2 = FUN_004f1440(DAT_009238e4 + 0x383c0); iVar2 != 0;
      iVar2 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar2)) {
    FUN_00621440(iVar2 + 8,0x10);
    FUN_006214d0(*(undefined4 *)(iVar2 + 0x18));
    FUN_006214d0(*(undefined4 *)(iVar2 + 0x1c));
    FUN_006214d0(*(undefined4 *)(iVar2 + 0x20));
    FUN_006214d0(*(undefined4 *)(iVar2 + 0x24));
    FUN_006214d0(*(undefined4 *)(iVar2 + 0x28));
    FUN_006214d0(*(undefined4 *)(iVar2 + 0x2c));
    FUN_006215a0(*(undefined2 *)(iVar2 + 0x30));
    if (DAT_0080171c < 0x14) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined1 *)(iVar2 + 0x33);
    }
    FUN_00621600(uVar3);
    FUN_00621600(0);
  }
  return;
}

