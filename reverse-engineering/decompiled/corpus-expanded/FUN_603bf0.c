/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x603bf0; label: FUN_00603bf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603bf0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0 [16];
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  local_cc = 0;
  local_c8 = 0x3f800000;
  local_c4 = 0;
  if (param_1 != (undefined4 *)0x0) {
    FUN_005b6ec0(param_1,&local_f0);
    FUN_005b4500(local_40,&local_f0);
    local_d8 = *param_2;
    local_d4 = param_2[1];
    local_d0 = param_2[2];
    local_e4 = local_f0;
    local_e0 = local_ec;
    local_dc = local_e8;
    D3DXMatrixLookAtLH(local_80,&local_e4,&local_d8,&local_cc);
    puVar2 = local_80;
    puVar3 = local_c0;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005b5a40(local_c0,local_c0);
    puVar2 = local_c0;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *puVar2;
      puVar2 = puVar2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}

