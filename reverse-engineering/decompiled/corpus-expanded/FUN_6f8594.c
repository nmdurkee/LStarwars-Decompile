/* Ghidra pseudocode, not original source.
 * ev_6f25f465777d6c282cbfa6a77d593954d589f2e76f9dc6caa100c42a001a6af1
 * Entry: 0x6f8594; label: FUN_006f8594
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006f8594(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = &PTR_FUN_0077dff8;
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

