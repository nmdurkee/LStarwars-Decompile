/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c5b90; label: FUN_006c5b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c5b90(byte param_1)

{
  undefined4 in_ECX;
  
  FUN_006bde00();
  if ((param_1 & 1) != 0) {
    FUN_006334d0(in_ECX,0x78);
  }
  return;
}

