/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60cfc0; label: FUN_0060cfc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060cfc0(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = &PTR_FUN_0076a8cc;
  if (0xf < *(uint *)(in_ECX + 0x24)) {
    FUN_006e85b0(*(undefined4 *)(in_ECX + 0x10));
  }
  *(undefined4 *)(in_ECX + 0x24) = 0xf;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  in_ECX[0x10] = (exception)0x0;
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

