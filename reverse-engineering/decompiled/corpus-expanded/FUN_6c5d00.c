/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c5d00; label: FUN_006c5d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006c5d00(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) != 0;
}

