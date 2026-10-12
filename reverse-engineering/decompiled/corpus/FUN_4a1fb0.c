/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x4a1fb0; label: FUN_004a1fb0
 */

void FUN_004a1fb0(void)

{
  undefined4 uVar1;
  int in_EAX;
  int in_ECX;
  int unaff_ESI;
  
  *(uint *)(unaff_ESI + 0xe20) = *(uint *)(unaff_ESI + 0xe20) | 0x20000;
  if (in_EAX == 0) {
    *(int *)(unaff_ESI + 0xd18) = in_ECX;
    *(undefined1 *)(unaff_ESI + 0xe2d) = 0;
    if (in_ECX == 0) {
      return;
    }
  }
  else {
    *(int *)(unaff_ESI + 0xd18) = in_EAX;
    *(undefined1 *)(unaff_ESI + 0xe2d) = 1;
    if (in_ECX == 0) {
      uVar1 = 0x3f800000;
    }
    else {
      uVar1 = *(undefined4 *)(in_ECX + 0x70);
    }
    *(undefined4 *)(unaff_ESI + 0xd8c) = uVar1;
    FUN_005cf9e0(in_EAX + 4);
  }
  FUN_0058bee0();
  if (in_ECX != 0) {
    FUN_0058bee0();
  }
  return;
}

