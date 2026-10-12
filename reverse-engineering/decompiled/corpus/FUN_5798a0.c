/* Ghidra analysis pseudocode, not original source.
 * ev_0fe45ae231fd2dfd40158a7785e6912069fa204ac07eb0ac56676de85047f6bb
 * Entry: 0x5798a0; label: FUN_005798a0
 */

void FUN_005798a0(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  if ((float)fVar1 < 0.0) {
    *(undefined4 *)(DAT_00951b74 + 0xbc) = 0;
    return;
  }
  *(float *)(DAT_00951b74 + 0xbc) = (float)fVar1;
  return;
}

