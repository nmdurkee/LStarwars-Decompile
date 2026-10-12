/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d3220; label: FUN_004d3220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d3220(int param_1,float *param_2,float param_3)

{
  undefined4 uVar1;
  float10 fVar2;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  double local_8;
  
  fVar2 = (float10)FUN_005b7d30(_DAT_00925064,0x3e800000);
  local_8 = (double)CONCAT44(local_8._4_4_,(int)ROUND(fVar2 * (float10)4.0 * (float10)65536.0));
  uVar1 = FUN_006e6b90();
  local_8 = (double)(param_3 * 0.3);
  local_c = 0xc2;
  local_a = 0;
  local_b = 0xa3;
  FUN_0050c780(&local_c,*param_2,param_3 * 0.3 + param_2[1],param_2[2],param_3,param_3,param_3,0,
               *(undefined1 *)(param_1 + 0xf4),*(undefined1 *)(param_1 + 0xf5),
               *(undefined1 *)(param_1 + 0xf6),uVar1);
  local_b = 0xac;
  FUN_0050c780(&local_c,*param_2,param_2[1] - (float)local_8,param_2[2],param_3,param_3,param_3,0,
               *(undefined1 *)(param_1 + 0xf4),*(undefined1 *)(param_1 + 0xf5),
               *(undefined1 *)(param_1 + 0xf6),uVar1);
  local_8 = (double)(param_3 * 0.25);
  FUN_0050c780(&DAT_007533c4,*param_2 - param_3 * 0.25,param_2[1],param_2[2],param_3,param_3,param_3
               ,0,*(undefined1 *)(param_1 + 0xf4),*(undefined1 *)(param_1 + 0xf5),
               *(undefined1 *)(param_1 + 0xf6),uVar1);
  FUN_0050c780(&DAT_007533c8,*param_2 + (float)local_8,param_2[1],param_2[2],param_3,param_3,param_3
               ,0,*(undefined1 *)(param_1 + 0xf4),*(undefined1 *)(param_1 + 0xf5),
               *(undefined1 *)(param_1 + 0xf6),uVar1);
  return;
}

