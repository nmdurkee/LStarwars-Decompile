/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x527ad0; label: FUN_00527ad0
 */

undefined4 FUN_00527ad0(void)

{
  float fVar1;
  int unaff_ESI;
  float *unaff_EDI;
  float10 fVar2;
  float local_c [2];
  float local_4;
  
  fVar2 = (float10)FUN_005c0240(*(float *)(unaff_ESI + 0x40) * *(float *)(unaff_ESI + 0x40) +
                                *(float *)(unaff_ESI + 0x44) * *(float *)(unaff_ESI + 0x44));
  fVar1 = (float)fVar2;
  local_c[0] = *unaff_EDI - *(float *)(unaff_ESI + 8);
  if ((((local_c[0] <= fVar1) && (-fVar1 <= local_c[0])) &&
      (local_4 = unaff_EDI[2] - *(float *)(unaff_ESI + 0x10), local_4 <= fVar1)) &&
     (((-fVar1 <= local_4 &&
       (FUN_005b3620(local_c,local_c,-*(int *)(unaff_ESI + 0x3c)),
       ABS(local_c[0]) < *(float *)(unaff_ESI + 0x40))) &&
      (ABS(local_4) < *(float *)(unaff_ESI + 0x44))))) {
    return 1;
  }
  return 0;
}

