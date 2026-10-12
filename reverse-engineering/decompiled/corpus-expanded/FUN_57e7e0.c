/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57e7e0; label: FUN_0057e7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057e7e0(int param_1)

{
  if (((DAT_00951cb0 != (int *)0x0) && (-1 < param_1)) &&
     (param_1 < (int)(uint)*(ushort *)(DAT_00951cb0 + 2))) {
    FUN_0057a6d0(*(short *)(param_1 * 0x44 + *DAT_00951cb0) * 0x130 + DAT_00951b78,0xffffffff,
                 0xffffffff,1);
    DAT_00951cb0[1] = *DAT_00951cb0 + param_1 * 0x44;
    DAT_0093b29c = 0;
    DAT_0093b2a4 = 0;
  }
  return;
}

