/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x474710; label: FUN_00474710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00474710(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00879470;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00879484 = 0;
  _DAT_00879490 = 0;
  _DAT_008794a8 = 0;
  _DAT_008794b0 = 0;
  _DAT_008794b4 = 0;
  _DAT_008794b8 = 0;
  _DAT_008794bc = 0;
  _DAT_008794c0 = 0;
  _DAT_008794c4 = 0;
  _DAT_008794e0 = 0;
  _DAT_008794e4 = 0;
  _DAT_007f926c = param_1;
  DAT_00879470 = "HatMachine";
  DAT_00879474 = &DAT_007516c0;
  _DAT_00879478 = 0xc;
  _DAT_0087947c = FUN_00473e90;
  _DAT_00879480 = FUN_00473eb0;
  _DAT_00879488 = FUN_00472e90;
  _DAT_0087948c = FUN_00472fe0;
  _DAT_00879494 = FUN_00473f20;
  _DAT_00879498 = FUN_00473f50;
  _DAT_0087949c = &LAB_00473f60;
  _DAT_008794a0 = &LAB_00473f70;
  _DAT_008794a4 = FUN_004746d0;
  _DAT_008794ac = FUN_00472b00;
  _DAT_008794c8 = FUN_00473f80;
  _DAT_008794cc = FUN_00473fa0;
  _DAT_008794d0 = FUN_00473fc0;
  _DAT_008794d4 = &LAB_00472cd0;
  _DAT_008794d8 = FUN_00472a50;
  _DAT_008794dc = FUN_00472890;
  return &DAT_00879470;
}

