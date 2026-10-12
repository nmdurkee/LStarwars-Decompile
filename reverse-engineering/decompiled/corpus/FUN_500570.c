/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x500570; label: FUN_00500570
 */

void FUN_00500570(void)

{
  int iVar1;
  int unaff_ESI;
  float10 fVar2;
  undefined4 *puVar3;
  
  *(uint *)(unaff_ESI + 0x88) = *(uint *)(unaff_ESI + 0x88) | 0x400;
  iVar1 = *(int *)(unaff_ESI + 0x58);
  if (*(int *)(iVar1 + 0x20) == 0) {
    return;
  }
  if (((*(uint *)(unaff_ESI + 0x88) & 0x200) == 0) ||
     (fVar2 = (float10)FUN_005d6860(unaff_ESI + 0x60), (float)fVar2 <= *(float *)(unaff_ESI + 0x84))
     ) {
    if ((*(uint *)(unaff_ESI + 0x88) & 0x100) == 0) {
      return;
    }
    iVar1 = *(int *)(iVar1 + 0x20);
    if ((char)*(uint *)(unaff_ESI + 0x88) < '\0') {
      puVar3 = (undefined4 *)(unaff_ESI + 0x18);
    }
    else {
      puVar3 = &DAT_00806680;
    }
    iVar1 = FUN_006042e0(iVar1,iVar1 + 0xc,puVar3,0,0);
    if (iVar1 != 0) {
      return;
    }
  }
  *(uint *)(unaff_ESI + 0x88) = *(uint *)(unaff_ESI + 0x88) & 0xfffffbff;
  return;
}

