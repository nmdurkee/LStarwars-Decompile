/* Ghidra analysis pseudocode, not original source.
 * ev_7e6f21d847db13540c188bfca3b16bfe9d42e9ab138b0a2487dfabbe836b8541
 * Entry: 0x520e10; label: FUN_00520e10
 */

int FUN_00520e10(undefined4 *param_1,undefined2 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 *unaff_EDI;
  
  iVar1 = FUN_004f1440(DAT_009238e4 + 0x383b8);
  if (iVar1 != 0) {
    FUN_004f1410(DAT_009238e4 + 0x383b8,iVar1);
    FUN_004f1310(DAT_009238e4 + 0x383c0,iVar1);
    *(undefined4 *)(iVar1 + 0x18) = *unaff_EDI;
    *(undefined4 *)(iVar1 + 0x1c) = unaff_EDI[1];
    *(undefined4 *)(iVar1 + 0x20) = unaff_EDI[2];
    if (param_1 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar1 + 0x24) = *param_1;
      *(undefined4 *)(iVar1 + 0x28) = param_1[1];
      *(undefined4 *)(iVar1 + 0x2c) = param_1[2];
    }
    *(undefined2 *)(iVar1 + 0x30) = param_2;
    *(undefined1 *)(iVar1 + 0x33) = param_3;
  }
  return iVar1;
}

