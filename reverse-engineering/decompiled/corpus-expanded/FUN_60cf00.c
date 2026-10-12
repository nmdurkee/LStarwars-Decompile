/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60cf00; label: FUN_0060cf00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060cf00(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_006e9c07();
  *in_ECX = &PTR_FUN_0076a8cc;
  in_ECX[8] = 0;
  in_ECX[9] = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_0060cb30(param_1,0,0xffffffff);
  return;
}

