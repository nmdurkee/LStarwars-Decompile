/* Ghidra pseudocode, not original source.
 * ev_9cfa2c7caaff9bea1a8899eb9da7a192a21c6dc6359864cdd250e80ead8b0fa3
 * Entry: 0x4e3890; label: FUN_004e3890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e3890(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  undefined4 *local_d0 [5];
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 *local_ac;
  undefined *local_a4;
  code *local_9c;
  code *local_90;
  code *local_8c;
  undefined4 local_44;
  
  piVar1 = &DAT_0087a810 + param_1;
  if (((&DAT_0087a810)[param_1] != 0) && (*(int *)(&DAT_0087aae0 + param_1 * 0xc) != 0)) {
    puVar3 = &DAT_00810210;
    ppuVar4 = local_d0;
    for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
      *ppuVar4 = (undefined4 *)*puVar3;
      puVar3 = puVar3 + 1;
      ppuVar4 = ppuVar4 + 1;
    }
    local_b8 = _DAT_008000a4;
    local_bc = _DAT_008000a4;
    local_b4 = 0;
    local_44 = _DAT_00925018;
    local_d0[0] = &DAT_00806680;
    local_d0[2] = &DAT_0093b0cc;
    local_a4 = &DAT_0080861a;
    local_d0[3] = (undefined4 *)0x0;
    local_9c = FUN_004e36d0;
    local_90 = FUN_0042cf20;
    local_8c = FUN_004e3810;
    local_ac = &DAT_0087aad8 + param_1 * 3;
    iVar2 = FUN_0064d270(local_d0);
    if (iVar2 != 0) {
      (&DAT_008895c0)[param_1] = iVar2;
    }
    *(undefined4 *)(*piVar1 + 0x4c) = 0x3f800000;
    *(uint *)(*piVar1 + 0x50) = *(uint *)(*piVar1 + 0x50) | 1;
    puVar3 = &DAT_00806680;
    puVar5 = (undefined4 *)*piVar1;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    FUN_005cfc00(&DAT_0087aad8 + param_1 * 3,1);
  }
  return;
}

