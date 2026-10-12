/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5a99e0; label: FUN_005a99e0
 */

void FUN_005a99e0(void)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(byte *)(unaff_ESI + 0x20) & 1) != 0) {
    local_c = *(undefined4 *)(in_EAX * 0x20 + 0x14 + *(int *)(unaff_ESI + 0x40));
    local_8 = *(undefined4 *)(unaff_ESI + 8);
    local_4 = *(undefined4 *)(in_EAX * 0x20 + *(int *)(unaff_ESI + 0x40) + 0x1c);
    if (((-1 < DAT_00805cb4) && (DAT_00805cb4 < *(int *)(*(int *)(unaff_EDI + 0x134) + 4))) &&
       (iVar1 = *(int *)(*(int *)(*(int *)(unaff_EDI + 0x134) + 8) + DAT_00805cb4 * 0x14),
       iVar1 != -1)) {
      FUN_00684c90(iVar1,&local_c,0x50,0,0);
    }
    FUN_0062c560(*(undefined4 *)(unaff_EDI + 0x134),DAT_00805cb8,&local_c);
    FUN_0062c560(*(undefined4 *)(unaff_EDI + 0x134),DAT_00805cbc,&local_c);
    FUN_0062c560(*(undefined4 *)(unaff_EDI + 0x134),DAT_00805cc0,&local_c);
  }
  iVar1 = FUN_0054fa60();
  *(float *)(unaff_ESI + 0x28) = (float)iVar1 * 6.103609e-05 + 2.0;
  return;
}

