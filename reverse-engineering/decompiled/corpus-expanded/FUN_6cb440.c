/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cb440; label: FUN_006cb440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cb440(byte param_1)

{
  int in_ECX;
  
  *(undefined ***)(in_ECX + 0x109c) = &PTR_FUN_0076f6e0;
  FUN_00633540();
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

