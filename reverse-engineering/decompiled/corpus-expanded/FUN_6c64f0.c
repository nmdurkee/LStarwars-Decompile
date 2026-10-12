/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c64f0; label: FUN_006c64f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c64f0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x18))(&DAT_00763b1c);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0x10))();
    (**(code **)(*param_1 + 8))(in_ECX + 4,4,1);
    (**(code **)(*param_1 + 0x1c))();
  }
  return;
}

