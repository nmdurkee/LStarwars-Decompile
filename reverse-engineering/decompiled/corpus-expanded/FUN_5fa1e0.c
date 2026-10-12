/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5fa1e0; label: FUN_005fa1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fa1e0(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = &PTR_FUN_0076a75c;
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

