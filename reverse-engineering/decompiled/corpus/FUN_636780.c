/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x636780; label: FUN_00636780
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00636780(int param_1)

{
  int iVar1;
  int *in_ECX;
  char *in_EDX;
  int unaff_ESI;
  
  if (unaff_ESI == 0) {
    iVar1 = FUN_00547580(_DAT_02913970,param_1);
    return iVar1;
  }
  if ((in_EDX != (char *)0x0) && (in_ECX != (int *)0x0)) {
    if ((int)*in_EDX <= *in_ECX) {
      return 0;
    }
    iVar1 = *in_ECX + 1;
    *in_ECX = iVar1;
    return in_EDX[iVar1] * 0x8c + 4 + unaff_ESI;
  }
  return param_1 + 0x8c;
}

