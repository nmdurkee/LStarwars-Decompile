/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x560fa0; label: FUN_00560fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00560fa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_50 [4];
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  
  puVar2 = &DAT_00802cd8;
  puVar3 = local_50;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_50[3] = param_3;
  local_40 = param_5;
  local_34 = param_10;
  local_50[1] = param_2;
  local_50[0] = param_1;
  local_3b = param_7;
  local_50[2] = param_4;
  local_3c = param_6;
  local_3a = param_8;
  local_38 = param_9;
  FUN_00560b60(local_50);
  return;
}

