/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1c90; label: FUN_004f1c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1c90(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = *(undefined4 *)(param_1 + 4);
  local_4 = *(undefined4 *)(param_1 + 8);
  local_10 = *(undefined4 *)(param_1 + 0xc);
  local_c = *(undefined4 *)(param_1 + 0x10);
  local_18 = param_5;
  local_14 = param_6;
  local_20 = param_3;
  local_1c = param_4;
  FUN_004f18c0(param_1,0,&local_10,&local_20,param_2,*(undefined4 *)(param_1 + 0x34));
  return;
}

