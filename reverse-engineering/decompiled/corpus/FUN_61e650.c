/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61e650; label: FUN_0061e650
 */

undefined4 FUN_0061e650(void)

{
  int in_EAX;
  int unaff_ESI;
  
  DAT_0080f598 = 1;
  if (((*(byte *)(unaff_ESI + 0x4c) & 8) != 0) ||
     ((*(int *)(unaff_ESI + 8) == 0x11 && ((*(byte *)(in_EAX + 0x70) & 0x40) != 0)))) {
    if (*(int *)(unaff_ESI + 0x74) != 0) {
      DAT_0080f598 = 0;
      (**(code **)(unaff_ESI + 0x74))();
      *(uint *)(unaff_ESI + 0x4c) = *(uint *)(unaff_ESI + 0x4c) & 0xfffffff7;
    }
    if ((DAT_02912ec4 & 0x40) == 0) {
      *(uint *)(unaff_ESI + 0x4c) = *(uint *)(unaff_ESI + 0x4c) & 0xfffffff7;
    }
  }
  return 0;
}

