/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ae8e0; label: FUN_005ae8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005ae8e0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_0095e070;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_0095e078 = 0;
  _DAT_0095e084 = 0;
  _DAT_0095e088 = 0;
  _DAT_0095e08c = 0;
  _DAT_0095e090 = 0;
  _DAT_0095e0b0 = 0;
  _DAT_0095e0bc = 0;
  _DAT_0095e0c0 = 0;
  _DAT_0095e0c4 = 0;
  _DAT_0095e0dc = 0;
  _DAT_0095e0e0 = 0;
  _DAT_0095e0e4 = 0;
  DAT_00805ebc = param_1;
  DAT_0095e070 = "NuSpecial";
  DAT_0095e074 = &DAT_00805eb4;
  _DAT_0095e07c = FUN_005ae130;
  _DAT_0095e080 = FUN_005ae150;
  _DAT_0095e094 = FUN_005ae390;
  _DAT_0095e098 = FUN_005ae3a0;
  _DAT_0095e09c = FUN_005ae420;
  _DAT_0095e0a0 = FUN_005ae440;
  _DAT_0095e0a4 = FUN_005ae450;
  _DAT_0095e0a8 = FUN_005ae4a0;
  _DAT_0095e0ac = FUN_005ae520;
  _DAT_0095e0b4 = FUN_005ae540;
  _DAT_0095e0b8 = FUN_005ae590;
  _DAT_0095e0c8 = FUN_005ae6c0;
  _DAT_0095e0cc = FUN_005ae6e0;
  _DAT_0095e0d0 = FUN_005ae720;
  _DAT_0095e0d4 = &LAB_005ae620;
  _DAT_0095e0d8 = FUN_005ae7d0;
  return &DAT_0095e070;
}

