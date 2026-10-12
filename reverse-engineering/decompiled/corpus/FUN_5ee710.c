/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ee710; label: FUN_005ee710
 */

void FUN_005ee710(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  
  if ((in_EAX != -1) && (in_EAX < *(int *)(in_ECX + 0xf0))) {
    iVar1 = in_EAX * 0x10 + *(int *)(in_ECX + 0xf8);
    FUN_005ebeb0(iVar1,*(undefined4 *)(iVar1 + 0xc),0x400000,0x3f800000);
  }
  return;
}

