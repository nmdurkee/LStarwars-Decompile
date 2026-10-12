/* Ghidra pseudocode, not original source.
 * ev_48d4eb782bac12eedeead3c338e4f978b0df7732be8621fd20cf56d53bd7b1ed
 * Entry: 0x401140; label: FUN_00401140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00401140(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    FUN_00547930(0x31,0,0,0);
    return;
  case 1:
  case 2:
    FUN_00547930(0x30,0,0,0);
    return;
  case 3:
  case 4:
  case 5:
    FUN_00547930(0x2f,0,0,0);
    break;
  case 6:
    FUN_00547930(0x32,0,0,0);
    return;
  }
  return;
}

