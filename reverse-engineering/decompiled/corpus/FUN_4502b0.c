/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x4502b0; label: FUN_004502b0
 */

undefined4 FUN_004502b0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  
  if ((in_stack_00000018 != 0) && (iVar4 = 0, 0 < in_stack_00000014)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar4 * 4),"name=");
      if ((iVar1 != 0) &&
         (piVar2 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802f54,
                                       iVar1 + 5), piVar2 != (int *)0x0)) {
        iVar3 = *piVar2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < in_stack_00000014);
    if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0x94) & 1) == 0)) {
      FUN_00567800(iVar3,1,0xffffffff,1,0,1);
    }
  }
  return 1;
}

