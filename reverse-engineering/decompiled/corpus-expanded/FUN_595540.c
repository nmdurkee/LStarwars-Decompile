/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x595540; label: FUN_00595540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00595540(undefined4 *param_1,float param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_144 [30];
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_84;
  float local_80;
  float local_7c;
  
  if (param_2 == 1.0) {
    FUN_006363b0(param_1);
    return;
  }
  puVar2 = local_144;
  for (iVar1 = 0x51; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  local_cc = local_cc * param_2;
  local_c8 = local_c8 * param_2;
  local_c4 = local_c4 * param_2;
  local_c0 = local_c0 * param_2;
  local_bc = local_bc * param_2;
  local_b8 = local_b8 * param_2;
  local_b4 = local_b4 * param_2;
  local_b0 = local_b0 * param_2;
  local_ac = local_ac * param_2;
  local_84 = local_84 * param_2;
  local_80 = local_80 * param_2;
  local_7c = param_2 * local_7c;
  FUN_006363b0(local_144);
  return;
}

