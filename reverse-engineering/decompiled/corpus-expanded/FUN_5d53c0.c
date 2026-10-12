/* Ghidra pseudocode, not original source.
 * ev_8bfd975316f8cf2b7f750252451c539d63e4b7da44e3fbde714e6599bb2e7713
 * Entry: 0x5d53c0; label: FUN_005d53c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d53c0(float param_1)

{
  float fVar1;
  float *unaff_ESI;
  
  _memset(unaff_ESI,0,0x40);
  fVar1 = _DAT_0080b9cc;
  *unaff_ESI = _DAT_0080b9cc * param_1;
  unaff_ESI[5] = fVar1;
  unaff_ESI[10] = 1.0;
  unaff_ESI[0xf] = 1.0;
  return;
}

