/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x514550; label: FUN_00514550
 */

undefined4 FUN_00514550(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (unaff_ESI == 0) {
    return 0;
  }
  if (*(int *)(unaff_ESI + 0xc) == 0) {
    iVar1 = FUN_004f1440(*(int *)(unaff_ESI + 8) + 0x10);
  }
  else {
    iVar1 = FUN_004f1460(*(int *)(unaff_ESI + 8) + 0x10,*(int *)(unaff_ESI + 0xc));
  }
  if (iVar1 != 0) {
    *(uint *)(unaff_ESI + 0x50) = *(uint *)(unaff_ESI + 0x50) | 1;
    *(int *)(unaff_ESI + 0xc) = iVar1;
    return 1;
  }
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  return 1;
}

