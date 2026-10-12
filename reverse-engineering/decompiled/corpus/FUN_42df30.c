/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x42df30; label: FUN_0042df30
 */

void FUN_0042df30(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  
  if ((*(char *)(param_2 + 0x91) == '\x02') && (*(float *)(param_2 + 0x44) < 0.25)) {
    uVar1 = FUN_00650dc0("SwPPad");
    *(undefined2 *)(param_2 + 0x8c) = uVar1;
  }
  return;
}

