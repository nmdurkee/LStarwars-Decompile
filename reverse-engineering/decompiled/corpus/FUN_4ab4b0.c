/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4ab4b0; label: FUN_004ab4b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ab4b0(void)

{
  int in_ECX;
  int unaff_ESI;
  float10 fVar1;
  float local_8;
  float local_4;
  
  if (*(char *)(unaff_ESI + 0x280) != -1) {
    local_4 = _DAT_00925018 * 3.0;
    if (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087b014) {
      if ((in_ECX != 0) ||
         (((local_8 = _DAT_007fc17c, _DAT_00950780 != 0.0 || (DAT_00855de0 != 0)) &&
          (DAT_00882410 != -1)))) {
        local_8 = 1.0;
      }
      local_8 = local_8 + *(float *)(unaff_ESI + 0x1038) * (_DAT_007fc180 - local_8);
      if (in_ECX != 0) {
        local_4 = _DAT_00925018 * 5.0;
      }
    }
    else {
      local_8 = _DAT_007fc184 + *(float *)(unaff_ESI + 0x1038) * (_DAT_007fc188 - _DAT_007fc184);
    }
    fVar1 = (float10)FUN_0054fad0(*(undefined4 *)(unaff_ESI + 0xc44),local_8,local_4);
    *(float *)(unaff_ESI + 0xc44) = (float)fVar1;
  }
  return;
}

