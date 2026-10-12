/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56f990; label: FUN_0056f990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056f990(int param_1)

{
  int in_ECX;
  float *in_EDX;
  
  if (param_1 < 7) {
    if ((param_1 < 6) && (*in_EDX < 10.0)) {
      *in_EDX = 10.0;
    }
    if ((((-1 < in_ECX) && (in_ECX < DAT_00951360)) &&
        ((*(byte *)(in_ECX * 0x9c + 0x7a + DAT_00951354) & 1) != 0)) && (*in_EDX < 100.0)) {
      *in_EDX = 100.0;
    }
  }
  return;
}

