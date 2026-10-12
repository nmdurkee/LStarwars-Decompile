/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x631170; label: FUN_00631170
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00631170(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar2 = DAT_029765cc;
  uVar1 = DAT_029765c8;
  _DAT_029131c8 = 0;
  _DAT_029131c4 = 0;
  if (DAT_029131c0 == 0) {
    uVar3 = FUN_00697a20();
    iVar4 = FUN_00631890(DAT_00924864,uVar1,uVar2,uVar3);
    if (iVar4 == 0) goto LAB_006311f7;
    DAT_029131c0 = 1;
  }
  DAT_02913188 = FUN_00631940(&DAT_02913178,param_1,0,param_2,param_3);
  if (DAT_02913188 == 1) {
    return 1;
  }
  DAT_02913188 = 0;
LAB_006311f7:
  FUN_00631d00(&DAT_02913178);
  return 0;
}

