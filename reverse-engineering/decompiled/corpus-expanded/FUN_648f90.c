/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x648f90; label: FUN_00648f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00648f90(undefined4 param_1,int param_2)

{
  if (DAT_02920970 != 0) {
    if (DAT_02920968 == 0) {
      *(undefined4 *)(DAT_02920970 + 0x118) = *(undefined4 *)(param_2 + 0xc);
      return;
    }
    if (DAT_02920968 == 1) {
      *(undefined4 *)(DAT_02920970 + 0x11c) = *(undefined4 *)(param_2 + 0xc);
      return;
    }
    if (DAT_02920968 == 2) {
      *(undefined4 *)(DAT_02920970 + 0x128) = *(undefined4 *)(param_2 + 0xc);
      return;
    }
    if (DAT_02920968 == 3) {
      *(undefined4 *)(DAT_02920970 + 300) = *(undefined4 *)(param_2 + 0xc);
      return;
    }
    if (DAT_02920968 == 4) {
      *(undefined4 *)(DAT_02920970 + 0x144) = *(undefined4 *)(param_2 + 0xc);
    }
  }
  return;
}

