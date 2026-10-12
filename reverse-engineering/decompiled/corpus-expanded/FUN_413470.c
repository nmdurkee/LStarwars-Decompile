/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x413470; label: FUN_00413470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00413470(void)

{
  int iVar1;
  int in_EDX;
  int unaff_ESI;
  
  if (((*(int *)(unaff_ESI + 0x400) != 0) &&
      (*(float *)(in_EDX + 0x63724) < *(float *)(unaff_ESI + 0x404))) &&
     (*(float *)(unaff_ESI + 0x404) < *(float *)(in_EDX + 0x63720) !=
      (*(float *)(unaff_ESI + 0x404) == *(float *)(in_EDX + 0x63720)))) {
    iVar1 = FUN_00410050();
    *(undefined4 *)(iVar1 + 0xf8) = *(undefined4 *)(unaff_ESI + 0x404);
    FUN_00413270();
    if ((*(float *)(unaff_ESI + 0x40c) != 0.0) &&
       ((*(int *)(unaff_ESI + 0x514) == 0 ||
        (*(int *)(unaff_ESI + 0x518) = *(int *)(unaff_ESI + 0x518) + -1,
        *(int *)(unaff_ESI + 0x518) != 0)))) {
      *(float *)(unaff_ESI + 0x404) = *(float *)(unaff_ESI + 0x40c) + *(float *)(unaff_ESI + 0x404);
      return;
    }
    *(undefined4 *)(unaff_ESI + 0x404) = 0xbf800000;
  }
  return;
}

