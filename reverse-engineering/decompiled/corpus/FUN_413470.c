/* Ghidra analysis pseudocode, not original source.
 * ev_67a1dd79f1152a4a8dc944803f9da200f64b6e45b6a6754633c37085e261482d
 * Entry: 0x413470; label: FUN_00413470
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

