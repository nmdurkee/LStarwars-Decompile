/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x6491f0; label: FUN_006491f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006491f0(undefined4 param_1,int param_2)

{
  if ((DAT_02920970 != 0) && (DAT_00810190 == 5)) {
    *(undefined4 *)(DAT_02920970 + 0x130) = *(undefined4 *)(param_2 + 0xc);
  }
  return;
}

