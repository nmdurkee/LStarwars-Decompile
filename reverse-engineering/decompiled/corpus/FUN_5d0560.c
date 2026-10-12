/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0560; label: FUN_005d0560
 */

void FUN_005d0560(int param_1)

{
  if (((DAT_00966384 < 4) && (*(int *)(param_1 + 0x808) != 0)) && (*(int *)(param_1 + 0x824) == 0))
  {
    *(undefined4 *)(param_1 + 0x824) = 1;
    (&DAT_0096d9d0)[DAT_00966384] = param_1;
    DAT_00966384 = DAT_00966384 + 1;
    DAT_009715a0 = 0;
  }
  return;
}

