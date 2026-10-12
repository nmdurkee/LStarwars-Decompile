/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1730; label: FUN_004f1730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f1730(void)

{
  float *in_ECX;
  float *in_EDX;
  
  if ((((*in_ECX < in_EDX[1]) && (*in_EDX < in_ECX[1])) && (in_ECX[3] < in_EDX[2])) &&
     (in_EDX[3] < in_ECX[2])) {
    return 1;
  }
  return 0;
}

