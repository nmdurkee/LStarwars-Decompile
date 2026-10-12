/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f22a0; label: FUN_005f22a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f22a0(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int unaff_EBX;
  int unaff_EBP;
  
  uVar4 = DAT_00973904;
  uVar3 = DAT_00973900;
  uVar5 = param_1 & 0xc;
  DAT_00971598 = param_1;
  if (uVar5 != 0) {
    if (DAT_00974014 == (int *)0x0) {
      DAT_009737e0 = (int *)0x0;
      DAT_00974014 = DAT_00974014 + 0x58;
    }
    else {
      DAT_00974014 = DAT_00974014 + 0x58;
      DAT_009737e0 = (int *)FUN_0060a8b0();
    }
  }
  piVar2 = DAT_00974014;
  uVar6 = param_1 & 0x10;
  if (uVar6 != 0) {
    if (DAT_00974014 == (int *)0x0) {
      DAT_009737e8 = (int *)0x0;
      DAT_00974014 = DAT_00974014 + 0x28;
    }
    else {
      piVar1 = DAT_00974014 + 1;
      DAT_00974014 = DAT_00974014 + 0x28;
      *(undefined1 *)piVar1 = 0;
      piVar2[0x25] = 0;
      piVar2[2] = 0;
      piVar2[0x26] = 0;
      *piVar2 = (int)&PTR_LAB_007643e0;
      piVar2[0x27] = 0x3f800000;
      DAT_009737e8 = piVar2;
    }
    _DAT_009737f8 = _DAT_009737f8 | 0x20;
  }
  piVar2 = DAT_00974014;
  if ((param_1 & 0x40) != 0) {
    if (DAT_00974014 == (int *)0x0) {
      DAT_009737ec = (int *)0x0;
      DAT_00974014 = DAT_00974014 + 10;
    }
    else {
      piVar1 = DAT_00974014 + 7;
      DAT_00974014 = DAT_00974014 + 10;
      *piVar1 = 0x3f800000;
      *(undefined1 *)(piVar2 + 1) = 0;
      piVar2[2] = 0;
      piVar2[8] = 0;
      piVar2[6] = 0;
      *piVar2 = (int)&PTR_LAB_0076543c;
      DAT_009737ec = piVar2;
    }
  }
  piVar2 = DAT_00974014;
  uVar7 = param_1 & 0x80;
  if (uVar7 != 0) {
    DAT_00974014 = DAT_00974014 + 0x10;
    if (piVar2 == (int *)0x0) {
      DAT_009737f0 = (int *)0x0;
    }
    else {
      *(undefined1 *)(piVar2 + 1) = 0;
      piVar2[2] = 0;
      *piVar2 = (int)&PTR_FUN_00765468;
      FUN_006069a0();
      DAT_009737f0 = piVar2;
    }
  }
  if ((param_1 & 0x20) != 0) {
    if (DAT_00974014 == (int *)0x0) {
      DAT_009737e4 = (int *)0x0;
      DAT_00974014 = DAT_00974014 + 0xbe;
    }
    else {
      DAT_00974014 = DAT_00974014 + 0xbe;
      DAT_009737e4 = (int *)FUN_005e6840();
    }
    _DAT_009737f8 = _DAT_009737f8 | 0x10;
  }
  DAT_009737f4 = DAT_00974014;
  if (DAT_00974014 == (int *)0x0) {
    DAT_009737f4 = (int *)0x0;
    DAT_00974014 = DAT_00974014 + 5;
  }
  else {
    piVar2 = DAT_00974014 + 1;
    DAT_00974014 = DAT_00974014 + 5;
    *(undefined1 *)piVar2 = 0;
    DAT_009737f4[2] = 0;
    *DAT_009737f4 = (int)&PTR_LAB_0076440c;
  }
  FUN_005f7a90(param_2,param_3);
  FUN_00605ef0(uVar3,uVar4);
  if (uVar5 != 0) {
    (**(code **)(*DAT_009737e0 + 0xc))(uVar3,uVar4);
  }
  if (uVar6 != 0) {
    (**(code **)(*DAT_009737e8 + 0xc))(uVar3,uVar4);
  }
  if ((param_1 & 0x40) != 0) {
    (**(code **)(*DAT_009737ec + 0xc))(uVar3,uVar4);
  }
  if (uVar7 != 0) {
    (**(code **)(*DAT_009737f0 + 0xc))(uVar3,uVar4);
  }
  if ((param_1 & 0x20) != 0) {
    (**(code **)(*DAT_009737e4 + 0xc))(uVar3,uVar4);
  }
  if ((param_1 & 1) != 0) {
    DAT_00963e08 = DAT_02854c2c;
  }
  (**(code **)(*DAT_009737f4 + 0xc))(uVar3,uVar4);
  FUN_005f7aa0();
  FUN_0060db40(uVar3,uVar4);
  if (unaff_EBP != 0) {
    (**(code **)(*DAT_009737e0 + 4))();
  }
  if (unaff_EBX != 0) {
    (**(code **)(*DAT_009737e8 + 4))();
  }
  if (uVar5 != 0) {
    (**(code **)(*DAT_009737ec + 4))();
  }
  if (uVar7 != 0) {
    (**(code **)(*DAT_009737f0 + 4))();
  }
  if (uVar6 != 0) {
    (**(code **)(*DAT_009737e4 + 4))();
  }
  (**(code **)(*DAT_009737f4 + 4))();
  _DAT_009737d8 = 0;
  DAT_009737dc = 0;
  return;
}

