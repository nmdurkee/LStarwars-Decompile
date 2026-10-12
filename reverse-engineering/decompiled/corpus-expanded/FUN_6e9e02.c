/* Ghidra pseudocode, not original source.
 * ev_09868580522dc648f316624eb19739c7cb4fa50c58af47c6d946b46a2ca90732
 * Entry: 0x6e9e02; label: FUN_006e9e02
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e9e02(byte param_1)

{
  exception *in_ECX;
  
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_006e85b0();
  }
  return;
}

