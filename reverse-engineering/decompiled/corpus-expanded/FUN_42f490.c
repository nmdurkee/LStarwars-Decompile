/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42f490; label: FUN_0042f490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_0042f490(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x808) != 0;
}

