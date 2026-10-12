/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x527ad0; label: FUN_00527ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

