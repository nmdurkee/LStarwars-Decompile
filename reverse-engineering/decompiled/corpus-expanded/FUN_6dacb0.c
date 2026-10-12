/* Ghidra pseudocode, not original source.
 * ev_65739642fe41f5b8b860334b2741f542947d362cd0074980e50397e4ea9361e6
 * Entry: 0x6dacb0; label: FUN_006dacb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006dacb0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  undefined *puStack_78;
  code *pcStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  int *piStack_68;
  undefined4 *puStack_64;
  int *piStack_60;
  undefined *puStack_5c;
  undefined4 *puStack_58;
  undefined4 uStack_54;
  byte bStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_14;
  
  uStack_54 = 0;
  puVar1 = (undefined4 *)(in_ECX + 0x30);
  puStack_5c = &DAT_00784f6c;
  piStack_60 = (int *)0x800;
  puStack_64 = (undefined4 *)param_2;
  piStack_68 = (int *)0x6dacd4;
  puStack_58 = puVar1;
  DirectInput8Create();
  piStack_60 = (int *)*puVar1;
  uStack_54 = 0;
  puVar2 = (undefined4 *)(in_ECX + 0x20);
  puStack_5c = &DAT_00784e0c;
  puStack_64 = (undefined4 *)0x6dace8;
  puStack_58 = puVar2;
  (**(code **)(*piStack_60 + 0xc))();
  piStack_68 = (int *)*puVar2;
  puStack_64 = &uStack_3c;
  uStack_3c = 0x2c;
  uStack_6c = 0x6dacff;
  (**(code **)(*piStack_68 + 0xc))();
  if ((bStack_40 & 1) == 0) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  else {
    pcStack_74 = (code *)*puVar2;
    *(undefined4 *)(in_ECX + 0x38) = uStack_34;
    uStack_6c = 5;
    *(undefined4 *)(in_ECX + 0x34) = uStack_38;
    uStack_70 = uStack_14;
    puStack_78 = (undefined *)0x6dad29;
    (**(code **)(*(int *)pcStack_74 + 0x34))();
    puStack_78 = &DAT_007e7f54;
    (**(code **)(*(int *)*puVar2 + 0x2c))((int *)*puVar2);
    piStack_68 = (int *)0x10;
    uStack_6c = 0x14;
    piStack_60 = (int *)0x0;
    puStack_64 = (undefined4 *)0x0;
    puStack_5c = (undefined *)0x0;
    (**(code **)(*(int *)*puVar2 + 0x18))((int *)*puVar2,2,&uStack_6c);
    pcStack_74 = (code *)0x10;
    piStack_68 = (int *)0x10;
    puStack_78 = (undefined *)0x14;
    uStack_70 = 0;
    uStack_6c = 0;
    (**(code **)(*(int *)*puVar2 + 0x18))((int *)*puVar2,1,&puStack_78);
    (**(code **)(*(int *)*puVar2 + 0x1c))((int *)*puVar2);
  }
  uStack_6c = 0x68b4;
  uStack_70 = 0x6dadaf;
  iVar3 = FUN_006ea018();
  if (iVar3 == 0) {
    DAT_02975144 = 0;
  }
  else {
    uStack_6c = 0x6dadbd;
    DAT_02975144 = FUN_006da560();
  }
  uStack_6c = 0;
  uStack_70 = 0;
  pcStack_74 = (code *)0x6dadd1;
  FUN_006d9540();
  uStack_6c = 1;
  uStack_70 = 0;
  pcStack_74 = FUN_006d9df0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  puStack_78 = (undefined *)0x3;
  DAT_029755dc = 0;
  (**(code **)(*(int *)*puVar1 + 0x10))((int *)*puVar1);
  (**(code **)(*(int *)*puVar1 + 0x10))((int *)*puVar1,2,FUN_006d9df0,0,1);
  (**(code **)(*(int *)*puVar1 + 0x10))((int *)*puVar1,4,FUN_006d9df0,0,1);
  _DAT_02976580 = 0x3e4ccccd;
  _DAT_02976588 = 0x3e4ccccd;
  DAT_00824f9c = 0xffffffff;
  DAT_02976584 = 3;
  return;
}

