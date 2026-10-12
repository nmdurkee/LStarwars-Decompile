/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0880; label: FUN_006c0880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c0880(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_004fb550(*(undefined4 *)(in_ECX + 0x198),param_1,param_2 * param_3);
  if (((*(int *)(in_ECX + 0xc) != 0) && (1 < param_2)) && (0 < param_3)) {
    do {
      if (param_2 == 2) {
        FUN_00621180(param_1);
      }
      else if (param_2 == 4) {
        FUN_00621190(param_1);
      }
      param_1 = param_1 + param_2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return uVar1;
}

