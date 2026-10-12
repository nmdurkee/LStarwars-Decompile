/* Ghidra analysis pseudocode, not original source.
 * ev_9eaa74bb799d8967933988d6e124ea5c840b05143c454f375b97301964b1c1b3
 * Entry: 0x579130; label: FUN_00579130
 */

void FUN_00579130(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  fVar1 = (float)fVar2;
  if (fVar1 < 0.1) {
    *(undefined4 *)(DAT_00951b74 + 0x84) = 0x3dcccccd;
    return;
  }
  if (50.0 < fVar1) {
    *(undefined4 *)(DAT_00951b74 + 0x84) = 0x42480000;
    return;
  }
  *(float *)(DAT_00951b74 + 0x84) = fVar1;
  return;
}

