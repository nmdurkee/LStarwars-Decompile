/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x666160; label: FUN_00666160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00666160(undefined4 param_1,int param_2)

{
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    *(undefined4 *)
     (*(int *)(DAT_0296209c +
              *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4) * 4) +
     0x308) = *(undefined4 *)(param_2 + 0x54);
  }
  return;
}

