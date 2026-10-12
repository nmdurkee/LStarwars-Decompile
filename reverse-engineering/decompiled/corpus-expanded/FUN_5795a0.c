/* Ghidra pseudocode, not original source.
 * ev_9238a7d4a32c49ce947fe3ed44bc206dac4b982bd913cd0b1074936c5e6922ce
 * Entry: 0x5795a0; label: FUN_005795a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005795a0(int param_1)

{
  int iVar1;
  
  *(uint *)(DAT_00951b74 + 100) = *(uint *)(DAT_00951b74 + 100) | 0x4000;
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      *(uint *)(DAT_00951b74 + 100) = *(uint *)(DAT_00951b74 + 100) & 0xffffbfff;
    }
  }
  return;
}

