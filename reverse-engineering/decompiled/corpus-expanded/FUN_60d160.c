/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60d160; label: FUN_0060d160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060d160(exception *param_1)

{
  exception *in_ECX;
  
  std::exception::exception(in_ECX,param_1);
  *(undefined ***)in_ECX = &PTR_FUN_0076a8cc;
  *(undefined4 *)(in_ECX + 0x24) = 0xf;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  in_ECX[0x10] = (exception)0x0;
  FUN_0060cb30(param_1 + 0xc,0,0xffffffff);
  *(undefined ***)in_ECX = &PTR_FUN_0076a8d8;
  return;
}

