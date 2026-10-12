/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x483c10; label: FUN_00483c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00483c10(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *pcVar6;
  
  uVar2 = param_1[2];
  uVar1 = param_1[0x1a];
  uVar3 = param_1[4];
  uVar4 = *param_1;
  uVar5 = param_1[1];
  pcVar6 = (code *)param_1[3];
  (*pcVar6)(param_1);
  _memset(param_1,0,0x14c);
  param_1[0x1a] = uVar1;
  param_1[3] = pcVar6;
  *param_1 = uVar4;
  param_1[1] = uVar5;
  param_1[2] = uVar2;
  param_1[4] = uVar3;
  return;
}

