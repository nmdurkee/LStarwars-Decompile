/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x441fd0; label: FUN_00441fd0
 */

float10 FUN_00441fd0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    uint param_5)

{
  if (param_5 == 0xffffffff) {
    param_5 = (uint)*(byte *)(param_2 + 0xb0);
  }
  if ((param_5 != 0) && ((&DAT_00876847)[param_5] != '\0')) {
    return (float10)1;
  }
  return (float10)0;
}

