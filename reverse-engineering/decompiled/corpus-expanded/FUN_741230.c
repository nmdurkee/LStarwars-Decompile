/* Ghidra pseudocode, not original source.
 * ev_5ac1ee00c479ad98735f6958677979f6fc8ed4ea1e5106cd7456ee96087ef4e0
 * Entry: 0x741230; label: FUN_00741230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00741230(int *param_1,int param_2)

{
  undefined1 local_10 [4];
  int local_c;
  int local_4;
  
  FUN_00740e50();
  FUN_00740eb0(*param_1,param_2 - *param_1);
  if (local_c != 0) {
    local_c = local_c + 0x791b0;
    DAT_0297cc6c = FUN_00746020(local_10);
    *param_1 = *param_1 + (local_c - local_4);
    FUN_00740e90();
    return;
  }
  *param_1 = *param_1 + (0x791b0 - local_4);
  DAT_0297cc6c = 0;
  local_c = local_c + 0x791b0;
  FUN_00740e90();
  return;
}

