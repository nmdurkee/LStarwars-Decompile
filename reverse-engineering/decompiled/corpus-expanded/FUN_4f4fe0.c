/* Ghidra pseudocode, not original source.
 * ev_df79f36d452c441765aee3b48fdf5c85f40e43d18ea34c7e23c83a31d911b650
 * Entry: 0x4f4fe0; label: FUN_004f4fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f4fe0(undefined4 param_1)

{
  DAT_0297dbc8 = param_1;
  switch(param_1) {
  case 2:
  case 5:
  case 6:
    DAT_0297dbdc = 0;
    break;
  case 3:
  case 4:
    DAT_0297dbdc = 1;
    return;
  }
  return;
}

