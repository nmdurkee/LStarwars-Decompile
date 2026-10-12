/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644dc0; label: FUN_00644dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644dc0(undefined4 param_1,int param_2)

{
  DAT_02920a0c = 0;
  if (DAT_0292096c != 0) {
    *(undefined2 *)(DAT_0292096c + 0x44) = *(undefined2 *)(param_2 + 0xc);
    if (*(short *)(DAT_0292096c + 0x44) == 0) {
      *(undefined1 *)(DAT_0292096c + 0x3d) = 1;
    }
  }
  FUN_006279f0(param_1);
  FUN_00624220(param_1);
  return;
}

