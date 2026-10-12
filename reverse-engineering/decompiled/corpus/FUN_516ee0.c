/* Ghidra analysis pseudocode, not original source.
 * ev_84e2b506f29363daa42df6f934b4c92b1585b3e8a57a6b6866ee0e5470757f5b
 * Entry: 0x516ee0; label: FUN_00516ee0
 */

undefined4 FUN_00516ee0(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) && (*(int *)(param_2 + 0xc0) != 0)) {
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0xc0);
    *(undefined4 *)(param_2 + 0xc0) = 0;
  }
  return 1;
}

