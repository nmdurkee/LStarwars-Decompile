/* Ghidra analysis pseudocode, not original source.
 * ev_c738a20aab8983fc200bedf50414a33a26b9029d211323cd468d6edebc3fc3e7
 * Entry: 0x555930; label: FUN_00555930
 */

void FUN_00555930(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 4);
  if ((in_EAX != 0) && ((*(byte *)(in_EAX + 0x84) & 8) == 0)) {
    iVar2 = FUN_00554ff0();
    if (((iVar2 == 2) || (iVar2 == 1)) && (param_1 != 0)) {
      FUN_00547930(0x29,unaff_ESI + 0x88,0,0);
      FUN_0057fc80();
    }
    FUN_0054a850(**(undefined4 **)(iVar1 + 0xca4),0x3f000000,0);
    FUN_0057fe80();
    return;
  }
  return;
}

