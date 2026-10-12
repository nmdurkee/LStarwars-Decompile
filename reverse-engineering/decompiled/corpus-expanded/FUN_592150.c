/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x592150; label: FUN_00592150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00592150(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_009555b8 = PTR_s_GizBuildit_00804eb0;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_009555b8;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_009555d8 = 0;
  _DAT_009555f0 = 0;
  _DAT_009555f8 = 0;
  _DAT_00955600 = 0;
  _DAT_00955604 = 0;
  _DAT_00955608 = 0;
  _DAT_0095560c = 0;
  _DAT_0095562c = 0;
  DAT_009555bc = &DAT_007516c0;
  _DAT_009555c0 = 0x60;
  _DAT_009555c4 = FUN_00590960;
  _DAT_009555c8 = FUN_00590980;
  _DAT_009555cc = FUN_00590610;
  _DAT_009555d0 = FUN_005912e0;
  _DAT_009555d4 = &LAB_005907b0;
  _DAT_009555dc = FUN_005909e0;
  _DAT_009555e0 = FUN_005909f0;
  _DAT_009555e4 = FUN_00590a20;
  _DAT_009555e8 = FUN_00590a30;
  _DAT_009555ec = FUN_00591120;
  _DAT_009555f4 = FUN_005900e0;
  _DAT_009555fc = FUN_00590120;
  _DAT_00955610 = FUN_00590a40;
  _DAT_00955614 = FUN_00590a60;
  _DAT_00955618 = FUN_00590aa0;
  _DAT_0095561c = FUN_00590530;
  _DAT_00955620 = &LAB_0058ffc0;
  _DAT_00955624 = FUN_00590e60;
  _DAT_00955628 = FUN_0058ff70;
  DAT_00804e44 = param_1;
  return &DAT_009555b8;
}

