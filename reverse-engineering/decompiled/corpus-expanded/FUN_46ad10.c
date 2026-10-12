/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x46ad10; label: FUN_0046ad10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046ad10(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_5c;
  float local_58;
  undefined4 local_54;
  int local_50 [2];
  undefined4 *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_2a;
  int local_28;
  code *local_14;
  code *local_8;
  undefined1 local_3;
  
  FUN_0054a8a0(**(undefined4 **)(param_4 + 0xca4),0x3e4ccccd,0);
  FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x13,param_2 + 8);
  iVar1 = *(int *)(PTR_DAT_00802c54 + 0x2ac0);
  if (*(char *)(iVar1 + 0xcfe) != '\0') {
    local_5c = _DAT_0080525c;
    local_58 = _DAT_00805270 + _DAT_00805260;
    piVar3 = &DAT_00802cd8;
    piVar4 = local_50;
    for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar4 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    local_54 = 0x3f800000;
    local_44 = DAT_00950f60;
    local_40 = _DAT_0080526c;
    local_34 = 0x3f800000;
    local_48 = &local_5c;
    local_28 = iVar1 + 0xcf0;
    local_38 = 0x2112d;
    local_2a = 0xcf;
    local_14 = FUN_0059a420;
    local_8 = FUN_0059a4c0;
    local_3 = 1;
    local_50[1] = param_2 + 8;
    iVar1 = FUN_00560b60(local_50);
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0xfe) = 6;
    }
    _DAT_0087b934 = 0x40000000;
    if (DAT_00951240 < 10) {
      DAT_00951240 = DAT_00951240 + 1;
    }
  }
  return;
}

