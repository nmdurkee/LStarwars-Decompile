/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x5235a0; label: FUN_005235a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005235a0(float param_1)

{
  float *unaff_ESI;
  float local_48;
  float local_44;
  float local_40;
  float local_24;
  float local_20;
  float local_1c;
  
  local_44 = unaff_ESI[1];
  local_40 = unaff_ESI[2];
  local_48 = param_1 + *unaff_ESI;
  local_24 = *unaff_ESI - param_1;
  local_20 = local_44;
  local_1c = local_40;
  FUN_00512b00(&local_48,0,0);
  local_48 = *unaff_ESI;
  local_44 = unaff_ESI[1];
  local_40 = param_1 + unaff_ESI[2];
  local_1c = unaff_ESI[2] - param_1;
  local_24 = local_48;
  local_20 = local_44;
  FUN_00512b00(&local_48,0,0);
  return;
}

