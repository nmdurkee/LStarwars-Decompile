/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1e00; label: FUN_004f1e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f1e00(void)

{
  char in_AL;
  
  if (((in_AL < '0') || ('9' < in_AL)) && (in_AL != '.')) {
    return 0;
  }
  return 1;
}

